#ifndef CDAPARAMETRE_H
#define CDAPARAMETRE_H

#include <QDialog>
#include "carrerasetting.h"

namespace Ui {
class CDAParametre;
}

class CDAParametre : public QDialog
{
    Q_OBJECT

public:
    explicit CDAParametre(QWidget *parent = nullptr);
    ~CDAParametre();
    void passObjPara(CArreraSetting* obj);

private slots:
    void on_IDC_GESTMODE1_clicked();

    void on_IDC_GESTMODE2_clicked();

    void on_IDC_GESTMODE3_clicked();

    void on_IDC_GESTMODE4_clicked();

    void on_IDC_GESTMODE5_clicked();

    void on_IDC_VALIDER_clicked();

private:
    Ui::CDAParametre *ui;
    void closeEvent(QCloseEvent *event);
    int modeSelectionner;
    bool sortieRyley,sortieSix;
    CArreraSetting* objParametre;
};

#endif // CDAPARAMETRE_H
