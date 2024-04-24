#include "carrerainterface.h"
#include "ui_carrerainterface.h"

CArreraInterface::CArreraInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CArreraInterface)
{
    ui->setupUi(this);
    winPostite = new CArreraPostite(this);
    winLib = new CArreraApplicationDrawer(this,winPostite);
    connect(this,&CArreraInterface::destroyed,winPostite,&CArreraInterface::close);
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

