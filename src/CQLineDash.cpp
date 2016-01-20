#include <CQLineDash.h>
#include <CQIconCombo.h>
#include <CQUtil.h>

#include <QHBoxLayout>
#include <QLineEdit>
#include <QToolButton>
#include <QMenu>
#include <QPainter>
#include <QProxyStyle>

class CQLineDashProxyStyle : public QProxyStyle {
 public:
  int pixelMetric(PixelMetric metric, const QStyleOption *option, const QWidget *widget) const {
    if      (metric == QStyle::PM_MenuHMargin  ) return 0;
    else if (metric == QStyle::PM_MenuVMargin  ) return 0;
    else if (metric == QStyle::PM_SmallIconSize) return 60;

    return QProxyStyle::pixelMetric(metric, option, widget);
  }

  QSize sizeFromContents(ContentsType type, const QStyleOption *option, const QSize &size,
                         const QWidget *widget) const {
    if (type == QStyle::CT_MenuItem)
      return QSize(80 + size.width(), 32);

    return QProxyStyle::sizeFromContents(type, option, size, widget);
  }
};

//------

CQLineDash::
CQLineDash(QWidget *parent) :
 QFrame(parent), editiable_(false)
{
  setObjectName("line_dash");

  setFrameStyle(QFrame::NoFrame | QFrame::Plain);

  //---

  QHBoxLayout *layout = new QHBoxLayout(this);
  layout->setMargin(0); layout->setSpacing(0);

  //---

  edit_ = new QLineEdit;
  edit_->setObjectName("edit");

  edit_->setToolTip("Line Dash\n(List of Dash Lengths)");

  connect(edit_, SIGNAL(editingFinished()), this, SLOT(dashChangedSlot()));

  layout->addWidget(edit_);

  button_ = new QToolButton;
  button_->setObjectName("button");

  menu_ = new QMenu;

  //menu_->setStyle(new CQLineDashProxyStyle);

  button_->setMenu(menu_);

  connect(menu_, SIGNAL(triggered(QAction *)), this, SLOT(menuItemActivated(QAction *)));

  button_->setPopupMode(QToolButton::InstantPopup);
  button_->setAutoRaise(true);
  button_->setFixedSize(QSize(11, 20));

  layout->addWidget(button_);

  //---

  combo_ = new CQIconCombo;

  combo_->setMenuIconSize(QSize(pixmapWidth(), pixmapHeight()));

  layout->addWidget(combo_);

  connect(combo_, SIGNAL(currentIndexChanged(int)), this, SLOT(comboItemChanged()));

  //---

  addDashOption("solid" , CLineDash());
  addDashOption("1, 1"  , CLineDash("1, 1"));
  addDashOption("1, 2"  , CLineDash("1, 2"));
  addDashOption("1, 3"  , CLineDash("1, 3"));
  addDashOption("1, 4"  , CLineDash("1, 4"));
  addDashOption("1, 6"  , CLineDash("1, 6"));
  addDashOption("1, 8"  , CLineDash("1, 8"));
  addDashOption("1, 12" , CLineDash("1, 12"));
  addDashOption("1, 24" , CLineDash("1, 24"));
  addDashOption("1, 48" , CLineDash("1, 48"));
  addDashOption("2, 1"  , CLineDash("2, 1"));
  addDashOption("3, 1"  , CLineDash("3, 1"));
  addDashOption("4, 1"  , CLineDash("4, 1"));
  addDashOption("6, 1"  , CLineDash("6, 1"));
  addDashOption("8, 1"  , CLineDash("8, 1"));
  addDashOption("12, 1" , CLineDash("12, 1"));
  addDashOption("24, 1" , CLineDash("24, 1"));
  addDashOption("2, 2"  , CLineDash("2, 2"));
  addDashOption("3, 3"  , CLineDash("3, 3"));
  addDashOption("4, 4"  , CLineDash("4, 4"));
  addDashOption("6, 6"  , CLineDash("6, 6"));
  addDashOption("8, 8"  , CLineDash("8, 8"));
  addDashOption("12, 12", CLineDash("12, 12"));
  addDashOption("24, 24", CLineDash("24, 24"));
  addDashOption("2, 4"  , CLineDash("2, 4"));
  addDashOption("4, 2"  , CLineDash("4, 2"));
  addDashOption("2, 6"  , CLineDash("2, 6"));
  addDashOption("6, 2"  , CLineDash("6, 2"));
  addDashOption("4, 8"  , CLineDash("4, 8"));
  addDashOption("8, 4"  , CLineDash("8, 4"));

  addDashOption("2,1,0.5,1", CLineDash("2,1,0.5,1"));
  addDashOption("4,2,1,2"  , CLineDash("4,2,1,2"));
  addDashOption("8,2,1,2"  , CLineDash("8,2,1,2"));
  addDashOption("0.5,0.5"  , CLineDash("0.5,0.5"));
  addDashOption("0.25,0.25", CLineDash("0.25,0.25"));
  addDashOption("0.1,0.1"  , CLineDash("0.1,0.1"));

  edit_  ->setVisible(editiable_);
  button_->setVisible(editiable_);
  combo_ ->setVisible(! editiable_);
}

