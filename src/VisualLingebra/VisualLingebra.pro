#-------------------------------------------------
#
# Project created by QtCreator 2016-11-21T01:47:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VisualLingebra
TEMPLATE = app

SOURCES += main.cpp

HEADERS  +=

CONFIG(release, debug|release) {
  DESTDIR=$$top_srcdir/bin
}
CONFIG(debug, debug|release) {
  DESTDIR=$$top_srcdir/debug
}
 #Target file directory
OBJECTS_DIR=$$top_srcdir/build/VisualLingebra #Intermediate object files directory
MOC_DIR=$$top_srcdir/build/VisualLingebra #Intermediate moc files directory

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../vlutils/release/ -lvlutils
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../vlutils/debug/ -lvlutils
else:unix: LIBS += -L$$top_srcdir/lib -lvlutils#-L$$OUT_PWD/../vlutils/ -lvlutils

INCLUDEPATH += $$PWD/../vlutils
DEPENDPATH += $$PWD/../vlutils
