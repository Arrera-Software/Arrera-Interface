#include "carrerapostite.h"
#include "ui_carrerapostite.h"

CArreraPostite::CArreraPostite(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CArreraPostite)
{
    ui->setupUi(this);
}

CArreraPostite::~CArreraPostite()
{
    delete ui;
}

void CArreraPostite::on_IDC_SAVE_clicked()
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



void CArreraPostite::on_IDC_OUVRIR_clicked()
{

}
