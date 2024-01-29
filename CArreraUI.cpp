#include "CArreraUI.h"
#include <QDesktopServices>
#include <QUrl>
#include "./ui_CArreraUI.h"

CArreraUI::CArreraUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CArreraUI)
{
    ui->setupUi(this);
    ui->IDC_COPILOTE->setVisible(false);
    winPara = new CDAParametre(this);
    winAPP = new ArreraAppLib(this);
    winApropos = new CArreraApropos(this);
    taskBar = new CArreraTakbar(this);
    objSoftware.setObjPara(&objPara);
    winPara->passObjPara(&objPara,&objSoftware);
    winAPP->passObjet(&objPara,&objSoftware);
    taskBar->passObj(&objPara,&objSoftware);
    connect(this,&CArreraUI::destroyed,winPara,&CArreraUI::close);
    connect(this,&CArreraUI::destroyed,winAPP,&CArreraUI::close);
    connect(this,&CArreraUI::destroyed,winApropos,&CArreraUI::close);
    connect(this,&CArreraUI::destroyed,taskBar,&CArreraUI::close);
    ui->FMode->setVisible(false);
    loadSetting();
}

CArreraUI::~CArreraUI()
{
    delete ui;
}

// Bouton Bottom
void CArreraUI::on_IDC_QUIT_clicked()
{
    qApp->quit();
}


void CArreraUI::on_IDC_PARAMETRE_clicked()
{
    winPara->show();
}

// Bouton assistant
void CArreraUI::on_IDC_SIX_clicked()
{
    bool sortie ;
    sortie = objSoftware.openSix();
    if (!sortie)
    {
        errorOpenSoft();
    }
}


void CArreraUI::on_IDC_COPILOTE_clicked()
{

}


void CArreraUI::on_IDC_RYLEY_clicked()
{
    bool sortie ;
    sortie = objSoftware.openRyley();
    if (!sortie)
    {
        errorOpenSoft();
    }
}

// bouton mode

void CArreraUI::on_IDC_MODE1_clicked()
{
    onMode(1);
}


void CArreraUI::on_IDC_MODE2_clicked()
{
    onMode(2);
}


void CArreraUI::on_IDC_MODE3_clicked()
{
    onMode(3);
}


void CArreraUI::on_IDC_MODE4_clicked()
{
    onMode(4);
}


void CArreraUI::on_IDC_MODE5_clicked()
{
    onMode(5);
}

// Bouton app
void CArreraUI::on_IDC_TABLEUR_clicked()
{
    bool sortie ;
    sortie = objSoftware.openTableur();
    if (!sortie)
    {
        errorOpenSoft();
    }

}


void CArreraUI::on_IDC_TRAITEMENT_clicked()
{
    bool sortie ;
    sortie = objSoftware.openTTexte();
    if (!sortie)
    {
        errorOpenSoft();
    }
}


void CArreraUI::on_IDC_APP_clicked()
{
    winAPP->show();
}


void CArreraUI::on_IDC_NAVIGATEUR_clicked()
{
    bool sortie ;
    sortie = objSoftware.openNavigateur();
    if (!sortie)
    {
        errorOpenSoft();
    }
}


void CArreraUI::on_IDC_PRESENTATION_clicked()
{
    bool sortie ;
    sortie = objSoftware.openPresentation();
    if (!sortie)
    {
        errorOpenSoft();
    }
}

void CArreraUI::closeEvent(QCloseEvent *event)
{
    // Fermer toutes les fenêtres enfants lorsque la fenêtre principale est fermée
    foreach(QWidget *widget, QApplication::topLevelWidgets()) {
        if (widget != this && widget->inherits("MaFenetreEnfant")) {
            widget->close();
        }
    }
    // Appeler la méthode closeEvent de la classe de base pour effectuer la fermeture par défaut
    QMainWindow::closeEvent(event);
}

void CArreraUI::loadSetting()
{
    QString nameUser;
    objPara.loadSetting();
    nameUser = QString::fromStdString(objPara.getNameUser().c_str());
    ui->IDC_LABELUSER->setText("Utilisateur : "+nameUser);
    ui->IDC_MODE1->setText(objPara.getNameMode1().c_str());
    ui->IDC_MODE2->setText(objPara.getNameMode2().c_str());
    ui->IDC_MODE3->setText(objPara.getNameMode3().c_str());
    ui->IDC_MODE4->setText(objPara.getNameMode4().c_str());
    ui->IDC_MODE5->setText(objPara.getNameMode5().c_str());
    winAPP->updateBTN();
    taskBar->loadPara(0);
}

void CArreraUI::on_IDC_RELOAD_clicked()
{
    loadSetting();
}

void CArreraUI::errorOpenSoft()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Erreur");
    msgBox.setText("Une erreur ces produite lors de l'ouverture du logiciel");
    msgBox.addButton(QMessageBox::Ok);
}

