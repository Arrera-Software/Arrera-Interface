#include "assistant.h"

assistant::assistant(QObject* parent) :
    QObject(parent),interface(nullptr),fncRecherche(nullptr),
    setting(nullptr),listApp(nullptr) {}

assistant::assistant(CArreraServeur*pinterface,CArreraRecheche* objRecherche,
          CAInterfaceSetting* objSetting,QList<CAppPC>* pListApp,QObject* parent):
    QObject(parent),interface(pinterface),fncRecherche(objRecherche),
    setting(objSetting),listApp(pListApp) {}

bool assistant::treatment(const QString name,const QString message)
{
    if (message == ""){
        return false;
    }else if (message.contains("ouvre",Qt::CaseInsensitive)){
        if (listApp && !listApp->isEmpty()) {
            if (listApp) {
                int outApp = appExecute(message);
                if ( outApp == 1) {
                    interface->sendMessage(name,"opensoft");
                    return true;
                } else if ( outApp == 2)  {
                    interface->sendMessage(name,"erreuropensoft");
                    return true;
                }else{
                    interface->sendMessage(name,"noopensoft");
                    return true;
                }
            }
            else
            {
                return false;
            }
    }else{
            return false;
        }
    }else if (message.contains("launch mode",Qt::CaseInsensitive)){
        QString requette = message;
        requette.remove("launch mode", Qt::CaseInsensitive);
        requette = requette.trimmed();

        bool ok = false;
        int nb = requette.toInt(&ok);

        if (ok && nb >= 1 && nb <= 6) {
            emit launchMode(nb);
            return true;
        } else {
            interface->sendMessage(name, "error launch mode");
            return false;
        }
    }else if (message.contains("close mode",Qt::CaseInsensitive)){
        emit closeMode();
        return true;
    }else{
        return false;
    }
}


// Methode private
int assistant::appExecute(const QString& message)
{
    if (!listApp) return false;

    QString query = message;
    query.replace("ouvre", "", Qt::CaseInsensitive);
    query = query.simplified();

    for (CAppPC app : *listApp) {
        QString name = app.getName().simplified();
        if (name.compare(query, Qt::CaseInsensitive) == 0)
            if (app.executeApplication()){
                emit textTopLabel("Ouverture de "+name);
                return 1;
            }
            else{
                emit textTopLabel("Erreur sur l'ouverture de "+name);
                return 2;
            }
    }
    emit textTopLabel("L'application n'est pas enregistrer");
    return 0;
}
