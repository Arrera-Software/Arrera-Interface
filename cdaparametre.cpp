#include "cdaparametre.h"
#include <QMessageBox>
#include "ui_cdaparametre.h"

CDAParametre::CDAParametre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CDAParametre)
{
    ui->setupUi(this);
    modeSelectionner = 0 ;
    ui->IDC_MODESELECT->setText("Mode selectionner : Aucun");
    ui->IDC_CHOIXSIX->setChecked(true);
    ui->IDC_RARRERABAR->setChecked(false);
    ui->IDC_CHECKVM->setChecked(false);
    ui->IDC_CHECKTOUCHSCREEN->setChecked(false);
    winParaApp = new CDAparaArreraLib(this);
    taskBarModeEnable = false;
    connect(this,&CDAParametre::destroyed,winParaApp,&CDAParametre::close);
    ui->FGESTMODE->setVisible(false);
    ui->FMODESET->setVisible(false);
    ui->FMTPUSER->setVisible(false);
    ui->IDC_PSIX->setVisible(false);
    ui->IDC_PRYLEY->setVisible(false);
    if((osDetecteur.getLinux())&&(!osDetecteur.getWindows()))
    {
        //ui->IDC_ESIX->setVisible(false);
        ui->IDC_PSIX->setVisible(false);
        //ui->IDC_CHOIXSIX->setVisible(false);
        ui->IDC_INSTALLCOPILOTE->setVisible(false);
    }
}

CDAParametre::~CDAParametre()
{
    delete ui;
}

void CDAParametre::passObjPara(CArreraSetting* obj,CArreraOpenSoft *objSoft)
{
    objParametre = obj ;
    objOpenSoft = objSoft;
    winParaApp->passObjet(objParametre);

}

void CDAParametre::closeEvent(QCloseEvent *event)
{
    // Émettre le signal lorsque la fenêtre des paramètres est fermée
    emit parametresFerme();
    QWidget::closeEvent(event);
}

void CDAParametre::on_IDC_GESTMODE1_clicked()
{

    if (objParametre->getModeEnable(1)=="0")
    {

        ui->IDC_MODESELECT->setText("Mode selectionner : Mode 1");
        ui->IDC_CHECKVM->setChecked(false);
        ui->IDC_CHECKTOUCHSCREEN->setChecked(false);
        ui->FGESTMODE->setVisible(true);
        ui->FALLMODE->setVisible(false);
    }
    else
    {
        ui->FGESTMODE->setVisible(false);
        ui->FALLMODE->setVisible(false);
        ui->FMODESET->setVisible(true);
        ui->IDC_NAMEMODESET->setText(objParametre->getNameMode(1).c_str());
    }
    modeSelectionner = 1 ;
}


void CDAParametre::on_IDC_GESTMODE2_clicked()
{
    if (objParametre->getModeEnable(2)=="0")
    {

    ui->IDC_MODESELECT->setText("Mode selectionner : Mode 2");
    ui->IDC_CHECKVM->setChecked(false);
    ui->IDC_CHECKTOUCHSCREEN->setChecked(false);
    ui->FGESTMODE->setVisible(true);
    ui->FALLMODE->setVisible(false);
    }
    else
    {
        ui->FGESTMODE->setVisible(false);
        ui->FALLMODE->setVisible(false);
        ui->FMODESET->setVisible(true);
        ui->IDC_NAMEMODESET->setText(objParametre->getNameMode(2).c_str());
    }
    modeSelectionner = 2 ;
}


void CDAParametre::on_IDC_GESTMODE3_clicked()
{
    if (objParametre->getModeEnable(3)=="0")
    {
    ui->IDC_MODESELECT->setText("Mode selectionner : Mode 3");
    ui->FGESTMODE->setVisible(true);
    ui->FALLMODE->setVisible(false);
    ui->IDC_CHECKVM->setChecked(false);
    ui->IDC_CHECKTOUCHSCREEN->setChecked(false);
    }
    else
    {
        ui->FGESTMODE->setVisible(false);
        ui->FALLMODE->setVisible(false);
        ui->FMODESET->setVisible(true);
        ui->IDC_NAMEMODESET->setText(objParametre->getNameMode(3).c_str());
    }
    modeSelectionner = 3 ;
}


