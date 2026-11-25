#include "arrerasettingui.h"
#include "ui_arrerasettingui.h"

// Methode principal public
ArreraSettingUI::ArreraSettingUI(QWidget *parent,CAInterfaceSetting *obp,CArreraRecheche *ar,CDetectionOS *pos)
    : QDialog(parent)
    , ui(new Ui::ArreraSettingUI)
{
    ui->setupUi(this);
    // Varrible systeme
    appSpeSelected = 0;// 1.Navigateur 2.Presentation 3.tableur 4.Traitement de texte
    // Mise en place de CAInterfaceSetting dans son atribut
    objPara = obp;
    // Mise en place de l'objet dectetion os
    dectOS = pos;
    // Mise en place de l'objet Arrera Recherche
    objRecherche = ar;
    // Recuperation liste moteur
    QList listMoteur = objPara->getListMoteur();
    // Id de mainstaked
    idMainPage = ui->mainstacked->indexOf(ui->main);
    idGenerauxPage = ui->mainstacked->indexOf(ui->generaux);
    idAssistantPage= ui->mainstacked->indexOf(ui->assistant);
    idApplicationPage = ui->mainstacked->indexOf(ui->application);
    idRecherchePage = ui->mainstacked->indexOf(ui->recherche);
    // id de appstacked
    idMainAppStaked = ui->appstacked->indexOf(ui->mainpcapp);
    idAddAppStacked = ui->appstacked->indexOf(ui->addpcapp);
    idSupprAppStacked = ui->appstacked->indexOf(ui->supprpcapp);
    idIconChangeApp = ui->appstacked->indexOf(ui->iconchangedapp);
    idEmplacementAppStacked = ui->appstacked->indexOf(ui->changeemplacement);
    idManageAppSpeciaux = ui->appstacked->indexOf(ui->manageappspe);
    // Id stakedGeneraux
    idMainGeneraux = ui->stakedGeneraux->indexOf(ui->mainGeneraux);
    idNameUser = ui->stakedGeneraux->indexOf(ui->nameUser);
    idResetInterface = ui->stakedGeneraux->indexOf(ui->resetInterface);
    idTaskbarSetting = ui->stakedGeneraux->indexOf(ui->taskbarSetting);
    // Mise en place des moteur de recherche dans IDC_LISTEMOTEURERECHERCHE
    ui->IDC_LISTEMOTEURERECHERCHE->addItems(listMoteur);
    // Desactivation du bouton assistant
    //ui->IDC_ASSISTANT->setVisible(false);
    QStringList list_gui_six = objPara->get_list_gui_six();
    ui->LIST_SIX_GUI->addItems(list_gui_six);
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

    QList <QString> listApp = objPara->getListNameAppSetted();
    ui->LISTAPPCHANGEICON->clear();
    ui->LISTOPTIONAPPSUPPR->clear();
    ui->LISTAPPCHANGEEMPLACEMENT->clear();

    if (listApp.isEmpty()){
        ui->LISTAPPCHANGEICON->addItem("nothing");
        ui->LISTOPTIONAPPSUPPR->addItem("nothing");
        ui->LISTAPPCHANGEEMPLACEMENT->addItem("nothing");
    }else{
        ui->LISTAPPCHANGEICON->addItems(listApp);
        ui->LISTOPTIONAPPSUPPR->addItems(listApp);
        ui->LISTAPPCHANGEEMPLACEMENT->addItems(listApp);
    }
}

void ArreraSettingUI::show()
{
    QDialog::show();
    ui->mainstacked->setCurrentIndex(idMainPage);
    ui->appstacked->setCurrentIndex(idMainAppStaked);
    ui->LINDICATIONSETTING->setText("Arrera I2026 Parametre");
}

// Partie acceuil

void ArreraSettingUI::on_IDC_GENERAUX_clicked()
{
    ui->LINDICATIONSETTING->setText("Parametre generaux");
    ui->mainstacked->setCurrentIndex(idGenerauxPage);
    ui->stakedGeneraux->setCurrentIndex(idMainGeneraux);
}


void ArreraSettingUI::on_IDC_ASSISTANT_clicked()
{
    ui->mainstacked->setCurrentWidget(ui->assistant);
}


