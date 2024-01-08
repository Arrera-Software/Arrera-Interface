#include "cconfiguration.h"

Cconfiguration::Cconfiguration()
{

}

Cconfiguration::~Cconfiguration()
{

}

bool Cconfiguration::charger(const string& nomFichier) {
    ifstream fichier(nomFichier);
    if (!fichier.is_open()) {
        return false;
    }

    string ligne;
    while (getline(fichier, ligne)) {
        size_t pos = ligne.find('=');
        if (pos != string::npos) {
            string cle = ligne.substr(0, pos);
            string valeur = ligne.substr(pos + 1);
            parametres[cle] = valeur;
        }
    }

    fichier.close();
    return true;
}

bool Cconfiguration::sauvegarder(const string& nomFichier) {
    ofstream fichier(nomFichier);
    if (!fichier.is_open()) {
        return false;
    }

    for (const auto& parametre : parametres) {
        fichier << parametre.first << "=" << parametre.second << "\n";
    }

    fichier.close();
    return true;
}

string Cconfiguration::obtenirParametre(const string& cle){
    auto it = parametres.find(cle);
    return (it != parametres.end()) ? it->second : "";
}

void Cconfiguration::definirParametre(const string& cle, const string& valeur) {
    parametres[cle] = valeur;
}

bool Cconfiguration::creerFichierIni(const string& nomFichier ) {
    ofstream fichier(nomFichier);
    if (!fichier.is_open()) {
        return false;
    }
    fichier.close();
    return true;
}
/*
void  Cconfiguration::supprimerParametre(const std::string& cle) {
    auto it = parametres.find(cle);
    if (it != parametres.end()) {
        parametres.erase(it);
    }
}
*/
