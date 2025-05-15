#include "ccommunication.h"
#include <iostream>

using namespace std;

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
    if (nameSoft == "opale" || nameSoft == "six" || nameSoft == "ryley" || nameSoft == "copilote") {
        int nbApp, i;
        bool outMethode;
        if (message.contains("recherche")) {
            QString moteur = pSetting->getMoteurRecherche();
            QString recherche = message;
            recherche.replace("recherche", "");
            recherche = recherche.trimmed();
            if (moteur == "GOOGLE") {
                outMethode = precherche->searchGoogle(recherche);
                if (outMethode){
                    emit textLabel("Lancement de la recherche sur Google");
                    return true;
                }else{
                    emit textLabel("Impossible de lancer la recherche sur Google");
                    return false;
                }
            }
            else if (moteur == "DUCKDUCKGO") {
                outMethode = precherche->searchQwant(recherche);
                if (outMethode){
                    emit textLabel("Lancement de la recherche sur Duckduckgo");
                    return true;
                }else{
                    emit textLabel("Impossible de lancer la recherche sur Duckduckgo");
                    return false;
                }
            }
            else if (moteur == "ECOSIA") {
                outMethode = precherche->searchEcosia(recherche);
                if (outMethode){
                    emit textLabel("Lancement de la recherche sur Ecosia");
                    return true;
                }else{
                    emit textLabel("Impossible de lancer la recherche sur Ecosia");
                    return false;
                }
            }
            else if (moteur == "BING") {
                outMethode = precherche->searchBing(recherche);
                if (outMethode){
                    emit textLabel("Lancement de la recherche sur Bing");
                    return true;
                }else{
                    emit textLabel("Impossible de lancer la recherche sur Bing");
                    return false;
                }
            }
            else if (moteur == "BRAVE") {
                outMethode = precherche->searchBrave(recherche);
                if (outMethode){
                    emit textLabel("Lancement de la recherche sur Brave");
                    return true;
                }else{
                    emit textLabel("Impossible de lancer la recherche sur Brave");
                    return false;
                }
            }
            else if (moteur == "QWANT") {
                outMethode = precherche->searchQwant(recherche);
                if (outMethode){
                    emit textLabel("Lancement de la recherche sur Qwant");
                    return true;
                }else{
                    emit textLabel("Impossible de lancer la recherche sur Qwant");
                    return false;
                }
            }
            else {
                outMethode = precherche->searchGoogle(recherche);
                if (outMethode){
                    emit textLabel("Lancement de la recherche sur Google");
                    return true;
                }else{
                    emit textLabel("Impossible de lancer la recherche sur Google");
                    return false;
                }
            }
        }
        else if (message.contains("ouvre")) {
            nbApp = listApp->size();
            CAppPC app;
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
            return false;
        }
        else if (message.contains("website"))
        {
            QString url = message;
            url.replace("website","");
            url = url.trimmed();
            outMethode = precherche->openWebPage(url);
            if (outMethode){
                emit textLabel("Ouverture de votre page internet");
                return true;
            }else{
                emit textLabel("Imposible d'ouvrir votre page internet");
                return false;
            }
        }
        else{
            return false;
        }
    }
    else {
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
