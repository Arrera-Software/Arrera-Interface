// arreraui.h
#ifndef ARRERAUI_H
#define ARRERAUI_H

#include <QWidget>
#include <QDialog>
#include <QApplication>
#include <QDesktopServices>
#include <QUrl>
#include <QShortcut>
#include "manager/update/windowsmaj.h"
#include "manager/update/ctigerdemon.h"
#include "ui_arreraui.h"
#include "librairy/cdetectionos.h"
#include "socket/carreraserveur.h"
#include "manager/application/carreraapp.h"
#include "gui/setting/arrerasettingui.h"
#include "manager/application/capppc.h"
#include "manager/application/cappspeciaux.h"
#include "manager/communication/assistant.h"
#include "arrera_qt/arrera_theme.h"

#define VERSION "dev"


/*

*/
#include "iostream"
using namespace std;

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

    void on_IDC_MOTEURDUCK_clicked();

    void on_IDC_MOTEURGOOGLE_clicked();

    void on_IDC_MOTEURBING_clicked();

    void on_IDC_MOTEURBRAVE_clicked();

    void on_IDC_MOTEURECOSIA_clicked();

    void on_IDC_MOTEURQWANT_clicked();

    void on_IDC_MOTEURBIGSEARCH_clicked();

    void on_IDC_MOTEURWIKIPEDIA_clicked();

    void on_IDC_MOTEURAMAZON_clicked();

    void on_IDC_MOTEURWORDREFERENCE_clicked();

    void on_IDC_MOTEURYT_clicked();

    void on_IDC_MOTEURREVERSO_clicked();

    void closeEvent(QCloseEvent *event);

    void on_IDC_APP_001_clicked();

    void on_IDC_APP_002_clicked();

    void on_IDC_APP_003_clicked();

    void on_IDC_APP_004_clicked();

    void on_IDC_APP_005_clicked();

    void on_IDC_APP_006_clicked();

    void on_IDC_APP_007_clicked();

    void on_IDC_APP_008_clicked();

    void on_IDC_APP_009_clicked();

    void on_IDC_APP_010_clicked();

    void on_IDC_APP_011_clicked();

    void on_IDC_APP_012_clicked();

    void on_IDC_APP_013_clicked();

    void on_IDC_APP_014_clicked();

    void on_IDC_APP_015_clicked();

    void on_IDC_APP_016_clicked();

    void on_IDC_APP_017_clicked();

    void on_IDC_APP_018_clicked();

    void on_IDC_APP_019_clicked();

    void on_IDC_APP_020_clicked();

    void on_IDC_NAVIGATEUR_clicked();

    void on_IDC_PRESENTATION_clicked();

    void on_IDC_TABLEUR_clicked();

    void on_IDC_TRAITEMENTTEXTE_clicked();

    // Bouton pour envoyer des ordes a l'assistant

    void on_IDC_BREEF_clicked();

    void on_IDC_METEO_clicked();

    void on_IDC_TASK_clicked();

    void on_IDC_AGENDA_clicked();

private : // methode
    void loadSetting();
    void loadArreraApp();
    bool loadApp();
    void launchGestServeur();
    void launchSearch(int mode);
    void searchEnter();

private: // Attribut
    // Objet
    Ui::ArreraUI *ui;
    CAInterfaceSetting objSetting;
    WindowsMaj winMaj;
    ArreraSettingUI uipara;
    CArreraRecheche arecherche;
    CArreraApp arrera_application;
    QList <CAppPC> appPC;
    CAppSpeciaux appNavigateur,appPresentation,appTableur,appTraitementTexte;
    CArreraServeur connection_arrera_hub,serveurAssistant;
    CTigerDemon tigerDemon;
    QShortcut shortcutReturn,shortcutEnter;
    assistant assistantCommunication;
    Arrera_Theme theme;

    // Variable
    QIcon iconSearchMode,iconAssistantMode;
    bool assistantIsActived,searchBarAssistantMode;
    QString nameAssistantConnected;
    int idPageI2025Main,idPageI2025App,idPageApropos,idPageRecherche;
    int idPageDesktopApp,idPageArreraApp,idPageRechercheMoteur, idPageRechercheHist;
    int idAppView,idNoApp,idNoArreraApp, idViewArreraApp;
    bool desktopApp = false;

};

#endif // ARRERAUI_H
