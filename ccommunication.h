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

class CCommunication : public QObject
{
    Q_OBJECT
private:
    CArreraServeur *app, *assistant;
    CArreraRecheche* precherche;
    CAInterfaceSetting* pSetting;
    QList<CAppPC>* listApp;
    CArreraApp* arreraApp;
    QLabel* labelTop;

public:
    explicit CCommunication(QObject* parent = nullptr); // Ajoute parent pour QObject
    CCommunication(QLabel* plabelTop, CArreraServeur* pserveur = nullptr, CArreraServeur* passistant = nullptr,
                   CArreraRecheche* objRecherche = nullptr, CAInterfaceSetting* objSetting = nullptr,
                   QList<CAppPC>* pListApp = nullptr, CArreraApp* pArreraApp = nullptr, QObject* parent = nullptr);

    // Partie App
    bool traitementApp(const QString& nameSoft, const QString message);
    bool sendDataApp(const QString& nameSoft, const QString& message);

    // Partie Assistant
    bool traitementAssistant(const QString& nameSoft, const QString message);
    bool sendDataAssistant(const QString& nameSoft, const QString& message);

signals:
    void textLabel(const QString& message);
};

#endif // CCOMMUNICATION_H
