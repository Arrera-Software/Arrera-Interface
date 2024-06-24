#include "carrerainterfacesetting.h"
#include "ui_carrerainterfacesetting.h"

CArreraInterfaceSetting::CArreraInterfaceSetting(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CArreraInterfaceSetting)
{
    ui->setupUi(this);
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
