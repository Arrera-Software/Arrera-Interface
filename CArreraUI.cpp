#include "CArreraUI.h"
#include <QDesktopServices>
#include <QUrl>
#include "./ui_CArreraUI.h"


CArreraUI::CArreraUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CArreraUI),
    process(new QProcess(this))
{
    //Initilisation de l'interface
    ui->setupUi(this);
    ui->IDC_COPILOTE->setVisible(false);
    ui->FMode->setVisible(false);
    ui->FGUI->setVisible(true);
    ui->FLOGIN->setVisible(false);
    ui->IDC_INDNOMODE->setVisible(true);
    ui->IDC_QUIT->setVisible(false);
    ui->IDC_RELOAD->setVisible(false);
    // Initilisation spesifique a linux
    if ((osDetecteur.getLinux())&&(!osDetecteur.getWindows()))
    {
        ui->IDC_SIX->setVisible(false);
    }
    // Declaration des fenetre fille
    winPara = new CDAParametre(this);
    winAPP = new ArreraAppLib(this);
    winApropos = new CArreraApropos(this);
    taskBar = new CArreraTakbar(this);
    winPostite = new CArreraPostite(this);
    objTiger = new CArreraTigerInteg(process);
    // Passage de parametre au fenetre fille
    objSoftware.setObjPara(&objPara);
    winPara->passObjPara(&objPara,&objSoftware);
    winAPP->passObjet(&objPara,&objSoftware);
    taskBar->passObj(&objPara,&objSoftware);
    // Ajout de la fermeture de tout les fenetre si la principal est quitter
    connect(this,&CArreraUI::destroyed,winPara,&CArreraUI::close);
    connect(this,&CArreraUI::destroyed,winAPP,&CArreraUI::close);
    connect(this,&CArreraUI::destroyed,winApropos,&CArreraUI::close);
    connect(this,&CArreraUI::destroyed,taskBar,&CArreraUI::close);
    connect(this,&CArreraUI::destroyed,winPostite,&CArreraUI::close);
    // Ajout de l'actulisation de la fenetre principal si les parametre son quitter
    connect(winPara,&CDAParametre::parametresFerme,this,&CArreraUI::loadSetting);
    // Chargement des parametre
    loadSetting();
    // Verif des parametre
    if(!objPara.getParaSetteur())
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Arrera : Information");
        msgBox.setText("Votre interface n'est pas configurer aller\ndans les parametre pour la configurer");
        msgBox.exec();
        winPara->show();
    }
}

CArreraUI::~CArreraUI()
{
    delete ui;
}

// Bouton Bottom
void CArreraUI::on_IDC_QUIT_clicked()
{
    qApp->quit();
}


void CArreraUI::on_IDC_PARAMETRE_clicked()
{
    winPara->show();
}

// Bouton assistant
void CArreraUI::on_IDC_SIX_clicked()
{
    bool sortie ;
    sortie = objSoftware.openSix();
    if (!sortie)
    {
        errorOpenSoft();
    }
}


void CArreraUI::on_IDC_COPILOTE_clicked()
{
    objTiger->startCopilote();
}


void CArreraUI::on_IDC_RYLEY_clicked()
{
    bool sortie ;
    sortie = objSoftware.openRyley();
    if (!sortie)
    {
        errorOpenSoft();
    }
}

// bouton mode

void CArreraUI::on_IDC_MODE1_clicked()
{
    onMode(1);
}


void CArreraUI::on_IDC_MODE2_clicked()
{
    onMode(2);
}


void CArreraUI::on_IDC_MODE3_clicked()
{
    onMode(3);
}


void CArreraUI::on_IDC_MODE4_clicked()
{
    onMode(4);
}


void CArreraUI::on_IDC_MODE5_clicked()
{
    onMode(5);
}

// Bouton app
void CArreraUI::on_IDC_TABLEUR_clicked()
{
    bool sortie ;
    sortie = objSoftware.openTableur();
    if (!sortie)
    {
        errorOpenSoft();
    }

}


