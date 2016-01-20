#include <CQPaletteChooser.h>
#include <CQPaletteDialog.h>
#include <CQUtil.h>

#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QColorDialog>

#include <svg/palette_dialog_svg.h>

CQPaletteChooser::
CQPaletteChooser(QWidget *parent) :
 QWidget(parent)
{
  QHBoxLayout *layout = new QHBoxLayout(this);
  layout->setMargin(2); layout->setSpacing(2);

  edit_   = new QLineEdit  (this);
  button_ = new QPushButton(this);

  button_->setIcon(CQPixmapCacheInst->getIcon("PALETTE_DIALOG"));

  //button_->setFixedSize(QSize(24,24));

  layout->addWidget(edit_  );
  layout->addWidget(button_);

  edit_  ->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
  button_->setSizePolicy(QSizePolicy::Fixed    , QSizePolicy::Fixed);

  connect(edit_  , SIGNAL(editingFinished()), this, SLOT(editPalette()));
  connect(button_, SIGNAL(clicked        ()), this, SLOT(choosePalette()));
}

void
CQPaletteChooser::
setPalette(const QPalette &palette)
{
  palette_    = palette;
  paletteDef_ = CQUtil::paletteToString(palette_);

  edit_->setText(paletteDef_);

  emit paletteChanged(palette);
  emit paletteChanged(paletteDef_);
}

void
CQPaletteChooser::
setPaletteDef(const QString &paletteDef)
{
  QString paletteDef1 = paletteDef.simplified();

  if (paletteDef1 == paletteDef_)
    return;

  QPalette palette;

  if (! CQUtil::paletteFromString(palette, paletteDef1))
    return;

  paletteDef_ = paletteDef1;
  palette_    = palette;

  edit_->setText(paletteDef_);

  emit paletteChanged(palette_);
  emit paletteChanged(paletteDef_);
}

const QPalette &
CQPaletteChooser::
palette() const
{
  return palette_;
}

const QString &
CQPaletteChooser::
paletteDef() const
{
  return paletteDef_;
}

void
CQPaletteChooser::
editPalette()
{
  setPaletteDef(edit_->text());
}

void
CQPaletteChooser::
choosePalette()
{
  QPalette palette = palette_;

  CQPaletteDialog *dialog = new CQPaletteDialog(this);

  dialog->setPalette(palette);

  if (dialog->exec(palette))
    setPalette(palette);
}
