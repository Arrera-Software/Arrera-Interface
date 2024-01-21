#ifndef CARRERAAPROPOS_H
#define CARRERAAPROPOS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class CArreraApropos;
}
QT_END_NAMESPACE

class CArreraApropos : public QMainWindow
{
    Q_OBJECT

public:
    CArreraApropos(QWidget *parent = nullptr);
    ~CArreraApropos();

private slots:
    void on_IDC_SOURCE_clicked();

    void on_IDC_QUIT_clicked();

private:
    Ui::CArreraApropos *ui;
};
#endif // CARRERAAPROPOS_H
