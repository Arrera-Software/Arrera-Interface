QT += core gui websockets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arrerasettingui.cpp \
    cainterfacesetting.cpp \
    calieu.cpp \
    camode.cpp \
    camodelieu.cpp \
    capplication.cpp \
    capppc.cpp \
    cappspeciaux.cpp \
    carreraapp.cpp \
    carrerarecheche.cpp \
    carreraserveur.cpp \
    ccommunication.cpp \
    cdetectionos.cpp \
    cjsonword.cpp \
    csetting.cpp \
    ctigerdemon.cpp \
    main.cpp \
    arreraui.cpp \
    windowsmaj.cpp

HEADERS += \
    arrerasettingui.h \
    arreraui.h \
    cainterfacesetting.h \
    calieu.h \
    camode.h \
    camodelieu.h \
    capplication.h \
    capppc.h \
    cappspeciaux.h \
    carreraapp.h \
    carrerarecheche.h \
    carreraserveur.h \
    ccommunication.h \
    cdetectionos.h \
    cjsonword.h \
    csetting.h \
    ctigerdemon.h \
    windowsmaj.h

FORMS += \
    arrerasettingui.ui \
    arreraui.ui \
    windowsmaj.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    img/arrera-postite.png