void ArreraSettingUI::on_IDC_APPLICATION_clicked()
{
    ui->mainstacked->setCurrentIndex(idApplicationPage);
    ui->LINDICATIONSETTING->setText("Parametre des applications");
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
        ui->LINDICATIONSETTING->setText("Arrera I2026 Parametre");
    }
    else{
        this->close();
    }
}

// Partie Parametre generaux
void ArreraSettingUI::on_IDC_RETOURGENERAUXUSER_clicked()
{
    ui->LINDICATIONSETTING->setText("Parametre generaux");
    ui->mainstacked->setCurrentIndex(idGenerauxPage);
    ui->stakedGeneraux->setCurrentIndex(idMainGeneraux);
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
    ui->LINDICATIONSETTING->setText("Parametre generaux");
    ui->stakedGeneraux->setCurrentIndex(idMainGeneraux);
}

// Acceuil Parametre generaux

void ArreraSettingUI::on_IDC_NAMEUSERPARAGENERAUX_clicked()
{
    ui->LINDICATIONSETTING->setText("Modification de l'utilisateur");
    ui->stakedGeneraux->setCurrentIndex(idNameUser);
}


void ArreraSettingUI::on_IDC_GENERAUXTASKBAR_clicked()
{
    ui->LINDICATIONSETTING->setText("Gestion de la barre des tâches");
    ui->stakedGeneraux->setCurrentIndex(idTaskbarSetting);

    if (objPara->getTaskbarBTNSix()){
        ui->IDC_ACTIVESIX->setText("Désactiver le bouton d'Arrera SIX.");
        ui->IDC_ACTIVESIX->setStyleSheet("background-color: red; color: white;");
    }else{
        ui->IDC_ACTIVESIX->setText("Activer le bouton d'Arrera SIX.");
        ui->IDC_ACTIVESIX->setStyleSheet("background-color: green; color: white;");
    }

    if (objPara->getTaskbarBTNArreraApp()){
        ui->IDC_ACTIVEARRERAAPP->setText("Désactiver le bouton des Application Arrera.");
        ui->IDC_ACTIVEARRERAAPP->setStyleSheet("background-color: red; color: white;");
    }else{
        ui->IDC_ACTIVEARRERAAPP->setText("Activer le bouton des Application Arrera.");
        ui->IDC_ACTIVEARRERAAPP->setStyleSheet("background-color: green; color: white;");
    }

    if (objPara->getTaskbarBTNRyley()){
        ui->IDC_ACTIVERYLEY->setText("Désactiver le bouton d'Arrera RYLEY.");
        ui->IDC_ACTIVERYLEY->setStyleSheet("background-color: red; color: white;");
    }else{
        ui->IDC_ACTIVERYLEY->setText("Activer le bouton d'Arrera RYLEY.");
        ui->IDC_ACTIVERYLEY->setStyleSheet("background-color: green; color: white;");
    }

    if (objPara->getTaskbarCopilote()){
        ui->IDC_ACTIVECOPILOTE->setText("Désactiver le bouton d'Arrera COPILOTE.");
        ui->IDC_ACTIVECOPILOTE->setStyleSheet("background-color: red; color: white;");
    }else{
        ui->IDC_ACTIVECOPILOTE->setText("Activer le bouton d'Arrera COPILOTE.");
        ui->IDC_ACTIVECOPILOTE->setStyleSheet("background-color: green; color: white;");
    }

    if (objPara->getTaskbarPostite()){
        ui->IDC_ACTIVEPOSTITE->setText("Désactiver le bouton d'Arrera Markdown.");
        ui->IDC_ACTIVEPOSTITE->setStyleSheet("background-color: red; color: white;");
    }else{
        ui->IDC_ACTIVEPOSTITE->setText("Activer le bouton d'Arrera Markdown.");
        ui->IDC_ACTIVEPOSTITE->setStyleSheet("background-color: green; color: white;");
    }


}


void ArreraSettingUI::on_IDC_RESETARRERAGENERAUX_clicked()
{
    ui->LINDICATIONSETTING->setText("Remise à zéro d'Arrera");
    ui->stakedGeneraux->setCurrentIndex(idResetInterface);
}

// Partie Reset

void ArreraSettingUI::on_IDC_RESETAPPPC_clicked()
{
    if (objPara->resetAppPC()){
         QMessageBox::information(this,"Application enregistrée",
                                 "Les applications enregistrées dans l'interface ont été remises à zéro.");
    }else{
        QMessageBox::critical(this,"Application enregistrée",
                              "Impossible de remettre à zéro les applications enregistrées.");
    }
    ui->LINDICATIONSETTING->setText("Parametre generaux");
    ui->stakedGeneraux->setCurrentIndex(idMainGeneraux);
}


