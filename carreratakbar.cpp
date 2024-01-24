#include "carreratakbar.h"
#include "ui_carreratakbar.h"

CArreraTakbar::CArreraTakbar(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CArreraTakbar)
{
    ui->setupUi(this);
}

void CArreraTakbar::passObj(CArreraSetting* p,CArreraOpenSoft* o){
    objPara = p;
    openObj = o;
}

void CArreraTakbar::loadPara(int mode)
{
    string sortiePara[5];
    sortiePara[0] = objPara->getNbAppTaskbar(1,mode);
    sortiePara[1] = objPara->getNbAppTaskbar(2,mode);
    sortiePara[2] = objPara->getNbAppTaskbar(3,mode);
    sortiePara[3] = objPara->getNbAppTaskbar(4,mode);
    sortiePara[4] = objPara->getNbAppTaskbar(4,mode);
    if ((sortiePara[0]=="nothing")||(sortiePara[0]==""))
    {
        ui->IDC_APP1->setVisible(false);
        nbApp[0]=0;
    }
    else
    {
        ui->IDC_APP1->setVisible(true);
        ui->IDC_APP1->setText(objPara->getNameApp(stoi(sortiePara[0])).c_str());
        nbApp[0]=stoi(sortiePara[0]);
    }
    if ((sortiePara[1]=="nothing")||(sortiePara[1]==""))
    {
        ui->IDC_APP2->setVisible(false);
        nbApp[1]=0;
    }
    else
    {
        ui->IDC_APP2->setVisible(true);
        ui->IDC_APP2->setText(objPara->getNameApp(stoi(sortiePara[1])).c_str());
        nbApp[1]=stoi(sortiePara[1]);
    }
    if ((sortiePara[2]=="nothing")||(sortiePara[2]==""))
    {
        ui->IDC_APP3->setVisible(false);
        nbApp[2]=0;
    }
    else
    {
        ui->IDC_APP3->setVisible(true);
        ui->IDC_APP3->setText(objPara->getNameApp(stoi(sortiePara[2])).c_str());
        nbApp[2]=stoi(sortiePara[2]);
    }
    if ((sortiePara[3]=="nothing")||(sortiePara[3]==""))
    {
        ui->IDC_APP4->setVisible(false);
        nbApp[3]=0;
    }
    else
    {
        ui->IDC_APP4->setVisible(true);
        ui->IDC_APP4->setText(objPara->getNameApp(stoi(sortiePara[3])).c_str());
        nbApp[3]=stoi(sortiePara[3]);
    }
    if ((sortiePara[4]=="nothing")||(sortiePara[4]==""))
    {
        ui->IDC_APP5->setVisible(false);
        nbApp[4]=0;
    }
    else
    {
        ui->IDC_APP5->setVisible(true);
        ui->IDC_APP5->setText(objPara->getNameApp(stoi(sortiePara[4])).c_str());
        nbApp[4]=stoi(sortiePara[4]);
    }
}

CArreraTakbar::~CArreraTakbar()
{
    delete ui;
}

void CArreraTakbar::on_IDC_APP1_clicked()
{
    if (nbApp[0]!=0)
    {
        openObj->openAppLib(nbApp[0]);
    }
}


void CArreraTakbar::on_IDC_APP2_clicked()
{
    if (nbApp[1]!=0)
    {
        openObj->openAppLib(nbApp[1]);
    }
}


void CArreraTakbar::on_IDC_APP3_clicked()
{
    if (nbApp[2]!=0)
    {
        openObj->openAppLib(nbApp[2]);
    }
}


void CArreraTakbar::on_IDC_APP4_clicked()
{
    if (nbApp[3]!=0)
    {
        openObj->openAppLib(nbApp[3]);
    }
}


void CArreraTakbar::on_IDC_APP5_clicked()
{
    if (nbApp[4]!=0)
    {
        openObj->openAppLib(nbApp[4]);
    }
}


void CArreraTakbar::on_IDC_QUIT_clicked()
{
    close();
}

