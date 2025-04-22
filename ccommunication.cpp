#include "ccommunication.h"
#include <iostream>
using namespace std;

CCommunication::CCommunication() {}

CCommunication::CCommunication(QLabel* plabelTop,CArreraServeur* pserveur,CArreraServeur* passistant,
                               CArreraRecheche* objRecherche,CAInterfaceSetting* objSetting,
                                QList <CAppPC>*pListApp,CArreraApp* pArreraApp){
    app = pserveur;
    assistant = passistant;
    precherche = objRecherche;
    pSetting = objSetting;
    listApp = pListApp;
    arreraApp = pArreraApp;
    labelTop = plabelTop;
}

bool CCommunication::traitementApp(const QString &nameSoft,const QString message)
{
    std::cout << nameSoft.toStdString()<< " " << message.toStdString() << std::endl;
    return true;
}

bool CCommunication::sendDataApp(const QString &nameSoft, const QString &message){
    return app->sendMessage(nameSoft,message);

}

bool CCommunication::traitementAssistant(const QString &nameSoft,const QString message){
    if (nameSoft == "opale" || nameSoft=="six" || nameSoft == "ryley" || nameSoft == "copilote"){
        int nbApp , i ;
        bool outMethode;
        if (message.contains("recherche")){
            QString moteur = pSetting->getMoteurRecherche();
            QString recherche = message;
            recherche.replace("recherche","");
            recherche = recherche.trimmed();
            if (moteur == "GOOGLE"){
                return precherche->searchGoogle(recherche);
            }else if (moteur == "DUCKDUCKGO"){
                return precherche->searchQwant(recherche);
            }else if (moteur == "ECOSIA"){
                return precherche->searchEcosia(recherche);
            }else if (moteur == "BING"){
                return precherche->searchBing(recherche);
            }else if (moteur == "BRAVE"){
                return precherche->searchBrave(recherche);
            }else if (moteur == "QWANT"){
                return precherche->searchQwant(recherche);
            }else{
                return precherche->searchGoogle(recherche);
            }
        }
        else if (message.contains("ouvre")){
            nbApp = listApp->size();
            CAppPC app;
            QString nameapp = message;
            nameapp.replace("ouvre","");
            nameapp = nameapp.trimmed();
            for (i=0;i<nbApp;i++){
                app = listApp->at(i);
                if (app.getAppSetted() && nameapp.contains(app.getName())){
                    return app.executeApplication();
                }
            }

            if (message.contains("arrera")){
                if (message.contains("postite")){
                    outMethode = arreraApp->executeApp("arrera-postite");
                    if (outMethode){
                        // labelTop->setText("Lancement du module Arrera Postite");
                        return true;
                    }else{
                        // labelTop->setText("Impossible de lancer le module Arrera Postite");
                        return false;
                    }
                }else if(message.contains("video download")){
                    outMethode = arreraApp->executeApp("arrera-video-download");
                    if (outMethode){
                        // labelTop->setText("Lancement du module Arrera Video Download");
                        return true;
                    }
                    else{
                        // labelTop->setText("Impossible de lancer le module Arrera Video Download");
                        return false;
                    }
                }else if (message.contains("raccourci")){
                    outMethode = arreraApp->executeApp("arrera-raccourci");
                    if (outMethode){
                        // labelTop->setText("Lancement du module Arrera Raccourci");
                        return true;
                    }
                    else{
                        // labelTop->setText("Impossible de lancer le module Arrera Raccourci");
                        return false;
                    }
                }else {
                    return false;
                }
            }
            return false;
        }
        else{
            return false;
        }
    }else{
        return false;
    }
}

bool CCommunication::sendDataAssistant(const QString &nameSoft, const QString &message){
    return assistant->sendMessage(nameSoft,message);
}
