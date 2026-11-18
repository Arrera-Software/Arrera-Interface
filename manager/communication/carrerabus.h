//
// Created by Pauchet Baptiste on 18/11/2026.
//

#ifndef ARRERA_CARRERABUS_H
#define ARRERA_CARRERABUS_H

#include "manager/communication/assistant.h"
#include "manager/socket/carreraserveur.h"



class CArreraBus : public QObject{
    Q_OBJECT
    private :
        CArreraServeur serveurAssistant;
        CArreraServeur connection_arrera_hub;
        assistant assistantCommunication;
        bool assistantIsActived;
        QString nameAssistantConnected;
        void sendCommand(const QString &command);
    public:
    explicit CArreraBus(CArreraRecheche *objRecherche,
             CAInterfaceSetting *objSetting,
             QList<CAppPC> *pListApp,
             QObject *parent = nullptr);
        ~CArreraBus();
        void launchGestServeur();
        void launch_breef();
        void launch_meteo();
        void launch_task();
        void launch_AGENDA();
        void sendQuery(const QString &query);
        void shutdown();
    signals:
        void assistantConnected();
        void assistantDisconnected();
        void statusMessageChanged(const QString &message);
        void hubAppUpdated();
};


#endif //ARRERA_CARRERABUS_H
