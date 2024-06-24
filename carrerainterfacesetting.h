#ifndef CARRERAINTERFACESETTING_H
#define CARRERAINTERFACESETTING_H

#include <QDialog>

namespace Ui {
class CArreraInterfaceSetting;
}

class CArreraInterfaceSetting : public QDialog
{
    Q_OBJECT

public:
    explicit CArreraInterfaceSetting(QWidget *parent = nullptr);
    ~CArreraInterfaceSetting();

private:
    Ui::CArreraInterfaceSetting *ui;
    void closeEvent(QCloseEvent *event);
signals:
    void parametresFerme();
private slots:
    void on_IDC_MODE_clicked();
    void on_IDC_ASSISTANT_clicked();
    void on_IDC_ARRECHERCHE_clicked();
    void on_IDC_ARRERAAPP_clicked();
    void on_IDC_LIEU_clicked();
    void on_IDC_APPLICATION_clicked();
};

#endif // CARRERAINTERFACESETTING_H
