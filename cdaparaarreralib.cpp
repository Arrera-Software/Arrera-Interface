#include "cdaparaarreralib.h"
#include "ui_cdaparaarreralib.h"

CDAparaArreraLib::CDAparaArreraLib(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CDAparaArreraLib)
{
    ui->setupUi(this);
    clearGestApp();
    nbAppSelect = 0;
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

