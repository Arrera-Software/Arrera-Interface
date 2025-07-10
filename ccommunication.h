#ifndef CCOMMUNICATION_H
#define CCOMMUNICATION_H

#include <QObject>
#include <QLabel>
#include "carreraserveur.h"
#include "carrerarecheche.h"
#include "arrerasettingui.h"
#include "carreraapp.h"
#include "capppc.h"
#include "cappspeciaux.h"

// Debug
/*
#include <iostream>
using namespace std;
*/


class CCommunication : public QObject
{
    Q_OBJECT
private:
    CArreraServeur *app, *assistant;
    CArreraRecheche* precherche;
    CAInterfaceSetting* pSetting;
    QList<CAppPC>* listApp;
    CArreraApp* arreraApp;
    QString nameAssistantConnected;
    // Methode
    bool searchInternet(const QString& message);
    bool openApplication(const QString& message);
    bool openWebsite(const QString& message);
public:
    explicit CCommunication(QObject* parent = nullptr); // Ajoute parent pour QObject
    CCommunication(CArreraServeur* pserveur = nullptr, CArreraServeur* passistant = nullptr,
                   CArreraRecheche* objRecherche = nullptr, CAInterfaceSetting* objSetting = nullptr,
                   QList<CAppPC>* pListApp = nullptr, CArreraApp* pArreraApp = nullptr, QObject* parent = nullptr);

    // Partie App
    bool traitementApp(const QString& nameSoft, const QString message);
    bool sendDataApp(const QString& nameSoft, const QString& message);

    // Partie Assistant
    bool traitementAssistant(const QString& nameSoft, const QString message);
    bool sendDataAssistant(const QString& message);

    // Partie enregistrement Assistant
    bool setNameAssistant(QString name);
    bool supprNameAssistant();

signals:
    void textLabel(const QString& message);
};

#endif // CCOMMUNICATION_H
