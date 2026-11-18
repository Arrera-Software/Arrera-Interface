#ifndef CAPPMANAGER_H
#define CAPPMANAGER_H

#include <QObject>
#include <QPushButton>
#include <QVector>
#include "manager/application/capppc.h"
#include "manager/application/cappspeciaux.h"
#include "manager/application/carreraapp.h"
#include "manager/setting/cainterfacesetting.h"
#include "librairy/cdetectionos.h"

struct ArreraAppButtons {
    QPushButton *homeSix = nullptr;
    QPushButton *homeRyley = nullptr;
    QPushButton *homeCopilot = nullptr;
    QPushButton *homeMarkdown = nullptr;

    QPushButton *pageSix = nullptr;
    QPushButton *pageRyley = nullptr;
    QPushButton *pageCopilot = nullptr;
    QPushButton *pageMarkdown = nullptr;
    QPushButton *pagePostIt = nullptr;
};

class CAppManager : public QObject
{
    Q_OBJECT
private:
    CAInterfaceSetting *objSetting;
    CDetectionOS *dectOS;
    CArreraApp arreraApp;
    QList<CAppPC> appPC;
    CAppSpeciaux appNavigateur, appPresentation, appTableur, appTraitementTexte;

    QString resolveSixAppName();

public:
    explicit CAppManager(CAInterfaceSetting *setting, CDetectionOS *os, QObject *parent = nullptr);

    void setupDesktopApps(const QVector<QPushButton*> &pcButtons,
                          QPushButton *btnNav,
                          QPushButton *btnPres,
                          QPushButton *btnTab,
                          QPushButton *btnTxt);

    bool loadDesktopApps();
    void loadArreraApps(bool assistantIsActive, const ArreraAppButtons &btns);
    void reloadHubConfig();
    bool openArreraHub();

    QList<CAppPC> *getAppPCList();

    signals:
        void desktopAppsLoaded(bool hasAnyPcApp);
};

#endif // CAPPMANAGER_H