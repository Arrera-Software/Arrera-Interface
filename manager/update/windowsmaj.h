#ifndef WINDOWSMAJ_H
#define WINDOWSMAJ_H

#include <QDialog>

namespace Ui {
class WindowsMaj;
}

class WindowsMaj : public QDialog
{
    Q_OBJECT

public:
    explicit WindowsMaj(QWidget *parent = nullptr);
    ~WindowsMaj();

private:
    Ui::WindowsMaj *ui;
};

#endif // WINDOWSMAJ_H