void CArreraUI::on_IDC_TRAITEMENT_clicked()
{
    bool sortie ;
    sortie = objSoftware.openTTexte();
    if (!sortie)
    {
        errorOpenSoft();
    }
}


void CArreraUI::on_IDC_APP_clicked()
{
    winAPP->show();
}


void CArreraUI::on_IDC_NAVIGATEUR_clicked()
{
    bool sortie ;
    sortie = objSoftware.openNavigateur();
    if (!sortie)
    {
        errorOpenSoft();
    }
}


void CArreraUI::on_IDC_PRESENTATION_clicked()
{
    bool sortie ;
    sortie = objSoftware.openPresentation();
    if (!sortie)
    {
        errorOpenSoft();
    }
}

void CArreraUI::closeEvent(QCloseEvent *event)
{
    // Fermer toutes les fenêtres enfants lorsque la fenêtre principale est fermée
    foreach(QWidget *widget, QApplication::topLevelWidgets()) {
        if (widget != this && widget->inherits("MaFenetreEnfant")) {
            widget->close();
        }
    }
    // Appeler la méthode closeEvent de la classe de base pour effectuer la fermeture par défaut
    QMainWindow::closeEvent(event);
}

void CArreraUI::loadSetting()
{
    QString nameUser;
    int modeCharger = 0 ;
    nameUser = QString::fromStdString(objPara.getNameUser().c_str());
    if (nameUser=="Nothing")
    {
        ui->IDC_LABELUSER->setVisible(false);
    }
    else
    {
        ui->IDC_LABELUSER->setText("Utilisateur : "+nameUser);
        ui->IDC_LABELUSER->setVisible(true);
        ui->IDC_NAMEUSERLOGIN->setText("Utilisateur : "+nameUser);
    }

    if (objPara.getModeEnable(1)=="1")
    {
        ui->IDC_MODE1->setVisible(true);
        ui->IDC_MODE1->setText(objPara.getNameMode(1).c_str());
        modeCharger++;
    }
    else
    {
        ui->IDC_MODE1->setVisible(false);
    }
    if (objPara.getModeEnable(2)=="1")
    {
        ui->IDC_MODE2->setVisible(true);
        ui->IDC_MODE2->setText(objPara.getNameMode(2).c_str());
        modeCharger++;
    }
    else
    {
        ui->IDC_MODE2->setVisible(false);
    }
    if (objPara.getModeEnable(3)=="1")
    {
        ui->IDC_MODE3->setVisible(true);
        ui->IDC_MODE3->setText(objPara.getNameMode(3).c_str());
        modeCharger++;
    }
    else
    {
        ui->IDC_MODE3->setVisible(false);
    }
    if (objPara.getModeEnable(4)=="1")
    {
        ui->IDC_MODE4->setVisible(true);
        ui->IDC_MODE4->setText(objPara.getNameMode(4).c_str());
        modeCharger++;
    }
    else
    {
        ui->IDC_MODE4->setVisible(false);
    }
    if (objPara.getModeEnable(5)=="1")
    {
        ui->IDC_MODE5->setVisible(true);
        ui->IDC_MODE5->setText(objPara.getNameMode(5).c_str());
        modeCharger++;
    }
    else
    {
        ui->IDC_MODE5->setVisible(false);
    }
    if(modeCharger==0)
    {
        ui->IDC_INDNOMODE->setVisible(true);
    }
    else
    {
        ui->IDC_INDNOMODE->setVisible(false);
    }
    if (objPara.getSoftTableur()=="nothing")
    {
        ui->IDC_TABLEUR->setVisible(false);
    }
    else
    {
        ui->IDC_TABLEUR->setVisible(true);
    }
    if(objPara.getSixEmplacement()=="nothing")
    {
        ui->IDC_SIX->setVisible(false);
    }
    else
    {
        ui->IDC_SIX->setVisible(true);
    }
    if(objPara.getSoftNavigateur()=="nothing")
    {
        ui->IDC_NAVIGATEUR->setVisible(false);
    }
    else
    {
        ui->IDC_NAVIGATEUR->setVisible(true);
    }
    if(objPara.getRyleyEmplacement()=="nothing")
    {
        ui->IDC_RYLEY->setVisible(false);
    }
    else
    {
        ui->IDC_RYLEY->setVisible(true);
    }
    if(objPara.getSoftPresentation()=="nothing")
    {
        ui->IDC_PRESENTATION->setVisible(false);
    }
    else
    {
        ui->IDC_PRESENTATION->setVisible(true);
    }
    if(objPara.getSoftTTexte()=="nothing")
    {
        ui->IDC_TRAITEMENT->setVisible(false);
    }
    else
    {
        ui->IDC_TRAITEMENT->setVisible(true);
    }
    if(objTiger->copiloteInstall())
    {
        ui->IDC_COPILOTE->setVisible(true);
    }
    else
    {
        ui->IDC_COPILOTE->setVisible(false);
    }
    winAPP->updateBTN();
    taskBar->loadPara(0);
    /*
    mtpIn =  "";
    mtpCacher="";
    userMTP = objPara.getMTPUser();
    ui->IDC_SHOWMTPLOGIN->setText(mtpCacher);
    */
}

