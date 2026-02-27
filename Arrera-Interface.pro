QT += core gui websockets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    fnc/carrerarecheche.cpp \
    widget/roundedframe.cpp \
    gui/arrera/arreraui.cpp \
    gui/setting/arrerasettingui.cpp \
    librairy/cdetectionos.cpp \
    librairy/cjsonword.cpp \
    librairy/csetting.cpp \
    main.cpp \
    manager/application/capplication.cpp \
    manager/application/capppc.cpp \
    manager/application/cappspeciaux.cpp \
    manager/application/carreraapp.cpp \
    manager/communication/assistant.cpp \
    manager/mode_lieu/calieu.cpp \
    manager/mode_lieu/camode.cpp \
    manager/mode_lieu/camodelieu.cpp \
    manager/setting/cainterfacesetting.cpp \
    manager/update/ctigerdemon.cpp \
    manager/update/windowsmaj.cpp \
    socket/carreraserveur.cpp

HEADERS += \
    config.h \
    fnc/carrerarecheche.h \
    widget/roundedframe.h \
    gui/arrera/arreraui.h \
    gui/setting/arrerasettingui.h \
    librairy/cdetectionos.h \
    librairy/cjsonword.h \
    librairy/csetting.h \
    manager/application/capplication.h \
    manager/application/capppc.h \
    manager/application/cappspeciaux.h \
    manager/application/carreraapp.h \
    manager/communication/assistant.h \
    manager/mode_lieu/calieu.h \
    manager/mode_lieu/camode.h \
    manager/mode_lieu/camodelieu.h \
    manager/setting/cainterfacesetting.h \
    manager/update/ctigerdemon.h \
    manager/update/version.h \
    manager/update/windowsmaj.h \
    socket/carreraserveur.h

FORMS += \
    gui/arrera/arreraui.ui \
    gui/setting/arrerasettingui.ui \
    manager/update/windowsmaj.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    gui/arrera/resource.qrc \
    resource.qrc

DISTFILES += \
    img/arrera-postite.png

macx{
    ICON = img/arrera-interface.icns
}

win32 {
    RC_ICONS = img/icon-linux-win.ico
}

TARGET = Arera_Interface
