#include "cdaparaarreralib.h"
#include "ui_cdaparaarreralib.h"

CDAparaArreraLib::CDAparaArreraLib(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CDAparaArreraLib)
{
    ui->setupUi(this);
}

CDAparaArreraLib::~CDAparaArreraLib()
{
    delete ui;
}
