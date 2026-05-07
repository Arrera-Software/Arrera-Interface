#include "windowsmaj.h"
#include "ui_windowsmaj.h"

WindowsMaj::WindowsMaj(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WindowsMaj)
{
    ui->setupUi(this);
}

void WindowsMaj::set_new_version(QString new_version){
    ui->IDC_TITLE->setText("La version " +new_version+ " d'Arrera est disponible");
}

WindowsMaj::~WindowsMaj()
{
    delete ui;
}

void WindowsMaj::on_IDC_CONTINUE_clicked()
{
    this->close();
}