void
CQLineDash::
setEditable(bool edit)
{
  if (edit == editiable_) return;

  editiable_ = edit;

  edit_  ->setVisible(editiable_);
  button_->setVisible(editiable_);
  combo_ ->setVisible(! editiable_);
}

void
CQLineDash::
setLineDash(const CLineDash &dash)
{
  dash_ = dash;

  edit_->setText(dash_.toString().c_str());

  for (int i = 0; i < combo_->count(); ++i) {
    QVariant var = combo_->itemData(i);

    CLineDash dash1 = var.value<CLineDash>();

    if (dash == dash1) {
      combo_->setCurrentIndex(i);
      break;
    }
  }
}

void
CQLineDash::
dashChangedSlot()
{
  CLineDash dash;

  QString str = edit_->text();

  if (dash.fromString(str.toStdString())) {
    dash_ = dash;

    emit valueChanged(dash_);
  }
}

void
CQLineDash::
menuItemActivated(QAction *action)
{
  edit_->setText(action->text());

  dashChangedSlot();
}

void
CQLineDash::
comboItemChanged()
{
  int ind = combo_->currentIndex();

  QVariant var = combo_->itemData(ind);

  dash_ = var.value<CLineDash>();

  emit valueChanged(dash_);
}

void
CQLineDash::
addDashOption(const std::string &id, const CLineDash &dash)
{
  auto p = actions_.find(id);
  if (p != actions_.end()) return;

  CQLineDashAction *action = new CQLineDashAction(this, id, dash);

  actions_[id] = action;

  menu_->addAction(action);

  combo_->addItem(QIcon(action->pixmap()), action->text(), QVariant::fromValue(dash));
}

//---

CQLineDashAction::
CQLineDashAction(CQLineDash *parent, const std::string &id, const CLineDash &dash) :
 QAction(parent), parent_(parent), id_(id), dash_(dash)
{
  init();
}

void
CQLineDashAction::
init()
{
  QRect rect(0, 0, parent_->pixmapWidth(), parent_->pixmapHeight());

  pixmap_ = QPixmap(rect.width(), rect.height());

  pixmap_.fill(QColor(0,0,0,0));

  QPainter painter(&pixmap_);

  painter.setRenderHints(QPainter::Antialiasing);

  QPen pen(QColor(0,0,0));

  pen.setWidthF(1.5);

  CQUtil::penSetLineDash(pen, dash_);

  int y = rect.height()/2;

  painter.setPen(pen);

  painter.drawLine(2, y, rect.width() - 2, y);

  setIcon(QIcon(pixmap_));
  setText(id_.c_str());

  setIconVisibleInMenu(true);

  //pixmap_.save("temp.png");
}
