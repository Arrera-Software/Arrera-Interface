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
    idGenerauxPage = ui->mainstacked->indexOf(ui->main);
    idAssistantPage= ui->mainstacked->indexOf(ui->main);
    idApplicationPage = ui->mainstacked->indexOf(ui->main);
    idLieuPage = ui->mainstacked->indexOf(ui->main);
    idRecherchePage = ui->mainstacked->indexOf(ui->main);
    // id de modestaked
    idMainModePage = ui->modestacked->indexOf(ui->mainmode);
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
    ui->LINDICATIONSETTING->setText("Arrera I2025 Parametre");
}

void ArreraSettingUI::on_IDC_MODE_clicked()
{
    ui->mainstacked->setCurrentIndex(idModePage);
    ui->modestacked->setCurrentIndex(idMainModePage);
    ui->LINDICATIONSETTING->setText("Parametre des modes");
}


void ArreraSettingUI::on_IDC_GENERAUX_clicked()
{

}


void ArreraSettingUI::on_IDC_ASSISTANT_clicked()
{

}


void ArreraSettingUI::on_IDC_APPLICATION_clicked()
{

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

