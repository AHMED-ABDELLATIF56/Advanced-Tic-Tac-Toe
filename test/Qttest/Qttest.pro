QT += widgets
QT += testlib
QT += gui sql
CONFIG += qt warn_on depend_includepath testcase
TEMPLATE = app

SOURCES += \
    tst_testcase.cpp \
    ../aihard.cpp \
    ../dialog.cpp \
    ../hard1.cpp \
    ../login.cpp \
    ../mainwindow.cpp \
    ../twoplayer.cpp

FORMS += \
    ../mainwindow.ui \
    ../aihard.ui \
    ../dialog.ui \
    ../hard1.ui \
    ../login.ui \
    ../twoplayer.ui

HEADERS += \
    tst_testcase.h \
    ../aihard.h \
    ../dialog.h \
    ../hard1.h \
    ../login.h \
    ../mainwindow.h \
    ../twoplayer.h

TARGET = MyQttest
