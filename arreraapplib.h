#ifndef ARRERAAPPLIB_H
#define ARRERAAPPLIB_H

#include <QDialog>
#include "carreratakbar.h"

namespace Ui {
class ArreraAppLib;
}

class ArreraAppLib : public QDialog
{
    Q_OBJECT

public:
    explicit ArreraAppLib(QWidget *parent = nullptr);
    ~ArreraAppLib();
    void passObjet(CArreraSetting *para,CArreraOpenSoft *objOpen);
    void updateBTN();
private slots:
    void on_IDC_BTNAPP_clicked();

    void on_IDC_BTNARRERAAPP_clicked();

    void on_IDC_BTNAPP1_clicked();

    void on_IDC_BTNAPP2_clicked();

    void on_IDC_BTNAPP3_clicked();

    void on_IDC_BTNAPP4_clicked();

    void on_IDC_BTNAPP5_clicked();

    void on_IDC_BTNAPP6_clicked();

    void on_IDC_BTNAPP7_clicked();

    void on_IDC_BTNAPP8_clicked();

    void on_IDC_BTNAPP9_clicked();

    void on_IDC_BTNAPP10_clicked();

    void on_IDC_BTNAPP11_clicked();

    void on_IDC_BTNAPP12_clicked();

    void on_IDC_BTNAVIDEO_clicked();

    void on_IDC_BTNADOC_clicked();

    void on_IDC_BTNAINFO_clicked();

    void on_IDC_BTNARECHERCHE_clicked();

    void on_IDC_BTNUTILITY_clicked();

    void on_IDC_BTNVM_clicked();

    void on_IDC_BTNSCREENTAB_clicked();

private:
    Ui::ArreraAppLib *ui;
    CArreraSetting* parametreArrera;
    CArreraOpenSoft* arreraOpen;
};

#endif // ARRERAAPPLIB_H
