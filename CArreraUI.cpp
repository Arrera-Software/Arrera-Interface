#include "CArreraUI.h"
#include "./ui_CArreraUI.h"

CArreraUI::CArreraUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CArreraUI)
{
    ui->setupUi(this);
}

CArreraUI::~CArreraUI()
{
    delete ui;
}

