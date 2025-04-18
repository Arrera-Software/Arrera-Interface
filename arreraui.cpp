#include "arreraui.h"

#include <iostream>
using namespace std;

ArreraUI::ArreraUI(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ArreraUI),serveurApp(this), serveurAssistant(this),comunictation(&serveurApp,&serveurApp)
{
    ui->setupUi(this);

    // Demarage des serveur websocket
    serveurApp.startServeur(12345);
    serveurAssistant.startServeur(6666);

    // Partie serveur app
    connect(&serveurApp, &CArreraServeur::messageReceived,
            [this](const QString &nameSoft, const QString &message)
            {comunictation.traitementApp(nameSoft,message);});
    connect(&serveurApp,&CArreraServeur::connectClient,[this]()
            {ui->LINDICATIONARRERA->setText("App connected");});

    // Partie serveur assistant
    connect(&serveurAssistant,&CArreraServeur::connectClient,[this](){
        ui->LINDICATIONARRERA->setText("Un assistant est connectée");
        ui->IDC_SIX->setVisible(false);
        ui->IDC_COPILOTE->setVisible(false);
        ui->IDC_RYLEY->setVisible(false);
    });
    connect(&serveurAssistant,&CArreraServeur::clientDeconected,[this](){
        ui->LINDICATIONARRERA->setText("L'assistant et deconnecter");
        ui->IDC_SIX->setVisible(objSetting->getTaskbarBTNSix());
        ui->IDC_COPILOTE->setVisible(objSetting->getTaskbarCopilote());
        ui->IDC_RYLEY->setVisible(objSetting->getTaskbarBTNRyley());
    });
    connect(&serveurAssistant, &CArreraServeur::messageReceived,
            [this](const QString &nameSoft, const QString &message)
            {comunictation.traitementAssistant(nameSoft,message);});

    // Connection du serveur websocket
    setWindowFlags(Qt::Window | Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
    // Instatation de l'objet de dectation de l'os
    QString confFile = "config.ini";
    objSetting = new CAInterfaceSetting(confFile,ui->IDC_SIX,ui->IDC_RYLEY,ui->IDC_COPILOTE);
    // Ajout de l'objet de l'interface des parametre
    uipara = new ArreraSettingUI(this,objSetting,&arecherche,&dectOS);
    // Ajout de l'objet pour gerer les application Arrera
    arreraApp = new CArreraApp(objSetting,&dectOS,this);
    // Recuperation ID de widget
    idPageI2025Main = ui->I2025->indexOf(ui->main);
    idPageI2025App = ui->I2025->indexOf(ui->app);
    idPageI2025Mode = ui->I2025->indexOf(ui->mode);
    idPageApropos = ui->I2025->indexOf(ui->apropos);
    idPageI2025ArreraApp = ui->I2025->indexOf(ui->arreraApp);
    idPageRecherche = ui->I2025->indexOf(ui->recherchePage);
    idAppView=ui->appStaked->indexOf(ui->AppView);
    idNoApp=ui->appStaked->indexOf(ui->NoApp);
    // Id Page recherche
    idPageRechercheMoteur = ui->arreraRecherche->indexOf(ui->moteur);
    idPageRechercheHist = ui->arreraRecherche->indexOf(ui->historique);
    // Id Acceuil Stacked
    idNonMode = ui->acceuilStacked->indexOf(ui->nomode);
    idYesMode = ui->acceuilStacked->indexOf(ui->yesmode);
    // id arreraAppStacked
    idNoArreraApp = ui->arreraAppStacked->indexOf(ui->noArreraApp);
    idViewArreraApp = ui->arreraAppStacked->indexOf(ui->viewArreraApp);
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
    // Mise en place de bouton d'application
    appPC.append(CAppPC(1,objSetting,ui->IDC_APP_001,&dectOS));
    appPC.append(CAppPC(2,objSetting,ui->IDC_APP_002,&dectOS));
    appPC.append(CAppPC(3,objSetting,ui->IDC_APP_003,&dectOS));
    appPC.append(CAppPC(4,objSetting,ui->IDC_APP_004,&dectOS));
    appPC.append(CAppPC(5,objSetting,ui->IDC_APP_005,&dectOS));
    appPC.append(CAppPC(6,objSetting,ui->IDC_APP_006,&dectOS));
    appPC.append(CAppPC(7,objSetting,ui->IDC_APP_007,&dectOS));
    appPC.append(CAppPC(8,objSetting,ui->IDC_APP_008,&dectOS));
    appPC.append(CAppPC(9,objSetting,ui->IDC_APP_009,&dectOS));
    appPC.append(CAppPC(10,objSetting,ui->IDC_APP_010,&dectOS));
    appPC.append(CAppPC(11,objSetting,ui->IDC_APP_011,&dectOS));
    appPC.append(CAppPC(12,objSetting,ui->IDC_APP_012,&dectOS));
    appPC.append(CAppPC(13,objSetting,ui->IDC_APP_013,&dectOS));
    appPC.append(CAppPC(14,objSetting,ui->IDC_APP_014,&dectOS));
    appPC.append(CAppPC(15,objSetting,ui->IDC_APP_015,&dectOS));
    appPC.append(CAppPC(16,objSetting,ui->IDC_APP_016,&dectOS));
    appPC.append(CAppPC(17,objSetting,ui->IDC_APP_017,&dectOS));
    appPC.append(CAppPC(18,objSetting,ui->IDC_APP_018,&dectOS));
    appPC.append(CAppPC(19,objSetting,ui->IDC_APP_019,&dectOS));
    appPC.append(CAppPC(20,objSetting,ui->IDC_APP_020,&dectOS));
    // Mise en place des app speciaux
    appNavigateur = CAppSpeciaux(1,objSetting,ui->IDC_NAVIGATEUR,&dectOS);
    appPresentation = CAppSpeciaux(2,objSetting,ui->IDC_PRESENTATION,&dectOS);
    appTableur = CAppSpeciaux(3,objSetting,ui->IDC_TABLEUR,&dectOS);
    appTraitementTexte = CAppSpeciaux(4,objSetting,ui->IDC_TRAITEMENTTEXTE,&dectOS);
    // Chargement des parametre
    loadSetting();
    // Initilisation de varriable
    modeIsActive = false;
    nameMode = "";
    lieuEnabled = 0;
    // Mise en place de l'image sur le label des mode
    QPixmap pixmap (":/icon/img/logo-Arrera.png");
    ui->LICONARRERA->setPixmap(pixmap.scaled(
        ui->LICONARRERA->size(),
        Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

ArreraUI::~ArreraUI()
{
    serveurApp.stopServeur();
    delete ui;
}

void ArreraUI::on_IDC_ACCEUILARRERA_clicked() // Bouton Arrera en haut a gauche
{
    int currentIndex = ui->I2025->currentIndex();

    if (currentIndex != idPageI2025Main)
    {
        if (modeIsActive)
        {
            ui->I2025->setCurrentIndex(idPageI2025Mode);
            ui->LINDICATIONARRERA->setText(nameMode);
            ui->IDC_SHOWHIST->setVisible(true);
            ui->IDC_AUTREMOTEUR->setVisible(true);
        }
        else
        {
            ui->I2025->setCurrentIndex(idPageI2025Main);
            ui->LINDICATIONARRERA->setText("Arrera I2025");
            ui->IDC_SHOWHIST->setVisible(true);
            ui->IDC_AUTREMOTEUR->setVisible(true);
        }
    }
    else
    {
        if (lieuEnabled != 0){
            int ret = QMessageBox::question(nullptr,
                                            "Quitter le lieu",
                                            "Voulez-vous quitter le lieu en cours ?",
                                            QMessageBox::Yes | QMessageBox::No);

            if (ret == QMessageBox::Yes)
            {
                switch (lieuEnabled) {
                case 1:
                    objSetting->disableLieu1();
                    lieuEnabled = 0;
                    break;
                case 2:
                    objSetting->disableLieu2();
                    lieuEnabled = 2;
                    break;
                default:
                    break;
                }
            }
            else
            {
            ui->I2025->setCurrentIndex(idPageApropos);
                ui->LINDICATIONARRERA->setText("Arrera I2025 A propos");
            }
        }   }
}

// Bar des taches
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
    loadArreraApp();
}

void ArreraUI::on_IDC_TIGER_clicked()
{
    bool sortie = arreraApp->openStore();
    if (!sortie){
        QMessageBox::critical(this,"Ouverture Arrera Store",
                              "Impossible de lancer Arrera Store.");
    }
}


void ArreraUI::on_IDC_RYLEY_clicked()
{
    if (!arreraApp->executeApp("ryley")){
        QMessageBox::critical(this,"Lancement de l'assistant Arrera RYLEY",
                              "Impossible de lancer votre assistant Arrera RYLEY.");
    }
}


void ArreraUI::on_IDC_COPILOTE_clicked()
{
    if (!arreraApp->executeApp("arrera-copilote")){
        QMessageBox::critical(this,"Lancement de l'assistant Arrera COPILOTE",
                              "Impossible de lancer votre assistant Arrera COPILOTE.");
    }
}


void ArreraUI::on_IDC_SIX_clicked()
{
    if (!arreraApp->executeApp("six")){
        QMessageBox::critical(this,"Lancement de l'assistant Arrera SIX",
                              "Impossible de lancer votre assistant Arrera SIX.");
    }
}


void ArreraUI::on_IDC_ARRERAPOSTITE_clicked()
{
    if (!arreraApp->executeApp("arrera-postite")){
        QMessageBox::critical(this,"Lancement Arrera Postite",
                              "Impossible de lancer Arrera Postite");
    }
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
    bool appSetted;
    ui->acceuilStacked->setCurrentIndex(idNonMode);
    if (objSetting->mode1IsSeted()){
        ui->IDC_MODE1->setVisible(true);
        ui->acceuilStacked->setCurrentIndex(idYesMode);
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
        ui->acceuilStacked->setCurrentIndex(idYesMode);
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
        ui->acceuilStacked->setCurrentIndex(idYesMode);
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
        ui->acceuilStacked->setCurrentIndex(idYesMode);
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
        ui->acceuilStacked->setCurrentIndex(idYesMode);
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
        ui->acceuilStacked->setCurrentIndex(idYesMode);
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
        ui->acceuilStacked->setCurrentIndex(idYesMode);
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
        ui->acceuilStacked->setCurrentIndex(idYesMode);
        // Mise en place de l'icon
        if (objSetting->iconLieu2IsSetted()){
            QIcon icon(objSetting->getIconLieu2());
            ui->IDC_LIEU2->setIcon(icon);
        }else{
            QIcon icon(":mode-lieu/img/lieu2.png");
            ui->IDC_LIEU2->setIcon(icon);
        }
    }else{
        ui->IDC_LIEU2->setVisible(false);
    }
    appPC[0].loadData();
    appPC[1].loadData();
    appPC[2].loadData();
    appPC[3].loadData();
    appPC[4].loadData();
    appPC[5].loadData();
    appPC[6].loadData();
    appPC[7].loadData();
    appPC[8].loadData();
    appPC[9].loadData();
    appPC[10].loadData();
    appPC[11].loadData();
    appPC[12].loadData();
    appPC[13].loadData();
    appPC[14].loadData();
    appPC[15].loadData();
    appPC[16].loadData();
    appPC[17].loadData();
    appPC[18].loadData();
    appPC[19].loadData();

    if (!appPC[0].getAppSetted()&&!appPC[1].getAppSetted()&&
        !appPC[2].getAppSetted()&&!appPC[3].getAppSetted()&&
        !appPC[4].getAppSetted()&&!appPC[5].getAppSetted()&&
        !appPC[6].getAppSetted()&&!appPC[7].getAppSetted()&&
        !appPC[8].getAppSetted()&&!appPC[9].getAppSetted()&&
        !appPC[10].getAppSetted()&&!appPC[11].getAppSetted()&&
        !appPC[12].getAppSetted()&&!appPC[13].getAppSetted()&&
        !appPC[14].getAppSetted()&&!appPC[15].getAppSetted()&&
        !appPC[16].getAppSetted()&&!appPC[17].getAppSetted()&&
        !appPC[18].getAppSetted()&&!appPC[19].getAppSetted()){
        ui->appStaked->setCurrentIndex(idNoApp);
        appSetted=false;
    }else{
        ui->appStaked->setCurrentIndex(idAppView);
        appSetted=true;
    }

    appNavigateur.loadData();
    appPresentation.loadData();
    appTableur.loadData();
    appTraitementTexte.loadData();

    if (!appNavigateur.getAppSetted()&&
        !appPresentation.getAppSetted()&&
        !appTableur.getAppSetted()&&
        !appTraitementTexte.getAppSetted()&&
        !appSetted)
    {
        ui->IDC_APPLISTMODE->setVisible(false);
        ui->IDC_APPBUREAU->setVisible(false);
    }else{
        ui->IDC_APPLISTMODE->setVisible(true);
        ui->IDC_APPBUREAU->setVisible(true);
    }

    if(!appNavigateur.getAppSetted()&&
        !appPresentation.getAppSetted()&&
        !appTableur.getAppSetted()&&
        !appTraitementTexte.getAppSetted()){
        ui->FBUREAUTIQUEAPP->setVisible(false);
    }else{
        ui->FBUREAUTIQUEAPP->setVisible(true);
    }

    ui->IDC_ARRERAAPP->setVisible(objSetting->getTaskbarBTNArreraApp());
    ui->IDC_ARRERAPOSTITE->setVisible(objSetting->getTaskbarPostite());
    ui->IDC_SIX->setVisible(objSetting->getTaskbarBTNSix());
    ui->IDC_COPILOTE->setVisible(objSetting->getTaskbarCopilote());
    ui->IDC_RYLEY->setVisible(objSetting->getTaskbarBTNRyley());
}

void ArreraUI::loadArreraApp(){
    if (arreraApp->loadJson()){
        bool videoSetted,postiteSetted,sixSetted,ryleySetted,raccourciSetted,copiloteSetted;
        videoSetted = arreraApp->loadApp("arrera-video-download",ui->IDC_AVIDEODOWNLOAD);
        postiteSetted = arreraApp->loadApp("arrera-postite",ui->IDC_APOSTITE);
        sixSetted = arreraApp->loadApp("six",ui->IDC_ASIX);
        ryleySetted =  arreraApp->loadApp("ryley",ui->IDC_ARYLEY);
        raccourciSetted = arreraApp->loadApp("arrera-raccourci",ui->IDC_ARACCOURCI);
        copiloteSetted = arreraApp->loadApp("arrera-copilote",ui->IDC_ACOPILOTE);

        if (videoSetted||postiteSetted||sixSetted||
            ryleySetted||raccourciSetted||copiloteSetted){
            ui->arreraAppStacked->setCurrentIndex(idViewArreraApp);
        }else{
            ui->arreraAppStacked->setCurrentIndex(idNoArreraApp);
        }

    }else{
        ui->arreraAppStacked->setCurrentIndex(idNoArreraApp);
    }
}

bool ArreraUI::launchAppMode(int nbApp,QString app){
    QPushButton *btn;
    QString icon,name;
    bool sortieExe;
    int i;
    switch (nbApp) {
    case 1:
        btn = ui->IDC_APPMODE1;
        app1Mode = app;
        break;
    case 2:
        app2Mode = app;
        btn = ui->IDC_APPMODE2;
        break;
    case 3:
        app3Mode = app;
        btn = ui->IDC_APPMODE3;
        break;
    case 4:
        app4Mode = app;
        btn = ui->IDC_APPMODE4;
        break;
    default:
        return false;
    }
    if (app=="app1"){
        i=0;
    }else if(app=="app2") {
        i=1;
    }else if(app=="app3"){
        i=2;
    }else if(app=="app4"){
        i=3;
    }else if(app =="app5"){
        i=4;
    }else if(app =="app6"){
        i=5;
    }else if(app =="app7"){
        i=6;
    }else if(app =="app8"){
        i=7;
    }else if(app =="app9"){
        i=8;
    }else if(app =="app10"){
        i=9;
    }else if(app =="app11"){
        i=10;
    }else if(app =="app12"){
        i=11;
    }else if(app =="app13"){
        i=12;
    }else if(app =="app14"){
        i=13;
    }else if(app =="app15"){
        i=14;
    }else if(app =="app16"){
        i=15;
    }else if(app =="app17"){
        i=16;
    }else if(app =="app18"){
        i=17;
    }else if(app =="app19"){
        i=18;
    }else if(app =="app20"){
        i=19;
    }else{
        return false;
    }

    name = appPC[i].getName();
    icon = appPC[i].getIcon();
    sortieExe = appPC[i].executeApplication();

    btn->setIcon(QIcon());
    if (icon!="nothing"){
        btn->setIcon(QIcon(icon));
        btn->setText("");
    }else{
        btn->setText(name);
    }

    return sortieExe;
}

bool ArreraUI::launchAssistantMode(QString assistant){
    if (assistant.isEmpty()){
        return arreraApp->executeApp(assistantMode);
    }else{
        if (assistant=="SIX"){
            assistantMode = "six";
            ui->IDC_ASSISTANT->setVisible(true);
            return arreraApp->executeApp("six");
        }else if (assistant == "RYLEY"){
            assistantMode = "ryley";
            ui->IDC_ASSISTANT->setVisible(true);
            return arreraApp->executeApp("ryley");
        }else if (assistant == "COPILOTE"){
            assistantMode = "arrera-copilote";
            ui->IDC_ASSISTANT->setVisible(true);
            return arreraApp->executeApp("arrera-copilote");
        }else{
            ui->IDC_ASSISTANT->setVisible(false);
            return false;
        }
    }
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
    ui->IDC_AUTREMOTEUR->setVisible(true);
    ui->IDC_SHOWHIST->setVisible(false);
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
        ui->IDC_SHOWHIST->setVisible(true);
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
    ui->IDC_AUTREMOTEUR->setVisible(false);
    ui->IDC_SHOWHIST->setVisible(true);
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
    }else if (moteur == "DUCKDUCKGO"){
        launchSearch(1);
    }else if (moteur == "ECOSIA"){
        launchSearch(4);
    }else if (moteur == "BING"){
        launchSearch(6);
    }else if (moteur == "BRAVE"){
        launchSearch(5);
    }else if (moteur == "QWANT"){
        launchSearch(3);
    }else{
        launchSearch(2);
    }
}

void ArreraUI::on_IDC_APP_001_clicked()
{
    appPC[0].executeApplication();
}


void ArreraUI::on_IDC_APP_002_clicked()
{
    appPC[1].executeApplication();
}


void ArreraUI::on_IDC_APP_003_clicked()
{
    appPC[2].executeApplication();
}


void ArreraUI::on_IDC_APP_004_clicked()
{
    appPC[3].executeApplication();
}


void ArreraUI::on_IDC_APP_005_clicked()
{
    appPC[4].executeApplication();
}


void ArreraUI::on_IDC_APP_006_clicked()
{
    appPC[5].executeApplication();
}


void ArreraUI::on_IDC_APP_007_clicked()
{
    appPC[6].executeApplication();
}


void ArreraUI::on_IDC_APP_008_clicked()
{
    appPC[7].executeApplication();
}


void ArreraUI::on_IDC_APP_009_clicked()
{
    appPC[8].executeApplication();
}


void ArreraUI::on_IDC_APP_010_clicked()
{
    appPC[9].executeApplication();
}


void ArreraUI::on_IDC_APP_011_clicked()
{
    appPC[10].executeApplication();
}


void ArreraUI::on_IDC_APP_012_clicked()
{
    appPC[11].executeApplication();
}


void ArreraUI::on_IDC_APP_013_clicked()
{
    appPC[12].executeApplication();
}


void ArreraUI::on_IDC_APP_014_clicked()
{
    appPC[13].executeApplication();
}


void ArreraUI::on_IDC_APP_015_clicked()
{
    appPC[14].executeApplication();
}


void ArreraUI::on_IDC_APP_016_clicked()
{
    appPC[15].executeApplication();
}


void ArreraUI::on_IDC_APP_017_clicked()
{
    appPC[16].executeApplication();
}


void ArreraUI::on_IDC_APP_018_clicked()
{
    appPC[17].executeApplication();
}


void ArreraUI::on_IDC_APP_019_clicked()
{
    appPC[18].executeApplication();
}


void ArreraUI::on_IDC_APP_020_clicked()
{
    appPC[19].executeApplication();
}


void ArreraUI::on_IDC_NAVIGATEUR_clicked()
{
    appNavigateur.executeApplication();
}


void ArreraUI::on_IDC_PRESENTATION_clicked()
{
    appPresentation.executeApplication();
}


void ArreraUI::on_IDC_TABLEUR_clicked()
{
    appTableur.executeApplication();
}


void ArreraUI::on_IDC_TRAITEMENTTEXTE_clicked()
{
    appTraitementTexte.executeApplication();
}
// Arrera APP
void ArreraUI::on_IDC_APOSTITE_clicked()
{
    if (!arreraApp->executeApp("arrera-postite")){
        QMessageBox::critical(this,"Lancement Arrera Postite",
                              "Impossible de lancer Arrera Postite");
    }
}


void ArreraUI::on_IDC_AVIDEODOWNLOAD_clicked()
{
    if (!arreraApp->executeApp("arrera-video-download")){
        QMessageBox::critical(this,"Lancement Arrera Video Download",
                              "Impossible de lancer Arrera Video Download");
    }
}


void ArreraUI::on_IDC_ARACCOURCI_clicked()
{
    if (!arreraApp->executeApp("arrera-raccourci")){
        QMessageBox::critical(this,"Lancement Arrera Raccourci",
                              "Impossible de lancer Arrera Raccourci");
    }
}


void ArreraUI::on_IDC_ASIX_clicked()
{
    if (!arreraApp->executeApp("six")){
        QMessageBox::critical(this,"Lancement de l'assistant Arrera SIX",
                              "Impossible de lancer votre assistant Arrera SIX.");
    }
}


void ArreraUI::on_IDC_ARYLEY_clicked()
{
    if (!arreraApp->executeApp("ryley")){
        QMessageBox::critical(this,"Lancement de l'assistant Arrera RYLEY",
                              "Impossible de lancer votre assistant Arrera RYLEY.");
    }
}


void ArreraUI::on_IDC_ACOPILOTE_clicked()
{
    if (!arreraApp->executeApp("arrera-copilote")){
        QMessageBox::critical(this,"Lancement de l'assistant Arrera COPILOTE",
                              "Impossible de lancer votre assistant Arrera COPILOTE.");
    }
}

// BTN Mode

void ArreraUI::on_IDC_MODE1_clicked()
{
    if (objSetting->mode1IsSeted()){
        QString app1,app2,app3,app4,assistant;
        objSetting->getAppMode1(&app1,&app2,&app3,&app4);
        assistant = objSetting->getAssistantMode1();
        ui->IDC_APPMODE1->setVisible(launchAppMode(1,app1));
        ui->IDC_APPMODE2->setVisible(launchAppMode(2,app2));
        ui->IDC_APPMODE3->setVisible(launchAppMode(3,app3));
        ui->IDC_APPMODE4->setVisible(launchAppMode(4,app4));
        launchAssistantMode(assistant);
        nameMode = objSetting->getNameMode1();
        ui->LINDICATIONARRERA->setText(nameMode);
        ui->I2025->setCurrentIndex(idPageI2025Mode);
        modeIsActive = true;
        ui->LINCNAMEMODE->setText("Mode : "+nameMode);
    }
}


void ArreraUI::on_IDC_MODE2_clicked()
{
    if (objSetting->mode2IsSeted()){
        QString app1,app2,app3,app4,assistant;
        objSetting->getAppMode2(&app1,&app2,&app3,&app4);
        assistant = objSetting->getAssistantMode2();
        ui->IDC_APPMODE1->setVisible(launchAppMode(1,app1));
        ui->IDC_APPMODE2->setVisible(launchAppMode(2,app2));
        ui->IDC_APPMODE3->setVisible(launchAppMode(3,app3));
        ui->IDC_APPMODE4->setVisible(launchAppMode(4,app4));
        launchAssistantMode(assistant);
        nameMode = objSetting->getNameMode2();
        ui->LINDICATIONARRERA->setText(nameMode);
        ui->I2025->setCurrentIndex(idPageI2025Mode);
        modeIsActive = true;
        ui->LINCNAMEMODE->setText("Mode : "+nameMode);
    }
}


void ArreraUI::on_IDC_MODE3_clicked()
{
    if (objSetting->mode3IsSeted()){
        QString app1,app2,app3,app4,assistant;
        objSetting->getAppMode3(&app1,&app2,&app3,&app4);
        assistant = objSetting->getAssistantMode3();
        ui->IDC_APPMODE1->setVisible(launchAppMode(1,app1));
        ui->IDC_APPMODE2->setVisible(launchAppMode(2,app2));
        ui->IDC_APPMODE3->setVisible(launchAppMode(3,app3));
        ui->IDC_APPMODE4->setVisible(launchAppMode(4,app4));
        launchAssistantMode(assistant);
        nameMode = objSetting->getNameMode3();
        ui->LINDICATIONARRERA->setText(nameMode);
        ui->I2025->setCurrentIndex(idPageI2025Mode);
        modeIsActive = true;
        ui->LINCNAMEMODE->setText("Mode : "+nameMode);
    }
}

void ArreraUI::on_IDC_MODE4_clicked()
{
    if (objSetting->mode4IsSeted()){
        QString app1,app2,app3,app4,assistant;
        objSetting->getAppMode4(&app1,&app2,&app3,&app4);
        assistant = objSetting->getAssistantMode4();
        ui->IDC_APPMODE1->setVisible(launchAppMode(1,app1));
        ui->IDC_APPMODE2->setVisible(launchAppMode(2,app2));
        ui->IDC_APPMODE3->setVisible(launchAppMode(3,app3));
        ui->IDC_APPMODE4->setVisible(launchAppMode(4,app4));
        launchAssistantMode(assistant);
        nameMode = objSetting->getNameMode4();
        ui->LINDICATIONARRERA->setText(nameMode);
        ui->I2025->setCurrentIndex(idPageI2025Mode);
        modeIsActive = true;
        ui->LINCNAMEMODE->setText("Mode : "+nameMode);
    }
}

void ArreraUI::on_IDC_MODE5_clicked()
{
    if (objSetting->mode5IsSeted()){
        QString app1,app2,app3,app4,assistant;
        objSetting->getAppMode5(&app1,&app2,&app3,&app4);
        assistant = objSetting->getAssistantMode5();
        ui->IDC_APPMODE1->setVisible(launchAppMode(1,app1));
        ui->IDC_APPMODE2->setVisible(launchAppMode(2,app2));
        ui->IDC_APPMODE3->setVisible(launchAppMode(3,app3));
        ui->IDC_APPMODE4->setVisible(launchAppMode(4,app4));
        launchAssistantMode(assistant);
        nameMode = objSetting->getNameMode5();
        ui->LINDICATIONARRERA->setText(nameMode);
        ui->I2025->setCurrentIndex(idPageI2025Mode);
        modeIsActive = true;
        ui->LINCNAMEMODE->setText("Mode : "+nameMode);
    }
}

void ArreraUI::on_IDC_MODE6_clicked()
{
    if (objSetting->mode1IsSeted()){
        QString app1,app2,app3,app4,assistant;
        objSetting->getAppMode6(&app1,&app2,&app3,&app4);
        assistant = objSetting->getAssistantMode6();
        ui->IDC_APPMODE1->setVisible(launchAppMode(1,app1));
        ui->IDC_APPMODE2->setVisible(launchAppMode(2,app2));
        ui->IDC_APPMODE3->setVisible(launchAppMode(3,app3));
        ui->IDC_APPMODE4->setVisible(launchAppMode(4,app4));
        launchAssistantMode(assistant);
        nameMode = objSetting->getNameMode6();
        ui->LINDICATIONARRERA->setText(nameMode);
        ui->I2025->setCurrentIndex(idPageI2025Mode);
        modeIsActive = true;
        ui->LINCNAMEMODE->setText("Mode : "+nameMode);
    }
}

// BTN lieu

void ArreraUI::on_IDC_LIEU1_clicked()
{
    objSetting->launchLieu1();
    ui->IDC_LIEU1->setVisible(false);
    ui->IDC_LIEU2->setVisible(false);
    lieuEnabled = 1;
    ui->LINDICATIONARRERA->setText("Bienvenu a "+objSetting->getNameLieu1());
}

void ArreraUI::on_IDC_LIEU2_clicked()
{
    objSetting->launchLieu2();
    ui->IDC_LIEU1->setVisible(false);
    ui->IDC_LIEU2->setVisible(false);
    lieuEnabled=2;
    ui->LINDICATIONARRERA->setText("Bienvenu a "+objSetting->getNameLieu2());
}

// btn QUIT

void ArreraUI::on_IDC_QUIT_clicked()
{
    modeIsActive = false;
    ui->I2025->setCurrentIndex(idPageI2025Main);
}


void ArreraUI::on_IDC_APPMODE1_clicked()
{
    if (app1Mode=="app1"){
         appPC[0].executeApplication();
    }else if(app1Mode=="app2") {
         appPC[1].executeApplication();
    }else if(app1Mode=="app3"){
         appPC[2].executeApplication();
    }else if(app1Mode=="app4"){
         appPC[3].executeApplication();
    }else if(app1Mode =="app5"){
         appPC[4].executeApplication();
    }else if(app1Mode =="app6"){
         appPC[5].executeApplication();
    }else if(app1Mode =="app7"){
         appPC[6].executeApplication();
    }else if(app1Mode =="app8"){
         appPC[7].executeApplication();
    }else if(app1Mode =="app9"){
         appPC[8].executeApplication();
    }else if(app1Mode =="app10"){
         appPC[9].executeApplication();
    }else if(app1Mode =="app11"){
         appPC[10].executeApplication();
    }else if(app1Mode =="app12"){
         appPC[11].executeApplication();
    }else if(app1Mode =="app13"){
         appPC[12].executeApplication();
    }else if(app1Mode =="app14"){
         appPC[13].executeApplication();
    }else if(app1Mode =="app15"){
         appPC[14].executeApplication();
    }else if(app1Mode =="app16"){
         appPC[15].executeApplication();
    }else if(app1Mode =="app17"){
         appPC[16].executeApplication();
    }else if(app1Mode =="app18"){
         appPC[17].executeApplication();
    }else if(app1Mode =="app19"){
         appPC[18].executeApplication();
    }else if(app1Mode =="app20"){
         appPC[19].executeApplication();
    }
}


void ArreraUI::on_IDC_APPMODE2_clicked()
{
    if (app2Mode=="app1"){
         appPC[0].executeApplication();
    }else if(app2Mode=="app2") {
         appPC[1].executeApplication();
    }else if(app2Mode=="app3"){
         appPC[2].executeApplication();
    }else if(app2Mode=="app4"){
         appPC[3].executeApplication();
    }else if(app2Mode =="app5"){
         appPC[4].executeApplication();
    }else if(app2Mode =="app6"){
         appPC[5].executeApplication();
    }else if(app2Mode =="app7"){
         appPC[6].executeApplication();
    }else if(app2Mode =="app8"){
         appPC[7].executeApplication();
    }else if(app2Mode =="app9"){
         appPC[8].executeApplication();
    }else if(app2Mode =="app10"){
         appPC[9].executeApplication();
    }else if(app2Mode =="app11"){
         appPC[10].executeApplication();
    }else if(app2Mode =="app12"){
         appPC[11].executeApplication();
    }else if(app2Mode =="app13"){
         appPC[12].executeApplication();
    }else if(app2Mode =="app14"){
         appPC[13].executeApplication();
    }else if(app2Mode =="app15"){
         appPC[14].executeApplication();
    }else if(app2Mode =="app16"){
         appPC[15].executeApplication();
    }else if(app2Mode =="app17"){
         appPC[16].executeApplication();
    }else if(app2Mode =="app18"){
         appPC[17].executeApplication();
    }else if(app2Mode =="app19"){
         appPC[18].executeApplication();
    }else if(app2Mode =="app20"){
         appPC[19].executeApplication();
    }
}


void ArreraUI::on_IDC_APPMODE3_clicked()
{
    if (app3Mode=="app1"){
         appPC[0].executeApplication();
    }else if(app3Mode=="app2") {
         appPC[1].executeApplication();
    }else if(app3Mode=="app3"){
         appPC[2].executeApplication();
    }else if(app3Mode=="app4"){
         appPC[3].executeApplication();
    }else if(app3Mode =="app5"){
         appPC[4].executeApplication();
    }else if(app3Mode =="app6"){
         appPC[5].executeApplication();
    }else if(app3Mode =="app7"){
         appPC[6].executeApplication();
    }else if(app3Mode =="app8"){
         appPC[7].executeApplication();
    }else if(app3Mode =="app9"){
         appPC[8].executeApplication();
    }else if(app3Mode =="app10"){
         appPC[9].executeApplication();
    }else if(app3Mode =="app11"){
         appPC[10].executeApplication();
    }else if(app3Mode =="app12"){
         appPC[11].executeApplication();
    }else if(app3Mode =="app13"){
         appPC[12].executeApplication();
    }else if(app3Mode =="app14"){
         appPC[13].executeApplication();
    }else if(app3Mode =="app15"){
         appPC[14].executeApplication();
    }else if(app3Mode =="app16"){
         appPC[15].executeApplication();
    }else if(app3Mode =="app17"){
         appPC[16].executeApplication();
    }else if(app3Mode =="app18"){
         appPC[17].executeApplication();
    }else if(app3Mode =="app19"){
         appPC[18].executeApplication();
    }else if(app3Mode =="app20"){
        appPC[19].executeApplication();
    }
}


void ArreraUI::on_IDC_APPMODE4_clicked()
{
    if (app4Mode=="app1"){
         appPC[0].executeApplication();
    }else if(app4Mode=="app2") {
         appPC[1].executeApplication();
    }else if(app4Mode=="app3"){
         appPC[2].executeApplication();
    }else if(app4Mode=="app4"){
         appPC[3].executeApplication();
    }else if(app4Mode =="app5"){
         appPC[4].executeApplication();
    }else if(app4Mode =="app6"){
         appPC[5].executeApplication();
    }else if(app4Mode =="app7"){
         appPC[6].executeApplication();
    }else if(app4Mode =="app8"){
         appPC[7].executeApplication();
    }else if(app4Mode =="app9"){
         appPC[8].executeApplication();
    }else if(app4Mode =="app10"){
         appPC[9].executeApplication();
    }else if(app4Mode =="app11"){
         appPC[10].executeApplication();
    }else if(app4Mode =="app12"){
         appPC[11].executeApplication();
    }else if(app4Mode =="app13"){
         appPC[12].executeApplication();
    }else if(app4Mode =="app14"){
         appPC[13].executeApplication();
    }else if(app4Mode =="app15"){
         appPC[14].executeApplication();
    }else if(app4Mode =="app16"){
         appPC[15].executeApplication();
    }else if(app4Mode =="app17"){
         appPC[16].executeApplication();
    }else if(app4Mode =="app18"){
         appPC[17].executeApplication();
    }else if(app4Mode =="app19"){
         appPC[18].executeApplication();
    }else if(app4Mode =="app20"){
        appPC[19].executeApplication();
    }
}


void ArreraUI::on_IDC_APPLISTMODE_clicked()
{
    on_IDC_APPBUREAU_clicked();
}


void ArreraUI::on_IDC_ARRERAAPPMODE_clicked()
{
    on_IDC_ARRERAAPP_clicked();
}

