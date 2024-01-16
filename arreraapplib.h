#ifndef ARRERAAPPLIB_H
#define ARRERAAPPLIB_H

#include <QDialog>

namespace Ui {
class ArreraAppLib;
}

class ArreraAppLib : public QDialog
{
    Q_OBJECT

public:
    explicit ArreraAppLib(QWidget *parent = nullptr);
    ~ArreraAppLib();

private:
    Ui::ArreraAppLib *ui;
};

#endif // ARRERAAPPLIB_H
