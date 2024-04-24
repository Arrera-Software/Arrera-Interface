#include "carreraapplicationdrawer.h"
#include "ui_carreraapplicationdrawer.h"

CArreraApplicationDrawer::CArreraApplicationDrawer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CArreraApplicationDrawer)
{
    ui->setupUi(this);
}

CArreraApplicationDrawer::~CArreraApplicationDrawer()
{
    delete ui;
}

void CArreraApplicationDrawer::on_IDC_SOFTPRESENTATION_clicked()
{
    close();
}


void CArreraApplicationDrawer::on_IDC_SOFTTABLEUR_clicked()
{
    close();
}


void CArreraApplicationDrawer::on_IDC_SOFTPENSEBETE_clicked()
{
    close();
}


void CArreraApplicationDrawer::on_IDC_SOFTTEXTE_clicked()
{
    close();
}


void CArreraApplicationDrawer::on_IDC_SOFTNAVIGATEUR_clicked()
{
    close();
}

