#ifndef CAINTERFACESETTING_H
#define CAINTERFACESETTING_H

#include <QString>
#include "csetting.h"
#include "camode.h"
#include "calieu.h"
#include <iostream>

using namespace std;

class CAInterfaceSetting {

private:
    CSetting fileINI;
    CALieu lieu1;
    CALieu lieu2;
    CAMode mode1;
    CAMode mode2;
    CAMode mode3;
    CAMode mode4;
    CAMode mode5;
    CAMode mode6;
    QStringList listApp = {"ryley","six",
                           "arrera-raccourci",
                           "arrera-postite",
                           "arrera-video-download",
                           "arrera-copilote"};

public:
    // Constructeurs et destructeur
    CAInterfaceSetting();
    ~CAInterfaceSetting();

    // Getteur
    QList <QString> getListAssistant();
    QList <QString> getListMoteur();

    QString getNameUser();

    QString getNameMode1();
    QString getNameMode2();
    QString getNameMode3();
    QString getNameMode4();
    QString getNameMode5();
    QString getNameMode6();

    QString getAssistantMode1();
    QString getAssistantMode2();
    QString getAssistantMode3();
    QString getAssistantMode4();
    QString getAssistantMode5();
    QString getAssistantMode6();

    QString getNameLieu1();
    QString getNameLieu2();

    bool getAppMode1(QString* app1,QString* app2,QString* app3,QString* app4);
    bool getAppMode2(QString* app1,QString* app2,QString* app3,QString* app4);
    bool getAppMode3(QString* app1,QString* app2,QString* app3,QString* app4);
    bool getAppMode4(QString* app1,QString* app2,QString* app3,QString* app4);
    bool getAppMode5(QString* app1,QString* app2,QString* app3,QString* app4);
    bool getAppMode6(QString* app1,QString* app2,QString* app3,QString* app4);

    QString getIconMode1();
    QString getIconMode2();
    QString getIconMode3();
    QString getIconMode4();
    QString getIconMode5();
    QString getIconMode6();

    QString getIconLieu1();
    QString getIconLieu2();

    int getFirstUnsetNumber();
    int getnbAppSetted();
    bool getAppSetted(int nbApp);
    QList <QString> getListNameAppSetted();
    QString assosNameOfApp(QString app);
    bool checkNameAppIsAvailable(QString name);
    int getNbAppWithName(QString name);
    bool getApplication(int nb,QString *name,QString *exe,QString *icon);
    QString getAppSpeciaux(int app);// 1.Navigateur 2.Presentation 3.tableur 4.Traitement de texte
    bool getAppSpeciauxSetted(int app);// 1.Navigateur 2.Presentation 3.tableur 4.Traitement de texte

    QString getMoteurRecherche();
    QString getFileJson();
    QString getEmplacementStore();
    QString getExeArreraApp(QString nameApp);

    bool getTaskbarBTNSix();
    bool getTaskbarBTNArreraApp();
    bool getTaskbarBTNRyley();
    bool getTaskbarCopilote();
    bool getTaskbarPostite();

    // Setteurs
    bool setNameUser(QString& user);

    bool setNameMode1(QString& name);
    bool setNameMode2(QString& name);
    bool setNameMode3(QString& name);
    bool setNameMode4(QString& name);
    bool setNameMode5(QString& name);
    bool setNameMode6(QString& name);

    bool setNameLieu1(QString& name);
    bool setNameLieu2(QString& name);

    bool setAssistantLieu1(QString& assistant);
    bool setAssistantLieu2(QString& assistant);

    bool setGeoLieu1(QString& geo);
    bool setGeoLieu2(QString& geo);

    bool setIconLieu1(QString& icon);
    bool setIconLieu2(QString& icon);

    bool setAppMode1(QString& nameApp1,QString& nameApp2,QString& nameApp3,QString& nameApp4);
    bool setAppMode2(QString& nameApp1,QString& nameApp2,QString& nameApp3,QString& nameApp4);
    bool setAppMode3(QString& nameApp1,QString& nameApp2,QString& nameApp3,QString& nameApp4);
    bool setAppMode4(QString& nameApp1,QString& nameApp2,QString& nameApp3,QString& nameApp4);
    bool setAppMode5(QString& nameApp1,QString& nameApp2,QString& nameApp3,QString& nameApp4);
    bool setAppMode6(QString& nameApp1,QString& nameApp2,QString& nameApp3,QString& nameApp4);

    bool setAssistantMode1(QString& assistant);
    bool setAssistantMode2(QString& assistant);
    bool setAssistantMode3(QString& assistant);
    bool setAssistantMode4(QString& assistant);
    bool setAssistantMode5(QString& assistant);
    bool setAssistantMode6(QString& assistant);

    bool setIconMode1(QString icon);
    bool setIconMode2(QString icon);
    bool setIconMode3(QString icon);
    bool setIconMode4(QString icon);
    bool setIconMode5(QString icon);
    bool setIconMode6(QString icon);

    bool setApplication(int nb,QString nameApp,QString emplacement,QString icon);
    bool setNewExeApplication(int nb,QString emplacement);
    bool setNewIconApplication(int nb,QString icon);
    bool setSupprApplication(int nb);

    bool setAppTableur(QString emplacement);
    bool setAppTraitementTexte(QString emplacement);
    bool setAppPresentation(QString emplacement);
    bool setAppNavigateur(QString emplacement);

    bool setSupprAppTableur();
    bool setSupprAppTraitementTexte();
    bool setSupprAppPresentation();
    bool setSupprAppNavigateur();

    bool setMoteurRecherche(QString moteur);

    // Methode pour savoir si les lieu ou mode son paramétrer
    bool mode1IsSeted();
    bool mode2IsSeted();
    bool mode3IsSeted();
    bool mode4IsSeted();
    bool mode5IsSeted();
    bool mode6IsSeted();

    bool lieu1IsSeted();
    bool lieu2IsSeted();

    // Methode pour savoir si une icon est parametrer pour le mode
    bool iconMode1IsSetted();
    bool iconMode2IsSetted();
    bool iconMode3IsSetted();
    bool iconMode4IsSetted();
    bool iconMode5IsSetted();
    bool iconMode6IsSetted();
    bool iconLieu1IsSetted();
    bool iconLieu2IsSetted();

    // Methode pour remettre a Zero les modes et lieu
    bool resetMode1();
    bool resetMode2();
    bool resetMode3();
    bool resetMode4();
    bool resetMode5();
    bool resetMode6();

    bool resetLieu1();
    bool resetLieu2();

    // Partie gestion Arrera APP
    bool setFileJson(QString file);

    bool setEmplacementStore(QString emplacement);
    bool setEmplacementArreraApp(QString nameApp,QString emplacement);

    bool setTaskbarBTNSix();
    bool setTaskbarBTNArreraApp();
    bool setTaskbarBTNRyley();
    bool setTaskbarBTNCopilote();
    bool setTaskbarBBTNPostite();

    bool unsetTaskbarBTNSix();
    bool unsetTaskbarBTNArreraApp();
    bool unsetTaskbarBTNRyley();
    bool unsetTaskbarBTNCopilote();
    bool unsetTaskbarBTNPostite();

    // Partie reset
    bool resetArreraApp();
    bool resetAppPC();
    void resetAll();

    // Partie launch lieu
    bool launchLieu1(QPushButton* six,QPushButton* ryley,QPushButton* copilote);
    bool launchLieu2(QPushButton* six,QPushButton* ryley,QPushButton* copilote);

    bool disableLieu1();
    bool disableLieu2();
};

#endif // CAINTERFACESETTING_H
