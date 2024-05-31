#include "arreraapplib.h"
#include "ui_arreraapplib.h"

ArreraAppLib::ArreraAppLib(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ArreraAppLib)
{
    ui->setupUi(this);
    ui->FARRERAAPP->setVisible(false);
    ui->FUTILITY->setVisible(false);
    ui->IDC_BTNAPP->setVisible(false);
    ui->FAPP->setVisible(true);
    ui->IDC_BTNARRERAAPP->setVisible(true);
}

void ArreraAppLib::passObjet(CArreraSetting *para,CArreraOpenSoft *objOpen)
{
    parametreArrera = para;
    arreraOpen = objOpen;
}

void ArreraAppLib::updateBTN()
{
    QString nameAPP[12];
    int i ;
    for (i=0;i<=11;i++)
    {
        nameAPP[i] = parametreArrera->getNameApp(i+1).c_str();
    }
    if (nameAPP[0]=="nothing")
    {
        ui->IDC_BTNAPP1->setVisible(false);
    }
    else
    {
        ui->IDC_BTNAPP1->setVisible(true);
        ui->IDC_BTNAPP1->setText(nameAPP[0]);
    }
    if (nameAPP[1]=="nothing")
    {
        ui->IDC_BTNAPP2->setVisible(false);
    }
    else
    {
        ui->IDC_BTNAPP2->setVisible(true);
        ui->IDC_BTNAPP2->setText(nameAPP[1]);
    }
    if (nameAPP[2]=="nothing")
    {
        ui->IDC_BTNAPP3->setVisible(false);
    }
    else
    {
        ui->IDC_BTNAPP3->setVisible(true);
        ui->IDC_BTNAPP3->setText(nameAPP[2]);
    }
    if (nameAPP[3]=="nothing")
    {
        ui->IDC_BTNAPP4->setVisible(false);
    }
    else
    {
        ui->IDC_BTNAPP4->setVisible(true);
        ui->IDC_BTNAPP4->setText(nameAPP[3]);
    }

    if (nameAPP[4]=="nothing")
    {
        ui->IDC_BTNAPP5->setVisible(false);
    }
    else
    {
        ui->IDC_BTNAPP5->setVisible(true);
        ui->IDC_BTNAPP5->setText(nameAPP[4]);
    }
    if (nameAPP[5]=="nothing")
    {
        ui->IDC_BTNAPP6->setVisible(false);
    }
    else
    {
        ui->IDC_BTNAPP6->setVisible(true);
        ui->IDC_BTNAPP6->setText(nameAPP[5]);
    }
    if (nameAPP[6]=="nothing")
    {
        ui->IDC_BTNAPP7->setVisible(false);
    }
    else
    {
        ui->IDC_BTNAPP7->setVisible(true);
        ui->IDC_BTNAPP7->setText(nameAPP[6]);
    }
    if (nameAPP[7]=="nothing")
    {
        ui->IDC_BTNAPP8->setVisible(false);
    }
    else
    {
        ui->IDC_BTNAPP8->setVisible(true);
        ui->IDC_BTNAPP8->setText(nameAPP[7]);
    }

    if (nameAPP[8]=="nothing")
    {
        ui->IDC_BTNAPP9->setVisible(false);
    }
    else
    {
        ui->IDC_BTNAPP9->setVisible(true);
        ui->IDC_BTNAPP9->setText(nameAPP[8]);
    }
    if (nameAPP[9]=="nothing")
    {
        ui->IDC_BTNAPP10->setVisible(false);
    }
    else
    {
        ui->IDC_BTNAPP10->setVisible(true);
        ui->IDC_BTNAPP10->setText(nameAPP[9]);
    }
    if (nameAPP[10]=="nothing")
    {
        ui->IDC_BTNAPP11->setVisible(false);
    }
    else
    {
        ui->IDC_BTNAPP11->setVisible(true);
        ui->IDC_BTNAPP11->setText(nameAPP[10]);
    }
    if (nameAPP[11]=="nothing")
    {
        ui->IDC_BTNAPP12->setVisible(false);
    }
    else
    {
        ui->IDC_BTNAPP12->setVisible(true);
        ui->IDC_BTNAPP12->setText(nameAPP[11]);
    }
    if ((nameAPP[0]=="nothing")&&(nameAPP[1]=="nothing")&&(nameAPP[2]=="nothing")&&(nameAPP[3]=="nothing")&&(nameAPP[4]=="nothing")&&(nameAPP[5]=="nothing")&&(nameAPP[6]=="nothing")&&(nameAPP[7]=="nothing")&&(nameAPP[8]=="nothing")&&(nameAPP[9]=="nothing")&&(nameAPP[10]=="nothing")&&(nameAPP[11]=="nothing"))
    {
        ui->FNOAPP->setVisible(true);
    }
    else
    {
        ui->FNOAPP->setVisible(false);
    }
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
    ui->FUTILITY->setVisible(false);
    ui->IDC_BTNARRERAAPP->setVisible(true);
    ui->IDC_BTNUTILITY->setVisible(true);
    updateBTN();
}


