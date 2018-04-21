#include <CQPropertyTree.h>
#include <CQPropertyItem.h>
#include <CQPropertyDelegate.h>

#include <QHeaderView>
#include <QMenu>
#include <QMouseEvent>
#include <iostream>

CQPropertyTree::
CQPropertyTree(QWidget *parent) :
 QTreeWidget(parent)
{
  setObjectName("propertyTree");

  //--

  setColumnCount(2);

  setHeaderLabels(QStringList() << "Name" << "Value");

  //--

  header()->setStretchLastSection(true);

  header()->setSectionResizeMode(QHeaderView::ResizeToContents);

  //--

  setUniformRowHeights(true);

  setAlternatingRowColors(true);

  setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed);

  //--

  CQPropertyDelegate *delegate = new CQPropertyDelegate(this);

  setItemDelegate(delegate);

  //--

  connect(this, SIGNAL(itemClicked(QTreeWidgetItem *, int)),
          this, SLOT(itemClickedSlot(QTreeWidgetItem *, int)));

  connect(this, SIGNAL(itemSelectionChanged()),
          this, SLOT(itemSelectionSlot()));

  //--

  setContextMenuPolicy(Qt::CustomContextMenu);

  connect(this, SIGNAL(customContextMenuRequested(const QPoint&)),
          this, SLOT(customContextMenuSlot(const QPoint&)));
}

void
CQPropertyTree::
setMouseHighlight(bool b)
{
  mouseHighlight_ = b;

  setMouseTracking(mouseHighlight_);
}

void
CQPropertyTree::
clear()
{
  QTreeWidget::clear();
}

CQPropertyItem *
CQPropertyTree::
addProperty(const QString &path, QObject *object, const QString &name, const QString &alias)
{
  QStringList pathParts = path.split('/', QString::SkipEmptyParts);

  QTreeWidgetItem *parent = 0;

  for (int i = 0; i < pathParts.size(); ++i) {
    if (i == 0) {
      QList<QTreeWidgetItem *> items = findItems(pathParts[i], Qt::MatchExactly, 0);

      if (items.empty()) {
        QTreeWidgetItem *item = new QTreeWidgetItem(QStringList() << pathParts[i] << "");

        items.push_back(item);

        addTopLevelItem(item);
      }

      parent = items[0];
    }
    else {
      int j  = 0;
      int nc = parent->childCount();

      for ( ; j < nc; ++j) {
        QTreeWidgetItem *child = parent->child(j);

        if (child->text(0) == pathParts[i]) {
          parent = child;
          break;
        }
      }

      if (j >= nc) {
        QTreeWidgetItem *child = new QTreeWidgetItem(parent, QStringList() << pathParts[i] << "");

        parent = child;
      }
    }
  }

  CQPropertyItem *item = new CQPropertyItem(parent, name, "", "", object);

  connect(item, SIGNAL(valueChanged(QObject *, const QString &)),
          this, SIGNAL(valueChanged(QObject *, const QString &)));

  if (! parent)
    addTopLevelItem(item);

  if (alias != "")
    item->setLabel(alias);

  return item;
}

void
CQPropertyTree::
selectObject(const QObject *obj)
{
  for (int i = 0; i < topLevelItemCount(); ++i) {
    QTreeWidgetItem *item = topLevelItem(i);

    if (selectObject(item, obj))
      return;
  }
}

bool
CQPropertyTree::
selectObject(QTreeWidgetItem *item, const QObject *obj)
{
  if (CQPropertyItem::isType(item->type())) {
    CQPropertyItem *item1 = static_cast<CQPropertyItem *>(item);

    QObject *obj1 = item1->getObject();

    if (obj1 == obj) {
      item->setSelected(true);
      return true;
    }
  }

  for (int i = 0; i < item->childCount(); ++i) {
    QTreeWidgetItem *item1 = item->child(i);

    if (selectObject(item1, obj))
      return true;
  }

  return false;
}

void
CQPropertyTree::
expandSelected()
{
  QList<QTreeWidgetItem *> items = this->selectedItems();

  for (int i = 0; i < items.length(); ++i) {
    QTreeWidgetItem *item = items[i];

    expandItemTree(item);
  }

  resizeColumnToContents(0);
  resizeColumnToContents(1);

  for (int i = 0; i < items.length(); ++i) {
    QTreeWidgetItem *item = items[i];

    scrollToItem(item);
  }
}

