#include "carrerarecheche.h"

CArreraRecheche::CArreraRecheche()
{
    if (CDetectionOS().getosApple() || CDetectionOS().getosLinux()){
        filePath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation)+
                   "/.config/arrera-interface/hist.txt";
    }
}

CArreraRecheche::~CArreraRecheche()
{

}

// Partie recherche
bool CArreraRecheche::searchDuckduckgo(QString q)
{
    QString url = "https://duckduckgo.com/?q="+q;
    if (QDesktopServices::openUrl(QUrl(url))){
        return add("duckduckgo",q);
    }
    else{
        return false;
    }
}

bool CArreraRecheche::searchGoogle(QString q)
{
    QString url = "https://www.google.com/search?q="+q;
    if (QDesktopServices::openUrl(QUrl(url))){
        return add("google",q);
    }
    else{
        return false;
    }
}

bool CArreraRecheche::searchQwant(QString q)
{
    QString url = "https://www.qwant.com/?l=fr&q="+q;
    if (QDesktopServices::openUrl(QUrl(url))){
        return add("qwant",q);
    }
    else{
        return false;
    }
}

bool CArreraRecheche::searchEcosia(QString q)
{
    QString url = "https://www.ecosia.org/search?method=index&q="+q;
    if (QDesktopServices::openUrl(QUrl(url))){
        return add("ecosia",q);
    }
    else{
        return false;
    }
}

bool CArreraRecheche::searchBrave(QString q)
{
    QString url = "https://search.brave.com/search?q="+q+"&source=web";
    if (QDesktopServices::openUrl(QUrl(url))){
        return add("brave",q);
    }
    else{
        return false;
    }
}

bool CArreraRecheche::searchBing(QString q)
{
    QString url = "https://www.bing.com/search?q="+q;
    if (QDesktopServices::openUrl(QUrl(url))){
        return add("bing",q);
    }
    else{
        return false;
    }
}
bool CArreraRecheche::searchAmazon(QString q)
{
    QString url = "https://www.amazon.fr/s?k="+q;
    if (QDesktopServices::openUrl(QUrl(url))){
        return add("amazon",q);
    }
    else{
        return false;
    }
}

bool CArreraRecheche::searchWikipedia(QString q)
{
    QString url = "https://fr.wikipedia.org/wiki/"+q;
    if (QDesktopServices::openUrl(QUrl(url))){
        return add("wikipedia",q);
    }
    else{
        return false;
    }
}

bool CArreraRecheche::searchReverso(QString q)
{
    QString url = "https://www.reverso.net/traduction-texte#sl=fra&tl=eng&text="+q;
    if (QDesktopServices::openUrl(QUrl(url))){
        return add("reverso",q);
    }
    else{
        return false;
    }
}

bool CArreraRecheche::searchWordreference(QString q)
{
    QString url = "https://www.wordreference.com/fren/"+q;
    if (QDesktopServices::openUrl(QUrl(url))){
        return add("wordreference",q);
    }
    else{
        return false;
    }
}

bool CArreraRecheche::searchYTmusic(QString q)
{
    QString url = "https://music.youtube.com/search&q="+q;
    if (QDesktopServices::openUrl(QUrl(url))){
        return add("youtube",q);
    }
    else{
        return false;
    }
}

bool CArreraRecheche::searchAll(QString q)
{
    if(searchGoogle(q)){
        if(searchBing(q)){
            if (searchBrave(q)){
                if (searchQwant(q)){
                    if(searchDuckduckgo(q)){
                        if (searchEcosia(q)){
                            return add("all",q);
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

// Partie ouverture de page web
bool CArreraRecheche::openWebPage(QString url){
    if (QDesktopServices::openUrl(QUrl(url))){
        return add("open url",url);
    }
    else{
        return false;
    }
}
