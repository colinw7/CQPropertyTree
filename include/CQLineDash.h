#ifndef CQLINE_DASH_H
#define CQLINE_DASH_H

#include <QFrame>
#include <QAction>
#include <CLineDash.h>
#include <map>

class QMenu;
class QLineEdit;
class QToolButton;
class CQIconCombo;
class CQLineDashAction;

class CQLineDash : public QFrame {
  Q_OBJECT

 public:
  CQLineDash(QWidget *parent=0);

  bool editiable() const { return editiable_; }
  void setEditable(bool b);

  void setLineDash(const CLineDash &dash);
  const CLineDash &getLineDash() const { return dash_; }

  void addDashOption(const std::string &id, const CLineDash &dash);

  int pixmapWidth () const { return 96; }
  int pixmapHeight() const { return 20; }

 private slots:
  void dashChangedSlot();
  void menuItemActivated(QAction *);
  void comboItemChanged();

 signals:
  void valueChanged(const CLineDash &dash);

 private:
  typedef std::map<std::string, CQLineDashAction *> Actions;

  bool         editiable_;
  CLineDash    dash_;
  QLineEdit   *edit_;
  QToolButton *button_;
  QMenu       *menu_;
  CQIconCombo *combo_;
  Actions      actions_;
};

class CQLineDashAction : public QAction {
 public:
  CQLineDashAction(CQLineDash *parent, const std::string &id, const CLineDash &dash);

  const QPixmap &pixmap() const { return pixmap_; }

 private:
  void init();

 private:
  CQLineDash  *parent_;
  std::string  id_;
  CLineDash    dash_;
  QPixmap      pixmap_;
};

#endif
