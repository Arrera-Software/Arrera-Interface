#ifndef CARRERAINTERFACE_H
#define CARRERAINTERFACE_H

#include <QWidget>

namespace Ui {
class CArreraInterface;
}

class CArreraInterface : public QWidget
{
    Q_OBJECT

public:
    explicit CArreraInterface(QWidget *parent = nullptr);
    ~CArreraInterface();

private:
    Ui::CArreraInterface *ui;
};

#endif // CARRERAINTERFACE_H
