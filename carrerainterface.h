#ifndef CARRERAINTERFACE_H
#define CARRERAINTERFACE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class CArreraInterface;
}
QT_END_NAMESPACE

class CArreraInterface : public QMainWindow
{
    Q_OBJECT

public:
    CArreraInterface(QWidget *parent = nullptr);
    ~CArreraInterface();

private:
    Ui::CArreraInterface *ui;
};
#endif // CARRERAINTERFACE_H