void CArreraUI::on_IDC_RELOAD_clicked()
{
    loadSetting();
}

void CArreraUI::errorOpenSoft()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Erreur");
    msgBox.setText("Une erreur ces produite lors de l'ouverture du logiciel");
    msgBox.addButton(QMessageBox::Ok);
}

void CArreraUI::on_IDC_APROPOS_clicked()
{
    winApropos->show();
}


void CArreraUI::on_IDC_TASKBAR_clicked()
{
    taskBar->show();
}

//BTN UI MODE

void CArreraUI::bootAssistantMode()
{
    bool sortie ;
    qDebug() <<nbModeON;
    if(objPara.getAssistantMode(nbModeON)=="six")
    {
        sortie = objSoftware.openSix();
        if (!sortie)
        {
            errorOpenSoft();
        }
    }
    else
    {
        if (objPara.getAssistantMode(nbModeON)=="ryley")
        {
            sortie = objSoftware.openRyley();
            if (!sortie)
            {
                errorOpenSoft();
            }
        }
        else {
            if (objPara.getAssistantMode(nbModeON)=="copilote")
            {
                if(!objTiger->startCopilote())
                {
                    errorOpenSoft();
                }
            }
        }
    }
}

void CArreraUI::onMode(int nbMode)
{
    if (objPara.getModeEnable(nbMode)=="1")
    {
        ui->FGUI->setVisible(false);
        ui->FMode->setVisible(true);
        ui->IDC_NAMEMODEON->setText(objPara.getNameMode(nbMode).c_str());
        if (objPara.getEtatTaskbar(nbMode)=="true")
        {
            ui->IDC_TASKBARMODE->setVisible(true);
        }
        else
        {
            ui->IDC_TASKBARMODE->setVisible(false);
        }
        nbModeON = nbMode;
        objSoftware.openAppLib((stoi(objPara.getModeAppAsBoot(nbMode))));
        bootAssistantMode();
        if (objPara.getAssistantMode(nbModeON)=="nothing")
        {
            ui->IDC_ASSISTANTMODE->setVisible(false);
        }
        if(objPara.getVMMode(nbMode)=="true")
        {
            objSoftware.openVMStart();
        }
        if(objPara.getTouchMode(nbMode)=="true")
        {
            objSoftware.openSoftTouchScreen();
        }
    }
    else
    {
        QMessageBox::information(nullptr, "Mode", "Le mode selectionner n'est pas parametrer");
    }
}

void CArreraUI::offMode()
{
    nbModeON = 0;
    ui->FGUI->setVisible(true);
    ui->FMode->setVisible(false);
    loadSetting();
}

void CArreraUI::on_IDC_TABLEURMODE_clicked()
{
    bool sortie ;
    sortie = objSoftware.openTableur();
    if (!sortie)
    {
        errorOpenSoft();
    }
}


