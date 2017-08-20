#include <CQPropertyDelegate.h>
#include <CQPropertyTree.h>
#include <CQPropertyItem.h>
#include <CQUtil.h>

#include <QApplication>
#include <QTreeWidget>
#include <QLineEdit>
#include <QPainter>
#include <QLayout>

#include <cassert>

/*! create tree widget delegate
*/
CQPropertyDelegate::
CQPropertyDelegate(CQPropertyTree *tree) :
 QItemDelegate(tree), tree_(tree)
{
}

/*! create editor for tree widget item
*/
QWidget *
CQPropertyDelegate::
createEditor(QWidget *parent, const QStyleOptionViewItem &, const QModelIndex &index) const
{
  QTreeWidgetItem *item = getModelItem(index);
  assert(item);

  CQPropertyDelegate *th = const_cast<CQPropertyDelegate *>(this);

  QWidget *w = 0;

  if (CQPropertyItem::isType(item->type())) {
    CQPropertyItem *item1 = dynamic_cast<CQPropertyItem *>(item);
    assert(item1);

    if (index.column() == 1)
      w = item1->createEditor(parent);
  }
  else
    assert(false);

  if (w) {
    w->updateGeometry();

    if (w->layout())
      w->layout()->invalidate();

    //w->setFixedSize(sizeHint(option, index));

    w->installEventFilter(th);
  }

  return w;
}

/*! get data to display in tree widget item
*/
void
CQPropertyDelegate::
setEditorData(QWidget *, const QModelIndex &index) const
{
  QTreeWidgetItem *item = getModelItem(index);
  assert(item);

  if (CQPropertyItem::isType(item->type())) {
    CQPropertyItem *item1 = dynamic_cast<CQPropertyItem *>(item);
    assert(item1);

    QVariant var = index.model()->data(index, Qt::DisplayRole);

    QString value;

    if (! CQUtil::variantToString(var, value))
      std::cerr << "Failed to convert to string" << std::endl;

    item1->setEditorData(value);
  }
  else
    assert(false);
}

/*! store displayed tree widget item data in model
*/
void
CQPropertyDelegate::
setModelData(QWidget *, QAbstractItemModel *model, const QModelIndex &index) const
{
  QTreeWidgetItem *item = getModelItem(index);
  assert(item);

  if (CQPropertyItem::isType(item->type())) {
    CQPropertyItem *item1 = dynamic_cast<CQPropertyItem *>(item);
    assert(item1);

    QVariant var = item1->getEditorData();

    model->setData(index, var);
  }
  else
    assert(false);
}

/*! update geometry
*/
void
CQPropertyDelegate::
updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                     const QModelIndex &/* index */) const
{
  editor->setGeometry(option.rect);
}

/*! draw item
*/
void
CQPropertyDelegate::
paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
  QTreeWidgetItem *item = getModelItem(index);
  assert(item);

  //---

  bool inside = tree_->isMouseInd(index);

  QBrush b;

  if (inside) {
    QVariant value = index.data(Qt::BackgroundRole);

    if (value.canConvert<QBrush>())
      b = qvariant_cast<QBrush>(value);

    QColor c = option.palette.color(QPalette::Window);

    QBrush b1(c.darker(110));

    item->setData(0, Qt::BackgroundRole, b1);
    item->setData(1, Qt::BackgroundRole, b1);
  }

  //---

  if (CQPropertyItem::isType(item->type())) {
    CQPropertyItem *item1 = dynamic_cast<CQPropertyItem *>(item);
    assert(item1);

    QStyleOptionViewItem option1 = option;

    if (! item1->isWritable()) {
      option1.font.setItalic(true);
    }

    if (index.column() == 1) {
      if (! item1->paint(this, painter, option1, index))
        QItemDelegate::paint(painter, option1, index);
    }
    else {
      QItemDelegate::paint(painter, option1, index);
    }
  }
  else
    QItemDelegate::paint(painter, option, index);

  //---

  if (inside) {
    item->setData(0, Qt::BackgroundRole, b);
    item->setData(1, Qt::BackgroundRole, b);
  }
}

/*! size hint
*/
QSize
CQPropertyDelegate::
sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
  QSize size = QItemDelegate::sizeHint(option, index);

  size.setHeight(size.height() + 2);

  return size;
}

/*! get tree widget item from index
*/
QTreeWidgetItem *
CQPropertyDelegate::
getModelItem(const QModelIndex &index) const
{
  QTreeWidgetItem *item;

  if (! index.parent().isValid())
    item = tree_->topLevelItem(index.row());
  else {
    QTreeWidgetItem *parent = getModelItem(index.parent());
    assert(parent);

    item = parent->child(index.row());
  }

  return item;
}

/*! create edit widget
*/
QWidget *
CQPropertyDelegate::
createEdit(QWidget *parent, const QString &text) const
{
  QLineEdit *edit = new QLineEdit(parent);

  edit->setText(text);

  edit->setMouseTracking(false);
  edit->setFocusPolicy(Qt::NoFocus);
  edit->setAcceptDrops(false);
  edit->setFrame(false);
  edit->setReadOnly(true);

  // set background of preview text to window background
  QPalette plt = QApplication::palette();
  QColor bgColor = plt.color(QPalette::Window);
  QString styleStr;
  styleStr.sprintf("background: #%2x%2x%2x", bgColor.red(), bgColor.green(), bgColor.blue());
  edit->setStyleSheet(styleStr);

  return edit;
}

