#ifndef CDAPARAARRERALIB_H
#define CDAPARAARRERALIB_H

#include <QDialog>
#include "carreraopensoft.h"

namespace Ui {
class CDAparaArreraLib;
}

class CDAparaArreraLib : public QDialog
{
    Q_OBJECT

public:
    explicit CDAparaArreraLib(QWidget *parent = nullptr);
    ~CDAparaArreraLib();
    void passObjet(CArreraSetting* p);
    void modeApp();
    void modeTaskbar(int mode);

private slots:
    void on_IDC_GESTAPP1_clicked();

    void on_IDC_GESTAPP2_clicked();

    void on_IDC_GESTAPP3_clicked();

    void on_IDC_GESTAPP4_clicked();

    void on_IDC_GESTAPP5_clicked();

    void on_IDC_GESTAPP6_clicked();

    void on_IDC_GESTAPP7_clicked();

    void on_IDC_GESTAPP8_clicked();

    void on_IDC_GESTAPP9_clicked();

    void on_IDC_GESTAPP10_clicked();

    void on_IDC_GESTAPP11_clicked();

    void on_IDC_GESTAPP12_clicked();

    void on_IDC_GESTARRERARECHERCHE_clicked();

    void on_IDC_GESTARRERAINFO_clicked();

    void on_IDC_GESTARRERAVIDEO_clicked();

    void on_IDC_GESTARRERADOC_clicked();

    void on_IDC_VALIDER_clicked();

    void on_IDC_TASK1_clicked();

    void on_IDC_TASK2_clicked();

    void on_IDC_TASK3_clicked();

    void on_IDC_TASK4_clicked();

    void on_IDC_TASK5_clicked();

    void on_IDC_VALIDERTASKBAR_clicked();

private:
    Ui::CDAparaArreraLib *ui;
    int nbAppSelect; // de 1 a 12
    int nbRacoucieSelect; // 1 a 5
    CArreraSetting* para;
    void clearGestApp();
    void selectApp(int nb);
    int modeSelected;
};

#endif // CDAPARAARRERALIB_H
