#include <CQPropertyItem.h>
#include <CQPropertyEditor.h>
#include <CQPropertyDelegate.h>
#include <CQUtil.h>

#include <QVariant>
#include <QComboBox>
#include <QCheckBox>
#include <QLineEdit>
#include <QPainter>

#include <iostream>

/*! create custom tree widget item for properties
*/
CQPropertyItem::
CQPropertyItem(QTreeWidgetItem *parent, const QString &name, const QString &info,
               const QString &type, QObject *object) :
 QObject(), QTreeWidgetItem(parent, PROPERTY_ITEM_ID), name_(name), info_(info),
 type_(type), object_(object), widget_(0), label_(), editor_(0)
{
  setText(0, name_ + info_);
  setData(1, Qt::EditRole, getEditorData());
  //setText(2, type_);

  CQUtil::PropInfo propInfo;

  if (CQUtil::getPropInfo(object_, name_, &propInfo) && propInfo.isWritable())
    setFlags(flags() | Qt::ItemIsEditable);
}

/*! duplicate custom tree widget item for properties
*/
CQPropertyItem::
CQPropertyItem(const CQPropertyItem &item) :
 QObject(), QTreeWidgetItem(item), name_(item.name_), info_(item.info_),
 type_(item.type_), object_(item.object_), widget_(0), label_(), editor_(0)
{
  setText(0, name_ + info_);
  setData(1, Qt::EditRole, getEditorData());
  //setText(1, type_);

  CQUtil::PropInfo propInfo;

  if (CQUtil::getPropInfo(object_, name_, &propInfo) && propInfo.isWritable())
    setFlags(flags() | Qt::ItemIsEditable);
}

//! set label
CQPropertyItem *
CQPropertyItem::
setLabel(const QString &label)
{
  label_ = label;

  if (label_.length())
    setText(0, label_);
  else
    setText(0, name_ + info_);

  return this;
}

//! get label
QString
CQPropertyItem::
getLabel() const
{
  if (label_.length())
    return label_;

  return name_;
}

// handle click
bool
CQPropertyItem::
click()
{
  CQUtil::PropInfo propInfo;
  QString          typeName;

  if (CQUtil::getPropInfo(object_, name_, &propInfo))
    typeName = propInfo.typeName();

  QVariant var;

  if (! CQUtil::getProperty(object_, name_, var))
    var = QVariant("");

  if (propInfo.isEnumType())
    return false;

  if (typeName == "bool" && propInfo.isWritable()) {
    if (! CQUtil::setProperty(object_, name_, ! var.toBool()))
      std::cerr << "Failed to set property " << name_.toStdString() << std::endl;

    emit valueChanged(object_, name_);

    return true;
  }

  return false;
}

/*! get property value
*/
QVariant
CQPropertyItem::
getEditorData() const
{
  CQUtil::PropInfo propInfo;
  QString          typeName;

  if (CQUtil::getPropInfo(object_, name_, &propInfo))
    typeName = propInfo.typeName();

  QVariant var;

  if (! CQUtil::getProperty(object_, name_, var))
    var = QVariant("");

  if (propInfo.isEnumType()) {
    int ind = var.toInt();

    const QStringList &names = propInfo.enumNames();

    if (ind >= 0 && ind < names.count())
      var = QString(names[ind]);
  }

  return var;
}

/*! create editor widget for property
*/
QWidget *
CQPropertyItem::
createEditor(QWidget *parent)
{
  CQUtil::PropInfo propInfo;
  QString          typeName;

  if (CQUtil::getPropInfo(object_, name_, &propInfo))
    typeName = propInfo.typeName();

  QVariant var;

  if (! CQUtil::getProperty(object_, name_, var))
    var = QVariant("");

  if (propInfo.isEnumType()) {
    int ind = var.toInt();

    const QStringList &names = propInfo.enumNames();

    if (ind >= 0 && ind < names.count())
      var = QVariant(names[ind]);
  }

  CQPropertyEditorFactory *editor = editor_;

  if (! editor)
    editor = CQPropertyEditorMgr::instance()->getEditor(typeName);

  if      (editor) {
    widget_ = editor->createEdit(parent);

    editor->setValue(widget_, var);

    editor->connect(widget_, this, SLOT(updateValue()));
  }
  // enum - create combobox
  else if (propInfo.isEnumType()) {
    QString valueStr = var.toString();

    const QStringList &names = propInfo.enumNames();

    QComboBox *combo = new QComboBox(parent);

    combo->addItems(names);
    combo->setCurrentIndex(combo->findText(valueStr));

    connect(combo, SIGNAL(currentIndexChanged(const QString &)),
            this, SLOT(updateValue()));

    widget_ = combo;
  }
  // bool - create toggle
  // TODO: use button press (no need to edit) see CQCheckTree.cpp
  else if (typeName == "bool") {
    QCheckBox *check = new QCheckBox(parent);

    check->setChecked(var.toBool());

    check->setText(check->isChecked() ? "true" : "false");

    check->setAutoFillBackground(true);
    //check->setLayoutDirection(Qt::RightToLeft);

    connect(check, SIGNAL(stateChanged(int)), this, SLOT(updateValue()));

    widget_ = check;
  }
  // anything else - create line edit
  else {
    QLineEdit *edit = new QLineEdit(parent);

    QString valueStr;

    if (! CQUtil::variantToString(var, valueStr))
      std::cerr << "Failed to convert to string" << std::endl;

    edit->setText(valueStr);

    connect(edit, SIGNAL(editingFinished()), this, SLOT(updateValue()));

    widget_ = edit;
  }

  return widget_;
}

