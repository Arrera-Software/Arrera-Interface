#include "carrerainterface.h"
#include "ui_carrerainterface.h"

CArreraInterface::CArreraInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CArreraInterface)
{
    ui->setupUi(this);
    winLib = new CArreraApplicationDrawer(this);
    connect(this,&CArreraInterface::destroyed,winLib,&CArreraInterface::close);
}

CArreraInterface::~CArreraInterface()
{
    delete ui;
}

void CArreraInterface::on_IDC_DRAWERAPP_clicked()
{
    winLib->show();
}

