#include <CQComboSlider.h>

#include <QSlider>
#include <QHBoxLayout>
#include <QDoubleSpinBox>

CQComboSlider::
CQComboSlider(QWidget *parent, double defValue, double minimum, double maximum) :
 QWidget(parent), defValue_(defValue), minValue_(minimum), maxValue_(maximum)
{
  setLayout(new QHBoxLayout());
  layout()->setContentsMargins(0,0,0,0);

  double val = (defValue_ - minValue_)/(maxValue_ - minValue_);

  slider_ = new QSlider(Qt::Horizontal,this);
  slider_->setRange(0, 100000);
  slider_->setValue(val*100000);

  spinner_ = new QDoubleSpinBox(this);
  spinner_->setDecimals(5);
  spinner_->setMaximum(maxValue_);
  spinner_->setMinimum(minValue_);
  spinner_->setValue(defValue_);

  value_ = defValue_;

  layout()->addWidget(slider_);
  layout()->addWidget(spinner_);

  connect(spinner_, SIGNAL(valueChanged(double)), this, SLOT(spinnerChanged(double)));
  connect(slider_ , SIGNAL(valueChanged(int))   , this, SLOT(sliderChanged(int)));
}

void
CQComboSlider::
setValue(double d)
{
  slider_ ->blockSignals(true);
  spinner_->blockSignals(true);

  double val = (d - minValue_)/(maxValue_ - minValue_);

  spinner_->setValue(value_ = d);
  slider_ ->setValue(val*100000);

  slider_ ->blockSignals(false);
  spinner_->blockSignals(false);

  emit valueChanged(value_);
}

void
CQComboSlider::
setSliderValue(double d)
{
  value_ = d;

  slider_->blockSignals(true);

  double val = (spinner_->value() - minValue_)/(maxValue_ - minValue_);

  slider_->setValue(val*100000);

  slider_->blockSignals(false);

  emit valueChanged(value_);
}

void
CQComboSlider::
setSpinnerValue(double d)
{
  spinner_->blockSignals(true);

  spinner_->setValue(value_ = d);

  spinner_->blockSignals(false);

  emit valueChanged(value_);
}

void
CQComboSlider::
spinnerChanged(double)
{
  setSliderValue(spinner_->value());

  value_ = spinner_->value();

  emit valueChanged(value_);
}

void
CQComboSlider::
sliderChanged(int)
{
  double val = (slider_->value()/100000.0)*(maxValue_ - minValue_) + minValue_;

  setSpinnerValue(val);

  value_ = spinner_->value();

  emit valueChanged(value_);
}

//------

CQIntComboSlider::
CQIntComboSlider(QWidget* parent, int defValue, int minimum, int maximum) :
 QWidget(parent), defValue_(defValue), minValue_(minimum), maxValue_(maximum)
{
  setLayout(new QHBoxLayout());
  layout()->setContentsMargins(0,0,0,0);

  slider_ = new QSlider(Qt::Horizontal,this);
  slider_->setRange(minValue_, maxValue_);
  slider_->setValue(defValue_);

  spinner_ = new QSpinBox(this);
  spinner_->setMaximum(maxValue_);
  spinner_->setMinimum(minValue_);
  spinner_->setValue(defValue_);

  value_ = defValue_;

  layout()->addWidget(slider_);
  layout()->addWidget(spinner_);

  connect(spinner_, SIGNAL(valueChanged(int)), this, SLOT(spinnerChanged(int)));
  connect(slider_ , SIGNAL(valueChanged(int)), this, SLOT(sliderChanged(int)));
}

void
CQIntComboSlider::
setValue(int i)
{
  value_ = i;

  spinner_->blockSignals(true);
  slider_ ->blockSignals(true);

  spinner_->setValue(i);
  slider_ ->setValue(i);

  spinner_->blockSignals(false);
  slider_ ->blockSignals(false);

  emit valueChanged(value_);
}

void
CQIntComboSlider::
setSliderValue(int i)
{
  slider_->blockSignals(true);

  slider_->setValue(value_ = i);

  slider_->blockSignals(false);

  emit valueChanged(value_);
}

void
CQIntComboSlider::
setSpinnerValue(int i)
{
  spinner_->blockSignals(true);

  spinner_->setValue(value_ = i);

  spinner_->blockSignals(false);

  emit valueChanged(value_);
}

void
CQIntComboSlider::
spinnerChanged(int)
{
  setSliderValue(spinner_->value());

  value_ = spinner_->value();

  emit valueChanged(value_);
}

void
CQIntComboSlider::
sliderChanged(int)
{
  setSpinnerValue(slider_->value());

  value_ = spinner_->value();

  emit valueChanged(value_);
}
