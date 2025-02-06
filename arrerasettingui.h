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
    // id lieustacked
    int idMainLieu,idAddLieu,idManageLieu;

signals:
    void parametresFerme();
private slots:
    // Partie acceuil
    void on_IDC_MODE_clicked();
    void on_IDC_GENERAUX_clicked();
    void on_IDC_ASSISTANT_clicked();
    void on_IDC_APPLICATION_clicked();
    void on_IDC_LIEU_clicked();
    void on_IDC_RECHERCHE_clicked();

    // Bouton TOP bar
    void on_IDC_ACCEUILPARAMETRE_clicked();

    // Partie mode
    void on_IDC_BTNMODE1_clicked();
    void on_IDC_BTNMODE2_clicked();
    void on_IDC_BTNMODE3_clicked();
    void on_IDC_BTNMODE4_clicked();
    void on_IDC_BTNMODE5_clicked();
    void on_IDC_BTNMODE6_clicked();
    // BTN addmode
    void on_IDC_VALIDERMODE_clicked();
    void on_IDC_RETOURMODE_clicked();
    // Partie gest mode
    void on_IDC_RESETMODE_clicked();
    void on_IDC_CHANGENAME_clicked();
    void on_IDC_ASSISTANTMAJGESTMODE_clicked();
    void on_IDC_MAJAPPGESTMODE_clicked();
    void on_IDC_RETOURGESTMODE_clicked();

    // Partie Parametre generaux
    void on_IDC_RETOURGENERAUXUSER_clicked();
    void on_IDC_VALIDERNAMEUSER_clicked();

    // Partie application
    //Partie ajout de l'app
    void on_IDC_SETAPPPC_clicked();
    void on_IDC_ICONAPPPC_clicked();
    void on_IDC_VALIDERAPPPC_clicked();
    void on_IDC_CANCELAPPPC_clicked();
    //Partie suppr de l'app
    void on_IDC_CANCELSUPPRAPP_clicked();
    void on_IDC_VALIDERSUPRR_clicked();
    //Partie acceuil d'app
    void on_IDC_ADDAPPPC_clicked();
    void on_IDC_SUPPRAPPPC_clicked();
    // Partie Recherche
    void on_IDC_VALIDERRECHERCHE_clicked();
    // Partie Lieu
    // Acceuil lieu
    void on_IDC_MANAGELIEU1_clicked();
    void on_IDC_MANAGELIEU1_2_clicked();
    // Create
    void on_IDC_CREALIEU_clicked();
    void on_IDC_CANCELCREATELIEU_clicked();
    // Manage lieu
    void on_IDC_CHANGENAMELIEU_clicked();
    void on_IDC_CHANGEASSISTANTLIEU_clicked();
    void on_IDC_ANNULERMANAGELIEU_clicked();
};

#endif // ARRERASETTINGUI_H
