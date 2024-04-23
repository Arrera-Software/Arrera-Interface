#include "carrerapostite.h"
#include "ui_carrerapostite.h"

CArreraPostite::CArreraPostite(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CArreraPostite)
{
    ui->setupUi(this);
}

CArreraPostite::~CArreraPostite()
{
    delete ui;
}
