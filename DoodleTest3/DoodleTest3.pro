QT       += core gui

LIBS     += -lX11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controller.cpp \
    defaultstep.cpp \
    defaultstep_Qt.cpp \
    doodleview.cpp \
    drawingitem.cpp \
    gamefield.cpp \
    gameunit.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp \
    player_Qt.cpp \
    pressedkeys.cpp

HEADERS += \
    Factory.h \
    GameUnitFactory.h \
    ItemFactory.h \
    SingletonHolder.h \
    controller.h \
    defaultstep.h \
    defaultstep_Qt.h \
    doodleview.h \
    drawingitem.h \
    gamefield.h \
    gameunit.h \
    mainwindow.h \
    player.h \
    player_Qt.h \
    preferences.h \
    pressedkeys.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES +=
