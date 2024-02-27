#include "cdaparaarreralib.h"
#include "ui_cdaparaarreralib.h"

CDAparaArreraLib::CDAparaArreraLib(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CDAparaArreraLib)
{
    ui->setupUi(this);
    clearGestApp();
    nbAppSelect = 0;
    ui->FGESTAPP->setVisible(false);
    ui->FArreraApp->setVisible(false);
    ui->Fapp->setVisible(false);
    ui->FGESTTASKBAR->setVisible(false);
    ui->FHISTORICAPP->setVisible(false);
}
void CDAparaArreraLib::modeApp()
{
    ui->FGESTAPP->setVisible(false);
    ui->FArreraApp->setVisible(true);
    ui->Fapp->setVisible(true);
    ui->FGESTTASKBAR->setVisible(false);
    ui->FHISTORICAPP->setVisible(false);
}
void CDAparaArreraLib::modeTaskbar(int mode)
{
    ui->FGESTAPP->setVisible(false);
    ui->FArreraApp->setVisible(false);
    ui->Fapp->setVisible(false);
    ui->FGESTTASKBAR->setVisible(true);
    ui->FHISTORICAPP->setVisible(false);
    ui->IDC_LRACOURCISELECT->setText("Aucun racourcie selectionner");
    nbRacoucieSelect=0;
    modeSelected = mode;
    qDebug()<<modeSelected;

}
CDAparaArreraLib::~CDAparaArreraLib()
{
    delete ui;
}
//fnc aide gestion

void CDAparaArreraLib::passObjet(CArreraSetting* p)
{
    para = p;
}
void CDAparaArreraLib::clearGestApp()
{
    ui->FGESTAPP->setVisible(false);
    ui->IDC_TEXTAPPNAME->setText("");
    ui->IDC_LAPPSELECTIONNER->setText("");
}

void CDAparaArreraLib::selectApp(int nb)
{
    nbAppSelect = nb;
    ui->IDC_LAPPSELECTIONNER->setText("Application n°"+QString::number(nb));
    ui->FGESTAPP->setVisible(true);
}

