#include "carrerarecheche.h"

CArreraRecheche::CArreraRecheche()
{

}

CArreraRecheche::~CArreraRecheche()
{

}

void CArreraRecheche::searchDuckduckgo(QString q)
{
    QString url = "https://duckduckgo.com/?q="+q;
    QDesktopServices::openUrl(QUrl(url));
}

void CArreraRecheche::searchGoogle(QString q)
{
    QString url = "https://www.google.com/search?q="+q;
    QDesktopServices::openUrl(QUrl(url));
}

void CArreraRecheche::searchQwant(QString q)
{
    QString url = "https://www.qwant.com/?l=fr&q="+q;
    QDesktopServices::openUrl(QUrl(url));
}

void CArreraRecheche::searchEcosia(QString q)
{
    QString url = "https://www.ecosia.org/search?method=index&q="+q;
    QDesktopServices::openUrl(QUrl(url));
}

void CArreraRecheche::searchBrave(QString q)
{
    QString url = "https://search.brave.com/search?q="+q+"&source=web";
    QDesktopServices::openUrl(QUrl(url));
}

void CArreraRecheche::searchBing(QString q)
{
    QString url = "https://www.bing.com/search?q="+q;
    QDesktopServices::openUrl(QUrl(url));
}

void CArreraRecheche::searchAmazon(QString q)
{
    QString url = "https://www.amazon.fr/s?k="+q;
    QDesktopServices::openUrl(QUrl(url));
}

void CArreraRecheche::searchWikipedia(QString q)
{
    QString url = "https://fr.wikipedia.org/wiki/"+q;
    QDesktopServices::openUrl(QUrl(url));
}

void CArreraRecheche::searchReverso(QString q)
{
    QString url = "https://www.reverso.net/traduction-texte#sl=fra&tl=eng&text="+q;
    QDesktopServices::openUrl(QUrl(url));
}

void CArreraRecheche::searchWordreference(QString q)
{
    QString url = "https://www.wordreference.com/fren/"+q;
    QDesktopServices::openUrl(QUrl(url));
}

void CArreraRecheche::searchYTmusic(QString q)
{
    QString url = "https://music.youtube.com/search&q="+q;
    QDesktopServices::openUrl(QUrl(url));
}

void CArreraRecheche::searchAll(QString q)
{
    searchGoogle(q);
    searchBing(q);
    searchBrave(q);
    searchQwant(q);
    searchDuckduckgo(q);
    searchEcosia(q);
}
