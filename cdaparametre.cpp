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
    ui->IDC_ARRERATASKBAR->setChecked(false);
}

CDAParametre::~CDAParametre()
{
    delete ui;
}

void CDAParametre::passObjPara(CArreraSetting* obj,CArreraOpenSoft *objSoft)
{
    objParametre = obj ;
    objOpenSoft = objSoft;

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
}


void CDAParametre::on_IDC_GESTMODE2_clicked()
{
    modeSelectionner = 2 ;
    ui->IDC_MODESELECT->setText("Mode selectionner : Mode 2");
}


void CDAParametre::on_IDC_GESTMODE3_clicked()
{
    modeSelectionner = 3 ;
    ui->IDC_MODESELECT->setText("Mode selectionner : Mode 3");
}


void CDAParametre::on_IDC_GESTMODE4_clicked()
{
    modeSelectionner = 4 ;
    ui->IDC_MODESELECT->setText("Mode selectionner : Mode 4");
}


void CDAParametre::on_IDC_GESTMODE5_clicked()
{
    modeSelectionner = 5;
    ui->IDC_MODESELECT->setText("Mode selectionner : Mode 5");
}


void CDAParametre::on_IDC_VALIDER_clicked()
{
    QMessageBox msgBox;
    bool sortieEcriture,arreraTaskBar;
    QString valeurGUI ;
    string valeurString;
    sortieRyley = ui->IDC_CHOIXRYLEY->isChecked();
    sortieSix = ui->IDC_CHOIXSIX->isChecked();
    arreraTaskBar = ui->IDC_ARRERATASKBAR->isChecked();
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
                sortieEcriture = objParametre->setNameMode(1,valeurString);
                sortieEcriture = objParametre->setAssistantMode(1,sortieRyley,sortieSix);
                sortieEcriture = objParametre->setEtatTaskbar(1,arreraTaskBar);
                break;
            case 2 :
                valeurGUI = ui->IDC_NAMETEXT->toPlainText();
                valeurString = valeurGUI.toStdString();
                sortieEcriture =objParametre->setNameMode(2,valeurString);
                sortieEcriture = objParametre->setAssistantMode(2,sortieRyley,sortieSix);
                sortieEcriture = objParametre->setEtatTaskbar(2,arreraTaskBar);
                break;
            case 3 :
                valeurGUI = ui->IDC_NAMETEXT->toPlainText();
                valeurString = valeurGUI.toStdString();
                sortieEcriture =objParametre->setNameMode(3,valeurString);
                sortieEcriture = objParametre->setAssistantMode(3,sortieRyley,sortieSix);
                sortieEcriture = objParametre->setEtatTaskbar(3,arreraTaskBar);
                break;
            case 4 :
                valeurGUI = ui->IDC_NAMETEXT->toPlainText();
                valeurString = valeurGUI.toStdString();
                sortieEcriture =objParametre->setNameMode(4,valeurString);
                sortieEcriture = objParametre->setAssistantMode(4,sortieRyley,sortieSix);
                sortieEcriture = objParametre->setEtatTaskbar(4,arreraTaskBar);
                break;
            case 5 :
                valeurGUI = ui->IDC_NAMETEXT->toPlainText();
                valeurString = valeurGUI.toStdString();
                sortieEcriture = objParametre->setNameMode(5,valeurString);
                sortieEcriture = objParametre->setAssistantMode(5,sortieRyley,sortieSix);
                sortieEcriture = objParametre->setEtatTaskbar(5,arreraTaskBar);
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
        ui->IDC_CHOIXSIX->setChecked(true);
        ui->IDC_ARRERATASKBAR->setChecked(false);
        ui->IDC_MODESELECT->setText("Mode selectionner : Aucun");
        modeSelectionner = 0 ;
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

