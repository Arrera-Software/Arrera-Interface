#ifndef ARRERASETTINGUI_H
#define ARRERASETTINGUI_H

#include <QDialog>

namespace Ui {
class ArreraSettingUI;
}

class ArreraSettingUI : public QDialog
{
    Q_OBJECT

public:
    explicit ArreraSettingUI(QWidget *parent = nullptr);
    ~ArreraSettingUI();
    void show();

private:
    Ui::ArreraSettingUI *ui;
    void closeEvent(QCloseEvent *event);
    // Id de mainstaked
    int idMainPage,idModePage,idGenerauxPage,idAssistantPage,idApplicationPage,idLieuPage,idRecherchePage;
    // id de modestaked
    int idMainModePage,idAddMode;
    // id appstacked
    int idMainAppStaked, idAddAppStacked,idSupprAppStacked;

signals:
    void parametresFerme();
private slots:
    void on_IDC_MODE_clicked();
    void on_IDC_GENERAUX_clicked();
    void on_IDC_ASSISTANT_clicked();
    void on_IDC_APPLICATION_clicked();
    void on_IDC_LIEU_clicked();
    void on_IDC_RECHERCHE_clicked();
    void on_IDC_ACCEUILPARAMETRE_clicked();
    void on_IDC_BTNMODE1_clicked();
    void on_IDC_BTNMODE2_clicked();
    void on_IDC_BTNMODE3_clicked();
    void on_IDC_BTNMODE4_clicked();
    void on_IDC_BTNMODE5_clicked();
    void on_IDC_BTNMODE6_clicked();
    void on_IDC_VALIDERMODE_clicked();
    void on_IDC_RETOURMODE_clicked();
    void on_IDC_RETOURGENERAUXUSER_clicked();
    void on_IDC_VALIDERNAMEUSER_clicked();
    void on_IDC_SETAPPPC_clicked();
    void on_IDC_ICONAPPPC_clicked();
    void on_IDC_VALIDERAPPPC_clicked();
    void on_IDC_CANCELAPPPC_clicked();
    void on_IDC_CANCELSUPPRAPP_clicked();
    void on_IDC_VALIDERSUPRR_clicked();
    void on_IDC_ADDAPPPC_clicked();
    void on_IDC_SUPPRAPPPC_clicked();
};

#endif // ARRERASETTINGUI_H
