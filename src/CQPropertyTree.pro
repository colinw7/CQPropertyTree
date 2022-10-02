TEMPLATE = lib

TARGET = CQPropertyTree

QT += widgets

DEPENDPATH += .

CONFIG += staticlib

QMAKE_CXXFLAGS += -std=c++17

MOC_DIR = .moc

SOURCES += \
CQPropertyDelegate.cpp \
CQPropertyEditor.cpp \
CQPropertyItem.cpp \
CQPropertyTree.cpp \
\
CQPaletteChooser.cpp \
CQPaletteDialog.cpp \

HEADERS += \
../include/CQPropertyDelegate.h \
../include/CQPropertyEditor.h \
../include/CQPropertyItem.h \
../include/CQPropertyTree.h \
\
../include/CQPaletteChooser.h \
../include/CQPaletteDialog.h \

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
../../COS/include \
../../CUtil/include \
