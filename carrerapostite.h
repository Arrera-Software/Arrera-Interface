#ifndef CARRERAPOSTITE_H
#define CARRERAPOSTITE_H

#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>

namespace Ui {
class CArreraPostite;
}

class CArreraPostite : public QDialog
{
    Q_OBJECT

public:
    explicit CArreraPostite(QWidget *parent = nullptr);
    ~CArreraPostite();

private slots:
    void on_IDC_SAVE_clicked();

    void on_IDC_OUVRIR_clicked();

private:
    Ui::CArreraPostite *ui;
};

#endif // CARRERAPOSTITE_H
