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

QString CAppManager::resolveSixAppName()
{
    const bool sixNormal = arreraApp.check_arrera_application("six");
    const bool sixChat = arreraApp.check_arrera_application("six_chat");

    if (sixNormal && !sixChat) return QStringLiteral("six");
    if (!sixNormal && sixChat) return QStringLiteral("six_chat");
    return (objSetting->get_gui_six() == QLatin1String("chat"))
               ? QStringLiteral("six_chat")
               : QStringLiteral("six");
}

void CAppManager::loadArreraApps(bool assistantIsActive, const ArreraAppButtons &btns)
{
    const QList<QPushButton*> allBtns = {
        btns.homeSix, btns.homeRyley, btns.homeCopilot, btns.homeMarkdown,
        btns.pageSix, btns.pageRyley, btns.pageCopilot, btns.pageMarkdown, btns.pagePostIt
    };
    for (QPushButton *btn : allBtns) {
        if (btn) btn->setVisible(false);
    }

    if (objSetting->getTaskbarPostite() && btns.homeMarkdown) {
        arreraApp.load_arrera_application("markdown", btns.homeMarkdown);
    }

    const QString sixApp = resolveSixAppName();

    if (!assistantIsActive) {
        if (objSetting->getTaskbarBTNRyley() && btns.homeRyley)
            arreraApp.load_arrera_application("ryley", btns.homeRyley);
        if (objSetting->getTaskbarBTNSix() && btns.homeSix)
            arreraApp.load_arrera_application(sixApp, btns.homeSix);
        if (objSetting->getTaskbarCopilote() && btns.homeCopilot)
            arreraApp.load_arrera_application("copilot", btns.homeCopilot);
    }

    if (btns.pageCopilot)  arreraApp.load_arrera_application("copilot", btns.pageCopilot);
    if (btns.pageRyley)    arreraApp.load_arrera_application("ryley", btns.pageRyley);
    if (btns.pageMarkdown) arreraApp.load_arrera_application("markdown", btns.pageMarkdown);
    if (btns.pagePostIt)   arreraApp.load_arrera_application("post-it", btns.pagePostIt);
    if (btns.pageSix)      arreraApp.load_arrera_application(sixApp, btns.pageSix);
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