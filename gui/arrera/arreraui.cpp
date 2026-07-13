#include "arreraui.h"

ArreraUI::ArreraUI(QWidget *parent)
    : QDialog(parent),
    dectOS(),
    ui(new Ui::ArreraUI),
    objSetting(),
    winMaj(this),
    uipara(this,&objSetting,&arecherche,&dectOS),
    arrera_application(),
    connection_arrera_hub(this),
    serveurAssistant(this),
    tigerDemon("arrera",VERSION,this),
    shortcutReturn(QKeySequence(Qt::Key_Return), this),
    shortcutEnter(QKeySequence(Qt::Key_Enter),  this),
    assistantCommunication(&serveurAssistant,
                             &arecherche,
                             &objSetting,
                             &appPC),
    theme(this)
{
    ui->setupUi(this);
    // Demarage du serveur
    launchGestServeur();
    // Mise en place des bouton
    setWindowFlags(Qt::Window | Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
    // Mise en place du theme
    theme.loadThemeFromJson(":/theme/widget/theme.json");
    // Ajout de l'objet de l'interface des parametre
    // Recuperation ID de widget
    idPageI2025Main = ui->I2025->indexOf(ui->main);
    idPageI2025App = ui->I2025->indexOf(ui->app);
    idPageI2025Mode = ui->I2025->indexOf(ui->mode);
    idPageApropos = ui->I2025->indexOf(ui->apropos);
    idPageRecherche = ui->I2025->indexOf(ui->recherchePage);
    idAppView=ui->appStaked->indexOf(ui->AppView);
    idNoApp=ui->appStaked->indexOf(ui->NoApp);

    idPageDesktopApp = ui->interfaceapp->indexOf(ui->desktopapp);
    idPageArreraApp = ui->interfaceapp->indexOf(ui->arreraapp);
    // Id Page recherche
    idPageRechercheMoteur = ui->arreraRecherche->indexOf(ui->moteur);
    idPageRechercheHist = ui->arreraRecherche->indexOf(ui->historique);
    // Id Acceuil Stacked
    idNonMode = ui->acceuilStacked->indexOf(ui->nomode);
    idYesMode = ui->acceuilStacked->indexOf(ui->yesmode);
    // id arreraAppStacked
    idNoArreraApp = ui->arreraAppStacked->indexOf(ui->noArreraApp);
    idViewArreraApp = ui->arreraAppStacked->indexOf(ui->viewArreraApp);
    // id lieuview
    idNoLieuSave = ui->lieuview->indexOf(ui->nolieu);
    idLieuSave = ui->lieuview->indexOf(ui->yeslieu);
    // id modeview
    idNoModeSave = ui->modeview->indexOf(ui->no);
    idModeSave = ui->modeview->indexOf(ui->yes);
    // Affichage du bon widget au demarage
    ui->I2025->setCurrentIndex(idPageI2025Main);
    // Changement du texte du label LINDICATIONARRERA
    ui->LINDICATIONARRERA->setText("Bienvenue sur Arrera I2026");
    ui->IDC_QUITLIEU->setVisible(false);
    // Connection de l'interface principale est le parametre
    connect(&uipara,&ArreraSettingUI::parametresFerme,this,
            &ArreraUI::loadSetting);

    // Mise en place de bouton d'application

    QVector<QPushButton*> widgets = {
        ui->IDC_APP_001, ui->IDC_APP_002, ui->IDC_APP_003, ui->IDC_APP_004,
        ui->IDC_APP_005, ui->IDC_APP_006, ui->IDC_APP_007, ui->IDC_APP_008,
        ui->IDC_APP_009, ui->IDC_APP_010, ui->IDC_APP_011, ui->IDC_APP_012,
        ui->IDC_APP_013, ui->IDC_APP_014, ui->IDC_APP_015, ui->IDC_APP_016,
        ui->IDC_APP_017, ui->IDC_APP_018, ui->IDC_APP_019, ui->IDC_APP_020
    };

    for (int i = 0; i < widgets.size(); ++i) {
        appPC.append(CAppPC(i + 1, &objSetting, widgets[i], &dectOS));
    }

    // Mise en place des app speciaux
    appNavigateur = CAppSpeciaux(1,&objSetting,ui->IDC_NAVIGATEUR,&dectOS);
    appPresentation = CAppSpeciaux(2,&objSetting,ui->IDC_PRESENTATION,&dectOS);
    appTableur = CAppSpeciaux(3,&objSetting,ui->IDC_TABLEUR,&dectOS);
    appTraitementTexte = CAppSpeciaux(4,&objSetting,ui->IDC_TRAITEMENTTEXTE,&dectOS);
    // Chargement des parametre
    loadSetting();
    // Initilisation de varriable
    modeIsActive = false;
    assistantIsActived = false;
    nameMode = "";
    lieuEnabled = 0;
    // Mise en place de l'image sur le label des mode
    QPixmap pixmap (":/icon/img/logo-Arrera.png");
    ui->LICONARRERA->setPixmap(pixmap.scaled(
        ui->LICONARRERA->size(),
        Qt::KeepAspectRatio, Qt::SmoothTransformation));
    // Mise en place icon A Propos

    if (dectOS.getosApple()){
        QPixmap icon(":/arrera/img/icon-mac.png");
        ui->IDC_LAPOPROSICON->setPixmap(icon.scaled(
            ui->IDC_LAPOPROSICON->size(),
            Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }else{
        QPixmap icon(":/arrera/img/icon-linux-win.png");
        ui->IDC_LAPOPROSICON->setPixmap(icon.scaled(
            ui->IDC_LAPOPROSICON->size(),
            Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }

    searchBarAssistantMode = false;

    // Ecriture du numero de version
    ui->IDC_APROPOSVERSION->setText(tigerDemon.get_version());
    // Mise en place de la touche entre pour la recherche
    connect(&shortcutEnter,&QShortcut::activated,this,&ArreraUI::searchEnter);
    connect(&shortcutReturn,&QShortcut::activated,this,&ArreraUI::searchEnter);

    // Connection de signaux de tiger demon

    connect(&tigerDemon, &CTigerDemon::updateResult, this, [=](bool hasUpdate, QString newVersion){
        if (hasUpdate) {
            ui->IDC_VIEW_MAJ->setVisible(true);
            ui->IDC_VIEW_MAJ->setText("La version " +newVersion+ " est disponible");
            winMaj.set_new_version(newVersion);
            winMaj.show();
            winMaj.raise();
            winMaj.activateWindow();
        }else {
            ui->IDC_VIEW_MAJ->setVisible(false);
        }
    });

    connect(&tigerDemon, &CTigerDemon::updateError, this, [=](int errorCode){
        if (errorCode == -1){
            ui->IDC_VIEW_MAJ->setVisible(true);
            ui->IDC_VIEW_MAJ->setText("Impossible de vérifier les mises à jour, une erreur réseau s'est produite");
        }else if (errorCode == -2){
            ui->IDC_VIEW_MAJ->setVisible(true);
            ui->IDC_VIEW_MAJ->setText("Impossible de vérifier les mises à jour");
        }else{
            ui->IDC_VIEW_MAJ->setVisible(false);
        }
    });

    nameAssistantConnected = "";

    ui->ACTIONASSISTANT->setVisible(false);
    ui->IDC_MODESEARCHBAR->setVisible(false);

    QIcon icon;
    icon.addFile(":/icon/img/search.png",   QSize(), QIcon::Normal, QIcon::Off);
    icon.addFile(":/icon/img/Assistant.png",QSize(), QIcon::Normal, QIcon::On);

    ui->IDC_MODESEARCHBAR->setCheckable(true);
    ui->IDC_MODESEARCHBAR->setIcon(icon);

    ui->IDC_MODESEARCHBAR->setChecked(searchBarAssistantMode);

    // Demarage du websocket pour la connection a Arrera Hub
    if (connection_arrera_hub.startServeur(2026)){

        connect(&connection_arrera_hub, &CArreraServeur::connectClient, this, [this](){
            this->ui->LINDICATIONARRERA->setText("Arrera Hub est prêt à gérer vos applications");
        });

        connect(&connection_arrera_hub, &CArreraServeur::messageReceived,
                this,
                [this](const QString &nameSoft, const QString &message) {
            if (nameSoft == "arrera_hub"){
                if (message.trimmed() == "update_app"){
                    loadArreraApp();
                }
            }
        });
    }
}

ArreraUI::~ArreraUI()
{
    delete ui;
}

void ArreraUI::show(){
    QDialog::show();
    tigerDemon.checkUpdate();
}

void ArreraUI::on_IDC_ACCEUILARRERA_clicked() // Bouton Arrera en haut a gauche
{
    int index = ui->I2025->currentIndex();

    if ((index == idPageI2025Main) || (index == idPageI2025Mode))
    {
        ui->I2025->setCurrentIndex(idPageApropos);
        ui->LINDICATIONARRERA->setText("Arrera I2026 A propos");

    } else if (index != idPageI2025Main){
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
            ui->LINDICATIONARRERA->setText("Arrera I2026");
            ui->IDC_SHOWHIST->setVisible(true);
            ui->IDC_AUTREMOTEUR->setVisible(true);
        }
    }
    else if (lieuEnabled != 0)
    {
        int ret = QMessageBox::question(nullptr,
                                        "Quitter le lieu",
                                        "Voulez-vous quitter le lieu en cours ?",
                                        QMessageBox::Yes | QMessageBox::No);

        if (ret == QMessageBox::Yes)
        {
            switch (lieuEnabled) {
            case 1:
                objSetting.disableLieu1();
                lieuEnabled = 0;
                break;
            case 2:
                objSetting.disableLieu2();
                lieuEnabled = 2;
                break;
            default:
                break;
            }
        }
        else
        {
            ui->I2025->setCurrentIndex(idPageApropos);
            ui->LINDICATIONARRERA->setText("Arrera I2026 A propos");
        }
    }
}

// Bar des taches
void ArreraUI::on_IDC_APPBUREAU_clicked()
{
    ui->I2025->setCurrentIndex(idPageI2025App);
    ui->LINDICATIONARRERA->setText("Page application de l'ordinateur");
    ui->IDC_CHANGEVIEWAPP->setText("Application Arrera");
    ui->interfaceapp->setCurrentIndex(idPageDesktopApp);
    desktopApp = false;
}

void ArreraUI::on_IDC_CHANGEVIEWAPP_clicked()
{
    if (!desktopApp){
        ui->interfaceapp->setCurrentIndex(idPageArreraApp);
        ui->LINDICATIONARRERA->setText("Page module Arrera");
        loadArreraApp();
        ui->IDC_CHANGEVIEWAPP->setText("Application Bureau");
        desktopApp = true;
    }else{
        ui->LINDICATIONARRERA->setText("Page application de l'ordinateur");
        ui->IDC_CHANGEVIEWAPP->setText("Application Arrera");
        ui->interfaceapp->setCurrentIndex(idPageDesktopApp);
        desktopApp = false;
    }
}

void ArreraUI::on_IDC_TIGER_clicked()
{
    bool sortie = arrera_application.open_arrera_hub();
    if (!sortie){
        QMessageBox::critical(this,"Arrera",
                              "Un problème est survenu au lancement d'Arrera Hub. Il n'est peut-être pas installé.");
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

void ArreraUI::on_IDC_CHECK_UPDATE_clicked()
{
    tigerDemon.checkUpdate();
}


void ArreraUI::on_IDC_PARA_clicked()
{
    uipara.show();
}

void ArreraUI::loadSetting()
{
    ui->acceuilStacked->setCurrentIndex(idNonMode);

    // Partie Mode
    if (!loadMode()){
        QMessageBox::information(this,
                                 "Information",
                                 "Les modes ne sont pas charger correctement");
    }

    // Partie lieu

    if (!loadLieu()){
        QMessageBox::information(this,
                                 "Information",
                                 "Les lieu ne sont pas charger correctement");
    }

    // Partie APP

    if (!loadApp()){
        QMessageBox::information(this,
                                 "Information",
                                 "Un probleme est survenu lors du chargement des application enregistrer");
    }
    arrera_application.load_hub_config_file();
    loadArreraApp();

}

bool ArreraUI::loadApp()
{
    if (!ui) {
        return false;
    }

    bool anyAppSetted = false,appSetted;

    try {
        const int count = std::size(appPC);

        for (int i = 0; i < count; ++i) {

            appPC[i].loadData();

            if (appPC[i].getAppSetted()) {
                anyAppSetted = true;
            }
        }

        if (!anyAppSetted) {
            ui->appStaked->setCurrentIndex(idNoApp);
            appSetted = false;
        } else {
            ui->appStaked->setCurrentIndex(idAppView);
            appSetted = true;
        }

        appNavigateur.loadData();
        appPresentation.loadData();
        appTableur.loadData();
        appTraitementTexte.loadData();

        bool anyExtraAppSetted =
            appNavigateur.getAppSetted() ||
            appPresentation.getAppSetted() ||
            appTableur.getAppSetted() ||
            appTraitementTexte.getAppSetted();

        ui->IDC_APPLISTMODE->setVisible(anyExtraAppSetted || appSetted);
    }
    catch (const std::exception &e) {
        qWarning() << "Exception in loadArreraApp() :" << e.what();
        return false;
    }
    catch (...) {
        qWarning() << "Unknown exception in loadArreraApp()";
        return false;
    }

    return true;
}


bool ArreraUI::loadLieu(){
    LieuConfig lieu[] = {
        {ui->IDC_LIEU1, [&]{return objSetting.lieu1IsSeted();},[&]{return objSetting.iconLieu1IsSetted();},
         [&]{return objSetting.getIconLieu1();},[&]{return objSetting.getNameLieu1();},
         ":/mode-lieu/img/lieu1.png",1},
        ui->IDC_LIEU2, [&]{return objSetting.lieu2IsSeted();},[&]{return objSetting.iconLieu2IsSetted();},
        [&]{return objSetting.getIconLieu2();},[&]{return objSetting.getNameLieu2();},
        ":/mode-lieu/img/lieu2.png",2};

    bool atLeastOne = false;

    ui->lieuview->setCurrentIndex(idNoLieuSave);

    try{
        for (auto &l : lieu){
            if (!l.isSet()) {
                l.button->setVisible(false);
                continue;
            }

            atLeastOne = true;
            l.button->setVisible(true);

            QString iconPath = l.iconIsSet() ? l.getIcon() : l.defaultIcon;

            if (QFile::exists(iconPath)) {
                l.button->setIcon(QIcon(iconPath));
            } else {
                l.button->setIcon(QIcon(l.defaultIcon));
            }
        }

        if (atLeastOne) {
            ui->lieuview->setCurrentIndex(idLieuSave);
        }

        return true;
    }
    catch(std::exception &e){
        qWarning() << "Exception in loadArreraApp() :" << e.what();
        return false;
    }catch(...){
        qWarning() << "Unknown exception in loadArreraApp()";
        return false;
    }
}


bool ArreraUI::loadMode(){

    ModeConfig modes[] = {
      { ui->IDC_MODE1, [&]{return objSetting.mode1IsSeted();}, [&]{return objSetting.iconMode1IsSetted();},
       [&]{return objSetting.getIconMode1();}, [&]{return objSetting.getNameMode1();}, ":mode-lieu/img/mode1.png", 1 },

      { ui->IDC_MODE2, [&]{return objSetting.mode2IsSeted();}, [&]{return objSetting.iconMode2IsSetted();},
       [&]{return objSetting.getIconMode2();}, [&]{return objSetting.getNameMode2();}, ":mode-lieu/img/mode2.png", 2 },

      { ui->IDC_MODE3, [&]{return objSetting.mode3IsSeted();}, [&]{return objSetting.iconMode3IsSetted();},
       [&]{return objSetting.getIconMode3();}, [&]{return objSetting.getNameMode3();}, ":mode-lieu/img/mode3.png", 3 },

      { ui->IDC_MODE4, [&]{return objSetting.mode4IsSeted();}, [&]{return objSetting.iconMode4IsSetted();},
       [&]{return objSetting.getIconMode4();}, [&]{return objSetting.getNameMode4();}, ":mode-lieu/img/mode4.png", 4 },

      { ui->IDC_MODE5, [&]{return objSetting.mode5IsSeted();}, [&]{return objSetting.iconMode5IsSetted();},
       [&]{return objSetting.getIconMode5();}, [&]{return objSetting.getNameMode5();}, ":mode-lieu/img/mode5.png", 5 },

      { ui->IDC_MODE6, [&]{return objSetting.mode6IsSeted();}, [&]{return objSetting.iconMode6IsSetted();},
       [&]{return objSetting.getIconMode6();}, [&]{return objSetting.getNameMode6();}, ":mode-lieu/img/mode6.png", 6 },
      };


    QString modeSendAssistant;
    bool atLeastOne = false;

    ui->acceuilStacked->setCurrentIndex(idYesMode);
    ui->modeview->setCurrentIndex(idNoModeSave);

    try {
        for (auto &m : modes)
        {
            if (!m.isSet()) {
                m.button->setVisible(false);
                continue;
            }

            atLeastOne = true;

            m.button->setVisible(true);

            QString iconPath = m.iconIsSet() ? m.getIcon() : m.defaultIcon;

            if (QFile::exists(iconPath)) {
                m.button->setIcon(QIcon(iconPath));
            } else {
                qWarning() << "Icon missing for mode" << m.index << ":" << iconPath;
                m.button->setIcon(QIcon(m.defaultIcon));
            }

            modeSendAssistant += "|" + QString("mode%1:%2").arg(m.index).arg(m.getName());
        }

        if (atLeastOne) {
            ui->acceuilStacked->setCurrentIndex(idYesMode);
            ui->modeview->setCurrentIndex(idModeSave);
        }

        if (!modeSendAssistant.isEmpty()) {
            serveurAssistant.sendMessage(nameAssistantConnected, "namemode" + modeSendAssistant);
        }

        return true;
    }catch (const std::exception& e)
    {
        return false;
    }
    catch (...)
    {
        return false;
    }

}

void ArreraUI::loadArreraApp(){
    QString gui_six = objSetting.get_gui_six();
    // Page d'application
    ui->IDC_APOSTITE->setVisible(false);
    ui->IDC_POSTIT->setVisible(false);
    ui->IDC_ACOPILOTE->setVisible(false);
    ui->IDC_ASIX->setVisible(false);
    ui->IDC_ARYLEY->setVisible(false);

    // Page d'acceuille
    ui->IDC_SIX->setVisible(false);
    ui->IDC_COPILOTE->setVisible(false);
    ui->IDC_RYLEY->setVisible(false);
    ui->IDC_ARRERA_MARKDOWN->setVisible(false);

    if (objSetting.getTaskbarPostite()) arrera_application.load_arrera_application("markdown",ui->IDC_ARRERA_MARKDOWN);

    if (!assistantIsActived){
        if (objSetting.getTaskbarBTNRyley()) arrera_application.load_arrera_application("ryley",ui->IDC_RYLEY);

        if (objSetting.getTaskbarBTNSix()) {
            if (gui_six == "normal"){
                arrera_application.load_arrera_application("six",ui->IDC_SIX);
            }else if (gui_six == "chat"){
                arrera_application.load_arrera_application("six_chat",ui->IDC_SIX);
            }else{
                arrera_application.load_arrera_application("six",ui->IDC_SIX);
            }
        }

        if (objSetting.getTaskbarCopilote()) arrera_application.load_arrera_application("copilot",ui->IDC_COPILOTE);
    }

    arrera_application.load_arrera_application("copilot",ui->IDC_ACOPILOTE);
    arrera_application.load_arrera_application("ryley",ui->IDC_ARYLEY);
    arrera_application.load_arrera_application("markdown",ui->IDC_APOSTITE);
    arrera_application.load_arrera_application("post-it",ui->IDC_POSTIT);

    if (gui_six == "normal"){
        arrera_application.load_arrera_application("six",ui->IDC_ASIX);
    }else if (gui_six == "chat"){
        arrera_application.load_arrera_application("six_chat",ui->IDC_ASIX);
    }else{
        arrera_application.load_arrera_application("six",ui->IDC_ASIX);
    }
}

bool ArreraUI::launchAppMode(int nbApp,QString app){

    static QPushButton* modeButtons[4] = {
            ui->IDC_APPMODE1,
            ui->IDC_APPMODE2,
            ui->IDC_APPMODE3,
            ui->IDC_APPMODE4
    };

    // Vérification nbApp
    if ((nbApp < 1 )|| (nbApp > 4)){
        return false;
    }

    if (!app.startsWith("app")){
        return false;
    }

    bool ok = false;
    int index = app.mid(3).toInt(&ok) - 1; // "7" → 7 → index=6 (0-based)
    if (!ok || index < 0 || index >= appPC.size()){
        return false;
    }


    switch (nbApp) {
    case 1: app1Mode = app; break;
    case 2: app2Mode = app; break;
    case 3: app3Mode = app; break;
    case 4: app4Mode = app; break;
    }


    QPushButton *btn = modeButtons[nbApp - 1];

    QString name = appPC[index].getName();
    QString icon = appPC[index].getIcon();
    bool sortieExe = appPC[index].executeApplication();


    // Mise à jour UI
    if (icon != "nothing") {
        btn->setIcon(QIcon(icon));
        btn->setText("");
    } else {
        btn->setIcon(QIcon());
        btn->setText(name);
    }

    return sortieExe;
}

bool ArreraUI::launchAssistantMode(QString assistant){
    if (assistant=="SIX"){
        if (arrera_application.load_arrera_application("six",ui->IDC_ASSISTANT)){
            assistantMode = "six";
            ui->IDC_ASSISTANT->clicked();
            return true;
        }else return false;
    }else if (assistant == "RYLEY"){
        if (arrera_application.load_arrera_application("ryley",ui->IDC_ASSISTANT)){
            assistantMode = "ryley";
            ui->IDC_ASSISTANT->clicked();
            return true;
        }return false;
    }else if (assistant == "COPILOTE"){
        if (arrera_application.load_arrera_application("copilote",ui->IDC_ASSISTANT)){
            assistantMode = "arrera-copilote";
            ui->IDC_ASSISTANT->clicked();
            return true;
        }return false;
    }else{
        ui->IDC_ASSISTANT->setVisible(false);
        return false;
    }
}

void ArreraUI::launchGestServeur(){
    serveurAssistant.startServeur(6666);

    // Partie serveur assistant
    connect(&serveurAssistant,&CArreraServeur::connectClient,[this](){
        ui->LINDICATIONARRERA->setText("Un assistant est connectée");
        ui->IDC_SIX->setVisible(false);
        ui->IDC_COPILOTE->setVisible(false);
        ui->IDC_RYLEY->setVisible(false);
        assistantIsActived = true;
        ui->ACTIONASSISTANT->setVisible(true);
        ui->IDC_MODESEARCHBAR->setVisible(true);
        ui->lieuview->setVisible(false);
    });
    connect(&serveurAssistant,&CArreraServeur::clientDeconected,[this](){
        ui->LINDICATIONARRERA->setText("L'assistant et deconnecter");
        ui->IDC_SIX->setVisible(objSetting.getTaskbarBTNSix());
        ui->IDC_COPILOTE->setVisible(objSetting.getTaskbarCopilote());
        ui->IDC_RYLEY->setVisible(objSetting.getTaskbarBTNRyley());
        assistantIsActived = false;
        nameAssistantConnected = "";
        ui->ACTIONASSISTANT->setVisible(false);
        ui->IDC_MODESEARCHBAR->setVisible(false);
        searchBarAssistantMode = false;
        ui->lieuview->setVisible(true);
    });
    connect(&serveurAssistant, &CArreraServeur::messageReceived,
            [this](const QString &nameSoft, const QString &message)
            {
                assistantCommunication.treatment(nameSoft,message);
                if (nameAssistantConnected.isEmpty()){
                    nameAssistantConnected = nameSoft;
                    loadMode();
                }
            });

    connect(&assistantCommunication, &assistant::textTopLabel,
            this, [this](const QString message) {
                ui->LINDICATIONARRERA->setText(message);
            });

    connect(&assistantCommunication, &assistant::launchMode,
            this, [this](const int nb) {
                QMetaObject::invokeMethod(this, [this, nb]() {
                    // ton switch ici
                    switch (nb) {
                    case 1: on_IDC_MODE1_clicked(); break;
                    case 2: on_IDC_MODE2_clicked(); break;
                    case 3: on_IDC_MODE3_clicked(); break;
                    case 4: on_IDC_MODE3_clicked(); break;
                    case 5: on_IDC_MODE4_clicked(); break;
                    case 6: on_IDC_MODE5_clicked(); break;
                    default:break;
                    }
                }, Qt::QueuedConnection);   // <---- IMPORTANT !!!
            });

    connect(&assistantCommunication, &assistant::closeMode,
            this,[this]() {QMetaObject::invokeMethod(this,[this]() {
                                on_IDC_QUIT_clicked();},Qt::QueuedConnection);
    });


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
            ui->LINDICATIONARRERA->setText("Recheche sur duckduckgo");
            break;
        case 2: // google
            sortie = arecherche.searchGoogle(recherche);
            ui->LINDICATIONARRERA->setText("Recheche sur google");
            break;
        case 3: // qwant
            sortie = arecherche.searchQwant(recherche);
            ui->LINDICATIONARRERA->setText("Recheche sur QWANT");
            break;
        case 4: // ecosia
            sortie = arecherche.searchEcosia(recherche);
            ui->LINDICATIONARRERA->setText("Recheche sur Ecosia");
            break;
        case 5: // brave
            sortie = arecherche.searchBrave(recherche);
            ui->LINDICATIONARRERA->setText("Recheche sur Brave");
            break;
        case 6: // bing
            sortie = arecherche.searchBing(recherche);
            ui->LINDICATIONARRERA->setText("Recheche sur Bing");
            break;
        case 7: // amazon
            sortie = arecherche.searchAmazon(recherche);
            ui->LINDICATIONARRERA->setText("Recheche sur Amazon");
            break;
        case 8: // wikipedia
            sortie = arecherche.searchWikipedia(recherche);
            ui->LINDICATIONARRERA->setText("Recheche sur Wikipedia");
            break;
        case 9: // reverso
            sortie = arecherche.searchReverso(recherche);
            ui->LINDICATIONARRERA->setText("Recheche sur Reverso");
            break;
        case 10: // wordreference
            sortie = arecherche.searchWordreference(recherche);
            ui->LINDICATIONARRERA->setText("Recheche sur WordReference");
            break;
        case 11: // YT
            sortie = arecherche.searchYTmusic(recherche);
            ui->LINDICATIONARRERA->setText("Recheche sur YT Music");
            break;
        case 12: // all
            sortie = arecherche.searchAll(recherche);
            ui->LINDICATIONARRERA->setText("BigSearch");

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

void ArreraUI::on_IDC_MODESEARCHBAR_clicked()
{
    if (searchBarAssistantMode){
        searchBarAssistantMode = false;
        ui->LINDICATIONARRERA->setText("Bar de recherche en mode recherche");
    }else {
        searchBarAssistantMode = true;
        ui->LINDICATIONARRERA->setText("Bar de recherche en mode requette assistant");
    }
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

// BTN Mode

bool ArreraUI::launchMode(int index)
{
    QString app1,app2,app3,app4,assistant,textAssistant,img;
    QPixmap *icon;
    bool ok = false;

    switch (index) {
    case 1:
        if (objSetting.mode1IsSeted()){
            ok = true;
            objSetting.getAppMode1(&app1,&app2,&app3,&app4);
            assistant = objSetting.getAssistantMode1();
            nameMode = objSetting.getNameMode1();
            img = objSetting.getIconMode1();
            if ((img == "error") || (img == "nothing")){
                icon = new QPixmap(":/mode-lieu/img/mode1.png");
            }else {
                icon = new QPixmap(img);
            }
            textAssistant = "mode-one-launch name:"+nameMode;
        }else {ok=false;}
        break;
    case 2:
        if (objSetting.mode2IsSeted()){
            ok = true;
            objSetting.getAppMode2(&app1,&app2,&app3,&app4);
            assistant = objSetting.getAssistantMode2();
            nameMode = objSetting.getNameMode2();
            img = objSetting.getIconMode2();
            if ((img == "error") || (img == "nothing")){
                icon = new QPixmap(":/mode-lieu/img/mode2.png");
            }else {
                icon = new QPixmap(img);
            }
            textAssistant = "mode-two-launch name:"+nameMode;
        }else{ok = false;}
        break;
    case 3:
        if (objSetting.mode3IsSeted()){
            ok = true;
            objSetting.getAppMode3(&app1,&app2,&app3,&app4);
            assistant = objSetting.getAssistantMode3();
            nameMode = objSetting.getNameMode3();
            img = objSetting.getIconMode3();
            if ((img == "error") || (img == "nothing")){
                icon = new QPixmap(":/mode-lieu/img/mode3.png");
            }else {
                icon = new QPixmap(img);
            }
            textAssistant = "mode-theer-launch name:"+nameMode;
        }else{ok = false;}
        break;
    case 4:
        if (objSetting.mode4IsSeted()){
            ok = true;
            objSetting.getAppMode4(&app1,&app2,&app3,&app4);
            assistant = objSetting.getAssistantMode4();
            nameMode = objSetting.getNameMode4();
            img = objSetting.getIconMode4();
            if ((img == "error") || (img == "nothing")){
                icon = new QPixmap(":/mode-lieu/img/mode4.png");
            }else {
                icon = new QPixmap(img);
            }
            textAssistant = "mode-four-launch name:"+nameMode;
        }else{ok = false;}
        break;
    case 5:
        if (objSetting.mode5IsSeted()){
            ok = true;
            objSetting.getAppMode5(&app1,&app2,&app3,&app4);
            assistant = objSetting.getAssistantMode5();
            nameMode = objSetting.getNameMode5();
            img = objSetting.getIconMode5();
            if ((img == "error") || (img == "nothing")){
                icon = new QPixmap(":/mode-lieu/img/mode5.png");
            }else {
                icon = new QPixmap(img);
            }
            textAssistant = "mode-five-launch name:"+nameMode;
        }else{ok = false;}
        break;
    case 6 :
        if (objSetting.mode6IsSeted()){
            ok = true;
            objSetting.getAppMode6(&app1,&app2,&app3,&app4);
            assistant = objSetting.getAssistantMode6();
            nameMode = objSetting.getNameMode6();
            img = objSetting.getIconMode6();
            if ((img == "error") || (img == "nothing")){
                icon = new QPixmap(":/mode-lieu/img/mode6.png");
            }else {
                icon = new QPixmap(img);
            }
            textAssistant = "mode-six-launch name:"+nameMode;
        }else{ok=false;}
        break;
    default:
        break;
    }


    if (ok){
        ui->IDC_APPMODE1->setVisible(launchAppMode(1,app1));
        ui->IDC_APPMODE2->setVisible(launchAppMode(2,app2));
        ui->IDC_APPMODE3->setVisible(launchAppMode(3,app3));
        ui->IDC_APPMODE4->setVisible(launchAppMode(4,app4));
        ui->LINDICATIONARRERA->setText(nameMode);
        ui->I2025->setCurrentIndex(idPageI2025Mode);
        ui->LICONARRERA->setPixmap(icon->scaled(
            ui->LICONARRERA->size(),
            Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->LINCNAMEMODE->setText("Mode : "+nameMode);
        modeIsActive = true;
        if (!assistantIsActived){
            launchAssistantMode(assistant);
        }else{
            serveurAssistant.sendMessage(nameAssistantConnected,textAssistant);
        }
        return true;
    }else{
        return false;
    }
}

void ArreraUI::on_IDC_MODE1_clicked()
{
    if (!launchMode(1)){
        QMessageBox::critical(this, "Erreur",
            "Une erreur c'est produite lors du lancement du mode");
    }else{modelaunched = "mode1";}
}


void ArreraUI::on_IDC_MODE2_clicked()
{
    if (!launchMode(2)){
        QMessageBox::critical(this, "Erreur",
                              "Une erreur c'est produite lors du lancement du mode");
    }else{modelaunched = "mode2";}
}


void ArreraUI::on_IDC_MODE3_clicked()
{
    if (!launchMode(3)){
        QMessageBox::critical(this, "Erreur",
                              "Une erreur c'est produite lors du lancement du mode");
    }else{modelaunched = "mode3";}
}

void ArreraUI::on_IDC_MODE4_clicked()
{
    if (!launchMode(4)){
        QMessageBox::critical(this, "Erreur",
                              "Une erreur c'est produite lors du lancement du mode");
    }else{modelaunched = "mode4";}
}

void ArreraUI::on_IDC_MODE5_clicked()
{
    if (!launchMode(5)){
        QMessageBox::critical(this, "Erreur",
                              "Une erreur c'est produite lors du lancement du mode");
    }else{modelaunched = "mode5";}
}

void ArreraUI::on_IDC_MODE6_clicked()
{
    if (!launchMode(6)){
        QMessageBox::critical(this, "Erreur",
                              "Une erreur c'est produite lors du lancement du mode");
    }else{modelaunched = "mode6";}
}

// BTN lieu

void ArreraUI::on_IDC_LIEU1_clicked()
{
    objSetting.launchLieu1(ui->IDC_SIX,ui->IDC_RYLEY,ui->IDC_COPILOTE);
    ui->IDC_LIEU1->setVisible(false);
    ui->IDC_LIEU2->setVisible(false);
    ui->IDC_QUITLIEU->setVisible(true);
    lieuEnabled = 1;
    ui->LINDICATIONARRERA->setText("Bienvenu a "+objSetting.getNameLieu1());
}

void ArreraUI::on_IDC_LIEU2_clicked()
{
    objSetting.launchLieu2(ui->IDC_SIX,ui->IDC_RYLEY,ui->IDC_COPILOTE);
    ui->IDC_LIEU1->setVisible(false);
    ui->IDC_LIEU2->setVisible(false);
    ui->IDC_QUITLIEU->setVisible(true);
    lieuEnabled=2;
    ui->LINDICATIONARRERA->setText("Bienvenu a "+objSetting.getNameLieu2());
}

void ArreraUI::on_IDC_QUITLIEU_clicked()
{
    lieuEnabled=0;
    ui->IDC_SIX->setVisible(objSetting.getTaskbarBTNSix());
    ui->IDC_COPILOTE->setVisible(objSetting.getTaskbarCopilote());
    ui->IDC_RYLEY->setVisible(objSetting.getTaskbarBTNRyley());
    ui->LINDICATIONARRERA->setText("Sortie du lieu");
    ui->IDC_QUITLIEU->setVisible(false);

    if (objSetting.lieu1IsSeted()){
        ui->IDC_LIEU1->setVisible(true);
    }else{
        ui->IDC_LIEU1->setVisible(false);
    }

    if (objSetting.lieu2IsSeted()){
        ui->IDC_LIEU2->setVisible(true);
    }else{
        ui->IDC_LIEU2->setVisible(false);
    }
}

// btn QUIT

void ArreraUI::on_IDC_QUIT_clicked()
{
    if (modeIsActive){
        QString message = "close mode "+modelaunched;
        modeIsActive = false;
        ui->I2025->setCurrentIndex(idPageI2025Main);
        loadArreraApp();
        serveurAssistant.sendMessage(nameAssistantConnected,message);
        modelaunched = nullptr;
    }
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

void ArreraUI::searchEnter()
{
    if (!ui->IDC_SEARCHBAR->text().isEmpty()){
        if(!searchBarAssistantMode){
            QString moteur = objSetting.getMoteurRecherche();
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
        }else{
            serveurAssistant.sendMessage(nameAssistantConnected,
                                         "requette : "+ui->IDC_SEARCHBAR->text());
            ui->LINDICATIONARRERA->setText("L'assistant vas vous repondre");
            ui->IDC_SEARCHBAR->clear();
        }
    }else{
        ui->LINDICATIONARRERA->setText("La bar de recherche est vide");
    }
}

void ArreraUI::closeEvent(QCloseEvent *event)
{
    if (assistantIsActived){
        serveurAssistant.sendMessage(nameAssistantConnected,"stop");
    }
    connection_arrera_hub.sendMessage("arrera_hub","stop");

    winMaj.close();

    if (uipara.isVisible()) uipara.close();

    connection_arrera_hub.stopServeur();
    QDialog::closeEvent(event);
}

// Bouton pour envoyer des ordes a l'assistant

void ArreraUI::on_IDC_BREEF_clicked()
{
    serveurAssistant.sendMessage(nameAssistantConnected,"breef");
}


void ArreraUI::on_IDC_METEO_clicked()
{
    serveurAssistant.sendMessage(nameAssistantConnected,"weather");
}


void ArreraUI::on_IDC_TASK_clicked()
{
    serveurAssistant.sendMessage(nameAssistantConnected,"task");
}


void ArreraUI::on_IDC_AGENDA_clicked()
{
    serveurAssistant.sendMessage(nameAssistantConnected,"agenda");
}