void CDAParametre::on_IDC_GESTMODE4_clicked()
{
    if (objParametre->getModeEnable(4)=="0")
    {
    ui->IDC_MODESELECT->setText("Mode selectionner : Mode 4");
    ui->FGESTMODE->setVisible(true);
    ui->FALLMODE->setVisible(false);
    ui->IDC_CHECKVM->setChecked(false);
    ui->IDC_CHECKTOUCHSCREEN->setChecked(false);
    }
    else
    {
        ui->FGESTMODE->setVisible(false);
        ui->FALLMODE->setVisible(false);
        ui->FMODESET->setVisible(true);
        ui->IDC_NAMEMODESET->setText(objParametre->getNameMode(4).c_str());
    }
    modeSelectionner = 4 ;
}


void CDAParametre::on_IDC_GESTMODE5_clicked()
{
    if (objParametre->getModeEnable(5)=="0")
    {
    ui->IDC_MODESELECT->setText("Mode selectionner : Mode 5");
    ui->FGESTMODE->setVisible(true);
    ui->FALLMODE->setVisible(false);
    ui->IDC_CHECKVM->setChecked(false);
    ui->IDC_CHECKTOUCHSCREEN->setChecked(false);
    }
    else
    {
        ui->FGESTMODE->setVisible(false);
        ui->FALLMODE->setVisible(false);
        ui->FMODESET->setVisible(true);
        ui->IDC_NAMEMODESET->setText(objParametre->getNameMode(5).c_str());
    }
    modeSelectionner = 5;
}


void CDAParametre::on_IDC_VALIDER_clicked()
{
    QMessageBox msgBox;
    bool sortieEcriture=false,arreraTaskBar;
    QString valeurGUI ;
    string valeurString;
    bool vmEnable=false,touchEnable=false;
    int nbAppBoot;
    sortieRyley = ui->IDC_CHOIXRYLEY->isChecked();
    sortieSix = ui->IDC_CHOIXSIX->isChecked();
    arreraTaskBar = ui->IDC_RARRERABAR->isChecked();
    sortieCopilote = ui->IDC_CHOIXCOPILOTE->isChecked();
    nbAppBoot = ui->IDC_NBAPPBOOT->value();
    vmEnable = ui->IDC_CHECKVM->isChecked();
    touchEnable = ui->IDC_CHECKTOUCHSCREEN->isChecked();
    //qDebug() << nbAppBoot ;
    if (modeSelectionner==0)
    {
        msgBox.setWindowTitle("Erreur de selection");
        msgBox.setText("Aucun mode a ete selectionner");
        msgBox.addButton(QMessageBox::Ok);
        msgBox.exec();
    }
    else
    {
        switch(modeSelectionner)
        {
            case 1 :
                valeurGUI = ui->IDC_NAMETEXT->toPlainText();
                valeurString = valeurGUI.toStdString();
                sortieEcriture = objParametre->setModeEnable(1);
                sortieEcriture = objParametre->setNameMode(1,valeurString);
                sortieEcriture = objParametre->setAssistantMode(1,sortieRyley,sortieSix,sortieCopilote);
                sortieEcriture = objParametre->setEtatTaskbar(1,arreraTaskBar);
                sortieEcriture = objParametre->setModeAppAsBoot(1,nbAppBoot);
                sortieEcriture = objParametre->setEtatVM(1,vmEnable);
                sortieEcriture = objParametre->setEtatTouch(1,touchEnable);
                if (arreraTaskBar)
                {
                    winParaApp->show();
                    winParaApp->modeTaskbar(1);
                }
                break;
            case 2 :
                valeurGUI = ui->IDC_NAMETEXT->toPlainText();
                valeurString = valeurGUI.toStdString();
                sortieEcriture = objParametre->setModeEnable(2);
                sortieEcriture =objParametre->setNameMode(2,valeurString);
                sortieEcriture = objParametre->setAssistantMode(2,sortieRyley,sortieSix,sortieCopilote);
                sortieEcriture = objParametre->setEtatTaskbar(2,arreraTaskBar);
                sortieEcriture = objParametre->setModeAppAsBoot(2,nbAppBoot);
                sortieEcriture = objParametre->setEtatVM(2,vmEnable);
                sortieEcriture = objParametre->setEtatTouch(2,touchEnable);
                if (arreraTaskBar)
                {
                    winParaApp->show();
                    winParaApp->modeTaskbar(2);
                }
                break;
            case 3 :
                valeurGUI = ui->IDC_NAMETEXT->toPlainText();
                valeurString = valeurGUI.toStdString();
                sortieEcriture = objParametre->setModeEnable(3);
                sortieEcriture =objParametre->setNameMode(3,valeurString);
                sortieEcriture = objParametre->setAssistantMode(3,sortieRyley,sortieSix,sortieCopilote);
                sortieEcriture = objParametre->setEtatTaskbar(3,arreraTaskBar);
                sortieEcriture = objParametre->setModeAppAsBoot(3,nbAppBoot);
                sortieEcriture = objParametre->setEtatVM(3,vmEnable);
                sortieEcriture = objParametre->setEtatTouch(3,touchEnable);
                if (arreraTaskBar)
                {
                    winParaApp->show();
                    winParaApp->modeTaskbar(3);
                }
                break;
            case 4 :
                valeurGUI = ui->IDC_NAMETEXT->toPlainText();
                valeurString = valeurGUI.toStdString();
                sortieEcriture = objParametre->setModeEnable(4);
                sortieEcriture =objParametre->setNameMode(4,valeurString);
                sortieEcriture = objParametre->setAssistantMode(4,sortieRyley,sortieSix,sortieCopilote);
                sortieEcriture = objParametre->setEtatTaskbar(4,arreraTaskBar);
                sortieEcriture = objParametre->setModeAppAsBoot(4,nbAppBoot);
                sortieEcriture = objParametre->setEtatVM(4,vmEnable);
                sortieEcriture = objParametre->setEtatTouch(4,touchEnable);
                if (arreraTaskBar)
                {
                    winParaApp->show();
                    winParaApp->modeTaskbar(4);
                }
                break;
            case 5 :
                valeurGUI = ui->IDC_NAMETEXT->toPlainText();
                valeurString = valeurGUI.toStdString();
                sortieEcriture = objParametre->setModeEnable(5);
                sortieEcriture = objParametre->setNameMode(5,valeurString);
                sortieEcriture = objParametre->setAssistantMode(5,sortieRyley,sortieSix,sortieCopilote);
                sortieEcriture = objParametre->setEtatTaskbar(5,arreraTaskBar);
                sortieEcriture = objParametre->setModeAppAsBoot(5,nbAppBoot);
                sortieEcriture = objParametre->setEtatVM(5,vmEnable);
                sortieEcriture = objParametre->setEtatTouch(5,touchEnable);
                if (arreraTaskBar)
                {
                    winParaApp->show();
                    winParaApp->modeTaskbar(5);
                }
                break;
            default :
                msgBox.setWindowTitle("Erreur de selection");
                msgBox.setText("Une erreur de selection de mode c'est produit");
                msgBox.addButton(QMessageBox::Ok);
                msgBox.exec();
                break;
        }

        }

    if (sortieEcriture==false)
    {
            msgBox.setWindowTitle("Erreur ecriture");
            msgBox.setText("Une erreur c'est passer lors de l'ecriture");
            msgBox.addButton(QMessageBox::Ok);
        }
        ui->IDC_NAMETEXT->clear();
        ui->IDC_NBAPPBOOT->setValue(0);
        ui->IDC_CHOIXSIX->setChecked(true);
        ui->IDC_RARRERABAR->setChecked(false);
        taskBarModeEnable = false;
        ui->IDC_MODESELECT->setText("Mode selectionner : Aucun");
        modeSelectionner = 0 ;
        ui->FGESTMODE->setVisible(false);
        ui->FALLMODE->setVisible(true);

    }


