QT       += core gui

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
    carrerarecheche.cpp \
    cdetectionos.cpp \
    cjsonword.cpp \
    csetting.cpp \
    main.cpp \
    arreraui.cpp

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
    carrerarecheche.h \
    cdetectionos.h \
    cjsonword.h \
    csetting.h

FORMS += \
    arrerasettingui.ui \
    arreraui.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc \
    resource.qrc

DISTFILES += \
    img/arrera-postite.png
