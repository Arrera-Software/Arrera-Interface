#ifndef CARRERAINTERFACE_H
#define CARRERAINTERFACE_H

#include <QWidget>
#include "carreraapplicationdrawer.h"

namespace Ui {
class CArreraInterface;
}

class CArreraInterface : public QWidget
{
    Q_OBJECT

public:
    explicit CArreraInterface(QWidget *parent = nullptr);
    ~CArreraInterface();

private slots:
    void on_IDC_DRAWERAPP_clicked();

private:
    Ui::CArreraInterface *ui;
    CArreraApplicationDrawer* winLib;
    CArreraPostite *winPostite;
};

#endif // CARRERAINTERFACE_H