void CDAParametre::on_IDC_ETABLEUR_clicked()
{
    objParametre->setSoftTableur();
}


void CDAParametre::on_IDC_ENAVIGATEUR_clicked()
{
    objParametre->setSoftNavigateur();
}


void CDAParametre::on_IDC_ETTEXTE_clicked()
{
    objParametre->setSoftTTexte();
}


void CDAParametre::on_IDC_EPRESENTATION_clicked()
{
    objParametre->setSoftPresentation();
}


void CDAParametre::on_IDC_ESIX_clicked()
{
    objParametre->setSixEmplacement();
}


void CDAParametre::on_IDC_ERYLEY_clicked()
{
    objParametre->setRyleyEmplacement();
}


void CDAParametre::on_IDC_VALIDERNAME_clicked()
{
    QString name;
    name = ui->IDC_NAMEUSER->toPlainText();
    ui->IDC_NAMEUSER->clear();
    objParametre->setNameUser(name.toStdString());
}


void CDAParametre::on_IDC_PSIX_clicked()
{
    objOpenSoft->openSixPara();
}


void CDAParametre::on_IDC_PRYLEY_clicked()
{
    objOpenSoft->openRyleyPara();
}


void CDAParametre::on_IDC_RESETINTERFACE_clicked()
{
    objParametre->resetAllPara();
}


void CDAParametre::on_IDC_APP_clicked()
{
    winParaApp->show();
    winParaApp->modeApp();
}


void CDAParametre::on_IDC_GESTTASKBAR_clicked()
{
    winParaApp->show();
    winParaApp->modeTaskbar(0);
}