void CDAparaArreraLib::viewListAPP(int mode)
{
    ui->FGESTAPP->setVisible(false);
    ui->FArreraApp->setVisible(false);
    ui->Fapp->setVisible(false);
    ui->FGESTTASKBAR->setVisible(false);
    ui->FHISTORICAPP->setVisible(true);

    ui->IDC_RAC1->setText("App n°1 : "+QString::fromStdString(para->getNameApp(1)));
    ui->IDC_RAC2->setText("App n°2 : "+QString::fromStdString(para->getNameApp(2)));
    ui->IDC_RAC3->setText("App n°3 : "+QString::fromStdString(para->getNameApp(3)));
    ui->IDC_RAC4->setText("App n°4 : "+QString::fromStdString(para->getNameApp(4)));
    ui->IDC_RAC5->setText("App n°5 : "+QString::fromStdString(para->getNameApp(5)));
    ui->IDC_RAC6->setText("App n°6 : "+QString::fromStdString(para->getNameApp(6)));
    ui->IDC_RAC7->setText("App n°7 : "+QString::fromStdString(para->getNameApp(7)));
    ui->IDC_RAC8->setText("App n°8 : "+QString::fromStdString(para->getNameApp(8)));
    ui->IDC_RAC9->setText("App n°9 : "+QString::fromStdString(para->getNameApp(9)));
    ui->IDC_RAC10->setText("App n°10 : "+QString::fromStdString(para->getNameApp(10)));
    ui->IDC_RAC11->setText("App n°11 : "+QString::fromStdString(para->getNameApp(11)));
    ui->IDC_RAC12->setText("App n°12 : "+QString::fromStdString(para->getNameApp(12)));

    if (para->getNbAppTaskbar(1,0)=="nothing")
    {
        ui->IDC_TASKRAC1->setText("Raccourci n°1 : App n°0");
    }
    else
    {
        ui->IDC_TASKRAC1->setText("Raccourci n°1 : App n°"+QString::fromStdString(para->getNbAppTaskbar(1,0)));
    }

    if (para->getNbAppTaskbar(2,0)=="nothing")
    {
        ui->IDC_TASKRAC2->setText("Raccourci n°2 : App n°0");
    }
    else
    {
        ui->IDC_TASKRAC2->setText("Raccourci n°2 : App n°"+QString::fromStdString(para->getNbAppTaskbar(2,0)));
    }

    if (para->getNbAppTaskbar(3,0)=="nothing")
    {
        ui->IDC_TASKRAC3->setText("Raccourci n°3 : App n°0");
    }
    else
    {
        ui->IDC_TASKRAC3->setText("Raccourci n°3 : App n°"+QString::fromStdString(para->getNbAppTaskbar(3,0)));
    }

    if (para->getNbAppTaskbar(4,0)=="nothing")
    {
        ui->IDC_TASKRAC4->setText("Raccourci n°4 : App n°0");
    }
    else
    {
        ui->IDC_TASKRAC4->setText("Raccourci n°4 : App n°"+QString::fromStdString(para->getNbAppTaskbar(4,0)));
    }

    if (para->getNbAppTaskbar(5,0)=="nothing")
    {
        ui->IDC_TASKRAC5->setText("Raccourci n°5 : App n°0");
    }
    else
    {
        ui->IDC_TASKRAC5->setText("Raccourci n°5 : App n°"+QString::fromStdString(para->getNbAppTaskbar(5,0)));
    }
    if (mode==0)
    {
        ui->IDC_QUITHIST->setVisible(true);
        ui->IDC_QUITHISTBIS->setVisible(false);
    }
    else
    {
        if (mode==1)
        {
            ui->IDC_QUITHIST->setVisible(false);
            ui->IDC_QUITHISTBIS->setVisible(true);
        }
    }
}
// Btn autre app
void CDAparaArreraLib::on_IDC_GESTAPP1_clicked()
{
    selectApp(1);
}

void CDAparaArreraLib::on_IDC_GESTAPP2_clicked()
{
    selectApp(2);
}


void CDAparaArreraLib::on_IDC_GESTAPP3_clicked()
{
    selectApp(3);
}


void CDAparaArreraLib::on_IDC_GESTAPP4_clicked()
{
    selectApp(4);
}


void CDAparaArreraLib::on_IDC_GESTAPP5_clicked()
{
    selectApp(5);
}


void CDAparaArreraLib::on_IDC_GESTAPP6_clicked()
{
    selectApp(6);
}


void CDAparaArreraLib::on_IDC_GESTAPP7_clicked()
{
    selectApp(7);
}


void CDAparaArreraLib::on_IDC_GESTAPP8_clicked()
{
    selectApp(8);
}


void CDAparaArreraLib::on_IDC_GESTAPP9_clicked()
{
    selectApp(9);
}


void CDAparaArreraLib::on_IDC_GESTAPP10_clicked()
{
    selectApp(10);
}


void CDAparaArreraLib::on_IDC_GESTAPP11_clicked()
{
    selectApp(11);
}


void CDAparaArreraLib::on_IDC_GESTAPP12_clicked()
{
    selectApp(12);
}

// Btn arrera App
/*
 1 :  Arrera Video
 2 :  Arrera Doc
 3 : Arrera Info
 4 : Arrera Recherche
*/
void CDAparaArreraLib::on_IDC_GESTARRERARECHERCHE_clicked()
{
    para->setArreraAppEmplacement(4);
}


void CDAparaArreraLib::on_IDC_GESTARRERAINFO_clicked()
{
    para->setArreraAppEmplacement(3);
}


void CDAparaArreraLib::on_IDC_GESTARRERAVIDEO_clicked()
{
    para->setArreraAppEmplacement(1);
}


