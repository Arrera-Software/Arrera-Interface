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
    objSoftware.setObjPara(&objPara);
    winPara->passObjPara(&objPara,&objSoftware);
    connect(this,&CArreraUI::destroyed,winPara,&CArreraUI::close);
    connect(this,&CArreraUI::destroyed,winAPP,&CArreraUI::close);
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
    QString nameMode1,nameMode2,nameMode3,nameMode4,nameMode5,nameUser;
    objPara.loadSetting();
    nameUser = QString::fromStdString(objPara.getNameUser());
    nameMode1 = QString::fromStdString(objPara.getNameMode1());
    nameMode2 = QString::fromStdString(objPara.getNameMode2());
    nameMode3 = QString::fromStdString(objPara.getNameMode3());
    nameMode4 = QString::fromStdString(objPara.getNameMode4());
    nameMode5 = QString::fromStdString(objPara.getNameMode5());
    ui->IDC_LABELUSER->setText("Utilisateur : "+nameUser);
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

void CArreraUI::errorOpenSoft()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Erreur");
    msgBox.setText("Une erreur ces produite lors de l'ouverture du logiciel");
    msgBox.addButton(QMessageBox::Ok);
}