void ArreraSettingUI::on_IDC_RETOURRESETINTERFACE_clicked()
{
    ui->LINDICATIONSETTING->setText("Parametre generaux");
    ui->mainstacked->setCurrentIndex(idGenerauxPage);
    ui->stakedGeneraux->setCurrentIndex(idMainGeneraux);
}


void ArreraSettingUI::on_IDC_RESETALLINTERFACE_clicked()
{
    objPara->resetAll();
    QMessageBox::information(this,"Remise a Zero d'Arrera",
                             "Les applications enregistrées dans l'interface ont été remises à zéro.");
    ui->LINDICATIONSETTING->setText("Parametre generaux");
    ui->stakedGeneraux->setCurrentIndex(idMainGeneraux);
}

// Partie bar des taches
void ArreraSettingUI::on_IDC_ACTIVEARRERAAPP_clicked()
{
    bool sortie;
    if (objPara->getTaskbarBTNArreraApp()){
        sortie = objPara->unsetTaskbarBTNArreraApp();
        if (sortie){
            ui->IDC_ACTIVEARRERAAPP->setText("Activer le bouton des Application Arrera.");
            ui->IDC_ACTIVEARRERAAPP->setStyleSheet("background-color: green; color: white;");
            QMessageBox::information(this,
                                     "Paramètre de barre des tâches",
                                     "Le bouton des applications Arrera ne sera plus affiché.");
        }else{
            QMessageBox::critical(this,
                                  "Paramètre de barre des tâches",
                                  "Une erreur s'est produite.");
        }
    }else{
        sortie = objPara->setTaskbarBTNArreraApp();
        if (sortie){
            ui->IDC_ACTIVEARRERAAPP->setText("Désactiver le bouton des Application Arrera.");
            ui->IDC_ACTIVEARRERAAPP->setStyleSheet("background-color: red; color: white;");
            QMessageBox::information(this,
                                     "Paramètre de barre des tâches",
                                     "Le bouton des applications Arrera est affiché.");
        }else{
            QMessageBox::critical(this,
                                  "Paramètre de barre des tâches",
                                  "Une erreur s'est produite.");
        }
    }
    ui->LINDICATIONSETTING->setText("Parametre generaux");
    ui->stakedGeneraux->setCurrentIndex(idMainGeneraux);
}


void ArreraSettingUI::on_IDC_ACTIVESIX_clicked()
{
    bool sortie;
    if (objPara->getTaskbarBTNSix()){
        sortie = objPara->unsetTaskbarBTNSix();
        if (sortie){
            ui->IDC_ACTIVESIX->setText("Activer le bouton d'Arrera SIX.");
            ui->IDC_ACTIVESIX->setStyleSheet("background-color: green; color: white;");
            QMessageBox::information(this,
                                     "Paramètre de barre des tâches",
                                     "Le bouton d'Arrera SIX ne sera plus affiché.");
        }else{
            QMessageBox::critical(this,
                                  "Paramètre de barre des tâches",
                                  "Une erreur s'est produite.");
        }
    }else{
        sortie = objPara->setTaskbarBTNSix();
        if (sortie){
            ui->IDC_ACTIVESIX->setText("Désactiver le bouton d'Arrera SIX.");
            ui->IDC_ACTIVESIX->setStyleSheet("background-color: red; color: white;");
            QMessageBox::information(this,
                                     "Paramètre de barre des tâches",
                                     "Le bouton d'Arrera SIX est affiché.");
        }else{
            QMessageBox::critical(this,
                                  "Paramètre de barre des tâches",
                                  "Une erreur s'est produite.");
        }
    }
    ui->LINDICATIONSETTING->setText("Parametre generaux");
    ui->stakedGeneraux->setCurrentIndex(idMainGeneraux);
}


