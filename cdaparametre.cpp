#include "cdaparametre.h"
#include "ui_cdaparametre.h"

CDAParametre::CDAParametre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CDAParametre)
{
    ui->setupUi(this);
}

CDAParametre::~CDAParametre()
{
    delete ui;
}
