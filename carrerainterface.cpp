#include "carrerainterface.h"
#include "ui_carrerainterface.h"

CArreraInterface::CArreraInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CArreraInterface)
{
    ui->setupUi(this);

}

CArreraInterface::~CArreraInterface()
{
    delete ui;
}
