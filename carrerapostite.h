#ifndef CARRERAPOSTITE_H
#define CARRERAPOSTITE_H

#include <QDialog>

namespace Ui {
class CArreraPostite;
}

class CArreraPostite : public QDialog
{
    Q_OBJECT

public:
    explicit CArreraPostite(QWidget *parent = nullptr);
    ~CArreraPostite();

private:
    Ui::CArreraPostite *ui;
};

#endif // CARRERAPOSTITE_H