void ArreraSettingUI::on_IDC_ACTIVERYLEY_clicked()
{
    bool sortie;
    if (objPara->getTaskbarBTNRyley()){
        sortie = objPara->unsetTaskbarBTNRyley();
        if (sortie){
            ui->IDC_ACTIVERYLEY->setText("Activer le bouton d'Arrera RYLEY.");
            ui->IDC_ACTIVERYLEY->setStyleSheet("background-color: green; color: white;");
            QMessageBox::information(this,
                                     "Paramètre de barre des tâches",
                                     "Le bouton d'Arrera RYLEY ne sera plus affiché.");
        }else{
            QMessageBox::critical(this,
                                  "Paramètre de barre des tâches",
                                  "Une erreur s'est produite.");
        }
    }else{
        sortie = objPara->setTaskbarBTNRyley();
        if (sortie){
            ui->IDC_ACTIVERYLEY->setText("Désactiver le bouton d'Arrera RYLEY.");
            ui->IDC_ACTIVERYLEY->setStyleSheet("background-color: red; color: white;");
            QMessageBox::information(this,
                                     "Paramètre de barre des tâches",
                                     "Le bouton d'Arrera RYLEY est affiché.");
        }else{
            QMessageBox::critical(this,
                                  "Paramètre de barre des tâches",
                                  "Une erreur s'est produite.");
        }
    }
    ui->LINDICATIONSETTING->setText("Parametre generaux");
    ui->stakedGeneraux->setCurrentIndex(idMainGeneraux);
}


void ArreraSettingUI::on_IDC_ACTIVECOPILOTE_clicked()
{
    bool sortie;
    if (objPara->getTaskbarCopilote()){
        sortie = objPara->unsetTaskbarBTNCopilote();
        if (sortie){
            ui->IDC_ACTIVECOPILOTE->setText("AActiver le bouton d'Arrera COPILOTE.");
            ui->IDC_ACTIVECOPILOTE->setStyleSheet("background-color: green; color: white;");
            QMessageBox::information(this,
                                     "Paramètre de barre des tâches",
                                     "Le bouton d'Arrera COPILOTE ne sera plus affiché.");
        }else{
            QMessageBox::critical(this,
                                  "Paramètre de barre des tâches",
                                  "Une erreur s'est produite.");
        }
    }else{
        sortie = objPara->setTaskbarBTNCopilote();
        if (sortie){
            ui->IDC_ACTIVECOPILOTE->setText("Désactiver le bouton d'Arrera COPILOTE.");
            ui->IDC_ACTIVECOPILOTE->setStyleSheet("background-color: red; color: white;");
            QMessageBox::information(this,
                                     "Paramètre de barre des tâches",
                                     "Le bouton d'Arrera COPILOTE est affiché.");
        }else{
            QMessageBox::critical(this,
                                  "Paramètre de barre des tâches",
                                  "Une erreur s'est produite.");
        }
    }
    ui->LINDICATIONSETTING->setText("Parametre generaux");
    ui->stakedGeneraux->setCurrentIndex(idMainGeneraux);
}

void ArreraSettingUI::on_IDC_ACTIVEPOSTITE_clicked()
{
    bool sortie;
    if (objPara->getTaskbarPostite()){
        sortie = objPara->unsetTaskbarBTNPostite();
        if (sortie){
            ui->IDC_ACTIVEPOSTITE->setText("Activer le bouton d'Arrera Markdown.");
            ui->IDC_ACTIVEPOSTITE->setStyleSheet("background-color: green; color: white;");
            QMessageBox::information(this,"Paramètre de barre des tâches","Le bouton d'Arrera Postite ne sera plus affiché.");
        }else{
            QMessageBox::critical(this,
                                  "Paramètre de barre des tâches",
                                  "Une erreur s'est produite.");
        }
    }else{
        sortie = objPara->setTaskbarBBTNPostite();
        if (sortie){
            ui->IDC_ACTIVEPOSTITE->setText("Désactiver le bouton d'Arrera Markdown.");
            ui->IDC_ACTIVEPOSTITE->setStyleSheet("background-color: red; color: white;");
            QMessageBox::information(this,
                                     "Paramètre de barre des tâches",
                                     "Le bouton d'Arrera POSTITE est affiché.");
        }else{
            QMessageBox::critical(this,
                                  "Paramètre de barre des tâches",
                                  "Une erreur s'est produite.");
        }
    }
    ui->LINDICATIONSETTING->setText("Parametre generaux");
    ui->stakedGeneraux->setCurrentIndex(idMainGeneraux);
}

void ArreraSettingUI::on_IDC_RETOURTASJBAR_clicked()
{
    ui->LINDICATIONSETTING->setText("Parametre generaux");
    ui->mainstacked->setCurrentIndex(idGenerauxPage);
    ui->stakedGeneraux->setCurrentIndex(idMainGeneraux);
}