void
CQPropertyDelegate::
drawCheck(QPainter *painter, const QStyleOptionViewItem &option,
          bool checked, const QModelIndex &index) const
{
  QItemDelegate::drawBackground(painter, option, index);

  Qt::CheckState checkState = (checked ? Qt::Checked : Qt::Unchecked);

  QRect rect = option.rect;

  rect.setWidth(option.rect.height());

  rect.adjust(0, 1, -3, -2);

  QItemDelegate::drawCheck(painter, option, rect, checkState);

  QFontMetrics fm(painter->font());

  int x = rect.right() + 4;
//int y = rect.top() + fm.ascent();

  QRect rect1;

  rect1.setCoords(x, option.rect.top(), option.rect.right(), option.rect.bottom());

  //painter->drawText(x, y, (checked ? "true" : "false"));
  QItemDelegate::drawDisplay(painter, option, rect1, checked ? "true" : "false");
}

void
CQPropertyDelegate::
drawColor(QPainter *painter, const QStyleOptionViewItem &option,
          const QColor &c, const QModelIndex &index) const
{
  QItemDelegate::drawBackground(painter, option, index);

  QRect rect = option.rect;

  rect.setWidth(option.rect.height());

  rect.adjust(0, 1, -3, -2);

  painter->fillRect(rect, QBrush(c));

  painter->setPen(QColor(0,0,0));
  painter->drawRect(rect);

  QFontMetrics fm(painter->font());

  int x = rect.right() + 2;
//int y = rect.top() + fm.ascent();

  QRect rect1;

  rect1.setCoords(x, option.rect.top(), option.rect.right(), option.rect.bottom());

//painter->drawText(x, y, c.name());
  QItemDelegate::drawDisplay(painter, option, rect1, c.name());
}

void
CQPropertyDelegate::
drawFont(QPainter *painter, const QStyleOptionViewItem &option,
         const QFont &f, const QModelIndex &index) const
{
  QItemDelegate::drawBackground(painter, option, index);

  QRect rect = option.rect;

  rect.setWidth(option.rect.height());

  rect.adjust(0, 1, -3, -2);

  QFont f1 = f;
  QFont f2 = painter->font();

  QFontMetrics fm1(f1);
  QFontMetrics fm2(f2);

  int fw = fm1.width("Abc");
  int fh = fm1.height();

  if (fh > rect.height()) {
    f1.setPixelSize(rect.height());

    fm1 = QFontMetrics(f1);

    fw = fm1.width("Abc");
  }

  int x1 = rect.left();
  int y1 = rect.top() + fm1.ascent();

  painter->save();

  painter->setFont(f1);
  painter->setPen(QColor(0,0,0));

  painter->drawText(x1, y1, "Abc");

  painter->restore();

  int x2 = x1 + fw + 4;
//int y2 = rect.top() + fm2.ascent();

  QRect rect1;

  rect1.setCoords(x2, option.rect.top(), option.rect.right(), option.rect.bottom());

//painter->drawText(x2, y2, f.toString());
  QItemDelegate::drawDisplay(painter, option, rect1, f.toString());
}

void
CQPropertyDelegate::
drawPoint(QPainter *painter, const QStyleOptionViewItem &option,
         const QPointF &p, const QModelIndex &index) const
{
  QItemDelegate::drawBackground(painter, option, index);

  QRect rect = option.rect;

  //rect.setWidth(option.rect.height());

  //QFontMetrics fm(painter->font());

  QString str = QString("(%1, %2)").arg(p.x()).arg(p.y());

  QItemDelegate::drawDisplay(painter, option, rect, str);
}

void
CQPropertyDelegate::
drawSize(QPainter *painter, const QStyleOptionViewItem &option,
         const QSizeF &s, const QModelIndex &index) const
{
  QItemDelegate::drawBackground(painter, option, index);

  QRect rect = option.rect;

  //rect.setWidth(option.rect.height());

  //QFontMetrics fm(painter->font());

  QString str = QString("(%1, %2)").arg(s.width()).arg(s.height());

  QItemDelegate::drawDisplay(painter, option, rect, str);
}

void
CQPropertyDelegate::
drawRect(QPainter *painter, const QStyleOptionViewItem &option,
         const QRectF &r, const QModelIndex &index) const
{
  QItemDelegate::drawBackground(painter, option, index);

  QRect rect = option.rect;

  //rect.setWidth(option.rect.height());

  //QFontMetrics fm(painter->font());

  QString str = QString("(%1, %2) (%3 %4)").arg(r.left ()).arg(r.top   ()).
                                            arg(r.right()).arg(r.bottom());

  QItemDelegate::drawDisplay(painter, option, rect, str);
}

void
CQPropertyDelegate::
drawAngle(QPainter *painter, const QStyleOptionViewItem &option,
         const CAngle &a, const QModelIndex &index) const
{
  QItemDelegate::drawBackground(painter, option, index);

  QRect rect = option.rect;

  //rect.setWidth(option.rect.height());

  //QFontMetrics fm(painter->font());

  QString str = QString("%1").arg(a.degrees());

  QItemDelegate::drawDisplay(painter, option, rect, str);
}

void
CQPropertyDelegate::
drawString(QPainter *painter, const QStyleOptionViewItem &option,
           const QString &str, const QModelIndex &index) const
{
  QItemDelegate::drawBackground(painter, option, index);

  QRect rect = option.rect;

  QItemDelegate::drawDisplay(painter, option, rect, str);
}
