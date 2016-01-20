#ifndef CQPaletteChooser_H
#define CQPaletteChooser_H

#include <QWidget>
#include <QPalette>

class QLineEdit;
class QPushButton;

class CQPaletteChooser : public QWidget {
  Q_OBJECT

  Q_PROPERTY(QPalette palette    READ palette    WRITE setPalette   )
  Q_PROPERTY(QString  paletteDef READ paletteDef WRITE setPaletteDef)

 public:
  CQPaletteChooser(QWidget *parent=0);

  const QPalette &palette() const;
  void setPalette(const QPalette &palette);

  const QString &paletteDef() const;
  void setPaletteDef(const QString &paletteDef);

 private slots:
  void choosePalette();
  void editPalette();

 signals:
  void paletteChanged(const QPalette &palette);
  void paletteChanged(const QString &paletteDef);

 private:
  QPalette     palette_;
  QString      paletteDef_;
  QLineEdit   *edit_;
  QPushButton *button_;
};

#endif
