#ifndef CDAPARAMETRE_H
#define CDAPARAMETRE_H

#include <QDialog>
#include "cdaparaarreralib.h"

namespace Ui {
class CDAParametre;
}

class CDAParametre : public QDialog
{
    Q_OBJECT

public:
    explicit CDAParametre(QWidget *parent = nullptr);
    ~CDAParametre();
    void passObjPara(CArreraSetting* obj,CArreraOpenSoft *objSoft);

private slots:
    void on_IDC_GESTMODE1_clicked();

    void on_IDC_GESTMODE2_clicked();

    void on_IDC_GESTMODE3_clicked();

    void on_IDC_GESTMODE4_clicked();

    void on_IDC_GESTMODE5_clicked();

    void on_IDC_VALIDER_clicked();

    void on_IDC_ETABLEUR_clicked();

    void on_IDC_ENAVIGATEUR_clicked();

    void on_IDC_ETTEXTE_clicked();

    void on_IDC_EPRESENTATION_clicked();

    void on_IDC_ESIX_clicked();

    void on_IDC_ERYLEY_clicked();

    void on_IDC_VALIDERNAME_clicked();

    void on_IDC_PSIX_clicked();

    void on_IDC_PRYLEY_clicked();

    void on_IDC_RESETINTERFACE_clicked();

    void on_IDC_APP_clicked();

    void on_IDC_GESTTASKBAR_clicked();

    void on_IDC_APPTASKMODE_clicked();

    void on_IDC_ANNULERMODE_clicked();

    void on_IDC_BTNRESETMODESET_clicked();

    void on_BTNMTP0_clicked();

    void on_BTNMTP1_5_clicked();

    void on_BTNMTP2_clicked();

    void on_BTNMTP3_clicked();

    void on_BTNMTP4_clicked();

    void on_BTNMTP5_clicked();

    void on_BTNMTP6_clicked();

    void on_BTNMTP7_clicked();

    void on_BTNMTP8_clicked();

    void on_BTNMTP9_clicked();

    void on_IDC_VALIDERMTP_clicked();

    void on_IDC_ANNULERMTP_clicked();

private:
    Ui::CDAParametre *ui;
    void closeEvent(QCloseEvent *event);
    int modeSelectionner;
    bool sortieRyley,sortieSix,taskBarModeEnable;
    QString mtpUser;
    CArreraSetting* objParametre;
    CArreraOpenSoft *objOpenSoft;
    CDAparaArreraLib *winParaApp;
};

#endif // CDAPARAMETRE_H
