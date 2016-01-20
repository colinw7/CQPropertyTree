#include <CQPaletteDialog.h>
#include <CQColorChooser.h>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>

CQPaletteDialog::
CQPaletteDialog(QWidget *parent, const char *name) :
 QDialog(parent)
{
  if (name)
    setObjectName(name);

  QVBoxLayout *layout = new QVBoxLayout(this);

  layout->setMargin (2);
  layout->setSpacing(2);

  QHBoxLayout *hlayout1 = new QHBoxLayout;
  QHBoxLayout *hlayout2 = new QHBoxLayout;

  QLabel *bglabel = new QLabel("Bg");
  QLabel *fglabel = new QLabel("Fg");

  bg_ = new CQColorChooser(this);
  fg_ = new CQColorChooser(this);

  hlayout1->addWidget(bglabel);
  hlayout1->addWidget(fg_);

  hlayout2->addWidget(fglabel);
  hlayout2->addWidget(bg_);

  layout->addLayout(hlayout1);
  layout->addLayout(hlayout2);

  QHBoxLayout *hlayout3 = new QHBoxLayout;

  QPushButton *ok     = new QPushButton("Ok");
  QPushButton *cancel = new QPushButton("Cancel");

  connect(ok    , SIGNAL(clicked()), this, SLOT(accept()));
  connect(cancel, SIGNAL(clicked()), this, SLOT(reject()));

  hlayout3->addStretch();
  hlayout3->addWidget(ok);
  hlayout3->addWidget(cancel);

  layout->addLayout(hlayout3);

  connect(bg_, SIGNAL(colorChanged(const QColor &)),
          this, SLOT(bgChanged(const QColor &)));
  connect(fg_, SIGNAL(colorChanged(const QColor &)),
          this, SLOT(fgChanged(const QColor &)));
}

void
CQPaletteDialog::
setPalette(const QPalette &palette)
{
  palette_ = palette;

  bg_->setColor(palette_.color(QPalette::Window));
  fg_->setColor(palette_.color(QPalette::WindowText));
}

void
CQPaletteDialog::
bgChanged(const QColor &color)
{
  palette_.setColor(QPalette::Window, color);
  palette_.setColor(QPalette::Button, color);
}

void
CQPaletteDialog::
fgChanged(const QColor &color)
{
  palette_.setColor(QPalette::WindowText, color);
  palette_.setColor(QPalette::ButtonText, color);
}

bool
CQPaletteDialog::
exec(QPalette &palette)
{
  if (! QDialog::exec())
    return false;

  palette = palette_;

  return true;
}
