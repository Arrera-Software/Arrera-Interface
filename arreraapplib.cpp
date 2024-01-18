#include "arreraapplib.h"
#include "ui_arreraapplib.h"

ArreraAppLib::ArreraAppLib(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ArreraAppLib)
{
    ui->setupUi(this);
    ui->FARRERAAPP->setVisible(false);
    ui->IDC_BTNAPP->setVisible(false);
    ui->FAPP->setVisible(true);
    ui->IDC_BTNARRERAAPP->setVisible(true);
}

void ArreraAppLib::passArreraPara(CArreraSetting *para)
{
    parametreArrera = para;
}

void ArreraAppLib::updateBTN()
{
    ui->IDC_BTNAPP1->setText(parametreArrera->getNameApp(1).c_str());
    ui->IDC_BTNAPP2->setText(parametreArrera->getNameApp(2).c_str());
    ui->IDC_BTNAPP3->setText(parametreArrera->getNameApp(3).c_str());
    ui->IDC_BTNAPP4->setText(parametreArrera->getNameApp(4).c_str());
    ui->IDC_BTNAPP5->setText(parametreArrera->getNameApp(5).c_str());
    ui->IDC_BTNAPP6->setText(parametreArrera->getNameApp(6).c_str());
    ui->IDC_BTNAPP7->setText(parametreArrera->getNameApp(7).c_str());
    ui->IDC_BTNAPP8->setText(parametreArrera->getNameApp(8).c_str());
    ui->IDC_BTNAPP9->setText(parametreArrera->getNameApp(9).c_str());
    ui->IDC_BTNAPP10->setText(parametreArrera->getNameApp(10).c_str());
    ui->IDC_BTNAPP11->setText(parametreArrera->getNameApp(11).c_str());
    ui->IDC_BTNAPP12->setText(parametreArrera->getNameApp(11).c_str());
}

ArreraAppLib::~ArreraAppLib()
{
    delete ui;
}
// btn bottom bar
void ArreraAppLib::on_IDC_BTNAPP_clicked()
{
    ui->FARRERAAPP->setVisible(false);
    ui->IDC_BTNAPP->setVisible(false);
    ui->FAPP->setVisible(true);
    ui->IDC_BTNARRERAAPP->setVisible(true);
}


void ArreraAppLib::on_IDC_BTNARRERAAPP_clicked()
{
    ui->FARRERAAPP->setVisible(true);
    ui->IDC_BTNAPP->setVisible(true);
    ui->FAPP->setVisible(false);
    ui->IDC_BTNARRERAAPP->setVisible(false);
}

// btn App
void ArreraAppLib::on_IDC_BTNAPP1_clicked()
{

}


void ArreraAppLib::on_IDC_BTNAPP2_clicked()
{

}


void ArreraAppLib::on_IDC_BTNAPP3_clicked()
{

}


void ArreraAppLib::on_IDC_BTNAPP4_clicked()
{

}


void ArreraAppLib::on_IDC_BTNAPP5_clicked()
{

}


void ArreraAppLib::on_IDC_BTNAPP6_clicked()
{

}


void ArreraAppLib::on_IDC_BTNAPP7_clicked()
{

}


void ArreraAppLib::on_IDC_BTNAPP8_clicked()
{

}


void ArreraAppLib::on_IDC_BTNAPP9_clicked()
{

}


void ArreraAppLib::on_IDC_BTNAPP10_clicked()
{

}


void ArreraAppLib::on_IDC_BTNAPP11_clicked()
{

}


void ArreraAppLib::on_IDC_BTNAPP12_clicked()
{

}

//btn app arrera
void ArreraAppLib::on_IDC_BTNAVIDEO_clicked()
{

}


void ArreraAppLib::on_IDC_BTNADOC_clicked()
{

}


void ArreraAppLib::on_IDC_BTNAINFO_clicked()
{

}


void ArreraAppLib::on_IDC_BTNARECHERCHE_clicked()
{

}

