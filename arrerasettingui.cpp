#include "arrerasettingui.h"
#include "ui_arrerasettingui.h"

// Methode principal public
ArreraSettingUI::ArreraSettingUI(QWidget *parent,CAInterfaceSetting *obp)
    : QDialog(parent)
    , ui(new Ui::ArreraSettingUI)
{
    ui->setupUi(this);
    // Varrible systeme
    modeSelected = 0;
    // Mise en place de CAInterfaceSetting dans son atribut
    objPara = obp;
    // Recuperation List des assistant
    QList listAssistant = objPara->getListAssistant();
    // Recuperation liste moteur
    QList listMoteur = objPara->getListMoteur();
    // Id de mainstaked
    idMainPage = ui->mainstacked->indexOf(ui->main);
    idModePage = ui->mainstacked->indexOf(ui->mode);
    idGenerauxPage = ui->mainstacked->indexOf(ui->generaux);
    idAssistantPage= ui->mainstacked->indexOf(ui->main);
    idApplicationPage = ui->mainstacked->indexOf(ui->application);
    idLieuPage = ui->mainstacked->indexOf(ui->lieu);
    idRecherchePage = ui->mainstacked->indexOf(ui->recherche);
    // id de modestaked
    idMainModePage = ui->modestacked->indexOf(ui->mainmode);
    idAddMode = ui->modestacked->indexOf(ui->addmode);
    idGestMode = ui->modestacked->indexOf(ui->gestMode);
    // id de appstacked
    idMainAppStaked = ui->appstocked->indexOf(ui->mainpcapp);
    idAddAppStacked = ui->appstocked->indexOf(ui->addpcapp);
    idSupprAppStacked = ui->appstocked->indexOf(ui->supprpcapp);
    // id lieustacked
    idMainLieu= ui->lieustacked->indexOf(ui->mainlieu);
    idAddLieu = ui->lieustacked->indexOf(ui->addlieu);
    idManageLieu = ui->lieustacked->indexOf(ui->managelieu);
    // Mise en place des item sur le IDC_LISTASSISTANTMODE
    ui->IDC_LISTASSISTANTMODE->addItems(listAssistant);
    // Mise en place des item sur le IDC_LISTASSISTANTMANAGELIEU
    ui->IDC_LISTASSISTANTMANAGELIEU->addItems(listAssistant);
    // Mise en place des item sur le IDC_ASSISTANTGESTMODE
    ui->IDC_ASSISTANTGESTMODE->addItems(listAssistant);
    // Mise en place des moteur de recherche dans IDC_LISTEMOTEURERECHERCHE
    ui->IDC_LISTEMOTEURERECHERCHE->addItems(listMoteur);
    // Desactivation du bouton assistant
    ui->IDC_ASSISTANT->setVisible(false);
}

ArreraSettingUI::~ArreraSettingUI()
{
    delete ui;
}

void ArreraSettingUI::closeEvent(QCloseEvent *event)
{
    // Émettre le signal lorsque la fenêtre des paramètres est fermée
    emit parametresFerme();
    QWidget::closeEvent(event);
}

void ArreraSettingUI::setAppComboBox(){
    ui->IDC_APP1MODE->addItem("nothing");
    ui->IDC_APP2MODE->addItem("nothing");
    ui->IDC_APP3MODE->addItem("nothing");
    ui->IDC_APP4MODE->addItem("nothing");
    ui->IDC_APP1GESTMODE->addItem("nothing");
    ui->IDC_APP1GESTMODE->addItem("nothing");
    ui->IDC_APP1GESTMODE->addItem("nothing");
    ui->IDC_APP4GESTMODE->addItem("nothing");
}

void ArreraSettingUI::show()
{
    QDialog::show();
    ui->mainstacked->setCurrentIndex(idMainPage);
    ui->modestacked->setCurrentIndex(idMainModePage);
    ui->appstocked->setCurrentIndex(idMainAppStaked);
    ui->lieustacked->setCurrentIndex(idMainLieu);
    ui->LINDICATIONSETTING->setText("Arrera I2025 Parametre");
}

// Partie acceuil

