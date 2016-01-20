#ifndef CQSlider_H
#define CQSlider_H

#include <QSlider>

class CQSlider : public QSlider {
  Q_OBJECT

  Q_PROPERTY(QString valueLabel READ valueLabel WRITE setValueLabel)

 public:
  CQSlider(QWidget *parent=0);

  const QString &valueLabel() const { return valueLabel_; }
  void setValueLabel(const QString &label);

  QSize sizeHint() const;

 private:
  void paintEvent(QPaintEvent *);

  int valueToPos(int v) const;

  int valueWidthToPos(int v, int width) const;

  void drawTick(QPainter *p, int val, int y, int s);

 private:
  QString     valueLabel_;
  QFont       valFont_, tickFont_;
  mutable int sliderHeight_;
  mutable int dx_, dy_;
};

//---

class CQRealSlider : public QSlider {
  Q_OBJECT

  Q_PROPERTY(QString valueLabel READ valueLabel WRITE setValueLabel)

 public:
  CQRealSlider(QWidget *parent=0);

  const QString &valueLabel() const { return valueLabel_; }
  void setValueLabel(const QString &label);

  QSize sizeHint() const;

 private:
  void paintEvent(QPaintEvent *);

  int valueToPos(int v) const;

  int valueWidthToPos(int v, int width) const;

  void drawTick(QPainter *p, int val, int y, int s);

 signals:
  void valueChanged(double);

 private slots:
  void valueChangedSlot(int);

 private:
  QString     valueLabel_;
  QFont       valFont_, tickFont_;
  mutable int sliderHeight_;
  mutable int dx_, dy_;
};

#endif
