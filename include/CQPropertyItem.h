#ifndef CQPropertyItem_H
#define CQPropertyItem_H

#include <QTreeWidgetItem>
#include <QPointer>

class CQPropertyEditorFactory;
class CQPropertyDelegate;

/*!
  \class CQPropertyItem

  \brief Custom Tree Widget item for editable object properties
*/
class CQPropertyItem : public QObject, public QTreeWidgetItem {
  Q_OBJECT

 private:
  //! unique id
  enum { PROPERTY_ITEM_ID = QTreeWidgetItem::UserType + 142 };

 public:
  //! type check for casting
  static bool isType(int type) { return type == PROPERTY_ITEM_ID; }

  //! constructor
  CQPropertyItem(QTreeWidgetItem *item, const QString &name, const QString &info,
                 const QString &type, QObject *object);

  //! copy constructor
  CQPropertyItem(const CQPropertyItem &item);

  //! get property object
  QObject *getObject() const { return object_; }

  //! set editor
  void setEditorFactory(CQPropertyEditorFactory *editor) { editor_ = editor; }

  //! set label
  CQPropertyItem *setLabel(const QString &label);
  //! get label
  QString getLabel() const;

  //! clone (required by QTreeWidgetItem interface)
  QTreeWidgetItem *clone() const { return new CQPropertyItem(*this); }

  //! handle click
  bool click();

  //! create editor widget (required by QTreeWidgetItem interface)
  QWidget *createEditor(QWidget *parent);

  //! set widget property from string
  void setEditorData(const QString &value);
  //! set widget property from variant
  void setEditorData(const QVariant &value);

  //! get editor widget text
  QVariant getEditorData() const;

  //! is writable
  bool isWritable() const;

  //! paint item
  bool paint(const CQPropertyDelegate *delegate, QPainter *painter,
             const QStyleOptionViewItem &option, const QModelIndex &index);

 signals:
  void valueChanged(QObject *obj, const QString &name);

 private slots:
  //! called when the editor widget is changed
  void updateValue();

 private:
  //! private data
  QString                  name_;   //! property name
  QString                  info_;   //! property info (RO), (ENUM), ...
  QString                  type_;   //! property type name
  QPointer<QObject>        object_; //! property object
  QWidget                 *widget_; //! editor widget
  QString                  label_;  //! property label
  CQPropertyEditorFactory *editor_; //! editor interface
};

#endif
