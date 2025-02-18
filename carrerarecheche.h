#ifndef CARRERARECHECHE_H
#define CARRERARECHECHE_H

#include <QDesktopServices>
#include <QUrl>
#include <QFile>
#include <QTextStream>

using namespace std ;

class CArreraRecheche
{
private :
    bool etatInternet ;
    QString filePath;
public:
    CArreraRecheche();
    ~CArreraRecheche();
    // Partie recherche
    bool searchDuckduckgo(QString q);
    bool searchGoogle(QString q);
    bool searchQwant(QString q);
    bool searchEcosia(QString q);
    bool searchBrave(QString q);
    bool searchBing(QString q);
    bool searchAmazon(QString q);
    bool searchWikipedia(QString q);
    bool searchReverso(QString q);
    bool searchWordreference(QString q);
    bool searchYTmusic(QString q);
    bool searchAll(QString q);
    // Partie hist
    bool add(QString moteur,QString recherche);
    bool clear();
    QString read();
};

#endif // CARRERARECHECHE_H
