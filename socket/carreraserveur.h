#ifndef CARRERASERVEUR_H
#define CARRERASERVEUR_H

#include <QObject>
#include <QWebSocketServer>
#include <QWebSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QHash>

// Debug
/*
#include <iostream>
using namespace std;
*/


class CArreraServeur : public QObject
{
    Q_OBJECT
private:
    QWebSocketServer *serverWebSocket;
    QHash <QWebSocket*, QString> webSocketClients;
    volatile bool signalEmitted = false;
public:
    explicit CArreraServeur(QObject *parent = nullptr);
    ~CArreraServeur();
    bool startServeur(quint16 port);
    bool stopServeur();
    bool sendMessage(const QString nameClient,const QString &message);
private slots:
    void onNewConnectionOfClient();
    void onMessageReceived(const QString &message);
    void onClientDeconected();
signals:
    void messageReceived(const QString &nameSoft,const QString &message);
    void connectClient();
    void clientDeconected();
};

#endif // CARRERASERVEUR_H
