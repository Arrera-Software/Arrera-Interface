// arreraui.h
#ifndef ARRERAUI_H
#define ARRERAUI_H

#include <QWidget>
#include <QDialog>
#include <QApplication>
#include <QDesktopServices>
#include <QUrl>
#include "carreraapp.h"
#include "arrerasettingui.h"
#include "carrerarecheche.h"
#include "capppc.h"
#include "cappspeciaux.h"

namespace Ui {
class ArreraUI;
}

class ArreraUI : public QDialog
{
    Q_OBJECT

public:
    explicit ArreraUI(QWidget *parent = nullptr);
    ~ArreraUI();

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

private:
    Ui::ArreraUI *ui;
    CAInterfaceSetting *objSetting;
    ArreraSettingUI *uipara;
    CArreraRecheche arecherche;
    CDetectionOS dectOS;
    CArreraApp *arreraApp;
    CAppPC appPC1,appPC2,appPC3,appPC4,appPC5,appPC6,appPC7,appPC8;
    CAppPC appPC9,appPC10,appPC11,appPC12,appPC13,appPC14,appPC15,appPC16;
    CAppPC appPC17,appPC18,appPC19,appPC20,appPC21;
    CAppSpeciaux appNavigateur,appPresentation,appTableur,appTraitementTexte;
    // Methode private
    void loadSetting();
    void loadArreraApp();
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
};

#endif // ARRERAUI_H
