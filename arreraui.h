// arreraui.h
#ifndef ARRERAUI_H
#define ARRERAUI_H

#include <QWidget>
#include <QDialog>
#include <QApplication>
#include <QDesktopServices>
#include <QUrl>
#include <QShortcut>
#include "windowsmaj.h"
#include "ctigerdemon.h"
#include "ccommunication.h"
#include "ui_arreraui.h"
/*
#include "iostream"
using namespace std;
*/


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

    void on_IDC_ARRERAAPP_clicked();

    void on_IDC_TIGER_clicked();

    void on_IDC_RYLEY_clicked();

    void on_IDC_COPILOTE_clicked();

    void on_IDC_SIX_clicked();

    void on_IDC_ARRERAPOSTITE_clicked();

    // Partie Apropos
    void on_IDC_SOURCECODE_clicked();

    void on_IDC_WEBSITE_clicked();

    void on_IDC_PARA_clicked();

    void on_IDC_SHOWHIST_clicked();

    void on_IDC_AUTREMOTEUR_clicked();

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

    void on_IDC_BTNSEACH_clicked();

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

    // Arrera APP

    void on_IDC_APOSTITE_clicked();

    void on_IDC_AVIDEODOWNLOAD_clicked();

    void on_IDC_ARACCOURCI_clicked();

    void on_IDC_ASIX_clicked();

    void on_IDC_ARYLEY_clicked();

    void on_IDC_ACOPILOTE_clicked();

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

    void on_IDC_QUIT_clicked();

    void on_IDC_APPMODE1_clicked();

    void on_IDC_APPMODE2_clicked();

    void on_IDC_APPMODE3_clicked();

    void on_IDC_APPMODE4_clicked();

    void on_IDC_APPLISTMODE_clicked();

    void on_IDC_ARRERAAPPMODE_clicked();

    void closeEvent(QCloseEvent *event) override;

private:
    Ui::ArreraUI *ui;
    CAInterfaceSetting objSetting;
    WindowsMaj winMaj;
    ArreraSettingUI uipara;
    CArreraRecheche arecherche;
    CArreraApp arreraApp;
    QList <CAppPC> appPC;
    CAppSpeciaux appNavigateur,appPresentation,appTableur,appTraitementTexte;
    QString assistantMode = nullptr;
    CArreraServeur serveurApp;
    CArreraServeur serveurAssistant;
    CCommunication comunictation;
    CTigerDemon tigerDemon;
    QShortcut shortcutReturn,shortcutEnter;
    bool modeIsActive,assistantIsActived;
    int lieuEnabled;
    QString nameMode,app1Mode,app2Mode,app3Mode,app4Mode;
    // Methode private
    void loadSetting();
    void loadArreraApp();
    bool launchAppMode(int nbApp,QString app);
    bool launchAssistantMode(QString assistant = "");
    void launchGestServeur();
    // Methode de recherche
    void launchSearch(int mode);
    // Id du staked widget I2025
    int idPageI2025Main,idPageI2025App,idPageI2025Mode,idPageI2025ArreraApp,idPageApropos,idPageRecherche;
    // Ide du staked widget arreraRecherche
    int idPageRechercheMoteur, idPageRechercheHist;
    // id du acceuilStacked
    int idNonMode, idYesMode;
    // id de appstacked
    int idAppView,idNoApp;
    // id arreraAppStacked
    int idNoArreraApp, idViewArreraApp;
    // _______________
    // Methode private
    void searchEnter();
};

#endif // ARRERAUI_H
