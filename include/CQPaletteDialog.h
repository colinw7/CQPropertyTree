#ifndef CQPaletteDialog_H
#define CQPaletteDialog_H

#include <QDialog>
#include <QPalette>

class CQColorChooser;

class CQPaletteDialog : public QDialog {
  Q_OBJECT

  Q_PROPERTY(QPalette palette READ palette WRITE setPalette)

 public:
  CQPaletteDialog(QWidget *parent, const char *name=0);

  const QPalette &palette() const { return palette_; }

  void setPalette(const QPalette &palette);

  bool exec(QPalette &palette);

 private slots:
  void bgChanged(const QColor &color);
  void fgChanged(const QColor &color);

 private:
  QPalette        palette_;
  CQColorChooser *fg_;
  CQColorChooser *bg_;
};

#endif
