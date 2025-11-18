#ifndef ASSISTANT_H
#define ASSISTANT_H

#include <QObject>
#include <QStringList>

#include "socket/carreraserveur.h"
#include "fnc/carrerarecheche.h"
#include "manager/application/capppc.h"
#include "manager/application/carreraapp.h"

/*Debug

*/
#include "iostream"
using namespace std;

class assistant : public QObject
{
    Q_OBJECT
private:
    CArreraServeur *interface;
    CArreraRecheche *fncRecherche;
    CAInterfaceSetting *setting;
    QList<CAppPC>* listApp;
    CArreraApp* arreraApp;
    QString nameAssistantConnected;

public:
    explicit assistant(QObject* parent = nullptr);
    assistant(CArreraServeur *pinterface = nullptr,CArreraRecheche* objRecherche = nullptr,
              CAInterfaceSetting* objSetting = nullptr,QList<CAppPC>* pListApp = nullptr,
              CArreraApp* pArreraApp = nullptr, QObject* parent = nullptr);
    bool treatment(const QString name,const QString message);

private :
    int appExecute(const QString& message);
signals :
    void textTopLabel(const QString message);
    void launchMode(const int nb);
    void closeMode();
};

#endif // ASSISTANT_H
