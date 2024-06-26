#ifndef CARRERAINTERFACESETTING_H
#define CARRERAINTERFACESETTING_H

#include <QDialog>
#include "carrerasetting.h"

namespace Ui {
class CArreraInterfaceSetting;
}

class CArreraInterfaceSetting : public QDialog
{
    Q_OBJECT

public:
    explicit CArreraInterfaceSetting(QWidget *parent = nullptr);
    ~CArreraInterfaceSetting();
    void passObjSetting(CArreraSetting *s);
private:
    Ui::CArreraInterfaceSetting *ui;
    CArreraSetting *objSetting;
    void closeEvent(QCloseEvent *event);
    int mainAcceuil,widgetApp ;
    int acceuilApp ;
signals:
    void parametresFerme();
private slots:
    void on_IDC_MODE_clicked();
    void on_IDC_ASSISTANT_clicked();
    void on_IDC_ARRECHERCHE_clicked();
    void on_IDC_ARRERAAPP_clicked();
    void on_IDC_LIEU_clicked();
    void on_IDC_APPLICATION_clicked();
    void on_IDC_BACKAPPACCEUIL_clicked();
    void on_IDC_ADDAPP_clicked();
    void on_IDC_SUPP_clicked();
    void on_IDC_TASKBAR_clicked();
    void on_IDC_VALIDERNAMEAPPADD_clicked();
    void on_IDC_BACKAPPADDNAME_clicked();
    void on_IDC_WINDOWSMENU_clicked();
    void on_IDC_USERMENU_clicked();
    void on_IDC_BACKAPPADD_clicked();
    void on_IDC_OPENCHOIXAPPLINUX_clicked();
    void on_IDC_BACKCHOIXAPPLINUX_clicked();
};

#endif // CARRERAINTERFACESETTING_H
