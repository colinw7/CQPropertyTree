#ifndef CQComboSlider_H
#define CQComboSlider_H

#include <QWidget>

class QSlider;
class QDoubleSpinBox;
class QSpinBox;

// combined double slider+spinner
class CQComboSlider : public QWidget {
  Q_OBJECT

  Q_PROPERTY(double value READ value WRITE setValue)

 public:
  CQComboSlider(QWidget *parent, double defValue, double minimum, double maximum);

  double value() const { return value_; }
  void setValue(double d);

  double getSpan() const { return maxValue_ - minValue_; }

 private:
  void setSliderValue (double d);
  void setSpinnerValue(double d);

 signals:
  void valueChanged(double);

 protected slots:
  void spinnerChanged(double);

  void sliderChanged(int);

 private:
  double          defValue_;
  double          minValue_;
  double          maxValue_;
  double          value_;
  QSlider*        slider_;
  QDoubleSpinBox* spinner_;
};

//------

// combined int slider+spinner
class CQIntComboSlider : public QWidget {
  Q_OBJECT

  Q_PROPERTY(int value READ value WRITE setValue)

 public:
  CQIntComboSlider(QWidget* parent, int defValue, int minimum, int maximum);

  int value() const { return value_; }
  void setValue(int i);

 private:
  void setSliderValue (int i);
  void setSpinnerValue(int i);

 signals:
  void valueChanged(int);

 protected slots:
  void spinnerChanged(int);

  void sliderChanged(int);

 private:
  int       defValue_;
  int       minValue_;
  int       maxValue_;
  int       value_;
  QSlider*  slider_;
  QSpinBox* spinner_;
};

#endif
