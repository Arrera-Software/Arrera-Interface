#ifndef ARRERASETTINGUI_H
#define ARRERASETTINGUI_H

#include <QDialog>
#include "manager/setting/cainterfacesetting.h"
#include <QMessageBox>
#include <QDir>
#include "manager/search/carrerarecheche.h"
#include <QFileDialog>
#include <QStandardPaths>

namespace Ui {
class ArreraSettingUI;
}

class ArreraSettingUI : public QDialog
{
    Q_OBJECT

public:
    explicit ArreraSettingUI(QWidget *parent = nullptr,CAInterfaceSetting *obp = nullptr,CArreraRecheche *ar = nullptr,CDetectionOS *pos = nullptr);
    ~ArreraSettingUI();
    void show();

private:
    Ui::ArreraSettingUI *ui;
    void closeEvent(QCloseEvent *event);
    // Atribut de l'objet CAInterfaceSetting
    CAInterfaceSetting *objPara;
    // Atribut de l'objet pour savoir l'os
    CDetectionOS *dectOS;
    // Atribut de l'objet CArreraRecherche
    CArreraRecheche *objRecherche;
    // Id de mainstaked
    int idMainPage,idGenerauxPage,idAssistantPage,idApplicationPage,idRecherchePage;
    // id appstacked
    int idMainAppStaked, idAddAppStacked,idSupprAppStacked,idIconChangeApp,idEmplacementAppStacked,idManageAppSpeciaux;
    // Id stakedGeneraux
    int idMainGeneraux,idNameUser,idResetInterface,idTaskbarSetting;
    // Variable qui permet de savoir quelle app speciaux est selectionner
    int appSpeSelected;
    // Set valeur combo box app
    void setAppComboBox();
    // Attribut pour gerer les app
    QString appEmplacement,appIcon;
signals:
    void parametresFerme();
private slots:
    // Partie acceuil
    void on_IDC_GENERAUX_clicked();
    void on_IDC_ASSISTANT_clicked();
    void on_IDC_APPLICATION_clicked();
    void on_IDC_RECHERCHE_clicked();

    // Bouton TOP bar
    void on_IDC_ACCEUILPARAMETRE_clicked();

    // Partie Parametre generaux
    void on_IDC_RETOURGENERAUXUSER_clicked();
    void on_IDC_VALIDERNAMEUSER_clicked();
    // Parametre generaux
    // Acceuil Parametre generaux
    void on_IDC_NAMEUSERPARAGENERAUX_clicked();
    void on_IDC_GENERAUXTASKBAR_clicked();
    void on_IDC_RESETARRERAGENERAUX_clicked();
    // Partie Reset
    void on_IDC_RESETAPPPC_clicked();
    void on_IDC_RETOURRESETINTERFACE_clicked();
    void on_IDC_RESETALLINTERFACE_clicked();
    // Partie bar des taches
    void on_IDC_ACTIVEARRERAAPP_clicked();
    void on_IDC_ACTIVESIX_clicked();
    void on_IDC_ACTIVERYLEY_clicked();
    void on_IDC_ACTIVECOPILOTE_clicked();
    void on_IDC_ACTIVEPOSTITE_clicked();
    void on_IDC_RETOURTASJBAR_clicked();

    // Partie application
    //Partie ajout de l'app
    void on_IDC_SETAPPPC_clicked();
    void on_IDC_ICONAPPPC_clicked();
    void on_IDC_VALIDERAPPPC_clicked();
    void on_IDC_CANCELAPPPC_clicked();

    //Partie suppr de l'app
    void on_IDC_CANCELSUPPRAPP_clicked();
    void on_IDC_VALIDERSUPRR_clicked();

    //Partie acceuil d'app
    void on_IDC_ADDAPPPC_clicked();
    void on_IDC_SUPPRAPPPC_clicked();
    void on_IDC_CHANGEICON_clicked();
    void on_IDC_MODIFEMPLACMENTAPPPC_clicked();
    void on_IDC_EDITTABLEUR_clicked();
    void on_IDC_EDITTRAITEMENTTEXTE_clicked();
    void on_IDC_EDITNAVIGATEUR_clicked();
    void on_IDC_EDITPRESENTATION_clicked();

    //Partie icon d'App
    void on_IDC_CANCELCHANGEICON_clicked();
    void on_IDC_CHANGEICONE_clicked();

    // Partie changement emplacement app
    void on_IDC_VALIDERCHANGEEMPLACEMENTAPP_clicked();
    void on_IDC_CANCELEMPLACEMENTAPP_clicked();

    // Partie appspeciaux
    void on_IDC_CANCELAPPSPEMANAGE_clicked();
    void on_IDC_CHOOSEAPPSPE_clicked();
    void on_IDC_RESETAPPSPEC_clicked();

    // Partie Recherche
    void on_IDC_VALIDERRECHERCHE_clicked();
    void on_IDC_SUPPRHIST_clicked();

    void on_BTN_CHANGE_GUI_SIX_clicked();
};

#endif // ARRERASETTINGUI_H
