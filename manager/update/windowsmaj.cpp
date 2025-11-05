#include "windowsmaj.h"
#include "ui_windowsmaj.h"

WindowsMaj::WindowsMaj(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WindowsMaj)
{
    ui->setupUi(this);
}

WindowsMaj::~WindowsMaj()
{
    delete ui;
}
