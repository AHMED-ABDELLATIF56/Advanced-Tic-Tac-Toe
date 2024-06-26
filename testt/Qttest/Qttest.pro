QT += widgets
QT += testlib
QT += gui sql
TEMPLATE = app

SOURCES += \
    tst_test.cpp \
     ../aihard.cpp \
     ../database.cpp \
     ../dialog.cpp \
     ../gamehistory.cpp \
     ../gamehistorydialog.cpp \
      ../hard1.cpp \
      ../login.cpp \
    ../mainwindow.cpp \
     ../medium.cpp \
    ../twoplayer.cpp

FORMS += \
    ../mainwindow.ui \
    ../aihard.ui \
    ../dialog.ui \
    ../gamehistorydialog.ui \
    ../hard1.ui \
    ../login.ui \
    ../mainwindow.ui \
     ../medium.ui \
    ../twoplayer.ui

HEADERS += \
    tst_test.h \
    ../aihard.h \
    ../database.h \
    ../dialog.h \
    ../gamehistorydialog.h \
    ../hard1.h \
    ../login.h \
    ../mainwindow.h \
    ../medium.h \
    ../twoplayer.h

TARGET = MyQttest
