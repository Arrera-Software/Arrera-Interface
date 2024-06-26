#include "carrerainterfacesetting.h"
#include "ui_carrerainterfacesetting.h"

CArreraInterfaceSetting::CArreraInterfaceSetting(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CArreraInterfaceSetting)
{
    ui->setupUi(this);
    mainAcceuil = ui->Main->indexOf(ui->Acceuil);
    widgetApp = ui->Main->indexOf(ui->App);
    acceuilApp = ui->PartieApp->indexOf(ui->AcceuilApp);
    ui->Main->setCurrentIndex(mainAcceuil);
    ui->Main->setCurrentIndex(mainAcceuil);
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

}


void CArreraInterfaceSetting::on_IDC_BACKAPPADDNAME_clicked()
{

}

// Partie Add App lnk emplacement

// Windows

void CArreraInterfaceSetting::on_IDC_WINDOWSMENU_clicked()
{

}


void CArreraInterfaceSetting::on_IDC_USERMENU_clicked()
{

}


void CArreraInterfaceSetting::on_IDC_BACKAPPADD_clicked()
{

}

// Linux

void CArreraInterfaceSetting::on_IDC_OPENCHOIXAPPLINUX_clicked()
{

}


void CArreraInterfaceSetting::on_IDC_BACKCHOIXAPPLINUX_clicked()
{

}

