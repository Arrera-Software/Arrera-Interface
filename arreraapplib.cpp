#include "arreraapplib.h"
#include "ui_arreraapplib.h"

ArreraAppLib::ArreraAppLib(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ArreraAppLib)
{
    ui->setupUi(this);
}

ArreraAppLib::~ArreraAppLib()
{
    delete ui;
}
