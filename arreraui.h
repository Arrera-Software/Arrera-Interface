// arreraui.h
#ifndef ARRERAUI_H
#define ARRERAUI_H

#include <QWidget>
#include <QDialog>
#include <QApplication>
#include <QDesktopServices>
#include <QUrl>
#include "cainterfacesetting.h"
#include "arrerasettingui.h"
#include "carrerarecheche.h"

namespace Ui {
class ArreraUI;
}

class ArreraUI : public QDialog
{
    Q_OBJECT

public:
    explicit ArreraUI(QWidget *parent = nullptr);
    ~ArreraUI();

private slots:
    void on_IDC_ACCEUILARRERA_clicked();

    void on_IDC_APPBUREAU_clicked();

    void on_IDC_ARRERAAPP_clicked();

    // Partie Apropos
    void on_IDC_SOURCECODE_clicked();

    void on_IDC_WEBSITE_clicked();

    void on_IDC_PARA_clicked();

    void on_IDC_SHOWHIST_clicked();

    void on_IDC_AUTREMOTEUR_clicked();

    void on_IDC_MOTEURDUCK_clicked();

    void on_IDC_MOTEURGOOGLE_clicked();

    void on_IDC_MOTEURBING_clicked();

    void on_IDC_MOTEURBRAVE_clicked();

    void on_IDC_MOTEURECOSIA_clicked();

    void on_IDC_MOTEURQWANT_clicked();

    void on_IDC_MOTEURBIGSEARCH_clicked();

    void on_IDC_MOTEURWIKIPEDIA_clicked();

    void on_IDC_MOTEURAMAZON_clicked();

    void on_IDC_MOTEURWORDREFERENCE_clicked();

    void on_IDC_MOTEURYT_clicked();

    void on_IDC_MOTEURREVERSO_clicked();

    void on_IDC_BTNSEACH_clicked();

private:
    Ui::ArreraUI *ui;
    CAInterfaceSetting *objSetting;
    ArreraSettingUI *uipara;
    CArreraRecheche arecherche;
    CDetectionOS dectOS;
    // Methode private
    void loadSetting();
    // Methode de recherche
    void launchSearch(int mode);
    // Id du staked widget I2025
    int idPageI2025Main,idPageI2025App,idPageI2025Mode,idPageI2025ArreraApp,idPageApropos,idPageRecherche;
    // Ide du staked widget arreraRecherche
    int idPageRechercheMoteur, idPageRechercheHist;
};

#endif // ARRERAUI_H
