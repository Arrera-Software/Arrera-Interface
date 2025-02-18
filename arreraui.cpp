#include "arreraui.h"
#include "ui_arreraui.h"

ArreraUI::ArreraUI(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ArreraUI)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
    // Objet
    QString confFile = "config.ini";
    QString tigerConf = "tiger.json";
    objSetting = new CAInterfaceSetting(confFile,tigerConf);
    // Ajout de l'objet de l'interface des parametre
    uipara = new ArreraSettingUI(this,objSetting);
    // Recuperation ID de widget
    idPageI2025Main = ui->I2025->indexOf(ui->main);
    idPageI2025App = ui->I2025->indexOf(ui->app);
    idPageI2025Mode = ui->I2025->indexOf(ui->mode);
    idPageApropos = ui->I2025->indexOf(ui->apropos);
    idPageI2025ArreraApp = ui->I2025->indexOf(ui->arreraApp);
    idPageRecherche = ui->I2025->indexOf(ui->recherchePage);
    // Id Page recherche
    idPageRechercheMoteur = ui->arreraRecherche->indexOf(ui->moteur);
    idPageRechercheHist = ui->arreraRecherche->indexOf(ui->historique);
    // Affichage du bon widget au demarage
    ui->I2025->setCurrentIndex(idPageI2025Main);
    // Changement du texte du label LINDICATIONARRERA
    ui->LINDICATIONARRERA->setText("Bienvenue sur Arrera I2025");
    // Mise en place d'une image de fond pour l'affichage main
    ui->TASKBARMAIN->setObjectName("MainWidget");
    ui->TASKBARMAIN->setStyleSheet("#MainWidget {"
                            "border: 2px solid black;"
                            "border-radius: 15px;"
                            "}");
    ui->FBUREAUTIQUEAPP->setObjectName("MainWidget");
    ui->FBUREAUTIQUEAPP->setStyleSheet("#MainWidget {"
                                        "border: 2px solid black;"
                                        "border-radius: 15px;"
                                       "}");
    // Connection de l'interface principale est le parametre
    connect(this,&ArreraUI::destroyed,uipara,&ArreraUI::close);
    connect(uipara,&ArreraSettingUI::parametresFerme,this,&ArreraUI::loadSetting);
    // Chargement des parametre
    loadSetting();

}

ArreraUI::~ArreraUI()
{
    delete ui;
}

void ArreraUI::on_IDC_ACCEUILARRERA_clicked() // Bouton Arrera en haut a gauche
{
    int currentIndex = ui->I2025->currentIndex();

    if (currentIndex != idPageI2025Main)
    {
        ui->I2025->setCurrentIndex(idPageI2025Main);
        ui->LINDICATIONARRERA->setText("Arrera I2025");
    }
    else
    {
        ui->I2025->setCurrentIndex(idPageApropos);
        ui->LINDICATIONARRERA->setText("Arrera I2025 A propos");
    }
}


void ArreraUI::on_IDC_APPBUREAU_clicked()
{
    // Boutton pour afficher les Application enregistrer par l'utilisateur
    ui->I2025->setCurrentIndex(idPageI2025App);
    ui->LINDICATIONARRERA->setText("Page application de l'ordinateur");
}


void ArreraUI::on_IDC_ARRERAAPP_clicked()
{
    ui->I2025->setCurrentIndex(idPageI2025ArreraApp);
    ui->LINDICATIONARRERA->setText("Page module Arrera");
}



// Partie Apropos
void ArreraUI::on_IDC_SOURCECODE_clicked()
{
    QUrl url("https://github.com/Arrera-Software/Arrera-Interface");
    QDesktopServices::openUrl(url);
}


void ArreraUI::on_IDC_WEBSITE_clicked()
{
    QUrl url("https://www.arrera-software.fr/");
    QDesktopServices::openUrl(url);
}


void ArreraUI::on_IDC_PARA_clicked()
{
    uipara->show();
}

