#include "carrerainterfacesetting.h"
#include "ui_carrerainterfacesetting.h"

CArreraInterfaceSetting::CArreraInterfaceSetting(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CArreraInterfaceSetting)
{
    ui->setupUi(this);
    // Declaration objet OS
    bool linux = objOS.getLinux();
    bool windows = objOS.getWindows();
    // Staked widget Main
    mainAcceuil = ui->Main->indexOf(ui->Acceuil);
    widgetApp = ui->Main->indexOf(ui->App);
    // Staked widget App
    acceuilApp = ui->PartieApp->indexOf(ui->AcceuilApp);
    addAppName = ui->PartieApp->indexOf(ui->AddAppName);
    if (linux)
    {
        addAppChoix = ui->PartieApp->indexOf(ui->AddAppChoixLinux);
    }
    else
    {
        if (windows)
        {
           addAppChoix = ui->PartieApp->indexOf(ui->AddAppChoixWindows);
        }
    }
    // Mise en place des widget
    ui->Main->setCurrentIndex(mainAcceuil);
    ui->PartieApp->setCurrentIndex(acceuilApp);
}

void CArreraInterfaceSetting::passObjSetting(CArreraSetting *s)
{
    objSetting = s ;
}

CArreraInterfaceSetting::~CArreraInterfaceSetting()
{
    delete ui;
}

void CArreraInterfaceSetting::closeEvent(QCloseEvent *event)
{
    // Émettre le signal lorsque la fenêtre des paramètres est fermée
    emit parametresFerme();
    QWidget::closeEvent(event);
}

void CArreraInterfaceSetting::on_IDC_MODE_clicked()
{

}


void CArreraInterfaceSetting::on_IDC_ASSISTANT_clicked()
{

}


void CArreraInterfaceSetting::on_IDC_ARRECHERCHE_clicked()
{

}


void CArreraInterfaceSetting::on_IDC_ARRERAAPP_clicked()
{

}


void CArreraInterfaceSetting::on_IDC_LIEU_clicked()
{

}


void CArreraInterfaceSetting::on_IDC_APPLICATION_clicked()
{
    ui->Main->setCurrentIndex(widgetApp);
    ui->PartieApp->setCurrentIndex(acceuilApp);
}


void CArreraInterfaceSetting::on_IDC_BACKAPPACCEUIL_clicked()
{
    ui->Main->setCurrentIndex(mainAcceuil);
}

// Partie App
void CArreraInterfaceSetting::on_IDC_ADDAPP_clicked()
{
    ui->PartieApp->setCurrentIndex(addAppName);
}


void CArreraInterfaceSetting::on_IDC_SUPP_clicked()
{

}


void CArreraInterfaceSetting::on_IDC_TASKBAR_clicked()
{

}

// Partie Add Name App

void CArreraInterfaceSetting::on_IDC_VALIDERNAMEAPPADD_clicked()
{
    if (ui->IDC_ENTRYNAMEAPP->toPlainText()=="")
    {
        QMessageBox::information(this, "Information : Parametre Arrera", "Imposible d'enregistrer un application sans nom");

    }
    else
    {
        ui->PartieApp->setCurrentIndex(addAppChoix);
    }
}


void CArreraInterfaceSetting::on_IDC_BACKAPPADDNAME_clicked()
{
    ui->IDC_ENTRYNAMEAPP->clear();
    ui->PartieApp->setCurrentIndex(acceuilApp);
}

// Partie Add App lnk emplacement

// Windows

void CArreraInterfaceSetting::on_IDC_WINDOWSMENU_clicked()
{
    QString nameApp = ui->IDC_ENTRYNAMEAPP->toPlainText();
    QString emplacement = QFileDialog::getOpenFileName(nullptr,nameApp,"C:/ProgramData/Microsoft/Windows/Start Menu/Programs"
                                 , "Fichiers de raccourci (*.lnk)");
    ui->IDC_ENTRYNAMEAPP->clear();
    ui->PartieApp->setCurrentIndex(acceuilApp);
    if (emplacement=="")
    {
        QMessageBox::information(this, "Information : Parametre Arrera", "Application non enregister");
    }
    else
    {
        QMessageBox::information(this, "Information : Parametre Arrera", "Application enregister");
    }
}


void CArreraInterfaceSetting::on_IDC_USERMENU_clicked()
{
    QString nameApp = ui->IDC_ENTRYNAMEAPP->toPlainText();
    QString emplacement = QFileDialog::getOpenFileName(nullptr,nameApp,QDir::homePath() +
                                    "/AppData/Roaming/Microsoft/Windows/Start Menu/Programs"
                                 , "Fichiers de raccourci (*.lnk)");
    ui->IDC_ENTRYNAMEAPP->clear();
    ui->PartieApp->setCurrentIndex(acceuilApp);
    if (emplacement=="")
    {
        QMessageBox::information(this, "Information : Parametre Arrera", "Application non enregister");
    }
    else
    {
        QMessageBox::information(this, "Information : Parametre Arrera", "Application enregister");
    }
}


void CArreraInterfaceSetting::on_IDC_BACKAPPADD_clicked()
{
    ui->PartieApp->setCurrentIndex(acceuilApp);
    ui->IDC_ENTRYNAMEAPP->clear();
}

// Linux

void CArreraInterfaceSetting::on_IDC_OPENCHOIXAPPLINUX_clicked()
{

}


void CArreraInterfaceSetting::on_IDC_BACKCHOIXAPPLINUX_clicked()
{
    ui->PartieApp->setCurrentIndex(acceuilApp);
    ui->IDC_ENTRYNAMEAPP->clear();
}