void CDAparaArreraLib::on_IDC_GESTARRERADOC_clicked()
{
    para->setArreraAppEmplacement(2);
}


void CDAparaArreraLib::on_IDC_VALIDER_clicked()//Btn valider
{
    para->setNameApp(nbAppSelect,ui->IDC_TEXTAPPNAME->toPlainText().toStdString());
    para->setEmplacementApp(nbAppSelect);
    clearGestApp();
}


void CDAparaArreraLib::on_IDC_TASK1_clicked()
{
    nbRacoucieSelect = 1 ;
    ui->IDC_LRACOURCISELECT->setText("Racourci selectioner : n°1");
}


void CDAparaArreraLib::on_IDC_TASK2_clicked()
{
    nbRacoucieSelect = 2 ;
    ui->IDC_LRACOURCISELECT->setText("Racourci selectioner : n°2");
}


void CDAparaArreraLib::on_IDC_TASK3_clicked()
{
    nbRacoucieSelect = 3 ;
    ui->IDC_LRACOURCISELECT->setText("Racourci selectioner : n°3");
}


void CDAparaArreraLib::on_IDC_TASK4_clicked()
{
    nbRacoucieSelect = 4 ;
    ui->IDC_LRACOURCISELECT->setText("Racourci selectioner : n°4");
}


void CDAparaArreraLib::on_IDC_TASK5_clicked()
{
    nbRacoucieSelect = 5 ;
    ui->IDC_LRACOURCISELECT->setText("Racourci selectioner : n°5");
}


void CDAparaArreraLib::on_IDC_VALIDERTASKBAR_clicked()
{
    if (nbRacoucieSelect==0)
    {

    }
    else
    {
        para->setAppTaskBar(nbRacoucieSelect,ui->IDC_CHOXBTN->value(),modeSelected);
        nbRacoucieSelect=0;
        ui->IDC_CHOXBTN->setValue(1);
        ui->IDC_LRACOURCISELECT->setText("Aucun racourcie selectionner");
    }

}


void CDAparaArreraLib::on_IDC_APPHISTORIC_clicked()
{
    viewListAPP(0);
}

void CDAparaArreraLib::on_IDC_QUITHIST_clicked()
{
    ui->FGESTAPP->setVisible(false);
    ui->FArreraApp->setVisible(true);
    ui->Fapp->setVisible(true);
    ui->FGESTTASKBAR->setVisible(false);
    ui->FHISTORICAPP->setVisible(false);
}

// Racourci app lib reset

void CDAparaArreraLib::on_IDC_RESETRAC1_clicked()
{
    para->setNameApp(1,"nothing");
    para->resetEmplacementApp(1);
    ui->IDC_RAC1->setText("App n°1 : "+QString::fromStdString(para->getNameApp(1)));
    viewListAPP(9);
}


void CDAparaArreraLib::on_IDC_RESETRAC2_clicked()
{
    para->setNameApp(2,"nothing");
    para->resetEmplacementApp(2);
    ui->IDC_RAC2->setText("App n°2 : "+QString::fromStdString(para->getNameApp(2)));
    viewListAPP(9);
}


void CDAparaArreraLib::on_IDC_RESETRAC3_clicked()
{
    para->setNameApp(3,"nothing");
    para->resetEmplacementApp(3);
    ui->IDC_RAC3->setText("App n°3 : "+QString::fromStdString(para->getNameApp(3)));
    viewListAPP(9);
}


void CDAparaArreraLib::on_IDC_RESETRAC4_clicked()
{
    para->setNameApp(4,"nothing");
    para->resetEmplacementApp(4);
    ui->IDC_RAC4->setText("App n°4 : "+QString::fromStdString(para->getNameApp(4)));
    viewListAPP(9);
}