/*! set property from string
*/
void
CQPropertyItem::
setEditorData(const QString &value)
{
  CQUtil::PropInfo propInfo;

  if (CQUtil::getPropInfo(object_, name_, &propInfo) && propInfo.isWritable()) {
    if (propInfo.isEnumType()) {
      const QStringList &names = propInfo.enumNames();

      for (int i = 0; i < names.size(); ++i) {
        if (value == names[i]) {
          QVariant v(i);

          if (! CQUtil::setProperty(object_, name_, v))
            std::cerr << "Failed to set property " << name_.toStdString() << std::endl;
        }
      }
    }
    else {
      if (! CQUtil::setProperty(object_, name_, value))
        std::cerr << "Failed to set property " << name_.toStdString() << std::endl;
    }

    emit valueChanged(object_, name_);
  }
}

/*! set property from variant
*/
void
CQPropertyItem::
setEditorData(const QVariant &var)
{
  CQUtil::PropInfo propInfo;

  if (CQUtil::getPropInfo(object_, name_, &propInfo) && propInfo.isWritable()) {
    if (propInfo.isEnumType()) {
      QString varStr = var.toString();

      const QStringList &names = propInfo.enumNames();

      for (int i = 0; i < names.size(); ++i) {
        if (varStr == names[i]) {
          QVariant v(i);

          if (! CQUtil::setProperty(object_, name_, v))
            std::cerr << "Failed to set property " << name_.toStdString() << std::endl;
        }
      }
    }
    else {
      if (! CQUtil::setProperty(object_, name_, var))
        std::cerr << "Failed to set property " << name_.toStdString() << std::endl;
    }

    emit valueChanged(object_, name_);
  }
}

/*! update property on widget change
*/
void
CQPropertyItem::
updateValue()
{
  QString typeName;

  CQUtil::PropInfo propInfo;

  if (CQUtil::getPropInfo(object_, name_, &propInfo))
    typeName = propInfo.typeName();

  CQPropertyEditorFactory *editor = editor_;

  if (! editor)
    editor = CQPropertyEditorMgr::instance()->getEditor(typeName);

  if      (editor) {
    QVariant var = editor->getValue(widget_);

    setEditorData(var);
  }
  else if (propInfo.isEnumType()) {
    QComboBox *combo = qobject_cast<QComboBox *>(widget_);
    assert(combo);

    QString text = combo->currentText();

    setEditorData(text);
  }
  else if (typeName == "bool") {
    QCheckBox *check = qobject_cast<QCheckBox *>(widget_);
    assert(check);

    check->setText(check->isChecked() ? "true" : "false");

    QString text = (check->isChecked() ? "1" : "0");

    setEditorData(text);
  }
  else {
    QLineEdit *edit = qobject_cast<QLineEdit *>(widget_);
    assert(edit);

    QString text = edit->text();

    setEditorData(text);
  }
}

bool
CQPropertyItem::
isWritable() const
{
   CQUtil::PropInfo propInfo;

  if (CQUtil::getPropInfo(object_, name_, &propInfo))
    return propInfo.isWritable();

  return false;
}

bool
CQPropertyItem::
paint(const CQPropertyDelegate *delegate, QPainter *painter,
      const QStyleOptionViewItem &option, const QModelIndex &index)
{
  CQUtil::PropInfo propInfo;
  QString          typeName;

  if (CQUtil::getPropInfo(object_, name_, &propInfo))
    typeName = propInfo.typeName();

  QVariant var;

  if (! CQUtil::getProperty(object_, name_, var))
    var = QVariant("");

  if (propInfo.isEnumType())
    return false;

  if      (typeName == "CAngle") {
    delegate->drawAngle(painter, option, var.value<CAngle>(), index);
    return true;
  }
  else if (typeName == "QColor") {
    delegate->drawColor(painter, option, var.value<QColor>(), index);
    return true;
  }
  else if (typeName == "QFont") {
    delegate->drawFont(painter, option, var.value<QFont>(), index);
    return true;
  }
  else if (typeName == "QPointF") {
    delegate->drawPoint(painter, option, var.value<QPointF>(), index);
    return true;
  }
  else if (typeName == "bool") {
    delegate->drawCheck(painter, option, var.toBool(), index);
    return true;
  }
  else {
    QString str;
    if (! CQUtil::variantToString(var, str))
      return false;
    delegate->drawString(painter, option, str, index);
    return true;
  }
}