void ArreraSettingUI::on_IDC_MODE_clicked()
{
    ui->mainstacked->setCurrentIndex(idModePage);
    ui->modestacked->setCurrentIndex(idMainModePage);
    ui->appstocked->setCurrentIndex(idMainAppStaked);
    ui->lieustacked->setCurrentIndex(idMainLieu);
    ui->LINDICATIONSETTING->setText("Parametre des modes");
}

void ArreraSettingUI::on_IDC_GENERAUX_clicked()
{
    ui->LINDICATIONSETTING->setText("Parametre generaux");
    ui->mainstacked->setCurrentIndex(idGenerauxPage);
}


void ArreraSettingUI::on_IDC_ASSISTANT_clicked()
{

}


void ArreraSettingUI::on_IDC_APPLICATION_clicked()
{
    ui->mainstacked->setCurrentIndex(idApplicationPage);
    ui->LINDICATIONSETTING->setText("Parametre des applications");
}


void ArreraSettingUI::on_IDC_LIEU_clicked()
{
    ui->mainstacked->setCurrentIndex(idLieuPage);
    ui->LINDICATIONSETTING->setText("Parametre des lieu");

}


void ArreraSettingUI::on_IDC_RECHERCHE_clicked()
{
    ui->mainstacked->setCurrentIndex(idRecherchePage);
    ui->LINDICATIONSETTING->setText("Parametre de recherche");
}

// Top bar
void ArreraSettingUI::on_IDC_ACCEUILPARAMETRE_clicked()
{
    int currentIndex = ui->mainstacked->currentIndex();
    if (currentIndex != idMainPage)
    {
        ui->mainstacked->setCurrentIndex(idMainPage);
        ui->LINDICATIONSETTING->setText("Arrera I2025 Parametre");
    }
}

// Partie mode
void ArreraSettingUI::on_IDC_BTNMODE1_clicked()
{
    if (!objPara->mode1IsSeted())
    {
        ui->LINDICATIONMODE->setText("Parametrage du Mode 1");
        ui->LINDICATIONSETTING->setText("Parametrage mode 1");
        ui->modestacked->setCurrentIndex(idAddMode);
    }
    else {
        ui->LINDICATIONSETTING->setText("Modification du mode 1");
        ui->LINDICATIONGESTMODE->setText("Modification du mode 1");
        ui->modestacked->setCurrentIndex(idGestMode);
    }

    modeSelected = 1;
    setAppComboBox();
}


void ArreraSettingUI::on_IDC_BTNMODE2_clicked()
{
    if (!objPara->mode1IsSeted())
    {
        ui->LINDICATIONMODE->setText("Parametrage du Mode 2");
        ui->LINDICATIONSETTING->setText("Parametrage mode 2");
        ui->modestacked->setCurrentIndex(idAddMode);
    }
    else {
        ui->LINDICATIONSETTING->setText("Modification du mode 2");
        ui->LINDICATIONGESTMODE->setText("Modification du mode 2");
        ui->modestacked->setCurrentIndex(idGestMode);
    }

    modeSelected = 2;
    setAppComboBox();
}


void ArreraSettingUI::on_IDC_BTNMODE3_clicked()
{
    if (!objPara->mode1IsSeted())
    {
        ui->LINDICATIONMODE->setText("Parametrage du Mode 3");
        ui->LINDICATIONSETTING->setText("Parametrage mode 3");
        ui->modestacked->setCurrentIndex(idAddMode);
    }
    else {
        ui->LINDICATIONSETTING->setText("Modification du mode 3");
        ui->LINDICATIONGESTMODE->setText("Modification du mode 3");
        ui->modestacked->setCurrentIndex(idGestMode);
    }

    modeSelected = 3;
    setAppComboBox();
}


void ArreraSettingUI::on_IDC_BTNMODE4_clicked()
{
    if (!objPara->mode1IsSeted())
    {
        ui->LINDICATIONMODE->setText("Parametrage du Mode 4");
        ui->LINDICATIONSETTING->setText("Parametrage mode 4");
        ui->modestacked->setCurrentIndex(idAddMode);
    }
    else {
        ui->LINDICATIONSETTING->setText("Modification du mode 4");
        ui->LINDICATIONGESTMODE->setText("Modification du mode 4");
        ui->modestacked->setCurrentIndex(idGestMode);
    }

    modeSelected = 4;
    setAppComboBox();
}


