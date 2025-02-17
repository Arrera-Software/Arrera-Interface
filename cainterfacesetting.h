#ifndef CAINTERFACESETTING_H
#define CAINTERFACESETTING_H

#include <QString>
#include "cjsonword.h"
#include "csetting.h"
#include "camode.h"
#include "calieu.h"

class CAInterfaceSetting {

private:
    CSetting* fileINI;
    CJSONWORD* fileTiger;
    CALieu lieu1;
    CALieu lieu2;
    CAMode mode1;
    CAMode mode2;
    CAMode mode3;
    CAMode mode4;
    CAMode mode5;
    CAMode mode6;

public:
    // Constructeurs et destructeur
    CAInterfaceSetting();
    CAInterfaceSetting(QString& inifile,QString& jsonfile);
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

    QString getIconMode1();
    QString getIconMode2();
    QString getIconMode3();
    QString getIconMode4();
    QString getIconMode5();
    QString getIconMode6();

    QString getIconLieu1();
    QString getIconLieu2();

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

    bool setApplication(int nb,QString nameApp,QString emplacement);
    bool setAppTableur(QString emplacement);
    bool setAppTraitementTexte(QString emplacement);
    bool setAppPresentation(QString emplacement);
    bool setAppNavigateur(QString emplacement);

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
};

#endif // CAINTERFACESETTING_H
