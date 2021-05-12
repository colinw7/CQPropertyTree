#ifndef CQPropertyDelegate_H
#define CQPropertyDelegate_H

#include <QItemDelegate>
#include <CAngle.h>

class CQPropertyTree;
class QTreeWidgetItem;

// Tree Widget Item Delegate class to handle custom editing of tree widget items
class CQPropertyDelegate : public QItemDelegate {
  Q_OBJECT

 public:
  CQPropertyDelegate(CQPropertyTree *tree);

  // Override to create editor
  QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                        const QModelIndex &index) const override;

  // Override to get content from editor
  void setEditorData(QWidget *editor, const QModelIndex &index) const override;

  void setModelData(QWidget *editor, QAbstractItemModel *model,
                    const QModelIndex &index) const override;

  void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                            const QModelIndex &index) const override;

  void paint(QPainter *painter, const QStyleOptionViewItem &option,
             const QModelIndex &index) const override;

  QTreeWidgetItem *getModelItem(const QModelIndex &index) const;

  QSize sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index ) const override;

  QWidget *createEdit(QWidget *parent, const QString &text) const;

  void drawChecked(QPainter *painter, const QStyleOptionViewItem &option,
                   bool checked, const QModelIndex &index) const;
  void drawColor(QPainter *painter, const QStyleOptionViewItem &option,
                 const QColor &c, const QModelIndex &index) const;
  void drawFont (QPainter *painter, const QStyleOptionViewItem &option,
                 const QFont &f, const QModelIndex &index) const;
  void drawPoint(QPainter *painter, const QStyleOptionViewItem &option,
                 const QPointF &p, const QModelIndex &index) const;
  void drawSize (QPainter *painter, const QStyleOptionViewItem &option,
                 const QSizeF &s, const QModelIndex &index) const;
  void drawRect (QPainter *painter, const QStyleOptionViewItem &option,
                 const QRectF &r, const QModelIndex &index) const;
  void drawAngle(QPainter *painter, const QStyleOptionViewItem &option,
                 const CAngle &a, const QModelIndex &index) const;
  void drawString(QPainter *painter, const QStyleOptionViewItem &option,
                  const QString &str, const QModelIndex &index) const;

 private:
  CQPropertyTree *tree_;
};

#endif
