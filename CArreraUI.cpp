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
    winPara->passObjPara(&objPara);
    connect(this,&CArreraUI::destroyed,winPara,&CArreraUI::close);
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

}


void CArreraUI::on_IDC_COPILOTE_clicked()
{

}


void CArreraUI::on_IDC_RYLEY_clicked()
{

}

// bouton mode

void CArreraUI::on_IDC_MODE1_clicked()
{

}


void CArreraUI::on_IDC_MODE2_clicked()
{

}


void CArreraUI::on_IDC_MODE3_clicked()
{

}


void CArreraUI::on_IDC_MODE4_clicked()
{

}


void CArreraUI::on_IDC_MODE5_clicked()
{

}

// Bouton app
void CArreraUI::on_IDC_TABLEUR_clicked()
{

}


void CArreraUI::on_IDC_TRAITEMENT_clicked()
{

}


void CArreraUI::on_IDC_APP_clicked()
{

}


void CArreraUI::on_IDC_NAVIGATEUR_clicked()
{

}


void CArreraUI::on_IDC_PRESENTATION_clicked()
{

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
    objPara.loadSetting();
    nameMode1 = QString::fromStdString(objPara.getNameMode1());
    nameMode2 = QString::fromStdString(objPara.getNameMode2());
    nameMode3 = QString::fromStdString(objPara.getNameMode3());
    nameMode4 = QString::fromStdString(objPara.getNameMode4());
    nameMode5 = QString::fromStdString(objPara.getNameMode5());
    ui->IDC_MODE1->setText(nameMode1);
    ui->IDC_MODE2->setText(nameMode2);
    ui->IDC_MODE3->setText(nameMode3);
    ui->IDC_MODE4->setText(nameMode4);
    ui->IDC_MODE5->setText(nameMode5);
}

void CArreraUI::on_IDC_RELOAD_clicked()
{
    loadSetting();
}

