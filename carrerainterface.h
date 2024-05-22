#ifndef CARRERAINTERFACE_H
#define CARRERAINTERFACE_H

#include <QWidget>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <carrerarecheche.h>
#include <carrerarecherchehist.h>

namespace Ui {
class CArreraInterface;
}

class CArreraInterface : public QWidget
{
    Q_OBJECT

public:
    explicit CArreraInterface(QWidget *parent = nullptr);
    CArreraRecheche objRecherche ;
    CArreraRechercheHist objRechercheHist;
    ~CArreraInterface();

private slots:
    void on_IDC_DRAWERAPP_clicked();

    void on_IDC_LIBEXIT_clicked();

    void on_IDC_SOFTPRESENTATION_clicked();

    void on_IDC_SOFTTABLEUR_clicked();

    void on_IDC_SOFTTEXTE_clicked();

    void on_IDC_SOFTPENSEBETE_clicked();

    void on_IDC_SOFTNAVIGATEUR_clicked();

    void on_IDC_POSTITEEXIT_clicked();

    void on_IDC_OUVRIR_clicked();

    void on_IDC_SAVE_clicked();

    void on_IDC_RECHERCHE_clicked();

    void on_IDC_VALIDERRECHERCHE_clicked();

    void on_IDC_HIST_clicked();

    void on_IDC_QUITARRERARECHERCHE_clicked();

    void on_IDC_RECHERCHEGOOGLE_clicked();

    void on_IDC_RECHERCHEDUCKDUCKGO_clicked();

    void on_IDC_RECHERCHEBING_clicked();

    void on_IDC_RECHERCHEBRAVE_clicked();

    void on_IDC_RECHERCHEQWANT_clicked();

    void on_IDC_RECHERCHEECOSIA_clicked();

    void on_IDC_GRECHERCHE_clicked();

    void on_IDC_RECHERCHEWORKREFERENCE_clicked();

    void on_IDC_RECHERCHEYTMUSIC_clicked();

    void on_IDC_RECHERCHEAMAZON_clicked();

    void on_IDC_RECHERCHEWIKIPEDIA_clicked();

    void on_IDC_RECHERCHEREVERSO_clicked();

private:
    Ui::CArreraInterface *ui;
    int mainPageIndex,libIndex,PostiteIndex,rechercheIndex;
};

#endif // CARRERAINTERFACE_H