void CDAparaArreraLib::on_IDC_RESETRAC5_clicked()
{
    para->setNameApp(5,"nothing");
    para->resetEmplacementApp(5);
    ui->IDC_RAC5->setText("App n°5 : "+QString::fromStdString(para->getNameApp(5)));
    viewListAPP(9);
}


void CDAparaArreraLib::on_IDC_RESETRAC6_clicked()
{
    para->setNameApp(6,"nothing");
    para->resetEmplacementApp(6);
    ui->IDC_RAC6->setText("App n°6 : "+QString::fromStdString(para->getNameApp(6)));
    viewListAPP(9);
}


void CDAparaArreraLib::on_IDC_RESETRAC7_clicked()
{
    para->setNameApp(7,"nothing");
    para->resetEmplacementApp(7);
    ui->IDC_RAC7->setText("App n°7 : "+QString::fromStdString(para->getNameApp(7)));
    viewListAPP(9);
}


void CDAparaArreraLib::on_IDC_RESETRAC8_clicked()
{
    para->setNameApp(8,"nothing");
    para->resetEmplacementApp(8);
    ui->IDC_RAC8->setText("App n°8 : "+QString::fromStdString(para->getNameApp(8)));
    viewListAPP(9);
}


void CDAparaArreraLib::on_IDC_RESETRAC9_clicked()
{
    para->setNameApp(9,"nothing");
    para->resetEmplacementApp(9);
    ui->IDC_RAC9->setText("App n°9 : "+QString::fromStdString(para->getNameApp(9)));
    viewListAPP(9);
}


void CDAparaArreraLib::on_IDC_RESETRAC10_clicked()
{
    para->setNameApp(10,"nothing");
    para->resetEmplacementApp(10);
    ui->IDC_RAC10->setText("App n°10 : "+QString::fromStdString(para->getNameApp(10)));
    viewListAPP(9);
}


void CDAparaArreraLib::on_IDC_RESETRAC11_clicked()
{
    para->setNameApp(11,"nothing");
    para->resetEmplacementApp(11);
    ui->IDC_RAC11->setText("App n°11 : "+QString::fromStdString(para->getNameApp(11)));
    viewListAPP(9);
}


void CDAparaArreraLib::on_IDC_RESETRAC12_clicked()
{
    para->setNameApp(12,"nothing");
    para->resetEmplacementApp(12);
    ui->IDC_RAC12->setText("App n°12 : "+QString::fromStdString(para->getNameApp(12)));
    viewListAPP(9);
}

// Racourci bar de tache liste

void CDAparaArreraLib::on_IDC_RESETTASK1_clicked()
{
    para->setAppTaskBar(1,0,0);
    viewListAPP(9);
}


void CDAparaArreraLib::on_IDC_RESETTASK2_clicked()
{
    para->setAppTaskBar(2,0,0);
    viewListAPP(9);
}

void CDAparaArreraLib::on_IDC_RESETTASK3_clicked()
{
    para->setAppTaskBar(3,0,0);
    viewListAPP(9);
}
void CDAparaArreraLib::on_IDC_RESETTASK1_3_clicked(){}


void CDAparaArreraLib::on_IDC_RESETTASK4_clicked()
{
    para->setAppTaskBar(4,0,0);
    viewListAPP(9);
}


void CDAparaArreraLib::on_IDC_RESETTASK5_clicked()
{
    para->setAppTaskBar(5,0,0);
    viewListAPP(9);
}


void CDAparaArreraLib::on_IDC_TASKSHOWAPP_clicked()
{
    viewListAPP(1);
    viewListAPP(9);
}


void CDAparaArreraLib::on_IDC_QUITHISTBIS_clicked()
{
    ui->FGESTAPP->setVisible(false);
    ui->FArreraApp->setVisible(false);
    ui->Fapp->setVisible(false);
    ui->FGESTTASKBAR->setVisible(true);
    ui->FHISTORICAPP->setVisible(false);
}




