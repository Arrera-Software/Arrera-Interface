#include "cdaparametre.h"
#include "ui_cdaparametre.h"

CDAParametre::CDAParametre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CDAParametre)
{
    ui->setupUi(this);
    modeSelectionner = 0 ;
    ui->IDC_MODESELECT->setText("Mode selectionner : Aucun");
}

CDAParametre::~CDAParametre()
{
    delete ui;
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

}

