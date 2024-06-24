QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    carrerainterface.cpp \
    carrerainterfacesetting.cpp \
    carrerarecheche.cpp \
    carrerarecherchehist.cpp \
    main.cpp

HEADERS += \
    carrerainterface.h \
    carrerainterfacesetting.h \
    carrerarecheche.h \
    carrerarecherchehist.h

FORMS += \
    carrerainterface.ui \
    carrerainterfacesetting.ui


CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ArreraTheme.qrc

DISTFILES += \
    ArreraCopiloteIcon.png \
    ArreraDoc.png \
    ArreraI2025.png \
    ArreraInfo.png \
    ArreraInterfaceLogo.png \
    ArreraInterfaceParametre.png \
    ArreraRecherche.png \
    Ryley.png \
    annuler.png \
    app-drawer-Arrera.png \
    app-drawer.png \
    fondTask.png \
    icon Assistant.png \
    iconNavigateur.png \
    iconPresentation.png \
    iconTableur.png \
    iconTraitementTexte.png \
    quitter.png \
    showMTP.png \
    six.png \
    valider.png \
    validerMTP.png
