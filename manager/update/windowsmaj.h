#ifndef WINDOWSMAJ_H
#define WINDOWSMAJ_H

#include <QDialog>
#include <QDesktopServices>

namespace Ui {
class WindowsMaj;
}

class WindowsMaj : public QDialog
{
    Q_OBJECT

public:
    explicit WindowsMaj(QWidget *parent = nullptr);
    ~WindowsMaj();
    void set_new_version(QString new_version);

private slots:
    void on_IDC_CONTINUE_clicked();

private:
    Ui::WindowsMaj *ui;
};

#endif // WINDOWSMAJ_H
