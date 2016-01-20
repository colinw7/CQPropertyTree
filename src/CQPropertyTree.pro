TEMPLATE = lib

TARGET = CQPropertyTree

QT += widgets

DEPENDPATH += .

CONFIG += staticlib

QMAKE_CXXFLAGS += -std=c++11

# Input
HEADERS += \
../include/CQPropertyDelegate.h \
../include/CQPropertyEditor.h \
../include/CQPropertyItem.h \
../include/CQPropertyTree.h \
\
../include/CQAngleSpinBox.h \
../include/CQComboSlider.h \
../include/CQIconCombo.h \
../include/CQLineDash.h \
../include/CQPaletteChooser.h \
../include/CQPaletteDialog.h \
../include/CQPixmapCache.h \
../include/CQPoint2DEdit.h \
../include/CQRealSpin.h \
../include/CQSlider.h \

SOURCES += \
CQPropertyDelegate.cpp \
CQPropertyEditor.cpp \
CQPropertyItem.cpp \
CQPropertyTree.cpp \
\
CQAngleSpinBox.cpp \
CQComboSlider.cpp \
CQIconCombo.cpp \
CQLineDash.cpp \
CQPaletteChooser.cpp \
CQPaletteDialog.cpp \
CQPixmapCache.cpp \
CQPoint2DEdit.cpp \
CQRealSpin.cpp \
CQSlider.cpp \

OBJECTS_DIR = ../obj

DESTDIR = ../lib

INCLUDEPATH += \
. \
../include \
../../CQUtil/include \
../../CImageLib/include \
../../CFont/include \
../../CFile/include \
../../CStrUtil/include \
../../CMath/include \
../../CUtil/include \
