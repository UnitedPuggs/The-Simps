QT     += core sql gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LoginApp
TEMPLATE = app

CONFIG += c++11
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        Admin.cpp \
        Manager.cpp \
        SalesReport.cpp \
        main.cpp \
        mainwindow.cpp \
        sqldatabase.cpp

FORMS += \
    Admin.ui \
    Manager.ui \
    SalesReport.ui \
    mainWindow.ui

HEADERS += \
    Admin.h \
    Manager.h \
    SalesReport.h \
    header.h \
    mainwindow.h \
    sqldatabase.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    data.qrc
