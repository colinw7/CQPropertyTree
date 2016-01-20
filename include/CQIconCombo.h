#ifndef CQIconCombo_H
#define CQIconCombo_H

#include <QComboBox>

class CQIconComboModel;

class CQIconCombo : public QComboBox {
  Q_OBJECT

 public:
  CQIconCombo(QWidget *parent=0);

  void setMenuIconSize(const QSize &s);
  const QSize &menuIconSize() const { return iconSize_; }

  void addItem(const QIcon &icon, const QString &str, const QVariant &var=QVariant());
  QVariant itemData(int ind) const;

  QSize sizeHint() const;
  QSize minimumSizeHint() const;

  void paintEvent(QPaintEvent *e);

 private slots:
  void updateTip();

 protected:
  void showPopup();

  QSize calcSize(bool includeText) const;

 private:
  CQIconComboModel *model_;
  QSize             iconSize_;
};

#endif