void ArreraAppLib::on_IDC_BTNARRERAAPP_clicked()
{
    ui->FARRERAAPP->setVisible(true);
    ui->IDC_BTNAPP->setVisible(true);
    ui->FUTILITY->setVisible(false);
    ui->FAPP->setVisible(false);
    ui->IDC_BTNARRERAAPP->setVisible(false);
    ui->FNOAPP->setVisible(false);
    ui->IDC_BTNUTILITY->setVisible(true);
}

// btn App
void ArreraAppLib::on_IDC_BTNAPP1_clicked()
{
    arreraOpen->openAppLib(1);
}


void ArreraAppLib::on_IDC_BTNAPP2_clicked()
{
    arreraOpen->openAppLib(2);
}


void ArreraAppLib::on_IDC_BTNAPP3_clicked()
{
    arreraOpen->openAppLib(3);
}


void ArreraAppLib::on_IDC_BTNAPP4_clicked()
{
    arreraOpen->openAppLib(4);
}


void ArreraAppLib::on_IDC_BTNAPP5_clicked()
{
    arreraOpen->openAppLib(5);
}


void ArreraAppLib::on_IDC_BTNAPP6_clicked()
{
    arreraOpen->openAppLib(6);
}


void ArreraAppLib::on_IDC_BTNAPP7_clicked()
{
    arreraOpen->openAppLib(7);
}


void ArreraAppLib::on_IDC_BTNAPP8_clicked()
{
    arreraOpen->openAppLib(8);
}


void ArreraAppLib::on_IDC_BTNAPP9_clicked()
{
    arreraOpen->openAppLib(9);
}


void ArreraAppLib::on_IDC_BTNAPP10_clicked()
{
    arreraOpen->openAppLib(10);
}


void ArreraAppLib::on_IDC_BTNAPP11_clicked()
{
    arreraOpen->openAppLib(11);
}


void ArreraAppLib::on_IDC_BTNAPP12_clicked()
{
    arreraOpen->openAppLib(12);
}

//btn app arrera
void ArreraAppLib::on_IDC_BTNAVIDEO_clicked()
{
    arreraOpen->openArreraApp(1);
}


void ArreraAppLib::on_IDC_BTNADOC_clicked()
{
    arreraOpen->openArreraApp(2);
}


void ArreraAppLib::on_IDC_BTNAINFO_clicked()
{
    arreraOpen->openArreraApp(3);
}


void ArreraAppLib::on_IDC_BTNARECHERCHE_clicked()
{
    arreraOpen->openArreraApp(4);
}

// Zone utility

void ArreraAppLib::on_IDC_BTNUTILITY_clicked()
{
    ui->FARRERAAPP->setVisible(false);
    ui->IDC_BTNAPP->setVisible(true);
    ui->FAPP->setVisible(false);
    ui->FUTILITY->setVisible(true);
    ui->IDC_BTNARRERAAPP->setVisible(true);
    ui->IDC_BTNUTILITY->setVisible(false);
    ui->FNOAPP->setVisible(false);
}


void ArreraAppLib::on_IDC_BTNVM_clicked()
{

}


void ArreraAppLib::on_IDC_BTNSCREENTAB_clicked()
{

}

