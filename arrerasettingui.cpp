#include "arrerasettingui.h"
#include "ui_arrerasettingui.h"

// Methode principal public
ArreraSettingUI::ArreraSettingUI(QWidget *parent,CAInterfaceSetting *obp,CArreraRecheche *ar,CDetectionOS *pos)
    : QDialog(parent)
    , ui(new Ui::ArreraSettingUI)
{
    ui->setupUi(this);
    // Varrible systeme
    modeSelected = 0;
    lieuSelected = 0;
    appSpeSelected = 0;// 1.Navigateur 2.Presentation 3.tableur 4.Traitement de texte
    // Mise en place de CAInterfaceSetting dans son atribut
    objPara = obp;
    // Mise en place de l'objet dectetion os
    dectOS = pos;
    // Mise en place de l'objet Arrera Recherche
    objRecherche = ar;
    // Recuperation List des assistant
    QList listAssistant = objPara->getListAssistant();
    // Recuperation liste moteur
    QList listMoteur = objPara->getListMoteur();
    // Id de mainstaked
    idMainPage = ui->mainstacked->indexOf(ui->main);
    idModePage = ui->mainstacked->indexOf(ui->mode);
    idGenerauxPage = ui->mainstacked->indexOf(ui->generaux);
    idAssistantPage= ui->mainstacked->indexOf(ui->main);
    idApplicationPage = ui->mainstacked->indexOf(ui->application);
    idLieuPage = ui->mainstacked->indexOf(ui->lieu);
    idRecherchePage = ui->mainstacked->indexOf(ui->recherche);
    // id de modestaked
    idMainModePage = ui->modestacked->indexOf(ui->mainmode);
    idAddMode = ui->modestacked->indexOf(ui->addmode);
    idGestMode = ui->modestacked->indexOf(ui->gestMode);
    // id de appstacked
    idMainAppStaked = ui->appstacked->indexOf(ui->mainpcapp);
    idAddAppStacked = ui->appstacked->indexOf(ui->addpcapp);
    idSupprAppStacked = ui->appstacked->indexOf(ui->supprpcapp);
    idIconChangeApp = ui->appstacked->indexOf(ui->iconchangedapp);
    idEmplacementAppStacked = ui->appstacked->indexOf(ui->changeemplacement);
    idManageAppSpeciaux = ui->appstacked->indexOf(ui->manageappspe);
    // id lieustacked
    idMainLieu= ui->lieustacked->indexOf(ui->mainlieu);
    idAddLieu = ui->lieustacked->indexOf(ui->addlieu);
    idManageLieu = ui->lieustacked->indexOf(ui->managelieu);
    // Id stakedGeneraux
    idMainGeneraux = ui->stakedGeneraux->indexOf(ui->mainGeneraux);
    idNameUser = ui->stakedGeneraux->indexOf(ui->nameUser);
    idResetInterface = ui->stakedGeneraux->indexOf(ui->resetInterface);
    idTaskbarSetting = ui->stakedGeneraux->indexOf(ui->taskbarSetting);
    // Mise en place des item sur le IDC_LISTASSISTANTMODE
    ui->IDC_LISTASSISTANTMODE->addItems(listAssistant);
    // Mise en place des item sur le IDC_LISTASSISTANTMANAGELIEU
    ui->IDC_LISTASSISTANTMANAGELIEU->addItems(listAssistant);
    // Mise en place des item sur le IDC_ASSISTANTGESTMODE
    ui->IDC_ASSISTANTGESTMODE->addItems(listAssistant);
    // Mise en place des item sur le IDC_LISTASSISTANTLIEU
    ui->IDC_LISTASSISTANTLIEU->addItems(listAssistant);
    // Mise en place des item sur le IDC_LISTASSISTANTMANAGELIEU
    ui->IDC_LISTASSISTANTMANAGELIEU->addItems(listAssistant);
    // Mise en place des moteur de recherche dans IDC_LISTEMOTEURERECHERCHE
    ui->IDC_LISTEMOTEURERECHERCHE->addItems(listMoteur);
    // Desactivation du bouton assistant
    ui->IDC_ASSISTANT->setVisible(false);
}

ArreraSettingUI::~ArreraSettingUI()
{
    delete ui;
}

void ArreraSettingUI::closeEvent(QCloseEvent *event)
{
    // Émettre le signal lorsque la fenêtre des paramètres est fermée
    emit parametresFerme();
    QWidget::closeEvent(event);
}

void ArreraSettingUI::setAppComboBox(){

    QList <QString> listApp = objPara->getListNameAppSetted();
    ui->IDC_APP1MODE->clear();
    ui->IDC_APP2MODE->clear();
    ui->IDC_APP3MODE->clear();
    ui->IDC_APP4MODE->clear();
    ui->IDC_APP1GESTMODE->clear();
    ui->IDC_APP2GESTMODE->clear();
    ui->IDC_APP3GESTMODE->clear();
    ui->IDC_APP4GESTMODE->clear();
    ui->LISTAPPCHANGEICON->clear();
    ui->LISTOPTIONAPPSUPPR->clear();
    ui->LISTAPPCHANGEEMPLACEMENT->clear();

    ui->IDC_APP1MODE->addItem("AUCUN");
    ui->IDC_APP2MODE->addItem("AUCUN");
    ui->IDC_APP3MODE->addItem("AUCUN");
    ui->IDC_APP4MODE->addItem("AUCUN");
    ui->IDC_APP1GESTMODE->addItem("AUCUN");
    ui->IDC_APP2GESTMODE->addItem("AUCUN");
    ui->IDC_APP3GESTMODE->addItem("AUCUN");
    ui->IDC_APP4GESTMODE->addItem("AUCUN");

    if (listApp.isEmpty()){
        ui->LISTAPPCHANGEICON->addItem("nothing");
        ui->LISTOPTIONAPPSUPPR->addItem("nothing");
        ui->LISTAPPCHANGEEMPLACEMENT->addItem("nothing");
    }else{
        ui->IDC_APP1MODE->addItems(listApp);
        ui->IDC_APP2MODE->addItems(listApp);
        ui->IDC_APP3MODE->addItems(listApp);
        ui->IDC_APP4MODE->addItems(listApp);
        ui->IDC_APP1GESTMODE->addItems(listApp);
        ui->IDC_APP2GESTMODE->addItems(listApp);
        ui->IDC_APP3GESTMODE->addItems(listApp);
        ui->IDC_APP4GESTMODE->addItems(listApp);
        ui->LISTAPPCHANGEICON->addItems(listApp);
        ui->LISTOPTIONAPPSUPPR->addItems(listApp);
        ui->LISTAPPCHANGEEMPLACEMENT->addItems(listApp);
    }
}

void ArreraSettingUI::show()
{
    QDialog::show();
    ui->mainstacked->setCurrentIndex(idMainPage);
    ui->modestacked->setCurrentIndex(idMainModePage);
    ui->appstacked->setCurrentIndex(idMainAppStaked);
    ui->lieustacked->setCurrentIndex(idMainLieu);
    ui->LINDICATIONSETTING->setText("Arrera I2025 Parametre");
}

