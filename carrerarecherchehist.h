#ifndef CARRERARECHERCHEHIST_H
#define CARRERARECHERCHEHIST_H
#include <QFile>
#include <QTextStream>
#include <QDebug>

class CArreraRechercheHist
{
private :
    QString filePath;

public:
    CArreraRechercheHist();
    bool add(QString valeur);
    bool clear();
    QString read();
};

#endif // CARRERARECHERCHEHIST_H
