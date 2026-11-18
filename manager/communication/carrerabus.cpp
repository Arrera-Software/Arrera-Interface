//
// Created by Pauchet Baptiste on 18/11/2026.
//

#include "carrerabus.h"

CArreraBus::CArreraBus(CArreraRecheche *objRecherche,
                 CAInterfaceSetting *objSetting,
                 QList<CAppPC> *pListApp,
                 QObject *parent)
    : QObject(parent)
    , serveurAssistant(this)
    , connection_arrera_hub(this)
    , assistantCommunication(&serveurAssistant, objRecherche, objSetting, pListApp, this)
    , assistantIsActived(false)
{
}



CArreraBus::~CArreraBus() = default;

void CArreraBus::launchGestServeur()
{
    serveurAssistant.startServeur(6666);

    connect(&serveurAssistant, &CArreraServeur::connectClient, this, [this]() {
        assistantIsActived = true;
        emit statusMessageChanged(QStringLiteral("Un assistant est connectée"));
        emit assistantConnected();
    });

    connect(&serveurAssistant, &CArreraServeur::clientDeconected, this, [this]() {
        assistantIsActived = false;
        nameAssistantConnected.clear();
        emit statusMessageChanged(QStringLiteral("L'assistant et deconnecter"));
        emit assistantDisconnected();
    });

    connect(&serveurAssistant, &CArreraServeur::messageReceived,
            this, [this](const QString &nameSoft, const QString &message) {
        assistantCommunication.treatment(nameSoft, message);
        if (nameAssistantConnected.isEmpty() && !nameSoft.isEmpty()) {
            nameAssistantConnected = nameSoft;
        }
    });

    connect(&assistantCommunication, &assistant::textTopLabel,
            this, [this](const QString &message) {
        emit statusMessageChanged(message);
    });

    if (connection_arrera_hub.startServeur(2026)) {
        connect(&connection_arrera_hub, &CArreraServeur::connectClient, this, [this]() {
            emit statusMessageChanged(QStringLiteral("Arrera Hub est prêt à gérer vos applications"));
        });
        connect(&connection_arrera_hub, &CArreraServeur::messageReceived,
                this, [this](const QString &nameSoft, const QString &message) {
            if (nameSoft == QLatin1String("arrera_hub")
                && message.trimmed() == QLatin1String("update_app")) {
                emit hubAppUpdated();
            }
        });
    }
}

void CArreraBus::sendCommand(const QString &command)
{
    if (!assistantIsActived || nameAssistantConnected.isEmpty()) {
        return;
    }
    serveurAssistant.sendMessage(nameAssistantConnected, command);
}

void CArreraBus::launch_breef()
{
    sendCommand(QStringLiteral("breef"));
}

void CArreraBus::launch_meteo()
{
    sendCommand(QStringLiteral("weather"));
}

void CArreraBus::launch_task()
{
    sendCommand(QStringLiteral("task"));
}

void CArreraBus::launch_AGENDA()
{
    sendCommand(QStringLiteral("agenda"));
}

void CArreraBus::sendQuery(const QString &query)
{
    if (query.isEmpty()) {
        return;
    }
    sendCommand(QStringLiteral("requette : ") + query);
}

void CArreraBus::shutdown()
{
    if (assistantIsActived && !nameAssistantConnected.isEmpty()) {
        serveurAssistant.sendMessage(nameAssistantConnected, QStringLiteral("stop"));
    }
    connection_arrera_hub.sendMessage(QStringLiteral("arrera_hub"), QStringLiteral("stop"));

    serveurAssistant.stopServeur();
    connection_arrera_hub.stopServeur();

    assistantIsActived = false;
    nameAssistantConnected.clear();
}
