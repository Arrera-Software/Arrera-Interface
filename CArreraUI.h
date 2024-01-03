#ifndef CARRERAUI_H
#define CARRERAUI_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class CArreraUI; }
QT_END_NAMESPACE

class CArreraUI : public QMainWindow
{
    Q_OBJECT

public:
    CArreraUI(QWidget *parent = nullptr);
    ~CArreraUI();

private:
    Ui::CArreraUI *ui;
};
#endif // CARRERAUI_H
