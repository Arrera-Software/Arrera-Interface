#ifndef CARRERARECHECHE_H
#define CARRERARECHECHE_H

#include <QDesktopServices>
#include <QUrl>
#include <string.h>

using namespace std ;

class CArreraRecheche
{
private :
    bool etatInternet ;
public:
    CArreraRecheche();
    ~CArreraRecheche();
    void searchDuckduckgo(QString q);
    void searchGoogle(QString q);
    void searchQwant(QString q);
    void searchEcosia(QString q);
    void searchBrave(QString q);
    void searchBing(QString q);
    void searchAmazon(QString q);
    void searchWikipedia(QString q);
    void searchReverso(QString q);
    void searchWordreference(QString q);
    void searchYTmusic(QString q);
    void searchAll(QString q);
};

#endif // CARRERARECHECHE_H
