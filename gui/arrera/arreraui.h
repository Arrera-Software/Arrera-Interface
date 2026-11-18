// arreraui.h
#ifndef ARRERAUI_H
#define ARRERAUI_H

#include <QDialog>
#include <QShortcut>
#include "manager/update/ctigerdemon.h"
#include "ui_arreraui.h"
#include "librairy/cdetectionos.h"
#include "gui/setting/arrerasettingui.h"
#include "arrera_qt/arrera_theme.h"
#include "manager/search/carrerarecheche.h"
#include "manager/communication/carrerabus.h"
#include "manager/application/CAppManager.h"

#define VERSION "dev"

namespace Ui {
class ArreraUI;
}

class ArreraUI : public QDialog
{
    Q_OBJECT

public:
    explicit ArreraUI(QWidget *parent = nullptr);
    ~ArreraUI();
    CDetectionOS dectOS;
    void show();

private slots:
    void on_IDC_ACCEUILARRERA_clicked();

    // Bar des taches

    void on_IDC_APPBUREAU_clicked();

    void on_IDC_CHANGEVIEWAPP_clicked();

    void on_IDC_TIGER_clicked();

    // Partie Apropos
    void on_IDC_SOURCECODE_clicked();

    void on_IDC_WEBSITE_clicked();

    void on_IDC_CHECK_UPDATE_clicked();

    void on_IDC_PARA_clicked();

    void on_IDC_SHOWHIST_clicked();

    void on_IDC_AUTREMOTEUR_clicked();

    void on_IDC_MODESEARCHBAR_clicked();

    void closeEvent(QCloseEvent *event);

    // Bouton pour envoyer des ordes a l'assistant

    void on_IDC_BREEF_clicked();

    void on_IDC_METEO_clicked();

    void on_IDC_TASK_clicked();

    void on_IDC_AGENDA_clicked();

private : // methode
    void loadSetting();
    void loadArreraApp();
    void launchSearch(int mode);
    void searchEnter();
    void handleSearchResult(bool ok, const QString &label);

private: // Attribut
    // Objet
    Ui::ArreraUI *ui;
    CAInterfaceSetting objSetting;
    ArreraSettingUI uipara;
    CArreraRecheche arecherche;
    CTigerDemon tigerDemon;
    QShortcut shortcutReturn,shortcutEnter;
    CAppManager appManager;
    CArreraBus annBus;
    Arrera_Theme theme;

    // Variable
    bool assistantIsActived,searchBarAssistantMode;
    int idPageI2025Main,idPageI2025App,idPageApropos,idPageRecherche;
    int idPageDesktopApp,idPageArreraApp,idPageRechercheMoteur, idPageRechercheHist;
    int idAppView,idNoApp,idNoArreraApp, idViewArreraApp;
    bool desktopApp = false;

};

#endif // ARRERAUI_H
