#include "carrerarecheche.h"

CArreraRecheche::CArreraRecheche()
{
    filePath = "hist.txt";
}

CArreraRecheche::~CArreraRecheche()
{

}

// Partie recherche
bool CArreraRecheche::searchDuckduckgo(QString q)
{
    QString url = "https://duckduckgo.com/?q="+q;
    return QDesktopServices::openUrl(QUrl(url));
}

bool CArreraRecheche::searchGoogle(QString q)
{
    QString url = "https://www.google.com/search?q="+q;
    return QDesktopServices::openUrl(QUrl(url));
}

bool CArreraRecheche::searchQwant(QString q)
{
    QString url = "https://www.qwant.com/?l=fr&q="+q;
    return QDesktopServices::openUrl(QUrl(url));
}

bool CArreraRecheche::searchEcosia(QString q)
{
    QString url = "https://www.ecosia.org/search?method=index&q="+q;
    return QDesktopServices::openUrl(QUrl(url));
}

bool CArreraRecheche::searchBrave(QString q)
{
    QString url = "https://search.brave.com/search?q="+q+"&source=web";
    return QDesktopServices::openUrl(QUrl(url));
}

bool CArreraRecheche::searchBing(QString q)
{
    QString url = "https://www.bing.com/search?q="+q;
    return QDesktopServices::openUrl(QUrl(url));
}
bool CArreraRecheche::searchAmazon(QString q)
{
    QString url = "https://www.amazon.fr/s?k="+q;
    return QDesktopServices::openUrl(QUrl(url));
}

bool CArreraRecheche::searchWikipedia(QString q)
{
    QString url = "https://fr.wikipedia.org/wiki/"+q;
    return QDesktopServices::openUrl(QUrl(url));
}

bool CArreraRecheche::searchReverso(QString q)
{
    QString url = "https://www.reverso.net/traduction-texte#sl=fra&tl=eng&text="+q;
    return QDesktopServices::openUrl(QUrl(url));
}

bool CArreraRecheche::searchWordreference(QString q)
{
    QString url = "https://www.wordreference.com/fren/"+q;
    return QDesktopServices::openUrl(QUrl(url));
}

bool CArreraRecheche::searchYTmusic(QString q)
{
    QString url = "https://music.youtube.com/search&q="+q;
    return QDesktopServices::openUrl(QUrl(url));
}

bool CArreraRecheche::searchAll(QString q)
{
    if(searchGoogle(q)){
        if(searchBing(q)){
            if (searchBrave(q)){
                if (searchQwant(q)){
                    if(searchDuckduckgo(q)){
                        if (searchEcosia(q)){
                            return true;
                        }
                        else{
                            return false;
                        }
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }else{
            return false;
        }
    }else{
        return false;
    }
}

// Partie hist
bool CArreraRecheche::add(QString moteur,QString recherche){
    QFile file(filePath);
    QString valeur = moteur+"->"+recherche;
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        return false;
    }
    QTextStream out(&file);
    out << valeur << Qt::endl;
    file.close();
    return true;
}

bool CArreraRecheche::clear(){
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        return false;
    }

    // Fermer le fichier après l'avoir ouvert en mode écriture
    file.close();
    return true;
}

QString CArreraRecheche::read(){
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return "-1";
    }
    QTextStream in(&file);
    return in.readAll();
}
