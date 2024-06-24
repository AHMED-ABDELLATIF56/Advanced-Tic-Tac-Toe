QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aihard.cpp \
    dialog.cpp \
    hard1.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    twoplayer.cpp

HEADERS += \
    aihard.h \
    dialog.h \
    hard1.h \
    login.h \
    mainwindow.h \
    twoplayer.h

FORMS += \
    aihard.ui \
    dialog.ui \
    hard1.ui \
    login.ui \
    mainwindow.ui \
    twoplayer.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    semi.pro.user
