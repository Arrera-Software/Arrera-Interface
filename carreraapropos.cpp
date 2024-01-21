#include "carreraapropos.h"
#include <QDesktopServices>
#include "./ui_carreraapropos.h"

CArreraApropos::CArreraApropos(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CArreraApropos)
{
    ui->setupUi(this);
}

CArreraApropos::~CArreraApropos()
{
    delete ui;
}

void CArreraApropos::on_IDC_SOURCE_clicked()
{
    QDesktopServices::openUrl(QUrl("https://github.com/Arrera-Software/Arrera-Interface"));

}


void CArreraApropos::on_IDC_QUIT_clicked()
{
    close();
}

