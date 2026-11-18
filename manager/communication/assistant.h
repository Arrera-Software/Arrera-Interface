#ifndef ASSISTANT_H
#define ASSISTANT_H

#include <QObject>

#include "manager/socket/carreraserveur.h"
#include "manager/search/carrerarecheche.h"
#include "manager/application/capppc.h"

class assistant : public QObject
{
    Q_OBJECT
private:
    CArreraServeur *interface;
    CArreraRecheche *fncRecherche;
    CAInterfaceSetting *setting;
    QList<CAppPC>* listApp;

public:
    explicit assistant(QObject* parent = nullptr);
    assistant(CArreraServeur *pinterface = nullptr,CArreraRecheche* objRecherche = nullptr,
              CAInterfaceSetting* objSetting = nullptr,QList<CAppPC>* pListApp = nullptr,
              QObject* parent = nullptr);
    bool treatment(const QString name,const QString message);

private :
    int appExecute(const QString& message);
signals :
    void textTopLabel(const QString message);
};

#endif // ASSISTANT_H
