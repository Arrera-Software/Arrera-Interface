#include "CAppManager.h"

CAppManager::CAppManager(CAInterfaceSetting *setting, CDetectionOS *os, QObject *parent)
    : QObject(parent)
    , objSetting(setting)
    , dectOS(os)
{
}

void CAppManager::setupDesktopApps(const QVector<QPushButton*> &pcButtons,
                                   QPushButton *btnNav,
                                   QPushButton *btnPres,
                                   QPushButton *btnTab,
                                   QPushButton *btnTxt)
{
    appPC.clear();
    for (int i = 0; i < pcButtons.size(); ++i) {
        appPC.append(CAppPC(i + 1, objSetting, pcButtons[i], dectOS));
        connect(pcButtons[i], &QPushButton::clicked, this, [this, i]() {
            appPC[i].executeApplication();
        });
    }

    appNavigateur = CAppSpeciaux(1, objSetting, btnNav, dectOS);
    appPresentation = CAppSpeciaux(2, objSetting, btnPres, dectOS);
    appTableur = CAppSpeciaux(3, objSetting, btnTab, dectOS);
    appTraitementTexte = CAppSpeciaux(4, objSetting, btnTxt, dectOS);

    connect(btnNav,  &QPushButton::clicked, this, [this]() { appNavigateur.executeApplication(); });
    connect(btnPres, &QPushButton::clicked, this, [this]() { appPresentation.executeApplication(); });
    connect(btnTab,  &QPushButton::clicked, this, [this]() { appTableur.executeApplication(); });
    connect(btnTxt,  &QPushButton::clicked, this, [this]() { appTraitementTexte.executeApplication(); });
}

bool CAppManager::loadDesktopApps()
{
    bool anyAppSetted = false;
    try {
        for (int i = 0; i < appPC.size(); ++i) {
            appPC[i].loadData();
            if (appPC[i].getAppSetted()) {
                anyAppSetted = true;
            }
        }

        appNavigateur.loadData();
        appPresentation.loadData();
        appTableur.loadData();
        appTraitementTexte.loadData();

        emit desktopAppsLoaded(anyAppSetted);
        return true;
    } catch (const std::exception &e) {
        qWarning() << "Exception in loadDesktopApps() :" << e.what();
        return false;
    } catch (...) {
        qWarning() << "Unknown exception in loadDesktopApps()";
        return false;
    }
}

void CAppManager::loadArreraApps(QPushButton *btnMarkdown)
{
    if (!btnMarkdown) {
        return;
    }
    btnMarkdown->setVisible(false);

    if (objSetting->getTaskbarPostite()) {
        arreraApp.load_arrera_application("markdown", btnMarkdown);
    }
}

void CAppManager::reloadHubConfig()
{
    arreraApp.load_hub_config_file();
}

bool CAppManager::openArreraHub()
{
    return arreraApp.open_arrera_hub();
}

QList<CAppPC> *CAppManager::getAppPCList()
{
    return &appPC;
}