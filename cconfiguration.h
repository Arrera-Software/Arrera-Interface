#ifndef CCONFIGURATION_H
#define CCONFIGURATION_H

#pragma once
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

class Cconfiguration {

private:
    unordered_map<string,string> parametres;

public:

    Cconfiguration();

    ~Cconfiguration();

    bool charger(const string& nomFichier);

    bool sauvegarder(const string& nomFichier);

    bool creerFichierIni(const string& nomFichier);

    string obtenirParametre(const string& cle);

    void definirParametre(const string& cle, const string& valeur);

    //void supprimerParametre(const string& cle);
};



#endif // CCONFIGURATION_H
