#include "ccommunication.h"

// Methode private
bool CCommunication::searchInternet(const QString& message)
{
    QString moteur = pSetting->getMoteurRecherche();
    QString recherche = message;
    recherche.replace("recherche", "");
    recherche = recherche.trimmed();

    const QMap<QString, std::function<bool(const QString&)>> moteurs = {
        {"GOOGLE",   [this](const QString& q) { return precherche->searchGoogle(q); }},
        {"DUCKDUCKGO", [this](const QString& q) { return precherche->searchQwant(q); }},
        {"ECOSIA",   [this](const QString& q) { return precherche->searchEcosia(q); }},
        {"BING",     [this](const QString& q) { return precherche->searchBing(q); }},
        {"BRAVE",    [this](const QString& q) { return precherche->searchBrave(q); }},
        {"QWANT",    [this](const QString& q) { return precherche->searchQwant(q); }}
    };

    auto it = moteurs.find(moteur);
    bool result = false;
    if (it !=moteurs.end()){
        result = it.value()(recherche);
    }else{
        result = precherche->searchGoogle(recherche);
    }

    emit textLabel(result ?
                       "Lancement de la recherche sur " + moteur :
                       "Impossible de lancer la recherche sur " + moteur);

    return result;
}

bool CCommunication::openApplication(const QString& message)
{
    int nbApp,i;
    if (message.contains("ouvre")){
        nbApp = listApp->size();
        CAppPC app;
        bool outMethode;
        QString nameapp = message;
        nameapp.replace("ouvre", "");
        nameapp = nameapp.trimmed();
        for (i = 0; i < nbApp; i++) {
            app = listApp->at(i);
            if (app.getAppSetted() && nameapp.contains(app.getName())) {
                outMethode = app.executeApplication();
                if (outMethode){
                    emit textLabel("Lancement de "+nameapp);
                    return true;
                }else{
                    emit textLabel("Imposible de lancer "+nameapp);
                    return false;
                }
            }
        }

        if (message.contains("arrera")) {
            if (message.contains("postite")) {
                outMethode = arreraApp->executeApp("arrera-postite");
                if (outMethode) {
                    emit textLabel("Lancement du module Arrera Postite");
                    return true;
                }
                else {
                    emit textLabel("Impossible de lancer le module Arrera Postite");
                    return false;
                }
            }
            else if (message.contains("video download")) {
                outMethode = arreraApp->executeApp("arrera-video-download");
                if (outMethode) {
                    emit textLabel("Lancement du module Arrera Video Download");
                    return true;
                }
                else {
                    emit textLabel("Impossible de lancer le module Arrera Video Download");
                    return false;
                }
            }
            else if (message.contains("raccourci")) {
                outMethode = arreraApp->executeApp("arrera-raccourci");
                if (outMethode) {
                    emit textLabel("Lancement du module Arrera Raccourci");
                    return true;
                }
                else {
                    emit textLabel("Impossible de lancer le module Arrera Raccourci");
                    return false;
                }
            }
            else {
                return false;
            }
        }
    }else{return false;}
}

bool CCommunication::openWebsite(const QString& message)
{
    QString url = message;
    url.replace("website","");
    url = url.trimmed();
    bool outMethode = precherche->openWebPage(url);
    if (outMethode){
        emit textLabel("Ouverture de votre page internet");
        return true;
    }else{
        emit textLabel("Imposible d'ouvrir votre page internet");
        return false;
    }
}

// Constructeur par défaut
CCommunication::CCommunication(QObject* parent)
    : QObject(parent), app(nullptr), assistant(nullptr), precherche(nullptr),
    pSetting(nullptr), listApp(nullptr), arreraApp(nullptr)
{
}

// Constructeur complet
CCommunication::CCommunication(CArreraServeur* pserveur, CArreraServeur* passistant,
                               CArreraRecheche* objRecherche, CAInterfaceSetting* objSetting,
                               QList<CAppPC>* pListApp, CArreraApp* pArreraApp, QObject* parent)
    : QObject(parent), app(pserveur), assistant(passistant), precherche(objRecherche),
    pSetting(objSetting), listApp(pListApp), arreraApp(pArreraApp)
{
}

bool CCommunication::traitementApp(const QString& nameSoft, const QString message)
{
    return false;
}

bool CCommunication::sendDataApp(const QString& nameSoft, const QString& message)
{
    return app->sendMessage(nameSoft, message);
}

bool CCommunication::traitementAssistant(const QString& nameSoft, const QString message)
{
    static const QSet<QString> assistants = {"opale", "six", "ryley", "copilote"};
    if (!assistants.contains(nameSoft)){
        return false;
    }

    if (message.contains("recherche")) {
        return searchInternet(message);
    }
    else if (message.contains("ouvre")) {
        return openApplication(message);
    }
    else if (message.contains("website")){
        return openWebsite(message);
    }
    else{
        return false;
    }

}

bool CCommunication::sendDataAssistant(const QString& message)
{
    return assistant->sendMessage(nameAssistantConnected, message);
}

// Partie enregistrement Assistant
bool CCommunication::setNameAssistant(QString name)
{
    if (name.isEmpty()){
        return false;
    }else{
        nameAssistantConnected = name;
        return true;
    }
}

bool CCommunication::supprNameAssistant(){
    nameAssistantConnected = "";
    return true;
}