void CDAParametre::on_IDC_APPTASKMODE_clicked()
{
}

void CDAParametre::on_IDC_ANNULERMODE_clicked()
{
    ui->IDC_MODESELECT->setText("Mode selectionner : Aucun");
    modeSelectionner = 0 ;
    ui->FMODESET->setVisible(false);
    ui->FGESTMODE->setVisible(false);
    ui->FALLMODE->setVisible(true);
}


void CDAParametre::on_IDC_BTNRESETMODESET_clicked()
{
    objParametre->resetMode(modeSelectionner);
    modeSelectionner = 0 ;
    ui->IDC_NAMETEXT->clear();
    ui->IDC_NBAPPBOOT->setValue(0);
    ui->IDC_CHOIXSIX->setChecked(true);
    ui->IDC_RARRERABAR->setChecked(false);
    taskBarModeEnable = false;
    ui->IDC_MODESELECT->setText("Mode selectionner : Aucun");
    modeSelectionner = 0 ;
    ui->FGESTMODE->setVisible(false);
    ui->FALLMODE->setVisible(true);
    ui->FMODESET->setVisible(false);
}

void CDAParametre::on_BTNMTP0_clicked()
{
    QString old,sortieUI = "0";
    old = mtpUser;
    mtpUser = old+sortieUI;
    ui->IDC_SHOWMTP->setText(mtpUser);
}


void CDAParametre::on_BTNMTP1_5_clicked()
{
    QString old,sortieUI = "1";
    old = mtpUser;
    mtpUser = old+sortieUI;
    ui->IDC_SHOWMTP->setText(mtpUser);
}


void CDAParametre::on_BTNMTP2_clicked()
{
    QString old,sortieUI = "2";
    old = mtpUser;
    mtpUser = old+sortieUI;
    ui->IDC_SHOWMTP->setText(mtpUser);
}


void CDAParametre::on_BTNMTP3_clicked()
{
    QString old,sortieUI = "3";
    old = mtpUser;
    mtpUser = old+sortieUI;
    ui->IDC_SHOWMTP->setText(mtpUser);
}


void CDAParametre::on_BTNMTP4_clicked()
{
    QString old,sortieUI = "4";
    old = mtpUser;
    mtpUser = old+sortieUI;
    ui->IDC_SHOWMTP->setText(mtpUser);
}


void CDAParametre::on_BTNMTP5_clicked()
{
    QString old,sortieUI = "5";
    old = mtpUser;
    mtpUser = old+sortieUI;
    ui->IDC_SHOWMTP->setText(mtpUser);
}


void CDAParametre::on_BTNMTP6_clicked()
{
    QString old,sortieUI = "6";
    old = mtpUser;
    mtpUser = old+sortieUI;
    ui->IDC_SHOWMTP->setText(mtpUser);
}


void CDAParametre::on_BTNMTP7_clicked()
{
    QString old,sortieUI = "7";
    old = mtpUser;
    mtpUser = old+sortieUI;
    ui->IDC_SHOWMTP->setText(mtpUser);
}


void CDAParametre::on_BTNMTP8_clicked()
{
    QString old,sortieUI = "8";
    old = mtpUser;
    mtpUser = old+sortieUI;
    ui->IDC_SHOWMTP->setText(mtpUser);
}


void CDAParametre::on_BTNMTP9_clicked()
{
    QString old,sortieUI = "9";
    old = mtpUser;
    mtpUser = old+sortieUI;
    ui->IDC_SHOWMTP->setText(mtpUser);
}


void CDAParametre::on_IDC_VALIDERMTP_clicked()
{
    objParametre->setMTPUser(mtpUser.toStdString());
    ui->IDC_SHOWMTP->setText("");
    mtpUser = "";
    ui->FMTPUSER->setVisible(false);
    ui->FGESTINTERFACE->setVisible(true);
}


void CDAParametre::on_IDC_ANNULERMTP_clicked()
{
    objParametre->setMTPUser("0000");
    ui->IDC_SHOWMTP->setText("");
    mtpUser = "";
    ui->FMTPUSER->setVisible(false);
    ui->FGESTINTERFACE->setVisible(true);
}

void CDAParametre::on_IDC_ADDUTILITYVM_clicked()
{
    objParametre->setVMStart();
}


void CDAParametre::on_IDC_SCREENTAB_clicked()
{
    objParametre->setScreenTouch();
}

void CDAParametre::on_IDC_INSTALLCOPILOTE_clicked()
{
    objOpenSoft->openTiger();
}
