#include "carrerainterface.h"
#include "ui_carrerainterface.h"

CArreraInterface::CArreraInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CArreraInterface)
{
    ui->setupUi(this);

    objRecherche = CArreraRecheche();
    objRechercheHist = CArreraRechercheHist();

    mainPageIndex = ui->PagesArrera->indexOf(ui->Mainpage);
    libIndex =  ui->PagesArrera->indexOf(ui->ArreraLibPage);
    PostiteIndex = ui->PagesArrera->indexOf(ui->PostitePage);
    rechercheIndex = ui->PagesArrera->indexOf(ui->PageRecherche);
    rechercheHistIndex = ui->PagesArrera->indexOf(ui->PageRechercheHist);
    ui->PagesArrera->setCurrentIndex(mainPageIndex);
    // Declaration objet
    objSetting  = CArreraSetting();
    // Declaration fenetre fille
    winPara = new CArreraInterfaceSetting(this);
    winPara->passObjSetting(&objSetting);
    connect(this,&CArreraInterface::destroyed,winPara,&CArreraInterface::close);
    connect(winPara,&CArreraInterfaceSetting::parametresFerme,this,&CArreraInterface::loadSetting);
}

CArreraInterface::~CArreraInterface()
{
    delete ui;
}

// Main

void CArreraInterface::on_IDC_DRAWERAPP_clicked()
{
    ui->PagesArrera->setCurrentIndex(libIndex);
}

void CArreraInterface::on_IDC_RECHERCHE_clicked()
{
    ui->PagesArrera->setCurrentIndex(rechercheIndex);
}

// Librairy

void CArreraInterface::on_IDC_LIBEXIT_clicked()
{
    ui->PagesArrera->setCurrentIndex(mainPageIndex);
}


void CArreraInterface::on_IDC_SOFTPRESENTATION_clicked()
{

}


void CArreraInterface::on_IDC_SOFTTABLEUR_clicked()
{

}


void CArreraInterface::on_IDC_SOFTTEXTE_clicked()
{

}


void CArreraInterface::on_IDC_SOFTPENSEBETE_clicked()
{
    ui->PagesArrera->setCurrentIndex(PostiteIndex);
}


void CArreraInterface::on_IDC_SOFTNAVIGATEUR_clicked()
{

}

// Postite
void CArreraInterface::on_IDC_POSTITEEXIT_clicked()
{
    if(!ui->ZONETEXTE->toPlainText().isEmpty())
    {
        ui->ZONETEXTE->clear();
        ui->PagesArrera->setCurrentIndex(mainPageIndex);
    }
    else
    {
        ui->PagesArrera->setCurrentIndex(mainPageIndex);
    }
}


void CArreraInterface::on_IDC_OUVRIR_clicked()
{
    QString contenu;
    QString nomFichier ;
    nomFichier = QFileDialog::getOpenFileName(this,
                                              "Choisir un fichier à ouvrir",
                                              QDir::homePath(), "Fichier Pense-bete (*.ab)");
    QFile fichier(nomFichier);
    if (fichier.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&fichier);
        contenu = in.readAll();
        fichier.close();
        ui->ZONETEXTE->setPlainText(contenu);
    }
}


void CArreraInterface::on_IDC_SAVE_clicked()
{
    QString contenuTextEdit;
    QString nomFichier ;
    nomFichier=QFileDialog::getSaveFileName(nullptr,
                                              "Enregistrer le fichier", QDir::homePath(), "Fichier Pense-bete (*.ab)");
    QFile file(nomFichier);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        contenuTextEdit = ui->ZONETEXTE->toPlainText();
        out << contenuTextEdit ;
        QMessageBox::StandardButton reponse = QMessageBox::question(this,
                                                                    "Continuer l'édition ?", "Voulez-vous continuer à éditer ?",
                                                                    QMessageBox::Yes | QMessageBox::No);
        if (reponse == QMessageBox::No)
        {
            ui->ZONETEXTE->clear();
        }
        file.close();
    }
}

// Recherche
void CArreraInterface::on_IDC_VALIDERRECHERCHE_clicked()
{

}


void CArreraInterface::on_IDC_HIST_clicked()
{
    ui->IDC_LRECHERCHEHIST->setText(objRechercheHist.read());
    ui->PagesArrera->setCurrentIndex(rechercheHistIndex);
}

void CArreraInterface::on_IDC_QUITARRERARECHERCHE_clicked()
{
    ui->PagesArrera->setCurrentIndex(mainPageIndex);
}