QString ArreraSettingUI::chooseIcon(){

    QString m_selectedIconPath;
    QIcon m_selectedIcon;
    // Créer une boîte de dialogue personnalisée
    QDialog iconDialog(this);
    iconDialog.setWindowTitle(tr("Choisir une icône"));
    iconDialog.setModal(true);

    // Créer le layout
    QVBoxLayout* layout = new QVBoxLayout(&iconDialog);

    // Créer une liste pour afficher les icônes
    QListWidget* iconList = new QListWidget(&iconDialog);
    iconList->setViewMode(QListWidget::IconMode);
    iconList->setIconSize(QSize(32, 32));
    iconList->setSpacing(10);
    iconList->setResizeMode(QListWidget::Adjust);

    // Charger toutes les icônes du répertoire /icon dans le .qrc
    QDir resourceDir(DIRICONMODELIEU);
    QStringList filters;
    filters << "*.png" << "*.jpg" << "*.jpeg" << "*.gif" << "*.bmp";
    resourceDir.setNameFilters(filters);

    foreach(const QString &fileName, resourceDir.entryList()) {
        QListWidgetItem* item = new QListWidgetItem(fileName);
        item->setIcon(QIcon(DIRICONMODELIEU + fileName));
        item->setData(Qt::UserRole, DIRICONMODELIEU + fileName); // Stocker le chemin complet
        iconList->addItem(item);
    }

    // Ajouter les boutons OK et Annuler
    QDialogButtonBox* buttonBox = new QDialogButtonBox(
        QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    // Connecter les signaux des boutons
    connect(buttonBox, &QDialogButtonBox::accepted, &iconDialog, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, &iconDialog, &QDialog::reject);

    // Ajouter les widgets au layout
    layout->addWidget(iconList);
    layout->addWidget(buttonBox);

    // Exécuter la boîte de dialogue
    if (iconDialog.exec() == QDialog::Accepted) {
        QListWidgetItem* selectedItem = iconList->currentItem();
        if (selectedItem) {
            QString iconPath = selectedItem->data(Qt::UserRole).toString();
            QIcon selectedIcon(iconPath);

            // Stocker l'icône sélectionnée
            m_selectedIcon = selectedIcon;
            return iconPath;
        }
        else{
            return "";
        }
    }
    return "";
}

// Partie acceuil

void ArreraSettingUI::on_IDC_MODE_clicked()
{
    ui->mainstacked->setCurrentIndex(idModePage);
    ui->modestacked->setCurrentIndex(idMainModePage);
    ui->appstacked->setCurrentIndex(idMainAppStaked);
    ui->lieustacked->setCurrentIndex(idMainLieu);
    ui->LINDICATIONSETTING->setText("Parametre des modes");
}

void ArreraSettingUI::on_IDC_GENERAUX_clicked()
{
    ui->LINDICATIONSETTING->setText("Parametre generaux");
    ui->mainstacked->setCurrentIndex(idGenerauxPage);
    ui->stakedGeneraux->setCurrentIndex(idMainGeneraux);
}


void ArreraSettingUI::on_IDC_ASSISTANT_clicked()
{

}


void ArreraSettingUI::on_IDC_APPLICATION_clicked()
{
    ui->mainstacked->setCurrentIndex(idApplicationPage);
    ui->LINDICATIONSETTING->setText("Parametre des applications");
}


void ArreraSettingUI::on_IDC_LIEU_clicked()
{
    ui->mainstacked->setCurrentIndex(idLieuPage);
    ui->LINDICATIONSETTING->setText("Parametre des lieu");

}


void ArreraSettingUI::on_IDC_RECHERCHE_clicked()
{
    ui->mainstacked->setCurrentIndex(idRecherchePage);
    ui->LINDICATIONSETTING->setText("Parametre de recherche");
}

// Top bar
void ArreraSettingUI::on_IDC_ACCEUILPARAMETRE_clicked()
{
    int currentIndex = ui->mainstacked->currentIndex();
    if (currentIndex != idMainPage)
    {
        ui->mainstacked->setCurrentIndex(idMainPage);
        ui->LINDICATIONSETTING->setText("Arrera I2025 Parametre");
    }
    else{
        this->close();
    }
}

// Partie mode
void ArreraSettingUI::on_IDC_BTNMODE1_clicked()
{
    if (!objPara->mode1IsSeted())
    {
        ui->LINDICATIONMODE->setText("Parametrage du Mode 1");
        ui->LINDICATIONSETTING->setText("Parametrage mode 1");
        ui->modestacked->setCurrentIndex(idAddMode);
    }
    else {
        ui->LINDICATIONSETTING->setText("Modification du mode 1");
        ui->LINDICATIONGESTMODE->setText("Modification du mode 1");
        ui->modestacked->setCurrentIndex(idGestMode);
    }

    modeSelected = 1;
    setAppComboBox();
}


void ArreraSettingUI::on_IDC_BTNMODE2_clicked()
{
    if (!objPara->mode2IsSeted())
    {
        ui->LINDICATIONMODE->setText("Parametrage du Mode 2");
        ui->LINDICATIONSETTING->setText("Parametrage mode 2");
        ui->modestacked->setCurrentIndex(idAddMode);
    }
    else {
        ui->LINDICATIONSETTING->setText("Modification du mode 2");
        ui->LINDICATIONGESTMODE->setText("Modification du mode 2");
        ui->modestacked->setCurrentIndex(idGestMode);
    }

    modeSelected = 2;
    setAppComboBox();
}


void ArreraSettingUI::on_IDC_BTNMODE3_clicked()
{
    if (!objPara->mode3IsSeted())
    {
        ui->LINDICATIONMODE->setText("Parametrage du Mode 3");
        ui->LINDICATIONSETTING->setText("Parametrage mode 3");
        ui->modestacked->setCurrentIndex(idAddMode);
    }
    else {
        ui->LINDICATIONSETTING->setText("Modification du mode 3");
        ui->LINDICATIONGESTMODE->setText("Modification du mode 3");
        ui->modestacked->setCurrentIndex(idGestMode);
    }

    modeSelected = 3;
    setAppComboBox();
}


void ArreraSettingUI::on_IDC_BTNMODE4_clicked()
{
    if (!objPara->mode4IsSeted())
    {
        ui->LINDICATIONMODE->setText("Parametrage du Mode 4");
        ui->LINDICATIONSETTING->setText("Parametrage mode 4");
        ui->modestacked->setCurrentIndex(idAddMode);
    }
    else {
        ui->LINDICATIONSETTING->setText("Modification du mode 4");
        ui->LINDICATIONGESTMODE->setText("Modification du mode 4");
        ui->modestacked->setCurrentIndex(idGestMode);
    }

    modeSelected = 4;
    setAppComboBox();
}


void ArreraSettingUI::on_IDC_BTNMODE5_clicked()
{
    if (!objPara->mode5IsSeted())
    {
        ui->LINDICATIONMODE->setText("Parametrage du Mode 5");
        ui->LINDICATIONSETTING->setText("Parametrage mode 5");
        ui->modestacked->setCurrentIndex(idAddMode);
    }
    else {
        ui->LINDICATIONSETTING->setText("Modification du mode 5");
        ui->LINDICATIONGESTMODE->setText("Modification du mode 5");
        ui->modestacked->setCurrentIndex(idGestMode);
    }

    modeSelected = 5;
    setAppComboBox();
}


void ArreraSettingUI::on_IDC_BTNMODE6_clicked()
{
    if (!objPara->mode6IsSeted())
    {
        ui->LINDICATIONMODE->setText("Parametrage du Mode 6");
        ui->LINDICATIONSETTING->setText("Parametrage mode 6");
        ui->modestacked->setCurrentIndex(idAddMode);
    }
    else {
        ui->LINDICATIONSETTING->setText("Modification du mode 6");
        ui->LINDICATIONGESTMODE->setText("Modification du mode 6");
        ui->modestacked->setCurrentIndex(idGestMode);
    }

    modeSelected = 6;
    setAppComboBox();
}


void ArreraSettingUI::on_IDC_VALIDERMODE_clicked()
{
    QString assistant;
    QString app1,app2,app3,app4;
    // Recuperation valeur entrer par l'user
    QString name = ui->IDC_LINENAMEMODE->text();
    if ((assistant = ui->IDC_LISTASSISTANTMODE->currentText())=="AUCUN"){
        assistant = "nothing";
    }

    // Recuperation de application
    if ((app1 = ui->IDC_APP1MODE->currentText())=="AUCUN"){
        app1 = "nothing";
    }
    else{
        app1 = objPara->assosNameOfApp(app1);
    }

    if ((app2 = ui->IDC_APP2MODE->currentText())=="AUCUN"){
        app2 = "nothing" ;
    }else{
        app2 = objPara->assosNameOfApp(app2);
    }

    if ((app3 = ui->IDC_APP3MODE->currentText())=="AUCUN"){
        app3 = "nothing";
    }else{
        app3 = objPara->assosNameOfApp(app3);
    }

    if ((app4 = ui->IDC_APP4MODE->currentText())=="AUCUN"){
        app4 = "nothing";
    }else{
        app4 = objPara->assosNameOfApp(app4);
    }

    // Clear des combox et QLine
    ui->IDC_APP1MODE->clear();
    ui->IDC_APP2MODE->clear();
    ui->IDC_APP3MODE->clear();
    ui->IDC_APP4MODE->clear();
    ui->IDC_LINENAMEMODE->clear();
    // Teste de valeur récupérer
    if (name.isEmpty()){
        QMessageBox::critical(this,"Erreur de création du mode",
                              "Impossible de créer un mode sans nom");
    }
    else {
        bool sortieApp,sortieName,sortieAssistant;
        // Ecriture dans le mode selectionner
        switch (modeSelected) {
            case 1 :
                sortieName = objPara->setNameMode1(name);
                sortieAssistant = objPara->setAppMode1(app1,app2,app3,app4);
                sortieApp = objPara->setAssistantMode1(assistant);
                break;
            case 2 :
                sortieName = objPara->setNameMode2(name);
                sortieAssistant = objPara->setAppMode2(app1,app2,app3,app4);
                sortieApp = objPara->setAssistantMode2(assistant);
                break;

            case 3 :
                sortieName = objPara->setNameMode3(name);
                sortieAssistant = objPara->setAppMode3(app1,app2,app3,app4);
                sortieApp = objPara->setAssistantMode3(assistant);
                break;

            case 4 :
                sortieName = objPara->setNameMode4(name);
                sortieAssistant = objPara->setAppMode4(app1,app2,app3,app4);
                sortieApp = objPara->setAssistantMode4(assistant);
                break;

            case 5 :
                sortieName = objPara->setNameMode5(name);
                sortieAssistant = objPara->setAppMode5(app1,app2,app3,app4);
                sortieApp = objPara->setAssistantMode5(assistant);
                break;

            case 6 :
                sortieName = objPara->setNameMode6(name);
                sortieAssistant = objPara->setAppMode6(app1,app2,app3,app4);
                sortieApp = objPara->setAssistantMode6(assistant);
                break;

            default :
                sortieName = false ;
                sortieAssistant = false ;
                sortieApp = false ;
                break;
        }
        if (sortieName && sortieApp && sortieAssistant){
            QMessageBox::information(this,"Mode "+QString::number(modeSelected),
                                     "Le mode "+QString::number(modeSelected)+" a bien été paramétré");
        }else{
            QMessageBox::critical(this,"Erreur",
                                  "Une erreur s'est produite");
        }
    }
    ui->modestacked->setCurrentIndex(idMainModePage);
    ui->LINDICATIONSETTING->setText("Parametre des modes");
}


void ArreraSettingUI::on_IDC_RETOURMODE_clicked()
{
    ui->LINDICATIONSETTING->setText("Parametre des modes");
    ui->modestacked->setCurrentIndex(idMainModePage);
    modeSelected = 0;
}

void ArreraSettingUI::on_IDC_ICONMODEADD_clicked(){
    QString icon = chooseIcon();
    bool sortie;
    if (!icon.isEmpty()){
        switch (modeSelected) {
        case 1:
            sortie = objPara->setIconMode1(icon);
            break;
        case 2:
            sortie = objPara->setIconMode2(icon);
            break;
        case 3:
            sortie = objPara->setIconMode3(icon);
            break;
        case 4:
            sortie = objPara->setIconMode4(icon);
            break;
        case 5:
            sortie = objPara->setIconMode5(icon);
            break;
        case 6:
            sortie = objPara->setIconMode6(icon);
            break;
        default:
            sortie = false;
            break;
        }

        if (sortie){
            QMessageBox::information(this,"Icon Mode","L'icône a bien été enregistrée pour ce mode.");
        }else{
            QMessageBox::critical(this,"Icon Mode","Impossible d'ajouter l'icône, une erreur est survenue.");
        }


    }
    else{
        QMessageBox::critical(this,"Icone Mode","Vous n'avez pas sélectionné d'icône.");
    }
}

// Partie gest mode

void ArreraSettingUI::on_IDC_RESETMODE_clicked()
{
    bool sortie;
    switch(modeSelected){
        case 1 :
            sortie = objPara->resetMode1();
            break;
        case 2 :
            sortie = objPara->resetMode2();
            break;
        case 3 :
            sortie = objPara->resetMode3();
            break;
        case 4 :
            sortie = objPara->resetMode4();
            break;
        case 5 :
            sortie = objPara->resetMode5();
            break;
        case 6 :
            sortie = objPara->resetMode6();
            break;
        default :
            sortie = false;
            break;
    }
    if (sortie){
        QMessageBox::information(this,"Mode reset",
                                 "Le mode "+QString::number(modeSelected)+"a bien été réinitialisé.");
    }else{
        QMessageBox::critical(this,"Erreur",
                              "Une erreur s'est produite");
    }
    ui->modestacked->setCurrentIndex(idMainModePage);
    ui->LINDICATIONSETTING->setText("Parametre des modes");
}


void ArreraSettingUI::on_IDC_CHANGENAME_clicked()
{
    QString newName = ui->IDC_LINECHANGENAMEMODE->text();
    bool sortie;

    if (newName.isEmpty()){
        QMessageBox::critical(this,"Erreur de modification du mode",
                              "Impossible de changer le nom du mode par un nom vide.");
    }

    switch (modeSelected) {
    case 1:
        sortie = objPara->setNameMode1(newName);
        break;
    case 2:
        sortie = objPara->setNameMode2(newName);
        break;
    case 3:
        sortie = objPara->setNameMode3(newName);
        break;
    case 4:
        sortie = objPara->setNameMode4(newName);
        break;
    case 5:
        sortie = objPara->setNameMode5(newName);
        break;
    case 6:
        sortie = objPara->setNameMode6(newName);
        break;
    default:
        sortie = false;
        break;
    }

    if (sortie){
        QMessageBox::information(this,"Nom changé",
                                 "Le nom du mode a bien été changé.");
    }else{
        QMessageBox::critical(this,"Erreur lors du changement du nom",
                              "Le nom du mode n'a pas pu être changé.");
    }
    ui->modestacked->setCurrentIndex(idMainModePage);
}


void ArreraSettingUI::on_IDC_ASSISTANTMAJGESTMODE_clicked()
{
    QString assistant = ui->IDC_ASSISTANTGESTMODE->currentText();
    bool sortie;
    switch (modeSelected) {
    case 1:
        sortie = objPara->setAssistantMode1(assistant);
        break;
    case 2:
        sortie = objPara->setAssistantMode2(assistant);
        break;
    case 3:
        sortie = objPara->setAssistantMode3(assistant);
        break;
    case 4:
        sortie = objPara->setAssistantMode4(assistant);
        break;
    case 5:
        sortie = objPara->setAssistantMode5(assistant);
        break;
    case 6:
        sortie = objPara->setAssistantMode6(assistant);
        break;
    default:
        sortie = false;
        break;
    }

    if (sortie){
        QMessageBox::information(this,
                                 "Assistant du mode "+QString::number(modeSelected),
                                 "L'assistant du mode "+
                                     QString::number(modeSelected)+" à été mis à jour");
    }else{
        QMessageBox::critical(this,"Erreur sur la mise a jour",
                              "Imposible de mettre a jour l'assistant du mode "+
                                  QString::number(modeSelected));
    }
    ui->modestacked->setCurrentIndex(idMainModePage);
}


void ArreraSettingUI::on_IDC_MAJAPPGESTMODE_clicked()
{
    bool sortie;
    QString app1;
    QString app2;
    QString app3;
    QString app4;

    if((app1 = ui->IDC_APP1GESTMODE->currentText())=="AUCUN"){
        app1 = "nothing";
    }
    else{
        app1 = objPara->assosNameOfApp(app1);
    }

    if((app2 = ui->IDC_APP2GESTMODE->currentText())=="AUCUN"){
        app2 = "nothing";
    }
    else{
        app2 = objPara->assosNameOfApp(app2);
    }

    if((app3 = ui->IDC_APP3GESTMODE->currentText())=="AUCUN"){
        app3 = "nothing";
    }else{
        app3 = objPara->assosNameOfApp(app3);
    }

    if((app4 = ui->IDC_APP4GESTMODE->currentText())=="AUCUN"){
        app4 = "nothing";
    }else{
        app4 = objPara->assosNameOfApp(app4);
    }

    switch (modeSelected) {
    case 1:
        sortie = objPara->setAppMode1(app1,app2,app3,app4);
        break;
    case 2:
        sortie = objPara->setAppMode2(app1,app2,app3,app4);
        break;
    case 3:
        sortie = objPara->setAppMode3(app1,app2,app3,app4);
        break;
    case 4:
        sortie = objPara->setAppMode4(app1,app2,app3,app4);
        break;
    case 5:
        sortie = objPara->setAppMode5(app1,app2,app3,app4);
        break;
    case 6:
        sortie = objPara->setAppMode6(app1,app2,app3,app4);
        break;
    default:
        sortie = false;
        break;
    }

    if (sortie){
        QMessageBox::information(this,
                                 "Application mode "+QString::number(modeSelected),
                                 "Les applications du mode "+
                                     QString::number(modeSelected)+" à été mis à jour");
    }else{
        QMessageBox::critical(this,"Erreur sur la mise a jour",
                              "Imposible de mettre a jour les application du mode "+
                                  QString::number(modeSelected));
    }
    ui->modestacked->setCurrentIndex(idMainModePage);
}


void ArreraSettingUI::on_IDC_RETOURGESTMODE_clicked()
{
    ui->LINDICATIONSETTING->setText("Parametre des modes");
    ui->modestacked->setCurrentIndex(idMainModePage);
    modeSelected = 0;
}

void ArreraSettingUI::on_IDC_CHANGEICONMODEGEST_clicked()
{
    on_IDC_ICONMODEADD_clicked();
    ui->LINDICATIONSETTING->setText("Parametre des modes");
    ui->modestacked->setCurrentIndex(idMainModePage);
    modeSelected = 0;
}

// Partie Parametre generaux
void ArreraSettingUI::on_IDC_RETOURGENERAUXUSER_clicked()
{
    ui->LINDICATIONSETTING->setText("Parametre generaux");
    ui->mainstacked->setCurrentIndex(idGenerauxPage);
    ui->stakedGeneraux->setCurrentIndex(idMainGeneraux);
}


void ArreraSettingUI::on_IDC_VALIDERNAMEUSER_clicked()
{
    // Recuperation de la valeur
    QString nameUser = ui->ICD_LINENAMEUSER->text();
    // Effacement de ICD_LINENAMEUSER
    ui->ICD_LINENAMEUSER->clear();
    // Teste si ICD_LINENAMEUSER etais vide
    if (!nameUser.isEmpty())
    {
        objPara->setNameUser(nameUser);
    }
    ui->LINDICATIONSETTING->setText("Parametre generaux");
    ui->stakedGeneraux->setCurrentIndex(idMainGeneraux);
}

// Acceuil Parametre generaux

void ArreraSettingUI::on_IDC_NAMEUSERPARAGENERAUX_clicked()
{
    ui->LINDICATIONSETTING->setText("Modification de l'utilisateur");
    ui->stakedGeneraux->setCurrentIndex(idNameUser);
}


void ArreraSettingUI::on_IDC_GENERAUXTASKBAR_clicked()
{
    ui->LINDICATIONSETTING->setText("Gestion de la barre des tâches");
    ui->stakedGeneraux->setCurrentIndex(idTaskbarSetting);

    if (objPara->getTaskbarBTNSix()){
        ui->IDC_ACTIVESIX->setText("Désactiver le bouton d'Arrera SIX.");
        ui->IDC_ACTIVESIX->setStyleSheet("background-color: red; color: white;");
    }else{
        ui->IDC_ACTIVESIX->setText("Activer le bouton d'Arrera SIX.");
        ui->IDC_ACTIVESIX->setStyleSheet("background-color: green; color: white;");
    }

    if (objPara->getTaskbarBTNArreraApp()){
        ui->IDC_ACTIVEARRERAAPP->setText("Désactiver le bouton des Application Arrera.");
        ui->IDC_ACTIVEARRERAAPP->setStyleSheet("background-color: red; color: white;");
    }else{
        ui->IDC_ACTIVEARRERAAPP->setText("Activer le bouton des Application Arrera.");
        ui->IDC_ACTIVEARRERAAPP->setStyleSheet("background-color: green; color: white;");
    }

    if (objPara->getTaskbarBTNRyley()){
        ui->IDC_ACTIVERYLEY->setText("Désactiver le bouton d'Arrera RYLEY.");
        ui->IDC_ACTIVERYLEY->setStyleSheet("background-color: red; color: white;");
    }else{
        ui->IDC_ACTIVERYLEY->setText("Activer le bouton d'Arrera RYLEY.");
        ui->IDC_ACTIVERYLEY->setStyleSheet("background-color: green; color: white;");
    }

    if (objPara->getTaskbarCopilote()){
        ui->IDC_ACTIVECOPILOTE->setText("Désactiver le bouton d'Arrera COPILOTE.");
        ui->IDC_ACTIVECOPILOTE->setStyleSheet("background-color: red; color: white;");
    }else{
        ui->IDC_ACTIVECOPILOTE->setText("Activer le bouton d'Arrera COPILOTE.");
        ui->IDC_ACTIVECOPILOTE->setStyleSheet("background-color: green; color: white;");
    }

    if (objPara->getTaskbarPostite()){
        ui->IDC_ACTIVEPOSTITE->setText("Désactiver le bouton d'Arrera POSTITE.");
        ui->IDC_ACTIVEPOSTITE->setStyleSheet("background-color: red; color: white;");
    }else{
        ui->IDC_ACTIVEPOSTITE->setText("Activer le bouton d'Arrera POSTITE.");
        ui->IDC_ACTIVEPOSTITE->setStyleSheet("background-color: green; color: white;");
    }


}


void ArreraSettingUI::on_IDC_RESETARRERAGENERAUX_clicked()
{
    ui->LINDICATIONSETTING->setText("Remise à zéro d'Arrera");
    ui->stakedGeneraux->setCurrentIndex(idResetInterface);
}

// Partie Reset

void ArreraSettingUI::on_IDC_RESETARRERAAPP_clicked()
{
    if (objPara->resetArreraApp()){
        QMessageBox::information(this,"Reset Arrera Application",
                                 "Les applications Arrera dans l'interface ont bien été remises à zéro.");
    }else{
        QMessageBox::critical(this,"Reset Arrera Application",
                              "Impossible de remettre à zéro la configuration des applications Arrera dans l'interface.");
    }
    ui->LINDICATIONSETTING->setText("Parametre generaux");
    ui->stakedGeneraux->setCurrentIndex(idMainGeneraux);
}


void ArreraSettingUI::on_IDC_RESETAPPPC_clicked()
{
    if (objPara->resetAppPC()){
         QMessageBox::information(this,"Application enregistrée",
                                 "Les applications enregistrées dans l'interface ont été remises à zéro.");
    }else{
        QMessageBox::critical(this,"Application enregistrée",
                              "Impossible de remettre à zéro les applications enregistrées.");
    }
    ui->LINDICATIONSETTING->setText("Parametre generaux");
    ui->stakedGeneraux->setCurrentIndex(idMainGeneraux);
}


void ArreraSettingUI::on_IDC_RETOURRESETINTERFACE_clicked()
{
    ui->LINDICATIONSETTING->setText("Parametre generaux");
    ui->mainstacked->setCurrentIndex(idGenerauxPage);
    ui->stakedGeneraux->setCurrentIndex(idMainGeneraux);
}


void ArreraSettingUI::on_IDC_RESETALLINTERFACE_clicked()
{
    objPara->resetAll();
    QMessageBox::information(this,"Remise a Zero d'Arrera",
                             "Les applications enregistrées dans l'interface ont été remises à zéro.");
    ui->LINDICATIONSETTING->setText("Parametre generaux");
    ui->stakedGeneraux->setCurrentIndex(idMainGeneraux);
}


void ArreraSettingUI::on_IDC_RESETMODEINTERFACE_clicked()
{
    bool sortMode1,sortMode2,sortMode3,sortMode4,sortMode5,sortMode6;

    sortMode1 = objPara->resetMode1();
    sortMode2 = objPara->resetMode2();
    sortMode3 = objPara->resetMode3();
    sortMode4 = objPara->resetMode4();
    sortMode5 = objPara->resetMode5();
    sortMode6 = objPara->resetMode6();

    if (sortMode1 && sortMode2 && sortMode3 && sortMode4&& sortMode5&& sortMode6){
        QMessageBox::information(this,"Mode Arrera",
                                 "Les modes d'Arrera ont été remis à zéro.");
    }else{
        QMessageBox::critical(this,"Mode Arrera",
                              "Impossible de remettre à zéro les modes Arrera.");
    }

    ui->LINDICATIONSETTING->setText("Parametre generaux");
    ui->stakedGeneraux->setCurrentIndex(idMainGeneraux);
}


void ArreraSettingUI::on_IDC_RESETLIEU_clicked()
{
    bool sortLieu1,sortLieu2 ;

    sortLieu1 = objPara->resetLieu1();
    sortLieu2 = objPara->resetLieu2();

    if (sortLieu1 && sortLieu2){
        QMessageBox::information(this,"Lieu Arrera",
                                 "Les lieux d'Arrera ont été remis à zéro");
    }else{
        QMessageBox::critical(this,"LIeu Arrera",
                              "Impossible de remettre à zéro les lieu Arrera.");
    }

    ui->LINDICATIONSETTING->setText("Parametre generaux");
    ui->stakedGeneraux->setCurrentIndex(idMainGeneraux);
}

// Partie bar des taches
void ArreraSettingUI::on_IDC_ACTIVEARRERAAPP_clicked()
{
    bool sortie;
    if (objPara->getTaskbarBTNArreraApp()){
        sortie = objPara->unsetTaskbarBTNArreraApp();
        if (sortie){
            ui->IDC_ACTIVEARRERAAPP->setText("Activer le bouton des Application Arrera.");
            ui->IDC_ACTIVEARRERAAPP->setStyleSheet("background-color: green; color: white;");
            QMessageBox::information(this,
                                     "Paramètre de barre des tâches",
                                     "Le bouton des applications Arrera ne sera plus affiché.");
        }else{
            QMessageBox::critical(this,
                                  "Paramètre de barre des tâches",
                                  "Une erreur s'est produite.");
        }
    }else{
        sortie = objPara->setTaskbarBTNArreraApp();
        if (sortie){
            ui->IDC_ACTIVEARRERAAPP->setText("Désactiver le bouton des Application Arrera.");
            ui->IDC_ACTIVEARRERAAPP->setStyleSheet("background-color: red; color: white;");
            QMessageBox::information(this,
                                     "Paramètre de barre des tâches",
                                     "Le bouton des applications Arrera est affiché.");
        }else{
            QMessageBox::critical(this,
                                  "Paramètre de barre des tâches",
                                  "Une erreur s'est produite.");
        }
    }
    ui->LINDICATIONSETTING->setText("Parametre generaux");
    ui->stakedGeneraux->setCurrentIndex(idMainGeneraux);
}


void ArreraSettingUI::on_IDC_ACTIVESIX_clicked()
{
    bool sortie;
    if (objPara->getTaskbarBTNSix()){
        sortie = objPara->unsetTaskbarBTNSix();
        if (sortie){
            ui->IDC_ACTIVESIX->setText("Activer le bouton d'Arrera SIX.");
            ui->IDC_ACTIVESIX->setStyleSheet("background-color: green; color: white;");
            QMessageBox::information(this,
                                     "Paramètre de barre des tâches",
                                     "Le bouton d'Arrera SIX ne sera plus affiché.");
        }else{
            QMessageBox::critical(this,
                                  "Paramètre de barre des tâches",
                                  "Une erreur s'est produite.");
        }
    }else{
        sortie = objPara->setTaskbarBTNSix();
        if (sortie){
            ui->IDC_ACTIVESIX->setText("Désactiver le bouton d'Arrera SIX.");
            ui->IDC_ACTIVESIX->setStyleSheet("background-color: red; color: white;");
            QMessageBox::information(this,
                                     "Paramètre de barre des tâches",
                                     "Le bouton d'Arrera SIX est affiché.");
        }else{
            QMessageBox::critical(this,
                                  "Paramètre de barre des tâches",
                                  "Une erreur s'est produite.");
        }
    }
    ui->LINDICATIONSETTING->setText("Parametre generaux");
    ui->stakedGeneraux->setCurrentIndex(idMainGeneraux);
}


void ArreraSettingUI::on_IDC_ACTIVERYLEY_clicked()
{
    bool sortie;
    if (objPara->getTaskbarBTNRyley()){
        sortie = objPara->unsetTaskbarBTNRyley();
        if (sortie){
            ui->IDC_ACTIVERYLEY->setText("Activer le bouton d'Arrera RYLEY.");
            ui->IDC_ACTIVERYLEY->setStyleSheet("background-color: green; color: white;");
            QMessageBox::information(this,
                                     "Paramètre de barre des tâches",
                                     "Le bouton d'Arrera RYLEY ne sera plus affiché.");
        }else{
            QMessageBox::critical(this,
                                  "Paramètre de barre des tâches",
                                  "Une erreur s'est produite.");
        }
    }else{
        sortie = objPara->setTaskbarBTNRyley();
        if (sortie){
            ui->IDC_ACTIVERYLEY->setText("Désactiver le bouton d'Arrera RYLEY.");
            ui->IDC_ACTIVERYLEY->setStyleSheet("background-color: red; color: white;");
            QMessageBox::information(this,
                                     "Paramètre de barre des tâches",
                                     "Le bouton d'Arrera RYLEY est affiché.");
        }else{
            QMessageBox::critical(this,
                                  "Paramètre de barre des tâches",
                                  "Une erreur s'est produite.");
        }
    }
    ui->LINDICATIONSETTING->setText("Parametre generaux");
    ui->stakedGeneraux->setCurrentIndex(idMainGeneraux);
}


void ArreraSettingUI::on_IDC_ACTIVECOPILOTE_clicked()
{
    bool sortie;
    if (objPara->getTaskbarCopilote()){
        sortie = objPara->unsetTaskbarBTNCopilote();
        if (sortie){
            ui->IDC_ACTIVECOPILOTE->setText("AActiver le bouton d'Arrera COPILOTE.");
            ui->IDC_ACTIVECOPILOTE->setStyleSheet("background-color: green; color: white;");
            QMessageBox::information(this,
                                     "Paramètre de barre des tâches",
                                     "Le bouton d'Arrera COPILOTE ne sera plus affiché.");
        }else{
            QMessageBox::critical(this,
                                  "Paramètre de barre des tâches",
                                  "Une erreur s'est produite.");
        }
    }else{
        sortie = objPara->setTaskbarBTNCopilote();
        if (sortie){
            ui->IDC_ACTIVECOPILOTE->setText("Désactiver le bouton d'Arrera COPILOTE.");
            ui->IDC_ACTIVECOPILOTE->setStyleSheet("background-color: red; color: white;");
            QMessageBox::information(this,
                                     "Paramètre de barre des tâches",
                                     "Le bouton d'Arrera COPILOTE est affiché.");
        }else{
            QMessageBox::critical(this,
                                  "Paramètre de barre des tâches",
                                  "Une erreur s'est produite.");
        }
    }
    ui->LINDICATIONSETTING->setText("Parametre generaux");
    ui->stakedGeneraux->setCurrentIndex(idMainGeneraux);
}

void ArreraSettingUI::on_IDC_ACTIVEPOSTITE_clicked()
{
    bool sortie;
    if (objPara->getTaskbarPostite()){
        sortie = objPara->unsetTaskbarBTNPostite();
        if (sortie){
            ui->IDC_ACTIVEPOSTITE->setText("Activer le bouton d'Arrera POSTITE.");
            ui->IDC_ACTIVEPOSTITE->setStyleSheet("background-color: green; color: white;");
            QMessageBox::information(this,"Paramètre de barre des tâches","Le bouton d'Arrera Postite ne sera plus affiché.");
        }else{
            QMessageBox::critical(this,
                                  "Paramètre de barre des tâches",
                                  "Une erreur s'est produite.");
        }
    }else{
        sortie = objPara->setTaskbarBBTNPostite();
        if (sortie){
            ui->IDC_ACTIVEPOSTITE->setText("Désactiver le bouton d'Arrera POSTITE.");
            ui->IDC_ACTIVEPOSTITE->setStyleSheet("background-color: red; color: white;");
            QMessageBox::information(this,
                                     "Paramètre de barre des tâches",
                                     "Le bouton d'Arrera POSTITE est affiché.");
        }else{
            QMessageBox::critical(this,
                                  "Paramètre de barre des tâches",
                                  "Une erreur s'est produite.");
        }
    }
    ui->LINDICATIONSETTING->setText("Parametre generaux");
    ui->stakedGeneraux->setCurrentIndex(idMainGeneraux);
}

void ArreraSettingUI::on_IDC_RETOURTASJBAR_clicked()
{
    ui->LINDICATIONSETTING->setText("Parametre generaux");
    ui->mainstacked->setCurrentIndex(idGenerauxPage);
    ui->stakedGeneraux->setCurrentIndex(idMainGeneraux);
}

// Partie application
//Partie ajout de l'app
void ArreraSettingUI::on_IDC_ICONAPPPC_clicked()
{
    QString imageFilter = "Images ("
                          "*.bmp *.gif *.jpg *.jpeg *.jpe *.jfif *.png "
                          "*.tif *.tiff *.webp *.svg *.svgz "
                          "*.ico *.icns *.ppm *.pgm *.pbm *.xpm *.xbm)";
    appIcon = QFileDialog::getOpenFileName(
        this,                       // Parent widget
        "Sélectionner l'application",  // Titre de la boîte de dialogue
        QDir::homePath(),       // Répertoire initial
        imageFilter);

    if (!appIcon.isEmpty()){
        ui->IDC_ICONAPPPC->setStyleSheet("background-color: #4CAF50;color: white;");
    }
}


void ArreraSettingUI::on_IDC_VALIDERAPPPC_clicked()
{
    int nbApp;
    bool sortie;
    QString nameApp = ui->IDC_LINENAMEAPPLICATINPC->text().toLower();
    ui->IDC_LINENAMEAPPLICATINPC->clear();
    if (objPara->checkNameAppIsAvailable(nameApp)){
        if (!nameApp.isEmpty() && !appEmplacement.isEmpty()){
            nbApp = objPara->getFirstUnsetNumber();
            if (appIcon.isEmpty()){
                sortie = objPara->setApplication(nbApp,nameApp,appEmplacement,"");
            }else{
                sortie =objPara->setApplication(nbApp,nameApp,appEmplacement,appIcon);
            }

            if (sortie){
                QMessageBox::information(this,"Enregistrement application",
                                         "L'application a bien été enregistrée.");
            }else{
                QMessageBox::critical(this,"Enregistrement application",
                                      "Impossible d'enregistrer l'application");
            }
        }
        else{
            QMessageBox::critical(this,"Enregistrement application",
                                  "Il manque une information pour enregistrer l'application.");
        }
    }
    else{
        QMessageBox::critical(this,"Enregistrement application",
                             "Il est impossible d'avoir deux applications qui ont le même nom.");
    }
    ui->appstacked->setCurrentIndex(idMainAppStaked);

}

void ArreraSettingUI::on_IDC_SETAPPPC_clicked()
{
    int rMessage;
    QString appDirectory ;
    // Partie linux
    if (dectOS->getosLinux() == true){
        rMessage = QMessageBox::question(this,"Emplacement application",
        "L'application est-elle dans le /bin ou dans votre /home ?",
        QMessageBox::Yes | QMessageBox::No,QMessageBox::No);

        if (rMessage == QMessageBox::Yes){
            // Dossier /bin
            appDirectory = "/bin";
        }else{
            // Dossier /home
            appDirectory = QDir::homePath();
        }
        appEmplacement = QFileDialog::getOpenFileName(
            this,                       // Parent widget
            "Sélectionner l'application",  // Titre de la boîte de dialogue
            appDirectory           // Répertoire initial
            );
    }else{
        if(dectOS->getosWin()==true){
            rMessage = QMessageBox::question(this,"Emplacement application",
                                                 "Le raccourci se trouve dans le menu Démarrer global ?",
                                                 QMessageBox::Yes | QMessageBox::No,QMessageBox::No);

            if (rMessage == QMessageBox::Yes){
                // Dossier programme data
                appDirectory = "C:/ProgramData/Microsoft/Windows/Start Menu/Programs";
            }else{
                // Menu demarer dans le dossier utilisateur
                appDirectory = QStandardPaths::writableLocation(QStandardPaths::ApplicationsLocation);
            }
            appEmplacement = QFileDialog::getOpenFileName(
                this,                       // Parent widget
                "Sélectionner l'application",  // Titre de la boîte de dialogue
                appDirectory           // Répertoire initial
                );
        }
    }

    // Teste si l'application a etais choisie
    if (appEmplacement != ""){
        ui->IDC_VALIDERAPPPC->setVisible(true);
        ui->IDC_SETAPPPC->setStyleSheet("background-color: #4CAF50;color: white;");
    }
}

void ArreraSettingUI::on_IDC_CANCELAPPPC_clicked()
{
    ui->LINDICATIONSETTING->setText("Parametre des applications");
    ui->appstacked->setCurrentIndex(idMainAppStaked);
}

//Partie suppr de l'app
void ArreraSettingUI::on_IDC_CANCELSUPPRAPP_clicked()
{
    ui->LINDICATIONSETTING->setText("Parametre des applications");
    ui->appstacked->setCurrentIndex(idMainAppStaked);
}


void ArreraSettingUI::on_IDC_VALIDERSUPRR_clicked()
{
    QString nameApp = ui->LISTOPTIONAPPSUPPR->currentText();
    int nbApp = objPara->getNbAppWithName(nameApp);

    if (objPara->setSupprApplication(nbApp)){
        QMessageBox::information(this,"Suppression d'une application",
                              "L'application a bien été supprimée.");
    }else{
        QMessageBox::critical(this,"Suppression d'une application",
                              "Impossible de supprimer l'application.");
    }

    ui->LINDICATIONSETTING->setText("Parametre des applications");
    ui->appstacked->setCurrentIndex(idMainAppStaked);
}

//Partie acceuil d'app
void ArreraSettingUI::on_IDC_ADDAPPPC_clicked()
{
    if (objPara->getnbAppSetted() < 21){
        ui->LINDICATIONSETTING->setText("Ajouter une application");
        ui->appstacked->setCurrentIndex(idAddAppStacked);
        ui->IDC_VALIDERAPPPC->setVisible(false);
        ui->IDC_LINENAMEAPPLICATINPC->clear();
        appEmplacement = "";
        appIcon = "";
        ui->IDC_ICONAPPPC->setStyleSheet("");
        ui->IDC_SETAPPPC->setStyleSheet("");
    }else{
        QMessageBox::critical(this,
                              "Gestion application",
                              "Vous n'avez plus d'emplacement pour enregistrer une application.");
    }
}


void ArreraSettingUI::on_IDC_SUPPRAPPPC_clicked()
{
    if (objPara->getnbAppSetted() == 0){
        QMessageBox::critical(this,
            "Gestion application",
            "Il n'y a aucune application pour enregistrer");
    }else{
        setAppComboBox();
        ui->LINDICATIONSETTING->setText("Supprimer une application");
        ui->appstacked->setCurrentIndex(idSupprAppStacked);
    }
}

void ArreraSettingUI::on_IDC_CHANGEICON_clicked()
{
    if (objPara->getnbAppSetted() == 0){
        QMessageBox::critical(this,
                              "Gestion application",
                              "Il n'y a aucune application pour enregistrer");
    }else{
        setAppComboBox();
        ui->LINDICATIONSETTING->setText("Changer l'icône des applications");
        ui->appstacked->setCurrentIndex(idIconChangeApp);
    }
}

void ArreraSettingUI::on_IDC_MODIFEMPLACMENTAPPPC_clicked()
{
    if (objPara->getnbAppSetted() == 0){
        QMessageBox::critical(this,
                              "Gestion application",
                              "Il n'y a aucune application pour enregistrer");
    }else{
        setAppComboBox();
        ui->LINDICATIONSETTING->setText("Changer l'emplacement des applications");
        ui->appstacked->setCurrentIndex(idEmplacementAppStacked);
    }
}

void ArreraSettingUI::on_IDC_EDITTABLEUR_clicked()
{
    if (objPara->getAppSpeciauxSetted(3)){
        ui->IDC_RESETAPPSPEC->setVisible(true);
        ui->IDC_CHOOSEAPPSPE->setVisible(false);
    }else{
        ui->IDC_RESETAPPSPEC->setVisible(false);
        ui->IDC_CHOOSEAPPSPE->setVisible(true);
    }
    ui->appstacked->setCurrentIndex(idManageAppSpeciaux);
    appSpeSelected = 3;
    ui->LINCAPPSPEMANAGE->setText("Gestion de l'enregistrement de l'application tableur");
    ui->LINDICATIONSETTING->setText("Parametre application tableur");
}


void ArreraSettingUI::on_IDC_EDITTRAITEMENTTEXTE_clicked()
{
    if (objPara->getAppSpeciauxSetted(4)){
        ui->IDC_RESETAPPSPEC->setVisible(true);
        ui->IDC_CHOOSEAPPSPE->setVisible(false);
    }else{
        ui->IDC_RESETAPPSPEC->setVisible(false);
        ui->IDC_CHOOSEAPPSPE->setVisible(true);
    }
    ui->appstacked->setCurrentIndex(idManageAppSpeciaux);
    appSpeSelected = 4;
    ui->LINCAPPSPEMANAGE->setText("Gestion de l'enregistrement de l'application\nde traitement de texte");
    ui->LINDICATIONSETTING->setText("Parametre application de traitement de texte");
}


void ArreraSettingUI::on_IDC_EDITNAVIGATEUR_clicked()
{
    if (objPara->getAppSpeciauxSetted(1)){
        ui->IDC_RESETAPPSPEC->setVisible(true);
        ui->IDC_CHOOSEAPPSPE->setVisible(false);
    }else{
        ui->IDC_RESETAPPSPEC->setVisible(false);
        ui->IDC_CHOOSEAPPSPE->setVisible(true);
    }
    ui->appstacked->setCurrentIndex(idManageAppSpeciaux);
    appSpeSelected = 1;
    ui->LINCAPPSPEMANAGE->setText("Gestion de l'enregistrement de l'application navigateur");
    ui->LINDICATIONSETTING->setText("Parametre application navigateur");
}


void ArreraSettingUI::on_IDC_EDITPRESENTATION_clicked()
{
    if (objPara->getAppSpeciauxSetted(2)){
        ui->IDC_RESETAPPSPEC->setVisible(true);
        ui->IDC_CHOOSEAPPSPE->setVisible(false);
    }else{
        ui->IDC_RESETAPPSPEC->setVisible(false);
        ui->IDC_CHOOSEAPPSPE->setVisible(true);
    }
    ui->appstacked->setCurrentIndex(idManageAppSpeciaux);
    appSpeSelected = 2;
    ui->LINCAPPSPEMANAGE->setText("Gestion de l'enregistrement de l'application\nde presentation");
    ui->LINDICATIONSETTING->setText("Parametre application presentation");
}

// Partie changement icon APP

void ArreraSettingUI::on_IDC_CANCELCHANGEICON_clicked()
{
    ui->LINDICATIONSETTING->setText("Parametre des applications");
    ui->appstacked->setCurrentIndex(idMainAppStaked);
}


void ArreraSettingUI::on_IDC_CHANGEICONE_clicked()
{
    bool sortie;

    QString nameApp = ui->LISTAPPCHANGEICON->currentText();
    int nbApp = objPara->getNbAppWithName(nameApp);

    QString imageFilter = "Images ("
                          "*.bmp *.gif *.jpg *.jpeg *.jpe *.jfif *.png "
                          "*.tif *.tiff *.webp *.svg *.svgz "
                          "*.ico *.icns *.ppm *.pgm *.pbm *.xpm *.xbm)";
    QString newIcon = QFileDialog::getOpenFileName(
        this,                       // Parent widget
        "Sélectionner l'application",  // Titre de la boîte de dialogue
        QDir::homePath(),       // Répertoire initial
        imageFilter);

    if (!newIcon.isEmpty()){
        sortie = objPara->setNewIconApplication(nbApp,newIcon);

        if (sortie){
            QMessageBox::information(this,"Icon application",
                                     "L'icône a bien été changée.");
        }
        else{
            QMessageBox::critical(this,"Icon application",
                                  "Impossible de changer l'icône.");
        }

    }
    else{
        QMessageBox::critical(this,"Icon application",
                              "Aucune icône sélectionnée.");
    }

    ui->LINDICATIONSETTING->setText("Parametre des applications");
    ui->appstacked->setCurrentIndex(idMainAppStaked);
}

// Partie changement emplacement app
void ArreraSettingUI::on_IDC_VALIDERCHANGEEMPLACEMENTAPP_clicked()
{
    bool sortie;
    int rMessage;
    QString appDirectory ;

    QString nameApp = ui->LISTAPPCHANGEEMPLACEMENT->currentText();
    int nbApp = objPara->getNbAppWithName(nameApp);

    QString newEmplacement ;

    if (dectOS->getosLinux() == true){

        rMessage = QMessageBox::question(this,"Emplacement application",
                                             "L'application est-elle dans le /bin ou dans votre /home ?",
                                             QMessageBox::Yes | QMessageBox::No,QMessageBox::No);

        if (rMessage == QMessageBox::Yes){
            // Dossier /bin
            appDirectory = "/bin";
        }else{
            // Dossier /home
            appDirectory = QDir::homePath();
        }
        newEmplacement = QFileDialog::getOpenFileName(
            this,                       // Parent widget
            "Sélectionner l'application",  // Titre de la boîte de dialogue
            appDirectory           // Répertoire initial
            );
    }else{
        if(dectOS->getosWin()==true){
            rMessage = QMessageBox::question(this,"Emplacement application",
                                             "Le raccourci se trouve dans le menu Démarrer global ?",
                                             QMessageBox::Yes | QMessageBox::No,QMessageBox::No);

            if (rMessage == QMessageBox::Yes){
                // Dossier programme data
                appDirectory = "C:/ProgramData/Microsoft/Windows/Start Menu/Programs";
            }else{
                // Menu demarer dans le dossier utilisateur
                appDirectory = appDirectory = QStandardPaths::writableLocation(QStandardPaths::ApplicationsLocation);
            }
            newEmplacement = QFileDialog::getOpenFileName(
                this,                       // Parent widget
                "Sélectionner l'application",  // Titre de la boîte de dialogue
                appDirectory           // Répertoire initial
                );
        }
    }

    // Teste si l'application a etais choisie
    if (newEmplacement != ""){
        sortie = objPara->setNewExeApplication(nbApp,newEmplacement);
        if (sortie){
            QMessageBox::information(this,"Nouveau emplacement",
                                     "Le nouvel emplacement de l'application a été enregistré.");
        }else{
            QMessageBox::critical(this,"Nouveau emplacement",
                                  "Impossible d'enregistrer le nouvel emplacement.");
        }
    }else{
        QMessageBox::critical(this,"Nouveau emplacement",
                              "Vous n'avez pas sélectionné l'application.");
    }

    ui->LINDICATIONSETTING->setText("Parametre des applications");
    ui->appstacked->setCurrentIndex(idMainAppStaked);
}

void ArreraSettingUI::on_IDC_CANCELEMPLACEMENTAPP_clicked()
{
    ui->LINDICATIONSETTING->setText("Parametre des applications");
    ui->appstacked->setCurrentIndex(idMainAppStaked);
}

// Partie app speciaux
void ArreraSettingUI::on_IDC_CANCELAPPSPEMANAGE_clicked()
{
    ui->LINDICATIONSETTING->setText("Parametre des applications");
    ui->appstacked->setCurrentIndex(idMainAppStaked);
}


void ArreraSettingUI::on_IDC_CHOOSEAPPSPE_clicked()
{
    QString speAppEmplacement,appDirectory;
    int rMessage;
    bool sortie;
    if (dectOS->getosLinux() == true){
        rMessage = QMessageBox::question(this,"Emplacement application",
                                         "L'application est-elle dans le /bin ou dans votre /home ?",
                                         QMessageBox::Yes | QMessageBox::No,QMessageBox::No);

        if (rMessage == QMessageBox::Yes){
            // Dossier /bin
            appDirectory = "/bin";
        }else{
            // Dossier /home
            appDirectory = QDir::homePath();
        }
        speAppEmplacement = QFileDialog::getOpenFileName(
            this,                       // Parent widget
            "Sélectionner l'application",  // Titre de la boîte de dialogue
            appDirectory           // Répertoire initial
            );
    }else{
        if(dectOS->getosWin()==true){
            rMessage = QMessageBox::question(this,"Emplacement application",
                                             "Le raccourci se trouve dans le menu Démarrer global ?",
                                             QMessageBox::Yes | QMessageBox::No,QMessageBox::No);

            if (rMessage == QMessageBox::Yes){
                // Dossier programme data
                appDirectory = "C:/ProgramData/Microsoft/Windows/Start Menu/Programs";
            }else{
                // Menu demarer dans le dossier utilisateur
                appDirectory = QStandardPaths::writableLocation(QStandardPaths::ApplicationsLocation);
            }
            speAppEmplacement = QFileDialog::getOpenFileName(
                this,                       // Parent widget
                "Sélectionner l'application",  // Titre de la boîte de dialogue
                appDirectory           // Répertoire initial
                );
        }
    }

    // Teste si l'application a etais choisie
    // 1.Navigateur 2.Presentation 3.tableur 4.Traitement de texte
    if (speAppEmplacement != ""){
        switch (appSpeSelected) {
        case 1:
            sortie = objPara->setAppNavigateur(speAppEmplacement);
            break;
        case 2:
            sortie = objPara->setAppPresentation(speAppEmplacement);
            break;
        case 3:
            sortie = objPara->setAppTableur(speAppEmplacement);
            break;
        case 4:
            sortie = objPara->setAppTraitementTexte(speAppEmplacement);
            break;
        default:
            break;
        }
    }
    if (sortie){
        QMessageBox::information(this,"Application",
                                 "L'application a bien été enregistrée.");
    }else{
        QMessageBox::critical(this,"Application",
                              "Impossible d'enregistrer l'application.");
    }
    ui->LINDICATIONSETTING->setText("Parametre des applications");
    ui->appstacked->setCurrentIndex(idMainAppStaked);
}


void ArreraSettingUI::on_IDC_RESETAPPSPEC_clicked()
{
    bool sortie;
    // 1.Navigateur 2.Presentation 3.tableur 4.Traitement de texte
    switch (appSpeSelected) {
    case 1:
        sortie = objPara->setSupprAppNavigateur();
        break;
    case 2:
        sortie = objPara->setSupprAppPresentation();
        break;
    case 3:
        sortie = objPara->setSupprAppTableur();
        break;
    case 4:
        sortie = objPara->setSupprAppTraitementTexte();
        break;
    default:
        break;
    }

    if (sortie){
        QMessageBox::information(this,"Application",
                                 "L'application a été supprimée.");
    }else{
        QMessageBox::critical(this,"Application",
                              "Impossible de supprimer l'application.");
    }

    ui->LINDICATIONSETTING->setText("Parametre des applications");
    ui->appstacked->setCurrentIndex(idMainAppStaked);
}

// Partie Recherche

void ArreraSettingUI::on_IDC_VALIDERRECHERCHE_clicked()
{
    QString moteur = ui->IDC_LISTEMOTEURERECHERCHE->currentText();
    bool sortie = objPara->setMoteurRecherche(moteur);

    if (sortie){
        QMessageBox::information(this,
                                 "Paramètre de recherche",
                                 "Le moteur de recherche a été modifié.");
    }else{
        QMessageBox::critical(this,"Paramètre de recherche",
                              "Impossible de changer le moteur de recherche.");
    }
    ui->mainstacked->setCurrentIndex(idMainPage);
}

void ArreraSettingUI::on_IDC_SUPPRHIST_clicked()
{
    bool sortie = objRecherche->clear();
    if(sortie){
        QMessageBox::information(this,
                                 "Historique Arrera Recherche",
                                 "L'historique de recherche a été supprimé.");
    }else{
        QMessageBox::critical(this,
                                 "Historique Arrera Recherche",
                                 "Impossible de supprimer l'historique.");
    }
    ui->mainstacked->setCurrentIndex(idMainPage);
}

// Partie Lieu

// Acceuil lieu
void ArreraSettingUI::on_IDC_MANAGELIEU1_clicked()
{
    if (!objPara->lieu1IsSeted()){
        ui->lieustacked->setCurrentIndex(idAddLieu);
        ui->LINDICATIONSETTING->setText("Paramétrage du lieu numéro 1");
        ui->IDC_INDCLIEUADD->setText("Création du lieu numéro 1");
    }else{
        ui->lieustacked->setCurrentIndex(idManageLieu);
        ui->LINDICATIONSETTING->setText("Modification du lieu numéro 1");
        ui->LINDICATIONMANAGELIEU->setText("Modification du lieu numéro 1");
    }
    lieuSelected = 1;
}


void ArreraSettingUI::on_IDC_MANAGELIEU1_2_clicked()
{
    if (!objPara->lieu2IsSeted()){
        ui->lieustacked->setCurrentIndex(idAddLieu);
        ui->LINDICATIONSETTING->setText("Paramétrage du lieu numéro 2");
        ui->IDC_INDCLIEUADD->setText("Création du lieu numéro 2");
    }else{
        ui->lieustacked->setCurrentIndex(idManageLieu);
        ui->LINDICATIONSETTING->setText("Modification du lieu numéro 2");
         ui->LINDICATIONMANAGELIEU->setText("Modification du lieu numéro 2");
    }
    lieuSelected = 2;
}

// Create

void ArreraSettingUI::on_IDC_CREALIEU_clicked()
{
    // Recuperation des valeur
    QString name = ui->IDC_NAMECREATELIEU->text();
    QString geo = ui->IDC_EDITLIEUADD->text();
    QString assistant = ui->IDC_LISTASSISTANTLIEU->currentText();

    ui->IDC_NAMECREATELIEU->clear();
    ui->IDC_EDITLIEUADD->clear();

    // Teste des valeur
    bool nameIsSetted = name.isEmpty();
    bool geoIsSetted = geo.isEmpty();

    // Creation des var pour tester les ecriture
    bool sortieName,sortieAssistant,sortieGeo;

    if (nameIsSetted && geoIsSetted ){
        QMessageBox::critical(this,"Erreur lieu",
                              "Impossible de créer un lieu sans son emplacement géographique et sans nom.");
    }else{
        if (nameIsSetted){
            QMessageBox::critical(this,"Erreur lieu",
                                  "Impossible de créer un lieu sans nom.");
        }else{
            if (geoIsSetted){
                QMessageBox::critical(this,"Erreur lieu",
                                      "Impossible de créer un lieu sans un emplacement géographique.");
            }
            else{
                switch (lieuSelected) {
                case 1:
                    sortieName = objPara->setNameLieu1(name);
                    sortieAssistant = objPara->setAssistantLieu1(assistant);
                    sortieGeo = objPara->setGeoLieu1(geo);
                    break;
                case 2:
                    sortieName = objPara->setNameLieu2(name);
                    sortieAssistant = objPara->setAssistantLieu2(assistant);
                    sortieGeo = objPara->setGeoLieu2(geo);
                    break;
                default:
                    sortieName = false;
                    sortieAssistant = false;
                    sortieGeo = false;
                    break;
                }
                if (sortieAssistant && sortieName && sortieGeo){
                    QMessageBox::information(this,"Parametrage du lieu"+QString::number(lieuSelected),
                                             "Le lieu numéro "+QString::number(lieuSelected)+" est bien paramétré.");
                }else{
                    QMessageBox::critical(this,"Erreur lieu",
                                          "Une erreur est survenue, il est donc impossible de créer le lieu");
                }
            }
        }
    }
    ui->lieustacked->setCurrentIndex(idMainLieu);
    lieuSelected = 0;
}


void ArreraSettingUI::on_IDC_CANCELCREATELIEU_clicked()
{
    ui->lieustacked->setCurrentIndex(idMainLieu);
    ui->LINDICATIONSETTING->setText("Parametre des lieu");
    lieuSelected = 0;
}

void ArreraSettingUI::on_IDC_ICONCHOOSELIEU_clicked()
{
    QString icon = chooseIcon();
    bool sortie ;
    if (!icon.isEmpty()){
        switch (lieuSelected) {
        case 1:
            sortie = objPara->setIconLieu1(icon);
            break;
        case 2:
            sortie = objPara->setIconLieu2(icon);
            break;
        default:
            sortie = false;
            break;
        }
        if (sortie){
            QMessageBox::information(this,"Icône lieu",
                                     "L'icône de votre lieu a bien été enregistrée.");
        }else{
            QMessageBox::critical(this,"Erreur icône lieu",
                                  "Une erreur s'est produite, je ne peux pas enregistrer l'icône pour ce lieu.");
        }
    }
    else{
        QMessageBox::critical(this,"Erreur icône lieu",
                              "Vous n'avez pas sélectionné d'icône.");
    }
}

// Manage lieu

void ArreraSettingUI::on_IDC_CHANGENAMELIEU_clicked()
{
    QString name = ui->IDC_LINECHANGENAMELIEU->text();
    bool sortie;

    ui->IDC_LINECHANGENAMELIEU->clear();

    if (!name.isEmpty()){
        switch (lieuSelected) {
        case 1:
            sortie = objPara->setNameLieu1(name);
            break;
        case 2:
            sortie = objPara->setNameLieu2(name);
            break;
        default:
            sortie = false;
            break;
        }

        if(sortie){
            QMessageBox::information(this,"Changement d'icône du lieu "+
                                               QString::number(lieuSelected),
                                     "Le nouveau nom du lieu "+
                                         QString::number(lieuSelected)+" est bien enregistré.");
        }else{
            QMessageBox::critical(this,"Changement d'icône du lieu "+
                                               QString::number(lieuSelected),
                                  "Une erreur s'est produite, impossible de changer le nom du lieu.");
        }
    }else{
        QMessageBox::critical(this,"Changement d'icône du lieu "+
                                        QString::number(lieuSelected),
                              "Impossible de changer le nom du lieu si le nouveau nom est vide.");
    }
    ui->lieustacked->setCurrentIndex(idMainLieu);
}


void ArreraSettingUI::on_IDC_CHANGEASSISTANTLIEU_clicked()
{
    QString newAssistant = ui->IDC_LISTASSISTANTMANAGELIEU->currentText();
    bool sortie ;

    switch (lieuSelected) {
    case 1:
        sortie = objPara->setAssistantLieu1(newAssistant);
        break;
    case 2:
        sortie = objPara->setAssistantLieu2(newAssistant);
        break;
    default:
        sortie = false;
        break;
    }

    if (sortie){
        QMessageBox::information(this,"Lieu assistant",
                                 "L'assistant du lieu "+
                                     QString::number(lieuSelected)+
                                     " a bien été changé.");
    }else{
        QMessageBox::critical(this,"Lieu assistant",
                              "Impossible de changer l'assistant, une erreur s'est produite.");
    }

    ui->lieustacked->setCurrentIndex(idMainLieu);
}


void ArreraSettingUI::on_IDC_ANNULERMANAGELIEU_clicked()
{
    ui->lieustacked->setCurrentIndex(idMainLieu);
    ui->LINDICATIONSETTING->setText("Parametre des lieu");
    lieuSelected = 0 ;
}

void ArreraSettingUI::on_IDC_CHANGEGEOMANAGE_clicked()
{
    QString geo = ui->ID_GEOLIEUMANAGE->text();
    bool sortie;
    if (!geo.isEmpty()){
        switch (lieuSelected) {
        case 1:
            sortie = objPara->setAssistantLieu1(geo);
            break;
        case 2:
            sortie = objPara->setAssistantLieu2(geo);
            break;
        default:
            sortie = false;
            break;
        }

        if(sortie){
            QMessageBox::information(this,"Emplacement lieu",
                                     "L'emplacement du lieu "+QString::number(lieuSelected)+
                                         " a bien été changé.");
        }else{
            QMessageBox::critical(this,"Emplacement lieu",
                                     "L'emplacement du lieu "+QString::number(lieuSelected)+
                                      " n'a pas pu être changé.");
        }
    }else{
        QMessageBox::critical(this,"Emplacement vide",
                              "Impossible de changer l'emplacement avec quelque chose de vide.");
    }

    ui->lieustacked->setCurrentIndex(idMainLieu);
}

void ArreraSettingUI::on_IDC_CHANGEICONLIEU_clicked()
{
    on_IDC_ICONCHOOSELIEU_clicked();
    ui->lieustacked->setCurrentIndex(idMainLieu);
    ui->LINDICATIONSETTING->setText("Parametre des lieu");
    lieuSelected = 0 ;
}