void ArreraSettingUI::on_IDC_BTNMODE5_clicked()
{
    if (!objPara->mode1IsSeted())
    {
        ui->LINDICATIONMODE->setText("Parametrage du Mode 5");
        ui->LINDICATIONSETTING->setText("Parametrage mode 5");
        ui->modestacked->setCurrentIndex(idAddMode);
    }
    else {
        ui->LINDICATIONSETTING->setText("Modification du mode 5");
        ui->LINDICATIONGESTMODE->setText("Modification du mode 5");
        ui->modestacked->setCurrentIndex(idGestMode);
    }

    modeSelected = 5;
    setAppComboBox();
}


void ArreraSettingUI::on_IDC_BTNMODE6_clicked()
{
    if (!objPara->mode1IsSeted())
    {
        ui->LINDICATIONMODE->setText("Parametrage du Mode 6");
        ui->LINDICATIONSETTING->setText("Parametrage mode 6");
        ui->modestacked->setCurrentIndex(idAddMode);
    }
    else {
        ui->LINDICATIONSETTING->setText("Modification du mode 6");
        ui->LINDICATIONGESTMODE->setText("Modification du mode 6");
        ui->modestacked->setCurrentIndex(idGestMode);
    }

    modeSelected = 6;
    setAppComboBox();
}


void ArreraSettingUI::on_IDC_VALIDERMODE_clicked()
{
    // Recuperation valeur entrer par l'user
    QString name = ui->IDC_LINENAMEMODE->text();
    QString assistant = ui->IDC_LISTASSISTANTMODE->currentText();
    // Recuperation de application
    QString app1 = ui->IDC_APP1MODE->currentText();
    QString app2 = ui->IDC_APP2MODE->currentText();
    QString app3 = ui->IDC_APP3MODE->currentText();
    QString app4 = ui->IDC_APP4MODE->currentText();
    // Clear des combox et QLine
    ui->IDC_APP1MODE->clear();
    ui->IDC_APP2MODE->clear();
    ui->IDC_APP3MODE->clear();
    ui->IDC_APP4MODE->clear();
    ui->IDC_LINENAMEMODE->clear();
    // Teste de valeur récupérer
    if (name.isEmpty()){
        QMessageBox::critical(this,"Erreur de création du mode",
                              "Impossible de créer un mode sans nom");
    }
    else {
        bool sortieApp,sortieName,sortieAssistant;
        // Ecriture dans le mode selectionner
        switch (modeSelected) {
            case 1 :
                sortieName = objPara->setNameMode1(name);
                sortieAssistant = objPara->setAppMode1(app1,app2,app3,app4);
                sortieApp = objPara->setAssistantMode1(assistant);
                break;
            case 2 :
                sortieName = objPara->setNameMode2(name);
                sortieAssistant = objPara->setAppMode2(app1,app2,app3,app4);
                sortieApp = objPara->setAssistantMode2(assistant);
                break;

            case 3 :
                sortieName = objPara->setNameMode3(name);
                sortieAssistant = objPara->setAppMode3(app1,app2,app3,app4);
                sortieApp = objPara->setAssistantMode3(assistant);
                break;

            case 4 :
                sortieName = objPara->setNameMode4(name);
                sortieAssistant = objPara->setAppMode4(app1,app2,app3,app4);
                sortieApp = objPara->setAssistantMode4(assistant);
                break;

            case 5 :
                sortieName = objPara->setNameMode5(name);
                sortieAssistant = objPara->setAppMode5(app1,app2,app3,app4);
                sortieApp = objPara->setAssistantMode5(assistant);
                break;

            case 6 :
                sortieName = objPara->setNameMode6(name);
                sortieAssistant = objPara->setAppMode6(app1,app2,app3,app4);
                sortieApp = objPara->setAssistantMode6(assistant);
                break;

            default :
                sortieName = false ;
                sortieAssistant = false ;
                sortieApp = false ;
                break;
        }
        if (sortieName && sortieApp && sortieAssistant){
            QMessageBox::information(this,"Mode "+QString::number(modeSelected),
                                     "Le mode "+QString::number(modeSelected)+" a bien été paramétré");
        }else{
            QMessageBox::critical(this,"Erreur",
                                  "Une erreur s'est produite");
        }
    }
    ui->modestacked->setCurrentIndex(idMainModePage);
}


