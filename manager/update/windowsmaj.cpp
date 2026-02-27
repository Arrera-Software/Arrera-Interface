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

void WindowsMaj::on_IDC_MAJ_clicked()
{
    QDesktopServices::openUrl(
        QUrl("https://github.com/Arrera-Software/Arrera-Interface/releases"));
}


void WindowsMaj::on_IDC_CONTINUE_clicked()
{
    this->close();
}

