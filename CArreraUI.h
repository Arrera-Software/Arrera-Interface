#ifndef CARRERAUI_H
#define CARRERAUI_H

#include <QMainWindow>
#include "cdaparametre.h"


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

private:
    Ui::CArreraUI *ui;
    CArreraSetting objPara;
    CDAParametre *winPara ;
    QString nameMode1,nameMode2,nameMode3,nameMode4,nameMode5;
    void closeEvent(QCloseEvent *event);

};
#endif // CARRERAUI_H
