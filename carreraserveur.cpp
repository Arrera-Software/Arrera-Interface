#include "carreraserveur.h"
#include <iostream>

using namespace std;

CArreraServeur::CArreraServeur(QObject *parent)
    : QObject{parent}
{}

CArreraServeur::~CArreraServeur(){
    stopServeur();
}

bool CArreraServeur::startServeur(quint16 port)
{
    serverWebSocket = new QWebSocketServer(QStringLiteral("WebSocket Server"),
                                           QWebSocketServer::NonSecureMode, this);

    connect(serverWebSocket,&QWebSocketServer::newConnection,
            this,&CArreraServeur::onNewConnectionOfClient);

    cout << "vire" << endl;

    if (serverWebSocket->listen(QHostAddress::Any,port)){
        return true;
    }else{
        return false;
    }
}

bool CArreraServeur::stopServeur() {
    if (serverWebSocket && serverWebSocket->isListening()) {
        serverWebSocket->close(); // Fermeture du serveur

        // Fermeture de toutes les connexions client
        for (QWebSocket *client : webSocketClients.keys()) {
            client->sendTextMessage("Serveur down");
            client->close();
            client->deleteLater();
        }

        // Clear de la map
        webSocketClients.clear();

        return true;
    }
    else {
        return false;
    }
}

bool CArreraServeur::sendMessage(const QString nameClient,const QString &message)
{
    if (webSocketClients.values().contains(nameClient)){

        QWebSocket* sockets = webSocketClients.key(nameClient);
        sockets->sendTextMessage(message);
        return true;
    }
    else{
        return false;
    }
}

void CArreraServeur::onNewConnectionOfClient(){
    QWebSocket *client = serverWebSocket->nextPendingConnection();
    connect(client,&QWebSocket::textFrameReceived, this,&CArreraServeur::onMessageReceived);
    connect(client,&QWebSocket::disconnected, this,&CArreraServeur::onClientDeconected);

    webSocketClients[client] = QString();
}

void CArreraServeur::onMessageReceived(const QString &message){
    QWebSocket *client = qobject_cast<QWebSocket *>(sender());

    if (message.contains("namesoft")){
        QString mutableMessage = message;
        mutableMessage.remove("namesoft").remove(" ");
        mutableMessage = mutableMessage.simplified().toLower();

        webSocketClients[client] = mutableMessage;

    }else{

        if (!client) return;

        signalEmitted = true;
        // Émettre un signal lorsqu'un message est reçu
        emit messageReceived(webSocketClients[client],message+"\n");

    }

    if (message != "Message Received"){
        client->sendTextMessage("Message Received");
    }
}

void CArreraServeur::onClientDeconected(){
    QWebSocket *client = qobject_cast<QWebSocket *>(sender());
    if (client)
    {
        webSocketClients.remove(client);
        client->deleteLater();
    }
}
