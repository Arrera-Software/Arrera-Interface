#ifndef CARRERATAKBAR_H
#define CARRERATAKBAR_H

#include <QDialog>

namespace Ui {
class CArreraTakbar;
}

class CArreraTakbar : public QDialog
{
    Q_OBJECT

public:
    explicit CArreraTakbar(QWidget *parent = nullptr);
    ~CArreraTakbar();

private slots:
    void on_IDC_APP1_clicked();

    void on_IDC_APP2_clicked();

    void on_IDC_APP3_clicked();

    void on_IDC_APP4_clicked();

    void on_IDC_APP5_clicked();

    void on_IDC_QUIT_clicked();

private:
    Ui::CArreraTakbar *ui;
};

#endif // CARRERATAKBAR_H
