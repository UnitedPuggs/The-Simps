QT     += core sql gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LoginApp
TEMPLATE = app

CONFIG += c++11 console
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        administrator.cpp \
        main.cpp \
        mainwindow.cpp \
        sqldatabase.cpp \
        storemanager.cpp

FORMS += \
    mainwindow.ui

HEADERS += \
    administrator.h \
    header.h \
    mainwindow.h \
    sqldatabase.h \
    storemanager.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
