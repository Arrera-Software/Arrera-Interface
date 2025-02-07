#ifndef CAINTERFACESETTING_H
#define CAINTERFACESETTING_H

#include <QString>
#include "cjsonword.h"
#include "csetting.h"

class CAInterfaceSetting {
private:
    CSetting* fileINI;
    CJSONWORD* fileTiger;

public:
    // Constructeurs et destructeur
    CAInterfaceSetting();
    CAInterfaceSetting(QString& inifile,QString& jsonfile);
    ~CAInterfaceSetting();

    // Getteurs
    QString getNameUser();
    QString getNameMode1();
    QString getNameMode2();
    QString getNameMode3();
    QString getNameMode4();
    QString getNameMode5();
    QString getNameMode6();

    QString getNameLieu1();
    QString getNameLieu2();

    bool getAppMode1(QString* nameApp1, QString* nameApp2, QString* nameApp3, QString* nameApp4);
    bool getAppMode2(QString* nameApp1, QString* nameApp2, QString* nameApp3, QString* nameApp4);
    bool getAppMode3(QString* nameApp1, QString* nameApp2, QString* nameApp3, QString* nameApp4);
    bool getAppMode4(QString* nameApp1, QString* nameApp2, QString* nameApp3, QString* nameApp4);
    bool getAppMode5(QString* nameApp1, QString* nameApp2, QString* nameApp3, QString* nameApp4);
    bool getAppMode6(QString* nameApp1, QString* nameApp2, QString* nameApp3, QString* nameApp4);

    QString getAssistantMode1();
    QString getAssistantMode2();
    QString getAssistantMode3();
    QString getAssistantMode4();
    QString getAssistantMode5();
    QString getAssistantMode6();

    QString getApplication(int nb);
    QString getAppTableur();
    QString getAppTraitementTexte();
    QString getAppPresentation();
    QString getAppNavigateur();

    QString getArreraRyley();
    QString getArreraSix();
    QString getArreraCopilote();
    QString getArreraPostite();
    QString getArreraVideoDownload();
    QString getArreraRaccourci();

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

    bool setApplication(int nb,QString nameApp,QString emplacement);
    bool setAppTableur(QString emplacement);
    bool setAppTraitementTexte(QString emplacement);
    bool setAppPresentation(QString emplacement);
    bool setAppNavigateur(QString emplacement);

};

#endif // CAINTERFACESETTING_H
