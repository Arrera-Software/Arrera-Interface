#ifndef CARRERAUI_H
#define CARRERAUI_H

#include <QMainWindow>
#include "arreraapplib.h"
#include "carreraapropos.h"
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class CArreraUI; }
QT_END_NAMESPACE

class CArreraUI : public QMainWindow
{
    Q_OBJECT

public:
    CArreraUI(QWidget *parent = nullptr);
    ~CArreraUI();
    void loadSetting();

private slots:
    void on_IDC_QUIT_clicked();

    void on_IDC_PARAMETRE_clicked();

    void on_IDC_SIX_clicked();

    void on_IDC_COPILOTE_clicked();

    void on_IDC_RYLEY_clicked();

    void on_IDC_MODE1_clicked();

    void on_IDC_MODE2_clicked();

    void on_IDC_MODE3_clicked();

    void on_IDC_MODE4_clicked();

    void on_IDC_MODE5_clicked();

    void on_IDC_TABLEUR_clicked();

    void on_IDC_TRAITEMENT_clicked();

    void on_IDC_APP_clicked();

    void on_IDC_NAVIGATEUR_clicked();

    void on_IDC_PRESENTATION_clicked();

    void on_IDC_RELOAD_clicked();


    void on_IDC_APROPOS_clicked();

    void on_IDC_TASKBAR_clicked();

    void on_IDC_TABLEURMODE_clicked();

    void on_IDC_TRAITEMENTMODE_clicked();

    void on_IDC_APPMODE_clicked();

    void on_IDC_TASKBARMODE_clicked();

    void on_IDC_NAVIGATEURMODE_clicked();

    void on_IDC_PRESENTATIONMODE_clicked();

    void on_IDC_QUITMODE_clicked();

    void on_IDC_QUIT2_clicked();

    void on_IDC_ASSISTANTMODE_clicked();

private:
    Ui::CArreraUI *ui;
    CArreraSetting objPara;
    CArreraApropos *winApropos;
    CDAParametre *winPara ;
    ArreraAppLib *winAPP;
    CArreraTakbar *taskBar;
    CArreraOpenSoft objSoftware;
    int nbModeON,assistantMode;
    void closeEvent(QCloseEvent *event);
    void errorOpenSoft();
    void onMode(int nbMode);
    void offMode();

};
#endif // CARRERAUI_H
