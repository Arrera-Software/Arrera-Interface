#include "arreraui.h"

ArreraUI::ArreraUI(QWidget *parent)
    : QDialog(parent),
    dectOS(),
    ui(new Ui::ArreraUI),
    objSetting(),
    uipara(this,&objSetting,&arecherche,&dectOS),
    appManager(&objSetting, &dectOS, this),
    tigerDemon("arrera",VERSION,this),
    shortcutReturn(QKeySequence(Qt::Key_Return), this),
    shortcutEnter(QKeySequence(Qt::Key_Enter),  this),
    annBus(&arecherche, &objSetting, appManager.getAppPCList(), this),
    theme(this),
    assistantIsActived(false),
    searchBarAssistantMode(false)
{
    ui->setupUi(this);
    // Demarage du serveur
    connect(&annBus, &CArreraBus::assistantConnected, this, [this]() {
        assistantIsActived = true;
        ui->ACTIONASSISTANT->setVisible(true);
        ui->IDC_MODESEARCHBAR->setVisible(true);
    });

    connect(&annBus, &CArreraBus::assistantDisconnected, this, [this]() {
        assistantIsActived = false;
        searchBarAssistantMode = false;
        ui->IDC_MODESEARCHBAR->setChecked(false);
        ui->ACTIONASSISTANT->setVisible(false);
        ui->IDC_MODESEARCHBAR->setVisible(false);
    });

    connect(&annBus, &CArreraBus::statusMessageChanged, this, [this](const QString &message) {
        ui->LINDICATIONARRERA->setText(message);
    });

    connect(&annBus, &CArreraBus::hubAppUpdated, this, &ArreraUI::loadArreraApp);

    connect(&appManager, &CAppManager::desktopAppsLoaded, this, [this](bool hasAny) {
        ui->appStaked->setCurrentIndex(hasAny ? idAppView : idNoApp);
    });

    annBus.launchGestServeur();
    // Mise en place des bouton
    setWindowFlags(Qt::Window | Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
    // Mise en place du theme
    theme.setTheme(QStringLiteral("default"));
    // Ajout de l'objet de l'interface des parametre
    // Recuperation ID de widget
    idPageI2025Main = ui->I2025->indexOf(ui->main);
    idPageI2025App = ui->I2025->indexOf(ui->app);
    idPageApropos = ui->I2025->indexOf(ui->apropos);
    idPageRecherche = ui->I2025->indexOf(ui->recherchePage);
    idAppView=ui->appStaked->indexOf(ui->AppView);
    idNoApp=ui->appStaked->indexOf(ui->NoApp);

    // Id Page recherche
    idPageRechercheMoteur = ui->arreraRecherche->indexOf(ui->moteur);
    idPageRechercheHist = ui->arreraRecherche->indexOf(ui->historique);
    // Affichage du bon widget au demarage
    ui->I2025->setCurrentIndex(idPageI2025Main);
    // Changement du texte du label LINDICATIONARRERA
    ui->LINDICATIONARRERA->setText("Bienvenue sur Arrera I2026");
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

    // Mise en place des app speciaux
    appManager.setupDesktopApps(widgets,
                            ui->IDC_NAVIGATEUR,
                            ui->IDC_PRESENTATION,
                            ui->IDC_TABLEUR,
                            ui->IDC_TRAITEMENTTEXTE);
    // Chargement des parametre
    loadSetting();
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

    const QList<QPair<QPushButton*, int>> searchButtons = {
        {ui->IDC_MOTEURDUCK, 1},
        {ui->IDC_MOTEURGOOGLE, 2},
        {ui->IDC_MOTEURQWANT, 3},
        {ui->IDC_MOTEURECOSIA, 4},
        {ui->IDC_MOTEURBRAVE, 5},
        {ui->IDC_MOTEURBING, 6},
        {ui->IDC_MOTEURAMAZON, 7},
        {ui->IDC_MOTEURWIKIPEDIA, 8},
        {ui->IDC_MOTEURREVERSO, 9},
        {ui->IDC_MOTEURWORDREFERENCE, 10},
        {ui->IDC_MOTEURYT, 11},
        {ui->IDC_MOTEURBIGSEARCH, 12}
    };
    for (const auto &entry : searchButtons) {
        connect(entry.first, &QPushButton::clicked, this, [this, mode = entry.second]() {
            launchSearch(mode);
        });
    }

    // Connection de signaux de tiger demon
    connect(&tigerDemon, &CTigerDemon::updateStatusChanged,
            this, [this](bool visible, const QString &message) {
        ui->IDC_VIEW_MAJ->setVisible(visible);
        if (visible) {
            ui->IDC_VIEW_MAJ->setText(message);
        }
    });

    ui->ACTIONASSISTANT->setVisible(false);
    ui->IDC_MODESEARCHBAR->setVisible(false);

    QIcon icon;
    icon.addFile(":/icon/img/search.png",   QSize(), QIcon::Normal, QIcon::Off);
    icon.addFile(":/icon/img/Assistant.png",QSize(), QIcon::Normal, QIcon::On);

    ui->IDC_MODESEARCHBAR->setCheckable(true);
    ui->IDC_MODESEARCHBAR->setIcon(icon);

    ui->IDC_MODESEARCHBAR->setChecked(searchBarAssistantMode);

    loadArreraApp();
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

    if (index == idPageI2025Main)
    {
        ui->I2025->setCurrentIndex(idPageApropos);
        ui->LINDICATIONARRERA->setText("Arrera I2026 A propos");

    } else {
        ui->I2025->setCurrentIndex(idPageI2025Main);
        ui->LINDICATIONARRERA->setText("Arrera I2026");
        ui->IDC_SHOWHIST->setVisible(true);
        ui->IDC_AUTREMOTEUR->setVisible(true);
    }
}

// Bar des taches
void ArreraUI::on_IDC_APPBUREAU_clicked()
{
    ui->I2025->setCurrentIndex(idPageI2025App);
    ui->LINDICATIONARRERA->setText("Page application de l'ordinateur");
}

void ArreraUI::on_IDC_TIGER_clicked()
{
    bool sortie = appManager.openArreraHub();
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
    if (!appManager.loadDesktopApps()){
        QMessageBox::information(this,
                                 "Information",
                                 "Un probleme est survenu lors du chargement des application enregistrer");
    }
    appManager.reloadHubConfig();
    loadArreraApp();
}

void ArreraUI::loadArreraApp(){
    appManager.loadArreraApps(ui->IDC_ARRERA_MARKDOWN);
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
    const QString recherche = ui->IDC_SEARCHBAR->text();
    ui->IDC_SEARCHBAR->clear();
    QString label;
    const bool sortie = arecherche.searchByIndex(mode, recherche, &label);
    handleSearchResult(sortie, label);
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

void ArreraUI::searchEnter()
{
    const QString text = ui->IDC_SEARCHBAR->text();
    if (text.isEmpty()) {
        ui->LINDICATIONARRERA->setText("La bar de recherche est vide");
        return;
    }
    if (!searchBarAssistantMode) {
        ui->IDC_SEARCHBAR->clear();
        QString label;
        const bool sortie = arecherche.searchWithEngine(objSetting.getMoteurRecherche(), text, &label);
        handleSearchResult(sortie, label);
    } else {
        annBus.sendQuery(text);
        ui->LINDICATIONARRERA->setText("L'assistant vas vous repondre");
        ui->IDC_SEARCHBAR->clear();
    }
}

void ArreraUI::handleSearchResult(bool ok, const QString &label) {
    if (ok) {
        ui->LINDICATIONARRERA->setText(label);
    } else {
        QMessageBox::critical(this, "Recherche Arrera",
                              "Une erreur s'est produite : impossible de faire la recherche.");
    }
}

void ArreraUI::closeEvent(QCloseEvent *event)
{
    annBus.shutdown();
    tigerDemon.closeUpdateWindow();
    if (uipara.isVisible()) uipara.close();
    QDialog::closeEvent(event);
}

// Bouton pour envoyer des ordes a l'assistant

void ArreraUI::on_IDC_BREEF_clicked()
{
    annBus.launch_breef();
}


void ArreraUI::on_IDC_METEO_clicked()
{
    annBus.launch_meteo();
}


void ArreraUI::on_IDC_TASK_clicked()
{
    annBus.launch_task();
}


void ArreraUI::on_IDC_AGENDA_clicked()
{
    annBus.launch_AGENDA();
}
