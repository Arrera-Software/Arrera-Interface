#include "arreraui.h"
#include "ui_arreraui.h"

ArreraUI::ArreraUI(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ArreraUI)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
    // Objet
    QString confFile = "config.ini";
    QString tigerConf = "tiger.json";
    objSetting = new CAInterfaceSetting(confFile,tigerConf);
    // Recuperation ID de widget
    idPageI2025Main = ui->I2025->indexOf(ui->main);
    idPageI2025App = ui->I2025->indexOf(ui->app);
    idPageI2025Mode = ui->I2025->indexOf(ui->mode);
    idPageI2025ArreraApp = ui->I2025->indexOf(ui->arreraApp);
    // Affichage du bon widget au demarage
    ui->I2025->setCurrentIndex(idPageI2025Main);
    // Changement du texte du label LINDICATIONARRERA
    ui->LINDICATIONARRERA->setText("Bienvenue sur Arrera I2025");
    // Mise en place d'une image de fond pour l'affichage main
    ui->TASKBARMAIN->setObjectName("MainWidget");
    ui->TASKBARMAIN->setStyleSheet("#MainWidget {"
                            "border: 2px solid black;"
                            "border-radius: 15px;"
                            "}");
    ui->FBUREAUTIQUEAPP->setObjectName("MainWidget");
    ui->FBUREAUTIQUEAPP->setStyleSheet("#MainWidget {"
                                        "border: 2px solid black;"
                                        "border-radius: 15px;"
                                       "}");

}

ArreraUI::~ArreraUI()
{
    delete ui;
}

void ArreraUI::on_IDC_ACCEUILARRERA_clicked() // Bouton Arrera en haut a gauche
{
    int currentIndex = ui->I2025->currentIndex();

    if (currentIndex != idPageI2025Main)
    {
        ui->I2025->setCurrentIndex(idPageI2025Main);
        ui->LINDICATIONARRERA->setText("Arrera I2025");
    }
    else
    {
        ui->I2025->setCurrentIndex(idPageApropos);
        ui->LINDICATIONARRERA->setText("Arrera I2025 A propos");
    }
}


void ArreraUI::on_IDC_APPBUREAU_clicked()
{
    // Boutton pour afficher les Application enregistrer par l'utilisateur
    ui->I2025->setCurrentIndex(idPageI2025App);
    ui->LINDICATIONARRERA->setText("Page application de l'ordinateur");
}


void ArreraUI::on_IDC_ARRERAAPP_clicked()
{
    ui->I2025->setCurrentIndex(idPageI2025ArreraApp);
    ui->LINDICATIONARRERA->setText("Page module Arrera");
}



// Partie Apropos
void ArreraUI::on_IDC_SOURCECODE_clicked()
{
    QUrl url("https://github.com/Arrera-Software/Arrera-Interface");
    QDesktopServices::openUrl(url);
}


void ArreraUI::on_IDC_WEBSITE_clicked()
{
    QUrl url("https://www.arrera-software.fr/");
    QDesktopServices::openUrl(url);
}

