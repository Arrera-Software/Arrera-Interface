#ifndef ARRERAAPPLIB_H
#define ARRERAAPPLIB_H

#include <QDialog>
#include "carreraopensoft.h"
namespace Ui {
class ArreraAppLib;
}

class ArreraAppLib : public QDialog
{
    Q_OBJECT

public:
    explicit ArreraAppLib(QWidget *parent = nullptr);
    ~ArreraAppLib();
    void passArreraPara(CArreraSetting *para);
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

private:
    Ui::ArreraAppLib *ui;
    CArreraSetting *parametreArrera;
};

#endif // ARRERAAPPLIB_H
