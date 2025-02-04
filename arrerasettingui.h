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
    int idMainModePage;

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
};

#endif // ARRERASETTINGUI_H
