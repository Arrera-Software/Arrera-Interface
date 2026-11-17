#ifndef CAINTERFACESETTING_H
#define CAINTERFACESETTING_H

#include <QString>
#include "librairy/csetting.h"

/*
#include <iostream>
*/

using namespace std;

class CAInterfaceSetting {

private:
    CSetting fileINI;

public:
    // Constructeurs et destructeur
    CAInterfaceSetting();
    ~CAInterfaceSetting();

    // Getteur
    QList <QString> getListAssistant();
    QList <QString> getListMoteur();

    QString getNameUser();

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




    bool getTaskbarBTNSix();
    bool getTaskbarBTNArreraApp();
    bool getTaskbarBTNRyley();
    bool getTaskbarCopilote();
    bool getTaskbarPostite();

    // Setteurs
    bool setNameUser(QString& user);

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
    bool resetAppPC();
    void resetAll();

    QStringList get_list_gui_six();
    bool set_gui_six(QString gui);
    QString get_gui_six();
};

#endif // CAINTERFACESETTING_H
