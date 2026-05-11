// arreraui.h
#ifndef ARRERAUI_H
#define ARRERAUI_H

#include <QWidget>
#include <QDialog>
#include <QApplication>
#include <QDesktopServices>
#include <QUrl>
#include <QShortcut>
#include "config.h"
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
#include "widget/arrera_theme.h"

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

    // BTN Mode
    void on_IDC_MODE1_clicked();

    void on_IDC_MODE2_clicked();

    void on_IDC_MODE3_clicked();

    void on_IDC_MODE5_clicked();

    void on_IDC_MODE4_clicked();

    void on_IDC_MODE6_clicked();

    // BTN lieu

    void on_IDC_LIEU1_clicked();

    void on_IDC_LIEU2_clicked();

    void on_IDC_QUITLIEU_clicked();

    // Partie Mode

    void on_IDC_QUIT_clicked();

    void on_IDC_APPMODE1_clicked();

    void on_IDC_APPMODE2_clicked();

    void on_IDC_APPMODE3_clicked();

    void on_IDC_APPMODE4_clicked();

    void on_IDC_APPLISTMODE_clicked();

    void closeEvent(QCloseEvent *event) override;

    // Bouton pour envoyer des ordes a l'assistant

    void on_IDC_BREEF_clicked();

    void on_IDC_METEO_clicked();

    void on_IDC_TASK_clicked();

    void on_IDC_AGENDA_clicked();

private : // methode
    void loadSetting();
    bool loadMode();
    bool loadLieu();
    void loadArreraApp();
    bool loadApp();
    bool launchAppMode(int nbApp,QString app);
    bool launchAssistantMode(QString assistant = "");
    void launchGestServeur();
    void launchSearch(int mode);
    void searchEnter();
    bool launchMode(int index);

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
    CArreraServeur serveurApp,serveurAssistant;
    CTigerDemon tigerDemon;
    QShortcut shortcutReturn,shortcutEnter;
    assistant assistantCommunication;
    Arrera_Theme theme;

    // Variable
    QIcon iconSearchMode,iconAssistantMode;
    bool modeIsActive,assistantIsActived,searchBarAssistantMode;
    QString assistantMode = nullptr,modelaunched= nullptr;
    QString nameMode,app1Mode,app2Mode,app3Mode,app4Mode,nameAssistantConnected;
    int lieuEnabled,idPageI2025Main,idPageI2025App,idPageI2025Mode,idPageApropos,idPageRecherche;
    int idPageDesktopApp,idPageArreraApp,idPageRechercheMoteur, idPageRechercheHist;
    int idNonMode, idYesMode,idNoLieuSave,idLieuSave;
    int idNoModeSave,idModeSave,idAppView,idNoApp,idNoArreraApp, idViewArreraApp;
    bool desktopApp = false;

};

#endif // ARRERAUI_H
