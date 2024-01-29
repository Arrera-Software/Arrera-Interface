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
    winParaApp = new CDAparaArreraLib(this);
    taskBarModeEnable = false;
    connect(this,&CDAParametre::destroyed,winParaApp,&CDAParametre::close);
    ui->FGESTMODE->setVisible(false);
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

void CDAParametre::closeEvent(QCloseEvent *event) {
    // Ajoutez votre logique de fermeture spécifique à la fenêtre enfant ici

    // Appeler la méthode closeEvent de la classe de base pour effectuer la fermeture par défaut
    QDialog::closeEvent(event);
}

void CDAParametre::on_IDC_GESTMODE1_clicked()
{
    modeSelectionner = 1 ;
    ui->IDC_MODESELECT->setText("Mode selectionner : Mode 1");
    ui->FGESTMODE->setVisible(true);
    ui->FALLMODE->setVisible(false);
}


void CDAParametre::on_IDC_GESTMODE2_clicked()
{
    modeSelectionner = 2 ;
    ui->IDC_MODESELECT->setText("Mode selectionner : Mode 2");
    ui->FGESTMODE->setVisible(true);
    ui->FALLMODE->setVisible(false);
}


void CDAParametre::on_IDC_GESTMODE3_clicked()
{
    modeSelectionner = 3 ;
    ui->IDC_MODESELECT->setText("Mode selectionner : Mode 3");
    ui->FGESTMODE->setVisible(true);
    ui->FALLMODE->setVisible(false);
}


void CDAParametre::on_IDC_GESTMODE4_clicked()
{
    modeSelectionner = 4 ;
    ui->IDC_MODESELECT->setText("Mode selectionner : Mode 4");
    ui->FGESTMODE->setVisible(true);
    ui->FALLMODE->setVisible(false);
}


void CDAParametre::on_IDC_GESTMODE5_clicked()
{
    modeSelectionner = 5;
    ui->IDC_MODESELECT->setText("Mode selectionner : Mode 5");
    ui->FGESTMODE->setVisible(true);
    ui->FALLMODE->setVisible(false);
}


void CDAParametre::on_IDC_VALIDER_clicked()
{
    QMessageBox msgBox;
    bool sortieEcriture=false,arreraTaskBar;
    QString valeurGUI ;
    string valeurString;
    int nbAppBoot;
    sortieRyley = ui->IDC_CHOIXRYLEY->isChecked();
    sortieSix = ui->IDC_CHOIXSIX->isChecked();
    arreraTaskBar = ui->IDC_RARRERABAR->isChecked();
    nbAppBoot = ui->IDC_NBAPPBOOT->value();
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
                sortieEcriture = objParametre->setAssistantMode(1,sortieRyley,sortieSix);
                sortieEcriture = objParametre->setEtatTaskbar(1,arreraTaskBar);
                sortieEcriture = objParametre->setModeAppAsBoot(1,nbAppBoot);
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
                sortieEcriture = objParametre->setAssistantMode(2,sortieRyley,sortieSix);
                sortieEcriture = objParametre->setEtatTaskbar(2,arreraTaskBar);
                sortieEcriture = objParametre->setModeAppAsBoot(2,nbAppBoot);
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
                sortieEcriture = objParametre->setAssistantMode(3,sortieRyley,sortieSix);
                sortieEcriture = objParametre->setEtatTaskbar(3,arreraTaskBar);
                sortieEcriture = objParametre->setModeAppAsBoot(3,nbAppBoot);
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
                sortieEcriture = objParametre->setAssistantMode(4,sortieRyley,sortieSix);
                sortieEcriture = objParametre->setEtatTaskbar(4,arreraTaskBar);
                sortieEcriture = objParametre->setModeAppAsBoot(4,nbAppBoot);
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
                sortieEcriture = objParametre->setAssistantMode(5,sortieRyley,sortieSix);
                sortieEcriture = objParametre->setEtatTaskbar(5,arreraTaskBar);
                sortieEcriture = objParametre->setModeAppAsBoot(5,nbAppBoot);
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
    ui->FGESTMODE->setVisible(false);
    ui->FALLMODE->setVisible(true);
}