void ArreraUI::loadSetting()
{
    ui->IDC_INDCNOLIEUMODE->setVisible(true);
    if (objSetting->mode1IsSeted()){
        ui->IDC_MODE1->setVisible(true);
        ui->IDC_INDCNOLIEUMODE->setVisible(false);
        // Mise en place de l'icon
        if (objSetting->iconMode1IsSetted()){
            QIcon icon(objSetting->getIconMode1());
            ui->IDC_MODE1->setIcon(icon);
        }else{
            QIcon icon(":mode-lieu/img/mode1.png");
            ui->IDC_MODE1->setIcon(icon);
        }
    }else{
        ui->IDC_MODE1->setVisible(false);}

    if (objSetting->mode2IsSeted()){
        ui->IDC_MODE2->setVisible(true);
        ui->IDC_INDCNOLIEUMODE->setVisible(false);
        // Mise en place de l'icon
        if (objSetting->iconMode2IsSetted()){
            QIcon icon(objSetting->getIconMode2());
            ui->IDC_MODE2->setIcon(icon);
        }else{
            QIcon icon(":mode-lieu/img/mode2.png");
            ui->IDC_MODE2->setIcon(icon);
        }
    }else{
        ui->IDC_MODE2->setVisible(false);}

    if (objSetting->mode3IsSeted()){
        ui->IDC_MODE3->setVisible(true);
        ui->IDC_INDCNOLIEUMODE->setVisible(false);
        // Mise en place de l'icon
        if (objSetting->iconMode3IsSetted()){
            QIcon icon(objSetting->getIconMode3());
            ui->IDC_MODE3->setIcon(icon);
        }else{
            QIcon icon(":mode-lieu/img/mode3.png");
            ui->IDC_MODE3->setIcon(icon);
        }
    }else{
        ui->IDC_MODE3->setVisible(false);}

    if (objSetting->mode4IsSeted()){
        ui->IDC_MODE4->setVisible(true);
        ui->IDC_INDCNOLIEUMODE->setVisible(false);
        // Mise en place de l'icon
        if (objSetting->iconMode4IsSetted()){
            QIcon icon(objSetting->getIconMode4());
            ui->IDC_MODE4->setIcon(icon);
        }else{
            QIcon icon(":mode-lieu/img/mode4.png");
            ui->IDC_MODE4->setIcon(icon);
        }
    }else{
        ui->IDC_MODE4->setVisible(false);}

    if (objSetting->mode5IsSeted()){
        ui->IDC_MODE5->setVisible(true);
        ui->IDC_INDCNOLIEUMODE->setVisible(false);
        // Mise en place de l'icon
        if (objSetting->iconMode5IsSetted()){
            QIcon icon(objSetting->getIconMode5());
            ui->IDC_MODE5->setIcon(icon);
        }else{
            QIcon icon(":mode-lieu/img/mode5.png");
            ui->IDC_MODE5->setIcon(icon);
        }
    }else{
        ui->IDC_MODE5->setVisible(false);}

    if (objSetting->mode6IsSeted()){
        ui->IDC_MODE6->setVisible(true);
        ui->IDC_INDCNOLIEUMODE->setVisible(false);
        // Mise en place de l'icon
        if (objSetting->iconMode6IsSetted()){
            QIcon icon(objSetting->getIconMode6());
            ui->IDC_MODE6->setIcon(icon);
        }else{
            QIcon icon(":mode-lieu/img/mode6.png");
            ui->IDC_MODE6->setIcon(icon);
        }
    }else{
        ui->IDC_MODE6->setVisible(false);}

    if (objSetting->lieu1IsSeted()){
        ui->IDC_LIEU1->setVisible(true);
        ui->IDC_INDCNOLIEUMODE->setVisible(false);
        // Mise en place de l'icon
        if (objSetting->iconLieu1IsSetted()){
            QIcon icon(objSetting->getIconLieu1());
            ui->IDC_LIEU1->setIcon(icon);
        }else{
            QIcon icon(":mode-lieu/img/lieu1.png");
            ui->IDC_LIEU1->setIcon(icon);
        }
    }else{
        ui->IDC_LIEU1->setVisible(false);}

    if (objSetting->lieu2IsSeted()){
        ui->IDC_LIEU2->setVisible(true);
        ui->IDC_INDCNOLIEUMODE->setVisible(false);
        // Mise en place de l'icon
        if (objSetting->iconLieu2IsSetted()){
            QIcon icon(objSetting->getIconLieu2());
            ui->IDC_LIEU2->setIcon(icon);
        }else{
            QIcon icon(":mode-lieu/img/lieu2.png");
            ui->IDC_LIEU2->setIcon(icon);
        }
    }else{
        ui->IDC_LIEU2->setVisible(false);}

}

