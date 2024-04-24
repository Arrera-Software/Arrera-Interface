#ifndef CARRERAAPPLICATIONDRAWER_H
#define CARRERAAPPLICATIONDRAWER_H

#include <QDialog>

namespace Ui {
class CArreraApplicationDrawer;
}

class CArreraApplicationDrawer : public QDialog
{
    Q_OBJECT

public:
    explicit CArreraApplicationDrawer(QWidget *parent = nullptr);
    ~CArreraApplicationDrawer();

private slots:
    void on_IDC_SOFTPRESENTATION_clicked();

    void on_IDC_SOFTTABLEUR_clicked();

    void on_IDC_SOFTPENSEBETE_clicked();

    void on_IDC_SOFTTEXTE_clicked();

    void on_IDC_SOFTNAVIGATEUR_clicked();

private:
    Ui::CArreraApplicationDrawer *ui;
};

#endif // CARRERAAPPLICATIONDRAWER_H