void CArreraUI::on_IDC_TRAITEMENTMODE_clicked()
{
    bool sortie ;
    sortie = objSoftware.openTTexte();
    if (!sortie)
    {
        errorOpenSoft();
    }
}


void CArreraUI::on_IDC_APPMODE_clicked()
{
    winAPP->show();
}


void CArreraUI::on_IDC_TASKBARMODE_clicked()
{
    taskBar->loadPara(nbModeON);
    taskBar->show();
}


void CArreraUI::on_IDC_NAVIGATEURMODE_clicked()
{
    bool sortie ;
    sortie = objSoftware.openNavigateur();
    if (!sortie)
    {
        errorOpenSoft();
    }
}


void CArreraUI::on_IDC_PRESENTATIONMODE_clicked()
{
    bool sortie ;
    sortie = objSoftware.openPresentation();
    if (!sortie)
    {
        errorOpenSoft();
    }
}


void CArreraUI::on_IDC_QUITMODE_clicked()
{
    offMode();
}


void CArreraUI::on_IDC_QUIT2_clicked()
{
    qApp->quit();
}


void CArreraUI::on_IDC_ASSISTANTMODE_clicked()
{
    bootAssistantMode();
}

// ecran login

void CArreraUI::addNumberMTP(QString nb)
{
    /*
    QString old = mtpIn , oldMtpCacher = mtpCacher;
    mtpIn = old+nb;
    mtpCacher = oldMtpCacher + "*";
    showMTP = 0 ;
    ui->IDC_SHOWMTPLOGIN->setText(mtpCacher);
*/
}

void CArreraUI::on_IDC_MTPLOGIN1_clicked()
{
    addNumberMTP("1");
}


void CArreraUI::on_IDC_MTPLOGIN2_clicked()
{
    addNumberMTP("2");
}


void CArreraUI::on_IDC_MTPLOGIN3_clicked()
{
    addNumberMTP("3");
}


void CArreraUI::on_IDC_MTPLOGIN4_clicked()
{
   addNumberMTP("4");
}


void CArreraUI::on_IDC_MTPLOGIN5_clicked()
{
    addNumberMTP("5");
}


void CArreraUI::on_IDC_MTPLOGIN6_clicked()
{
    addNumberMTP("6");
}


void CArreraUI::on_IDC_MTPLOGIN7_clicked()
{
    addNumberMTP("7");
}


void CArreraUI::on_IDC_MTPLOGIN8_clicked()
{
   addNumberMTP("8");
}


void CArreraUI::on_IDC_MTPLOGIN9_clicked()
{
   addNumberMTP("9");
}


void CArreraUI::on_IDC_MTPLOGIN0_clicked()
{
   addNumberMTP("0");
}


void CArreraUI::on_IDC_MTPLOGINQUIT_clicked()
{
    /*
    if (mtpIn=="")
    {
        qApp->quit();
    }
    else
    {
        mtpIn="";
        mtpCacher = "";
        ui->IDC_SHOWMTPLOGIN->setText(mtpCacher);
    }
*/
}


void CArreraUI::on_IDC_MTPLOGINVALIDER_clicked()
{
    /*
    string in = mtpIn.toStdString();
    if (in==userMTP)
    {
        ui->FGUI->setVisible(true);
        ui->FLOGIN->setVisible(false);
    }
    else
    {
        ui->IDC_SHOWMTPLOGIN->setText("Mauvais mots de passe");
        mtpIn =  "" ;
        mtpCacher = "";
    }
*/
}


void CArreraUI::on_IDC_MTPBTNSHOW_clicked()
{
    /*
    if (showMTP==0)
    {
        ui->IDC_SHOWMTPLOGIN->setText(mtpIn);
        showMTP = 1 ;
    }
    else
    {
        ui->IDC_SHOWMTPLOGIN->setText(mtpCacher);
        showMTP = 0 ;
    }*/
}


void CArreraUI::on_IDC_PENSEBETE_clicked()
{
    winPostite->show();
}


void CArreraUI::on_IDC_PENSEBETE_2_clicked()
{
    winPostite->show();
}

