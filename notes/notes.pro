QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    authentication.cpp \
    dialogfornote.cpp \
    dialogfortodolist.cpp \
    filemanagerfornote.cpp \
    filemanagerforregistration.cpp \
    main.cpp \
    mainwindow.cpp \
    manager.cpp \
    privatemanager.cpp \
    registration.cpp

HEADERS += \
    authentication.h \
    dialogfornote.h \
    dialogfortodolist.h \
    filemanagerfornote.h \
    filemanagerforregistration.h \
    mainwindow.h \
    manager.h \
    privatemanager.h \
    registration.h

FORMS += \
    authentication.ui \
    dialogfornote.ui \
    dialogfortodolist.ui \
    mainwindow.ui \
    registration.ui

LIBS += -lssl -lcrypto

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
