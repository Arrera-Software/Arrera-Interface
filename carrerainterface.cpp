#include "carrerainterface.h"
#include "ui_carrerainterface.h"

CArreraInterface::CArreraInterface(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CArreraInterface)
{
    ui->setupUi(this);
}

CArreraInterface::~CArreraInterface()
{
    delete ui;
}