void CArreraUI::on_IDC_APROPOS_clicked()
{
    winApropos->show();
}


void CArreraUI::on_IDC_TASKBAR_clicked()
{
    taskBar->show();
}

//BTN UI MODE

void CArreraUI::bootAssistantMode()
{
    bool sortie ;
    qDebug() <<nbModeON;
    if(objPara.getAssistantMode(nbModeON)=="six")
    {
        sortie = objSoftware.openSix();
        if (!sortie)
        {
            errorOpenSoft();
        }
    }
    else
    {
        if (objPara.getAssistantMode(nbModeON)=="ryley")
        {
            sortie = objSoftware.openRyley();
            if (!sortie)
            {
                errorOpenSoft();
            }
        }
    }
}

void CArreraUI::onMode(int nbMode)
{
    if (objPara.getModeEnable(nbMode)=="1")
    {
        ui->FGUI->setVisible(false);
        ui->FMode->setVisible(true);
        switch (nbMode) {
        case 1:
            ui->IDC_NAMEMODEON->setText(objPara.getNameMode1().c_str());
            if (objPara.getEtatTaskbar(1)=="true")
            {
                ui->IDC_TASKBARMODE->setVisible(true);
            }
            else
            {
                ui->IDC_TASKBARMODE->setVisible(false);
            }
            break;
        case 2:
            ui->IDC_NAMEMODEON->setText(objPara.getNameMode2().c_str());
            if (objPara.getEtatTaskbar(2)=="true")
            {
                ui->IDC_TASKBARMODE->setVisible(true);
            }
            else
            {
                ui->IDC_TASKBARMODE->setVisible(false);
            }
            break;
        case 3:
            ui->IDC_NAMEMODEON->setText(objPara.getNameMode3().c_str());
            if (objPara.getEtatTaskbar(3)=="true")
            {
                ui->IDC_TASKBARMODE->setVisible(true);
            }
            else
            {
                ui->IDC_TASKBARMODE->setVisible(false);
            }
            break;
        case 4:
            ui->IDC_NAMEMODEON->setText(objPara.getNameMode4().c_str());
            if (objPara.getEtatTaskbar(4)=="true")
            {
                ui->IDC_TASKBARMODE->setVisible(true);
            }
            else
            {
                ui->IDC_TASKBARMODE->setVisible(false);
            }
            break;
        case 5:
            ui->IDC_NAMEMODEON->setText(objPara.getNameMode5().c_str());
            if (objPara.getEtatTaskbar(5)=="true")
            {
                ui->IDC_TASKBARMODE->setVisible(true);
            }
            else
            {
                ui->IDC_TASKBARMODE->setVisible(false);
            }
            break;
        default:
            break;
        }
        nbModeON = nbMode;
        objSoftware.openAppLib((stoi(objPara.getModeAppAsBoot(nbMode))));
        bootAssistantMode();
        if (objPara.getAssistantMode(nbModeON)=="nothing")
        {
            ui->IDC_ASSISTANTMODE->setVisible(false);
        }
    }
    else
    {
        QMessageBox::information(nullptr, "Mode", "Le mode selectionner n'est pas parametrer");
    }
}

void CArreraUI::offMode()
{
    nbModeON = 0;
    ui->FGUI->setVisible(true);
    ui->FMode->setVisible(false);
    loadSetting();
}

void CArreraUI::on_IDC_TABLEURMODE_clicked()
{
    bool sortie ;
    sortie = objSoftware.openTableur();
    if (!sortie)
    {
        errorOpenSoft();
    }
}


void CArreraUI::on_IDC_TRAITEMENTMODE_clicked()
{
    bool sortie ;
    sortie = objSoftware.openTTexte();
    if (!sortie)
    {
        errorOpenSoft();
    }
}


void CArreraUI::on_IDC_APPMODE_clicked()
{
    winAPP->show();
}


void CArreraUI::on_IDC_TASKBARMODE_clicked()
{
    taskBar->loadPara(nbModeON);
    taskBar->show();
}


void CArreraUI::on_IDC_NAVIGATEURMODE_clicked()
{
    bool sortie ;
    sortie = objSoftware.openNavigateur();
    if (!sortie)
    {
        errorOpenSoft();
    }
}


void CArreraUI::on_IDC_PRESENTATIONMODE_clicked()
{
    bool sortie ;
    sortie = objSoftware.openPresentation();
    if (!sortie)
    {
        errorOpenSoft();
    }
}


void CArreraUI::on_IDC_QUITMODE_clicked()
{
    offMode();
}


void CArreraUI::on_IDC_QUIT2_clicked()
{
    qApp->quit();
}


void CArreraUI::on_IDC_ASSISTANTMODE_clicked()
{
    bootAssistantMode();
}