void ArreraUI::launchSearch(int mode){
    /*
     * 1. Duckduckgo
     * 2. Google
     * 3. Qwant
     * 4. Ecosia
     * 5. Brave
     * 6. Bing
     * 7. Amazon
     * 8. Wikipedia
     * 9. Reverso
     * 10. Wordreference
     * 11. YT
     * 12. all
    */
    QString recherche = ui->IDC_SEARCHBAR->text();
    bool sortie;
    ui->IDC_SEARCHBAR->clear();
    if (!recherche.isEmpty()){
        switch (mode) {
        case 1: // duck
            sortie = arecherche.searchDuckduckgo(recherche);
            break;
        case 2: // google
            sortie = arecherche.searchGoogle(recherche);
            break;
        case 3: // qwant
            sortie = arecherche.searchQwant(recherche);
            break;
        case 4: // ecosia
            sortie = arecherche.searchEcosia(recherche);
            break;
        case 5: // brave
            sortie = arecherche.searchBrave(recherche);
            break;
        case 6: // bing
            sortie = arecherche.searchBing(recherche);
            break;
        case 7: // amazon
            sortie = arecherche.searchAmazon(recherche);
            break;
        case 8: // wikipedia
            sortie = arecherche.searchWikipedia(recherche);
            break;
        case 9: // reverso
            sortie = arecherche.searchReverso(recherche);
            break;
        case 10: // wordreference
            sortie = arecherche.searchWordreference(recherche);
            break;
        case 11: // YT
            sortie = arecherche.searchYTmusic(recherche);
            break;
        case 12: // all
            sortie = arecherche.searchAll(recherche);
            break;
        default:
            sortie = false;
            break;
        }
        if (!sortie){
            QMessageBox::critical(this,"Recherche Arrera",
                                  "Une erreur s'est produite : impossible de faire la recherche.");
        }
    }else{
        QMessageBox::critical(this,"Recherche Arrera",
                              "Une erreur s'est produite : impossible de faire la recherche.");
    }
}

void ArreraUI::on_IDC_SHOWHIST_clicked()
{
    // Affichage de la page historique
    ui->I2025->setCurrentIndex(idPageRecherche);
    ui->LINDICATIONARRERA->setText("Historique de recherche");
    ui->arreraRecherche->setCurrentIndex(idPageRechercheHist);
    // Clear de SHOWHISTORIQUEUSER
    ui->SHOWHISTORIQUEUSER->clear();
    // Ajout de l'historique dans le text edit
    ui->SHOWHISTORIQUEUSER->setReadOnly(false);
    QString historique = arecherche.read();
    if (historique == "-1"){
        QMessageBox::critical(this,"Historique Arrera recherche",
                              "Impossible d'afficher l'historique de recherche");
        ui->I2025->setCurrentIndex(idPageI2025Main);
    }
    else{
        ui->SHOWHISTORIQUEUSER->appendPlainText(historique);
    }
    ui->SHOWHISTORIQUEUSER->setReadOnly(true);
}


void ArreraUI::on_IDC_AUTREMOTEUR_clicked()
{
    ui->I2025->setCurrentIndex(idPageRecherche);
    ui->LINDICATIONARRERA->setText("Recherche Arrera");
    ui->arreraRecherche->setCurrentIndex(idPageRechercheMoteur);
}


void ArreraUI::on_IDC_MOTEURDUCK_clicked()
{
    launchSearch(1);
}


void ArreraUI::on_IDC_MOTEURGOOGLE_clicked()
{
    launchSearch(2);
}


void ArreraUI::on_IDC_MOTEURBING_clicked()
{
    launchSearch(6);
}


void ArreraUI::on_IDC_MOTEURBRAVE_clicked()
{
    launchSearch(5);
}


void ArreraUI::on_IDC_MOTEURECOSIA_clicked()
{
    launchSearch(4);
}


void ArreraUI::on_IDC_MOTEURQWANT_clicked()
{
    launchSearch(3);
}


void ArreraUI::on_IDC_MOTEURBIGSEARCH_clicked()
{
    launchSearch(12);
}


void ArreraUI::on_IDC_MOTEURWIKIPEDIA_clicked()
{
    launchSearch(8);
}


void ArreraUI::on_IDC_MOTEURAMAZON_clicked()
{
    launchSearch(7);
}


void ArreraUI::on_IDC_MOTEURWORDREFERENCE_clicked()
{
    launchSearch(10);
}


void ArreraUI::on_IDC_MOTEURYT_clicked()
{
    launchSearch(11);
}


void ArreraUI::on_IDC_MOTEURREVERSO_clicked()
{
    launchSearch(9);
}


void ArreraUI::on_IDC_BTNSEACH_clicked()
{
    // "GOOGLE", "DUCKDUCKGO", "ECOSIA" , "BING", "BRAVE","QWANT"
    QString moteur = objSetting->getMoteurRecherche();

    if (moteur == "GOOGLE"){
        launchSearch(2);
        return ;
    }else{
        if (moteur == "DUCKDUCKGO"){
            launchSearch(1);
            return;
        }else{
            if (moteur == "ECOSIA"){
                launchSearch(4);
                return ;
            }else{
                if (moteur == "BING"){
                    launchSearch(6);
                    return ;
                }else{
                    if (moteur == "BRAVE"){
                        launchSearch(5);
                        return;
                    }else{
                        if (moteur == "QWANT"){
                            launchSearch(3);
                            return ;
                        }else{
                            launchSearch(2);
                        }
                    }
                }
            }
        }
    }
}