void
CQPropertyTree::
getSelectedObjects(std::vector<QObject *> &objs)
{
  QList<QTreeWidgetItem *> items = this->selectedItems();

  for (int i = 0; i < items.length(); ++i) {
    QTreeWidgetItem *item = items[i];

    QObject *obj;
    QString  path;

    getItemData(item, obj, path);

    objs.push_back(obj);
  }
}

void
CQPropertyTree::
search(const QString &text)
{
  Items items;

  int n = topLevelItemCount();

  for (int i = 0; i < n; ++i) {
    QTreeWidgetItem *item = topLevelItem(i);

    searchItemTree(item, text, items);
  }

  for (uint i = 0; i < items.size(); ++i) {
    QTreeWidgetItem *item = items[i];

    expandItemTree(item);
  }

  resizeColumnToContents(0);
  resizeColumnToContents(1);

  for (uint i = 0; i < items.size(); ++i) {
    QTreeWidgetItem *item = items[i];

    scrollToItem(item);
  }
}

void
CQPropertyTree::
searchItemTree(QTreeWidgetItem *item, const QString &text, Items &items)
{
  QString itemText = item->text(0);

  if (itemText.indexOf(text) >= 0) {
    item->setSelected(true);

    items.push_back(item);
  }
  else
    item->setSelected(false);

  int n = item->childCount();

  for (int i = 0; i < n; ++i) {
    QTreeWidgetItem *item1 = item->child(i);

    searchItemTree(item1, text, items);
  }
}

void
CQPropertyTree::
expandItemTree(QTreeWidgetItem *item)
{
  while (item) {
    expandItem(item);

    item = item->parent();
  }
}

void
CQPropertyTree::
itemClickedSlot(QTreeWidgetItem *item, int column)
{
  CQPropertyItem *item1 = 0;

  if (CQPropertyItem::isType(item->type()))
    item1 = static_cast<CQPropertyItem *>(item);

  if (item1 && column == 1) {
    if (item1->click()) {
      QModelIndex ind = indexFromItem(item1, column);

      update(ind);
    }
  }

  //---

  QObject *obj;
  QString  path;

  getItemData(item, obj, path);

  emit itemClicked(obj, path);
}

void
CQPropertyTree::
itemSelectionSlot()
{
  QList<QTreeWidgetItem *> items = selectedItems();
  if (items.empty()) return;

  QObject *obj;
  QString  path;

  getItemData(items[0], obj, path);

  emit itemSelected(obj, path);
}

void
CQPropertyTree::
getItemData(QTreeWidgetItem *item, QObject* &obj, QString &path)
{
  QTreeWidgetItem *item1 = item;

  while (item1) {
    if (path.length())
      path = item1->data(0, Qt::DisplayRole).toString() + "/" + path;
    else
      path = item1->data(0, Qt::DisplayRole).toString();

    item1 = item1->parent();
  }

  item1 = item;

  int n = item1->childCount();

  while (n > 0) {
    item1 = item1->child(0);

    n = item1->childCount();
  }

  obj = 0;

  if (CQPropertyItem::isType(item1->type())) {
    CQPropertyItem *item2 = static_cast<CQPropertyItem *>(item1);

    obj = item2->getObject();
  }
}

void
CQPropertyTree::
customContextMenuSlot(const QPoint &pos)
{
  QTreeWidgetItem *item = itemAt(pos);
  if (! item) return;

  QObject *obj;
  QString  path;

  getItemData(item, obj, path);

  if (! obj)
    return;

  // Map point to global from the viewport to account for the header.
  showContextMenu(obj, viewport()->mapToGlobal(pos));
}

void
CQPropertyTree::
showContextMenu(QObject *obj, const QPoint &globalPos)
{
  emit menuExec(obj, globalPos);
}

void
CQPropertyTree::
mouseMoveEvent(QMouseEvent *me)
{
  if (! isMouseHighlight()) return;

  QTreeWidgetItem *item = itemAt(me->pos());

  if (item) {
    QModelIndex ind = indexFromItem(item, 0);

    setMouseInd(ind);
  }
  else
    unsetMouseInd();

  update();
}

void
CQPropertyTree::
leaveEvent(QEvent *)
{
  if (! isMouseHighlight()) return;

  unsetMouseInd();

  update();
}

bool
CQPropertyTree::
isMouseInd(const QModelIndex &i)
{
  if (! isMouseHighlight())
    return false;

  if (! hasMouseInd_)
    return false;

  if (mouseInd_.parent() != i.parent())
    return false;

  return (mouseInd_.row() == i.row());
}
