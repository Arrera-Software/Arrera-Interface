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
    ui->mainstacked->setCurrentIndex(idModePage);
    ui->modestacked->setCurrentIndex(idMainModePage);
}
