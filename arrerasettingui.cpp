#include "arrerasettingui.h"
#include "ui_arrerasettingui.h"

ArreraSettingUI::ArreraSettingUI(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ArreraSettingUI)
{
    ui->setupUi(this);
    // Id de mainstaked
    idMainPage = ui->mainstacked->indexOf(ui->main);
    idModePage = ui->mainstacked->indexOf(ui->mode);
    idGenerauxPage = ui->mainstacked->indexOf(ui->generaux);
    idAssistantPage= ui->mainstacked->indexOf(ui->main);
    idApplicationPage = ui->mainstacked->indexOf(ui->application);
    idLieuPage = ui->mainstacked->indexOf(ui->main);
    idRecherchePage = ui->mainstacked->indexOf(ui->main);
    // id de modestaked
    idMainModePage = ui->modestacked->indexOf(ui->mainmode);
    idAddMode = ui->modestacked->indexOf(ui->addmode);
    // id de appstacked
    idMainAppStaked = ui->appstocked->indexOf(ui->mainpcapp);
    idAddAppStacked = ui->appstocked->indexOf(ui->addpcapp);
    idSupprAppStacked = ui->appstocked->indexOf(ui->supprpcapp);
    // Mise en place des item sur le IDC_LISTASSISTANTMODE
    ui->IDC_LISTASSISTANTMODE->addItem("AUCUN");
    ui->IDC_LISTASSISTANTMODE->addItem("SIX");
    ui->IDC_LISTASSISTANTMODE->addItem("RYLEY");
    ui->IDC_LISTASSISTANTMODE->addItem("COPILOTE");
}

ArreraSettingUI::~ArreraSettingUI()
{
    delete ui;
}

void ArreraSettingUI::closeEvent(QCloseEvent *event)
{
    // Émettre le signal lorsque la fenêtre des paramètres est fermée
    emit parametresFerme();
    QWidget::closeEvent(event);
}

void ArreraSettingUI::show()
{
    QDialog::show();
    ui->mainstacked->setCurrentIndex(idMainPage);
    ui->modestacked->setCurrentIndex(idMainModePage);
    ui->appstocked->setCurrentIndex(idMainAppStaked);
    ui->LINDICATIONSETTING->setText("Arrera I2025 Parametre");
}

void ArreraSettingUI::on_IDC_MODE_clicked()
{
    ui->mainstacked->setCurrentIndex(idModePage);
    ui->modestacked->setCurrentIndex(idMainModePage);
    ui->appstocked->setCurrentIndex(idMainAppStaked);
    ui->LINDICATIONSETTING->setText("Parametre des modes");
}

// Partie Mode
void ArreraSettingUI::on_IDC_GENERAUX_clicked()
{
    ui->LINDICATIONSETTING->setText("Parametre generaux");
    ui->mainstacked->setCurrentIndex(idGenerauxPage);
}


void ArreraSettingUI::on_IDC_ASSISTANT_clicked()
{

}


void ArreraSettingUI::on_IDC_APPLICATION_clicked()
{
    ui->mainstacked->setCurrentIndex(idApplicationPage);
    ui->LINDICATIONSETTING->setText("Parametre des applications");
}


void ArreraSettingUI::on_IDC_LIEU_clicked()
{

}


void ArreraSettingUI::on_IDC_RECHERCHE_clicked()
{

}


void ArreraSettingUI::on_IDC_ACCEUILPARAMETRE_clicked()
{
    int currentIndex = ui->mainstacked->currentIndex();
    if (currentIndex != idMainPage)
    {
        ui->mainstacked->setCurrentIndex(idMainPage);
        ui->LINDICATIONSETTING->setText("Arrera I2025 Parametre");
    }
}


void ArreraSettingUI::on_IDC_BTNMODE1_clicked()
{
    ui->LINDICATIONMODE->setText("Parametrage du Mode 1");
    ui->LINDICATIONSETTING->setText("Parametrage mode 1");
    ui->modestacked->setCurrentIndex(idAddMode);
}


void ArreraSettingUI::on_IDC_BTNMODE2_clicked()
{
    ui->LINDICATIONMODE->setText("Parametrage du Mode 2");
    ui->LINDICATIONSETTING->setText("Parametrage mode 2");
    ui->modestacked->setCurrentIndex(idAddMode);
}


void ArreraSettingUI::on_IDC_BTNMODE3_clicked()
{
    ui->LINDICATIONMODE->setText("Parametrage du Mode 3");
    ui->LINDICATIONSETTING->setText("Parametrage mode 3");
    ui->modestacked->setCurrentIndex(idAddMode);
}


void ArreraSettingUI::on_IDC_BTNMODE4_clicked()
{
    ui->LINDICATIONMODE->setText("Parametrage du Mode 4");
    ui->LINDICATIONSETTING->setText("Parametrage mode 4");
    ui->modestacked->setCurrentIndex(idAddMode);
}


void ArreraSettingUI::on_IDC_BTNMODE5_clicked()
{
    ui->LINDICATIONMODE->setText("Parametrage du Mode 5");
    ui->LINDICATIONSETTING->setText("Parametrage mode 5");
    ui->modestacked->setCurrentIndex(idAddMode);
}


void ArreraSettingUI::on_IDC_BTNMODE6_clicked()
{
    ui->LINDICATIONMODE->setText("Parametrage du Mode 6");
    ui->LINDICATIONSETTING->setText("Parametrage mode 6");
    ui->modestacked->setCurrentIndex(idAddMode);
}


void ArreraSettingUI::on_IDC_VALIDERMODE_clicked()
{

}


void ArreraSettingUI::on_IDC_RETOURMODE_clicked()
{
    ui->LINDICATIONSETTING->setText("Parametre des modes");
    ui->modestacked->setCurrentIndex(idMainModePage);
}


void ArreraSettingUI::on_IDC_RETOURGENERAUXUSER_clicked()
{
    ui->mainstacked->setCurrentIndex(idMainPage);
    ui->LINDICATIONSETTING->setText("Arrera I2025 Parametre");
}


void ArreraSettingUI::on_IDC_VALIDERNAMEUSER_clicked()
{

}


void ArreraSettingUI::on_IDC_ADDAPPPC_clicked()
{
    ui->LINDICATIONSETTING->setText("Ajout d'une application");
    ui->appstocked->setCurrentIndex(idAddAppStacked);
}


void ArreraSettingUI::on_IDC_SUPPRAPPPC_clicked()
{
    ui->LINDICATIONSETTING->setText("Supprimer d'une application");
    ui->appstocked->setCurrentIndex(idSupprAppStacked);
}

void ArreraSettingUI::on_IDC_SETAPPPC_clicked()
{

}


void ArreraSettingUI::on_IDC_ICONAPPPC_clicked()
{

}


void ArreraSettingUI::on_IDC_VALIDERAPPPC_clicked()
{

}


void ArreraSettingUI::on_IDC_CANCELAPPPC_clicked()
{
    ui->LINDICATIONSETTING->setText("Parametre des applications");
    ui->appstocked->setCurrentIndex(idMainAppStaked);
}


void ArreraSettingUI::on_IDC_CANCELSUPPRAPP_clicked()
{
    ui->LINDICATIONSETTING->setText("Parametre des applications");
    ui->appstocked->setCurrentIndex(idMainAppStaked);
}


void ArreraSettingUI::on_IDC_VALIDERSUPRR_clicked()
{
    ui->appstocked->setCurrentIndex(idMainAppStaked);
}




