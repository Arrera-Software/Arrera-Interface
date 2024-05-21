#include "carrerainterface.h"
#include "ui_carrerainterface.h"

CArreraInterface::CArreraInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CArreraInterface)
{
    ui->setupUi(this);
    mainPageIndex = ui->PagesArrera->indexOf(ui->Mainpage);
    libIndex =  ui->PagesArrera->indexOf(ui->ArreraLibPage);
    PostiteIndex = ui->PagesArrera->indexOf(ui->PostitePage);
    ui->PagesArrera->setCurrentIndex(mainPageIndex);
}

CArreraInterface::~CArreraInterface()
{
    delete ui;
}

// Librairy

void CArreraInterface::on_IDC_DRAWERAPP_clicked()
{
    ui->PagesArrera->setCurrentIndex(libIndex);
}


void CArreraInterface::on_IDC_LIBEXIT_clicked()
{
    ui->PagesArrera->setCurrentIndex(mainPageIndex);
}


void CArreraInterface::on_IDC_SOFTPRESENTATION_clicked()
{

}


void CArreraInterface::on_IDC_SOFTTABLEUR_clicked()
{

}


void CArreraInterface::on_IDC_SOFTTEXTE_clicked()
{

}


void CArreraInterface::on_IDC_SOFTPENSEBETE_clicked()
{
    ui->PagesArrera->setCurrentIndex(PostiteIndex);
}


void CArreraInterface::on_IDC_SOFTNAVIGATEUR_clicked()
{

}

// Postite
void CArreraInterface::on_IDC_POSTITEEXIT_clicked()
{
    if(!ui->ZONETEXTE->toPlainText().isEmpty())
    {
        ui->ZONETEXTE->clear();
        ui->PagesArrera->setCurrentIndex(mainPageIndex);
    }
    else
    {
        ui->PagesArrera->setCurrentIndex(mainPageIndex);
    }
}


void CArreraInterface::on_IDC_OUVRIR_clicked()
{
    QString contenu;
    QString nomFichier ;
    nomFichier = QFileDialog::getOpenFileName(this,
                                              "Choisir un fichier à ouvrir",
                                              QDir::homePath(), "Fichier Pense-bete (*.ab)");
    QFile fichier(nomFichier);
    if (fichier.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&fichier);
        contenu = in.readAll();
        fichier.close();
        ui->ZONETEXTE->setPlainText(contenu);
    }
}


void CArreraInterface::on_IDC_SAVE_clicked()
{
    QString contenuTextEdit;
    QString nomFichier ;
    nomFichier=QFileDialog::getSaveFileName(nullptr,
                                              "Enregistrer le fichier", QDir::homePath(), "Fichier Pense-bete (*.ab)");
    QFile file(nomFichier);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        contenuTextEdit = ui->ZONETEXTE->toPlainText();
        out << contenuTextEdit ;
        QMessageBox::StandardButton reponse = QMessageBox::question(this,
                                                                    "Continuer l'édition ?", "Voulez-vous continuer à éditer ?",
                                                                    QMessageBox::Yes | QMessageBox::No);
        if (reponse == QMessageBox::No)
        {
            ui->ZONETEXTE->clear();
        }
        file.close();
    }
}

