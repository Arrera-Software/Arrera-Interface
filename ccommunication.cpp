#include "ccommunication.h"
#include <iostream>
using namespace std;

CCommunication::CCommunication() {}

CCommunication::CCommunication(CArreraServeur* pserveur,CArreraServeur* passistant,
                               CArreraRecheche* objRecherche,CAInterfaceSetting* objSetting){
    app = pserveur;
    assistant = passistant;
    precherche = objRecherche;
    pSetting = objSetting;
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
        if (message.contains("recherche")){
            std::cout << "bite2" << std::endl;
            QString moteur = pSetting->getMoteurRecherche();
            QString recherche = message;
            recherche.replace("recherche","").trimmed();
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