// Partie application
//Partie ajout de l'app
void ArreraSettingUI::on_IDC_ICONAPPPC_clicked()
{
    QString imageFilter = "Images ("
                          "*.bmp *.gif *.jpg *.jpeg *.jpe *.jfif *.png "
                          "*.tif *.tiff *.webp *.svg *.svgz "
                          "*.ico *.icns *.ppm *.pgm *.pbm *.xpm *.xbm)";
    appIcon = QFileDialog::getOpenFileName(
        this,                       // Parent widget
        "Sélectionner l'application",  // Titre de la boîte de dialogue
        QDir::homePath(),       // Répertoire initial
        imageFilter);

    if (!appIcon.isEmpty()){
        ui->IDC_ICONAPPPC->setStyleSheet("background-color: #4CAF50;color: white;");
    }
}


void ArreraSettingUI::on_IDC_VALIDERAPPPC_clicked()
{
    int nbApp;
    bool sortie;
    QString nameApp = ui->IDC_LINENAMEAPPLICATINPC->text().toLower();
    ui->IDC_LINENAMEAPPLICATINPC->clear();
    if (objPara->checkNameAppIsAvailable(nameApp)){
        if (!nameApp.isEmpty() && !appEmplacement.isEmpty()){
            nbApp = objPara->getFirstUnsetNumber();
            if (appIcon.isEmpty()){
                sortie = objPara->setApplication(nbApp,nameApp,appEmplacement,"");
            }else{
                sortie =objPara->setApplication(nbApp,nameApp,appEmplacement,appIcon);
            }

            if (sortie){
                QMessageBox::information(this,"Enregistrement application",
                                         "L'application a bien été enregistrée.");
            }else{
                QMessageBox::critical(this,"Enregistrement application",
                                      "Impossible d'enregistrer l'application");
            }
        }
        else{
            QMessageBox::critical(this,"Enregistrement application",
                                  "Il manque une information pour enregistrer l'application.");
        }
    }
    else{
        QMessageBox::critical(this,"Enregistrement application",
                             "Il est impossible d'avoir deux applications qui ont le même nom.");
    }
    ui->appstacked->setCurrentIndex(idMainAppStaked);

}