void CArreraInterface::on_IDC_RECHERCHEGOOGLE_clicked()
{
    QString querry =  ui->IDC_BARRECHERCHE->toPlainText();
    ui->IDC_BARRECHERCHE->setPlainText("");
    objRecherche.searchGoogle(querry);
    objRechercheHist.add("google->"+querry);
}


void CArreraInterface::on_IDC_RECHERCHEDUCKDUCKGO_clicked()
{
    QString querry =  ui->IDC_BARRECHERCHE->toPlainText();
    ui->IDC_BARRECHERCHE->setPlainText("");
    objRecherche.searchDuckduckgo(querry);
    objRechercheHist.add("duck->"+querry);
}


void CArreraInterface::on_IDC_RECHERCHEBING_clicked()
{
    QString querry =  ui->IDC_BARRECHERCHE->toPlainText();
    ui->IDC_BARRECHERCHE->setPlainText("");
    objRecherche.searchBing(querry);
    objRechercheHist.add("bing->"+querry);
}


void CArreraInterface::on_IDC_RECHERCHEBRAVE_clicked()
{
    QString querry =  ui->IDC_BARRECHERCHE->toPlainText();
    ui->IDC_BARRECHERCHE->setPlainText("");
    objRecherche.searchBrave(querry);
    objRechercheHist.add("brave->"+querry);
}


void CArreraInterface::on_IDC_RECHERCHEQWANT_clicked()
{
    QString querry =  ui->IDC_BARRECHERCHE->toPlainText();
    ui->IDC_BARRECHERCHE->setPlainText("");
    objRecherche.searchQwant(querry);
    objRechercheHist.add("qwant->"+querry);
}


void CArreraInterface::on_IDC_RECHERCHEECOSIA_clicked()
{
    QString querry =  ui->IDC_BARRECHERCHE->toPlainText();
    ui->IDC_BARRECHERCHE->setPlainText("");
    objRecherche.searchEcosia(querry);
    objRechercheHist.add("ecosia->"+querry);
}


void CArreraInterface::on_IDC_GRECHERCHE_clicked()
{
    QString querry =  ui->IDC_BARRECHERCHE->toPlainText();
    ui->IDC_BARRECHERCHE->setPlainText("");
    objRecherche.searchAll(querry);
    objRechercheHist.add("grecherche->"+querry);
}


void CArreraInterface::on_IDC_RECHERCHEWORKREFERENCE_clicked()
{
    QString querry =  ui->IDC_BARRECHERCHE->toPlainText();
    ui->IDC_BARRECHERCHE->setPlainText("");
    objRecherche.searchWordreference(querry);
    objRechercheHist.add("wordReference->"+querry);
}


void CArreraInterface::on_IDC_RECHERCHEYTMUSIC_clicked()
{
    QString querry =  ui->IDC_BARRECHERCHE->toPlainText();
    ui->IDC_BARRECHERCHE->setPlainText("");
    objRecherche.searchYTmusic(querry);
    objRechercheHist.add("YT Music->"+querry);
}


void CArreraInterface::on_IDC_RECHERCHEAMAZON_clicked()
{
    QString querry =  ui->IDC_BARRECHERCHE->toPlainText();
    ui->IDC_BARRECHERCHE->setPlainText("");
    objRecherche.searchAmazon(querry);
    objRechercheHist.add("amazon->"+querry);
}


void CArreraInterface::on_IDC_RECHERCHEWIKIPEDIA_clicked()
{
    QString querry =  ui->IDC_BARRECHERCHE->toPlainText();
    ui->IDC_BARRECHERCHE->setPlainText("");
    objRecherche.searchWikipedia(querry);
    objRechercheHist.add("wikipedia->"+querry);
}


void CArreraInterface::on_IDC_RECHERCHEREVERSO_clicked()
{
    QString querry =  ui->IDC_BARRECHERCHE->toPlainText();
    ui->IDC_BARRECHERCHE->setPlainText("");
    objRecherche.searchReverso(querry);
    objRechercheHist.add("reverso->"+querry);
}


void CArreraInterface::on_IDC_RETOURHISTRECHERCHE_clicked()
{
    ui->PagesArrera->setCurrentIndex(rechercheIndex);
}

void CArreraInterface::loadSetting()
{
    qDebug() << "Load";
}

void CArreraInterface::on_IDC_PARAMETRE_clicked()
{
    winPara->show();
}