void ArreraSettingUI::on_IDC_RETOURMODE_clicked()
{
    ui->LINDICATIONSETTING->setText("Parametre des modes");
    ui->modestacked->setCurrentIndex(idMainModePage);
    modeSelected = 0;
}

// Partie gest mode

void ArreraSettingUI::on_IDC_RESETMODE_clicked()
{

}


void ArreraSettingUI::on_IDC_CHANGENAME_clicked()
{

}


void ArreraSettingUI::on_IDC_ASSISTANTMAJGESTMODE_clicked()
{

}


void ArreraSettingUI::on_IDC_MAJAPPGESTMODE_clicked()
{

}


void ArreraSettingUI::on_IDC_RETOURGESTMODE_clicked()
{

}

// Partie Parametre generaux
void ArreraSettingUI::on_IDC_RETOURGENERAUXUSER_clicked()
{
    ui->mainstacked->setCurrentIndex(idMainPage);
    ui->LINDICATIONSETTING->setText("Arrera I2025 Parametre");
}


void ArreraSettingUI::on_IDC_VALIDERNAMEUSER_clicked()
{
    // Recuperation de la valeur
    QString nameUser = ui->ICD_LINENAMEUSER->text();
    // Effacement de ICD_LINENAMEUSER
    ui->ICD_LINENAMEUSER->clear();
    // Teste si ICD_LINENAMEUSER etais vide
    if (!nameUser.isEmpty())
    {
        objPara->setNameUser(nameUser);
    }
}

// Partie application
//Partie ajout de l'app
void ArreraSettingUI::on_IDC_ICONAPPPC_clicked()
{

}


void ArreraSettingUI::on_IDC_VALIDERAPPPC_clicked()
{

}


void ArreraSettingUI::on_IDC_CANCELAPPPC_clicked()
{
    ui->LINDICATIONSETTING->setText("Parametre des applications");
    ui->appstocked->setCurrentIndex(idMainAppStaked);
}

//Partie suppr de l'app
void ArreraSettingUI::on_IDC_CANCELSUPPRAPP_clicked()
{
    ui->LINDICATIONSETTING->setText("Parametre des applications");
    ui->appstocked->setCurrentIndex(idMainAppStaked);
}


void ArreraSettingUI::on_IDC_VALIDERSUPRR_clicked()
{
    ui->appstocked->setCurrentIndex(idMainAppStaked);
}

//Partie acceuil d'app
void ArreraSettingUI::on_IDC_ADDAPPPC_clicked()
{
    ui->LINDICATIONSETTING->setText("Ajout d'une application");
    ui->appstocked->setCurrentIndex(idAddAppStacked);
}


void ArreraSettingUI::on_IDC_SUPPRAPPPC_clicked()
{
    ui->LINDICATIONSETTING->setText("Supprimer d'une application");
    ui->appstocked->setCurrentIndex(idSupprAppStacked);
}

void ArreraSettingUI::on_IDC_SETAPPPC_clicked()
{

}

// Partie Recherche

void ArreraSettingUI::on_IDC_VALIDERRECHERCHE_clicked()
{

}

// Partie Lieu

// Acceuil lieu
void ArreraSettingUI::on_IDC_MANAGELIEU1_clicked()
{

}


void ArreraSettingUI::on_IDC_MANAGELIEU1_2_clicked()
{

}

// Create

void ArreraSettingUI::on_IDC_CREALIEU_clicked()
{

}


void ArreraSettingUI::on_IDC_CANCELCREATELIEU_clicked()
{
    ui->lieustacked->setCurrentIndex(idMainLieu);
}

// Manage lieu

void ArreraSettingUI::on_IDC_CHANGENAMELIEU_clicked()
{

}


void ArreraSettingUI::on_IDC_CHANGEASSISTANTLIEU_clicked()
{

}


void ArreraSettingUI::on_IDC_ANNULERMANAGELIEU_clicked()
{
    ui->lieustacked->setCurrentIndex(idMainLieu);
}

void ArreraSettingUI::on_IDC_CHANGEGEOMANAGE_clicked()
{

}