QString ArreraSettingUI::selectApplicationPath()
{
    int rMessage;
    QString appDirectory;
    if (dectOS->getosLinux()) {
        rMessage = QMessageBox::question(this, "Emplacement application",
                                         "L'application est-elle dans le /bin ou dans votre /home ?",
                                         QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
        appDirectory = (rMessage == QMessageBox::Yes) ? "/bin" : QDir::homePath();
    } else if (dectOS->getosWin()) {
        rMessage = QMessageBox::question(this, "Emplacement application",
                                         "Le raccourci se trouve dans le menu Démarrer global ?",
                                         QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
        appDirectory = (rMessage == QMessageBox::Yes)
                           ? "C:/ProgramData/Microsoft/Windows/Start Menu/Programs"
                           : QStandardPaths::writableLocation(QStandardPaths::ApplicationsLocation);
    } else if (dectOS->getosApple()) {
        rMessage = QMessageBox::question(
            this,
            "Emplacement application",
            "Voulez-vous chercher dans le dossier Applications global (accessible à tous les utilisateurs) ?",
            QMessageBox::Yes | QMessageBox::No,
            QMessageBox::Yes);
        appDirectory = (rMessage == QMessageBox::Yes)
                           ? "/Applications"
                           : (QDir::homePath() + "/Applications");
    } else {
        return QString();
    }

    return QFileDialog::getOpenFileName(
        this,
        "Sélectionner l'application",
        appDirectory);
}

void ArreraSettingUI::on_IDC_SETAPPPC_clicked()
{
    appEmplacement = selectApplicationPath();

    // Teste si l'application a etais choisie
    if (appEmplacement != ""){
        ui->IDC_VALIDERAPPPC->setVisible(true);
        ui->IDC_SETAPPPC->setStyleSheet("background-color: #4CAF50;color: white;");
    }
}

void ArreraSettingUI::on_IDC_CANCELAPPPC_clicked()
{
    ui->LINDICATIONSETTING->setText("Parametre des applications");
    ui->appstacked->setCurrentIndex(idMainAppStaked);
}

//Partie suppr de l'app
void ArreraSettingUI::on_IDC_CANCELSUPPRAPP_clicked()
{
    ui->LINDICATIONSETTING->setText("Parametre des applications");
    ui->appstacked->setCurrentIndex(idMainAppStaked);
}


void ArreraSettingUI::on_IDC_VALIDERSUPRR_clicked()
{
    QString nameApp = ui->LISTOPTIONAPPSUPPR->currentText();
    int nbApp = objPara->getNbAppWithName(nameApp);

    if (objPara->setSupprApplication(nbApp)){
        QMessageBox::information(this,"Suppression d'une application",
                              "L'application a bien été supprimée.");
    }else{
        QMessageBox::critical(this,"Suppression d'une application",
                              "Impossible de supprimer l'application.");
    }

    ui->LINDICATIONSETTING->setText("Parametre des applications");
    ui->appstacked->setCurrentIndex(idMainAppStaked);
}

//Partie acceuil d'app
void ArreraSettingUI::on_IDC_ADDAPPPC_clicked()
{
    if (objPara->getnbAppSetted() < 20){
        ui->LINDICATIONSETTING->setText("Ajouter une application");
        ui->appstacked->setCurrentIndex(idAddAppStacked);
        ui->IDC_VALIDERAPPPC->setVisible(false);
        ui->IDC_LINENAMEAPPLICATINPC->clear();
        appEmplacement = "";
        appIcon = "";
        ui->IDC_ICONAPPPC->setStyleSheet("");
        ui->IDC_SETAPPPC->setStyleSheet("");
    }else{
        QMessageBox::critical(this,
                              "Gestion application",
                              "Vous n'avez plus d'emplacement pour enregistrer une application.");
    }
}


void ArreraSettingUI::on_IDC_SUPPRAPPPC_clicked()
{
    if (objPara->getnbAppSetted() == 0){
        QMessageBox::critical(this,
            "Gestion application",
            "Il n'y a aucune application pour enregistrer");
    }else{
        setAppComboBox();
        ui->LINDICATIONSETTING->setText("Supprimer une application");
        ui->appstacked->setCurrentIndex(idSupprAppStacked);
    }
}

void ArreraSettingUI::on_IDC_CHANGEICON_clicked()
{
    if (objPara->getnbAppSetted() == 0){
        QMessageBox::critical(this,
                              "Gestion application",
                              "Il n'y a aucune application pour enregistrer");
    }else{
        setAppComboBox();
        ui->LINDICATIONSETTING->setText("Changer l'icône des applications");
        ui->appstacked->setCurrentIndex(idIconChangeApp);
    }
}

void ArreraSettingUI::on_IDC_MODIFEMPLACMENTAPPPC_clicked()
{
    if (objPara->getnbAppSetted() == 0){
        QMessageBox::critical(this,
                              "Gestion application",
                              "Il n'y a aucune application pour enregistrer");
    }else{
        setAppComboBox();
        ui->LINDICATIONSETTING->setText("Changer l'emplacement des applications");
        ui->appstacked->setCurrentIndex(idEmplacementAppStacked);
    }
}

void ArreraSettingUI::on_IDC_EDITTABLEUR_clicked()
{
    if (objPara->getAppSpeciauxSetted(3)){
        ui->IDC_RESETAPPSPEC->setVisible(true);
        ui->IDC_CHOOSEAPPSPE->setVisible(false);
    }else{
        ui->IDC_RESETAPPSPEC->setVisible(false);
        ui->IDC_CHOOSEAPPSPE->setVisible(true);
    }
    ui->appstacked->setCurrentIndex(idManageAppSpeciaux);
    appSpeSelected = 3;
    ui->LINCAPPSPEMANAGE->setText("Gestion de l'enregistrement de l'application tableur");
    ui->LINDICATIONSETTING->setText("Parametre application tableur");
}


void ArreraSettingUI::on_IDC_EDITTRAITEMENTTEXTE_clicked()
{
    if (objPara->getAppSpeciauxSetted(4)){
        ui->IDC_RESETAPPSPEC->setVisible(true);
        ui->IDC_CHOOSEAPPSPE->setVisible(false);
    }else{
        ui->IDC_RESETAPPSPEC->setVisible(false);
        ui->IDC_CHOOSEAPPSPE->setVisible(true);
    }
    ui->appstacked->setCurrentIndex(idManageAppSpeciaux);
    appSpeSelected = 4;
    ui->LINCAPPSPEMANAGE->setText("Gestion de l'enregistrement de l'application\nde traitement de texte");
    ui->LINDICATIONSETTING->setText("Parametre application de traitement de texte");
}


void ArreraSettingUI::on_IDC_EDITNAVIGATEUR_clicked()
{
    if (objPara->getAppSpeciauxSetted(1)){
        ui->IDC_RESETAPPSPEC->setVisible(true);
        ui->IDC_CHOOSEAPPSPE->setVisible(false);
    }else{
        ui->IDC_RESETAPPSPEC->setVisible(false);
        ui->IDC_CHOOSEAPPSPE->setVisible(true);
    }
    ui->appstacked->setCurrentIndex(idManageAppSpeciaux);
    appSpeSelected = 1;
    ui->LINCAPPSPEMANAGE->setText("Gestion de l'enregistrement de l'application navigateur");
    ui->LINDICATIONSETTING->setText("Parametre application navigateur");
}


void ArreraSettingUI::on_IDC_EDITPRESENTATION_clicked()
{
    if (objPara->getAppSpeciauxSetted(2)){
        ui->IDC_RESETAPPSPEC->setVisible(true);
        ui->IDC_CHOOSEAPPSPE->setVisible(false);
    }else{
        ui->IDC_RESETAPPSPEC->setVisible(false);
        ui->IDC_CHOOSEAPPSPE->setVisible(true);
    }
    ui->appstacked->setCurrentIndex(idManageAppSpeciaux);
    appSpeSelected = 2;
    ui->LINCAPPSPEMANAGE->setText("Gestion de l'enregistrement de l'application\nde presentation");
    ui->LINDICATIONSETTING->setText("Parametre application presentation");
}

// Partie changement icon APP

void ArreraSettingUI::on_IDC_CANCELCHANGEICON_clicked()
{
    ui->LINDICATIONSETTING->setText("Parametre des applications");
    ui->appstacked->setCurrentIndex(idMainAppStaked);
}


void ArreraSettingUI::on_IDC_CHANGEICONE_clicked()
{
    bool sortie;

    QString nameApp = ui->LISTAPPCHANGEICON->currentText();
    int nbApp = objPara->getNbAppWithName(nameApp);

    QString imageFilter = "Images ("
                          "*.bmp *.gif *.jpg *.jpeg *.jpe *.jfif *.png "
                          "*.tif *.tiff *.webp *.svg *.svgz "
                          "*.ico *.icns *.ppm *.pgm *.pbm *.xpm *.xbm)";
    QString newIcon = QFileDialog::getOpenFileName(
        this,                       // Parent widget
        "Sélectionner l'application",  // Titre de la boîte de dialogue
        QDir::homePath(),       // Répertoire initial
        imageFilter);

    if (!newIcon.isEmpty()){
        sortie = objPara->setNewIconApplication(nbApp,newIcon);

        if (sortie){
            QMessageBox::information(this,"Icon application",
                                     "L'icône a bien été changée.");
        }
        else{
            QMessageBox::critical(this,"Icon application",
                                  "Impossible de changer l'icône.");
        }

    }
    else{
        QMessageBox::critical(this,"Icon application",
                              "Aucune icône sélectionnée.");
    }

    ui->LINDICATIONSETTING->setText("Parametre des applications");
    ui->appstacked->setCurrentIndex(idMainAppStaked);
}

// Partie changement emplacement app
void ArreraSettingUI::on_IDC_VALIDERCHANGEEMPLACEMENTAPP_clicked()
{
    bool sortie;

    QString nameApp = ui->LISTAPPCHANGEEMPLACEMENT->currentText();
    int nbApp = objPara->getNbAppWithName(nameApp);

    QString newEmplacement = selectApplicationPath();

    // Teste si l'application a etais choisie
    if (newEmplacement != ""){
        sortie = objPara->setNewExeApplication(nbApp,newEmplacement);
        if (sortie){
            QMessageBox::information(this,"Nouveau emplacement",
                                     "Le nouvel emplacement de l'application a été enregistré.");
        }else{
            QMessageBox::critical(this,"Nouveau emplacement",
                                  "Impossible d'enregistrer le nouvel emplacement.");
        }
    }else{
        QMessageBox::critical(this,"Nouveau emplacement",
                              "Vous n'avez pas sélectionné l'application.");
    }

    ui->LINDICATIONSETTING->setText("Parametre des applications");
    ui->appstacked->setCurrentIndex(idMainAppStaked);
}

void ArreraSettingUI::on_IDC_CANCELEMPLACEMENTAPP_clicked()
{
    ui->LINDICATIONSETTING->setText("Parametre des applications");
    ui->appstacked->setCurrentIndex(idMainAppStaked);
}

// Partie app speciaux
void ArreraSettingUI::on_IDC_CANCELAPPSPEMANAGE_clicked()
{
    ui->LINDICATIONSETTING->setText("Parametre des applications");
    ui->appstacked->setCurrentIndex(idMainAppStaked);
}


void ArreraSettingUI::on_IDC_CHOOSEAPPSPE_clicked()
{
    QString speAppEmplacement = selectApplicationPath();
    bool sortie = false;

    // Teste si l'application a etais choisie
    // 1.Navigateur 2.Presentation 3.tableur 4.Traitement de texte
    if (speAppEmplacement != ""){
        switch (appSpeSelected) {
        case 1:
            sortie = objPara->setAppNavigateur(speAppEmplacement);
            break;
        case 2:
            sortie = objPara->setAppPresentation(speAppEmplacement);
            break;
        case 3:
            sortie = objPara->setAppTableur(speAppEmplacement);
            break;
        case 4:
            sortie = objPara->setAppTraitementTexte(speAppEmplacement);
            break;
        default:
            sortie = false;
            break;
        }
    }
    if (sortie){
        QMessageBox::information(this,"Application",
                                 "L'application a bien été enregistrée.");
    }else{
        QMessageBox::critical(this,"Application",
                              "Impossible d'enregistrer l'application.");
    }
    ui->LINDICATIONSETTING->setText("Parametre des applications");
    ui->appstacked->setCurrentIndex(idMainAppStaked);
}


void ArreraSettingUI::on_IDC_RESETAPPSPEC_clicked()
{
    bool sortie = false;
    // 1.Navigateur 2.Presentation 3.tableur 4.Traitement de texte
    switch (appSpeSelected) {
    case 1:
        sortie = objPara->setSupprAppNavigateur();
        break;
    case 2:
        sortie = objPara->setSupprAppPresentation();
        break;
    case 3:
        sortie = objPara->setSupprAppTableur();
        break;
    case 4:
        sortie = objPara->setSupprAppTraitementTexte();
        break;
    default:
        break;
    }

    if (sortie){
        QMessageBox::information(this,"Application",
                                 "L'application a été supprimée.");
    }else{
        QMessageBox::critical(this,"Application",
                              "Impossible de supprimer l'application.");
    }

    ui->LINDICATIONSETTING->setText("Parametre des applications");
    ui->appstacked->setCurrentIndex(idMainAppStaked);
}

// Partie Recherche

void ArreraSettingUI::on_IDC_VALIDERRECHERCHE_clicked()
{
    QString moteur = ui->IDC_LISTEMOTEURERECHERCHE->currentText();
    bool sortie = objPara->setMoteurRecherche(moteur);

    if (sortie){
        QMessageBox::information(this,
                                 "Paramètre de recherche",
                                 "Le moteur de recherche a été modifié.");
    }else{
        QMessageBox::critical(this,"Paramètre de recherche",
                              "Impossible de changer le moteur de recherche.");
    }
    ui->mainstacked->setCurrentIndex(idMainPage);
}

void ArreraSettingUI::on_IDC_SUPPRHIST_clicked()
{
    bool sortie = objRecherche->clear();
    if(sortie){
        QMessageBox::information(this,
                                 "Historique Arrera Recherche",
                                 "L'historique de recherche a été supprimé.");
    }else{
        QMessageBox::critical(this,
                                 "Historique Arrera Recherche",
                                 "Impossible de supprimer l'historique.");
    }
    ui->mainstacked->setCurrentIndex(idMainPage);
}

void ArreraSettingUI::on_BTN_CHANGE_GUI_SIX_clicked()
{
    QString valeurChoisie = ui->LIST_SIX_GUI->currentText();
    if (objPara->set_gui_six(valeurChoisie)) {
        QMessageBox::information(this,"Interface de Six","L'interface de SIX a bien etais enregistrer");
    }else{
        QMessageBox::critical(this,"Erreur","L'interface de SIX n'a pas été instaler");
    }
}

