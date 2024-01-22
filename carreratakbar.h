#ifndef CARRERATAKBAR_H
#define CARRERATAKBAR_H
#include "cdaparametre.h"
#include <QDialog>

namespace Ui {
class CArreraTakbar;
}

class CArreraTakbar : public QDialog
{
    Q_OBJECT

public:
    explicit CArreraTakbar(QWidget *parent = nullptr);
    ~CArreraTakbar();
    void passObj(CArreraSetting* p);
    void loadPara(int mode);

private slots:
    void on_IDC_APP1_clicked();

    void on_IDC_APP2_clicked();

    void on_IDC_APP3_clicked();

    void on_IDC_APP4_clicked();

    void on_IDC_APP5_clicked();

    void on_IDC_QUIT_clicked();

private:
    Ui::CArreraTakbar *ui;
    CArreraSetting* objPara;
    int nbApp[5];
};

#endif // CARRERATAKBAR_H
