// arreraui.h
#ifndef ARRERAUI_H
#define ARRERAUI_H

#include <QWidget>
#include <QDialog>

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

private:
    Ui::ArreraUI *ui;
    int idPageI2025Main,idPageI2025App,idPageI2025Mode;
};

#endif // ARRERAUI_H
