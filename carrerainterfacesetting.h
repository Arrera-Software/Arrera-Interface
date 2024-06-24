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
};

#endif // CARRERAINTERFACESETTING_H
