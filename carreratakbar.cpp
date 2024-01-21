#include "carreratakbar.h"
#include "ui_carreratakbar.h"

CArreraTakbar::CArreraTakbar(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CArreraTakbar)
{
    ui->setupUi(this);
}

CArreraTakbar::~CArreraTakbar()
{
    delete ui;
}

void CArreraTakbar::on_IDC_APP1_clicked()
{

}


void CArreraTakbar::on_IDC_APP2_clicked()
{

}


void CArreraTakbar::on_IDC_APP3_clicked()
{

}


void CArreraTakbar::on_IDC_APP4_clicked()
{

}


void CArreraTakbar::on_IDC_APP5_clicked()
{

}


void CArreraTakbar::on_IDC_QUIT_clicked()
{
    close();
}

