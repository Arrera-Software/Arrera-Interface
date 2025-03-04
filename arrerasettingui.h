#ifndef ARRERASETTINGUI_H
#define ARRERASETTINGUI_H

#include <QDialog>
#include "cainterfacesetting.h"
#include <QMessageBox>
#include <QListWidget>
#include <QDir>
#include "carrerarecheche.h"
#include <QFileDialog>
#include <QStandardPaths>

#define DIRICONMODELIEU ":/mode-lieu/img/"

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
    int idMainPage,idModePage,idGenerauxPage,idAssistantPage,idApplicationPage,idLieuPage,idRecherchePage;
    // id de modestaked
    int idMainModePage,idAddMode,idGestMode;
    // id appstacked
    int idMainAppStaked, idAddAppStacked,idSupprAppStacked,idIconChangeApp,idEmplacementAppStacked,idManageAppSpeciaux;
    // id lieustacked
    int idMainLieu,idAddLieu,idManageLieu;
    // varriable qui permet de savoir quelle mode qui est selectionner
    int modeSelected;
    // Variable qui permet de savoir quelle lieu est selectionner
    int lieuSelected;
    // Variable qui permet de savoir quelle app speciaux est selectionner
    int appSpeSelected;
    // Set valeur combo box app
    void setAppComboBox();
    // Methode pour choisir un icon pour les bouton Mode et lieu
    QString chooseIcon();
    // Attribut pour gerer les app
    QString appEmplacement,appIcon;
signals:
    void parametresFerme();
private slots:
    // Partie acceuil
    void on_IDC_MODE_clicked();
    void on_IDC_GENERAUX_clicked();
    void on_IDC_ASSISTANT_clicked();
    void on_IDC_APPLICATION_clicked();
    void on_IDC_LIEU_clicked();
    void on_IDC_RECHERCHE_clicked();

    // Bouton TOP bar
    void on_IDC_ACCEUILPARAMETRE_clicked();

    // Partie mode
    void on_IDC_BTNMODE1_clicked();
    void on_IDC_BTNMODE2_clicked();
    void on_IDC_BTNMODE3_clicked();
    void on_IDC_BTNMODE4_clicked();
    void on_IDC_BTNMODE5_clicked();
    void on_IDC_BTNMODE6_clicked();

    // BTN addmode
    void on_IDC_VALIDERMODE_clicked();
    void on_IDC_RETOURMODE_clicked();
    void on_IDC_ICONMODEADD_clicked();

    // Partie gest mode
    void on_IDC_RESETMODE_clicked();
    void on_IDC_CHANGENAME_clicked();
    void on_IDC_ASSISTANTMAJGESTMODE_clicked();
    void on_IDC_MAJAPPGESTMODE_clicked();
    void on_IDC_RETOURGESTMODE_clicked();
    void on_IDC_CHANGEICONMODEGEST_clicked();

    // Partie Parametre generaux
    void on_IDC_RETOURGENERAUXUSER_clicked();
    void on_IDC_VALIDERNAMEUSER_clicked();

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

    // Partie Lieu
    // Acceuil lieu
    void on_IDC_MANAGELIEU1_clicked();
    void on_IDC_MANAGELIEU1_2_clicked();
    // Create
    void on_IDC_CREALIEU_clicked();
    void on_IDC_CANCELCREATELIEU_clicked();
    // Manage lieu
    void on_IDC_CHANGENAMELIEU_clicked();
    void on_IDC_CHANGEASSISTANTLIEU_clicked();
    void on_IDC_ANNULERMANAGELIEU_clicked();
    void on_IDC_CHANGEGEOMANAGE_clicked();
    void on_IDC_ICONCHOOSELIEU_clicked();
    void on_IDC_CHANGEICONLIEU_clicked();
};

#endif // ARRERASETTINGUI_H
