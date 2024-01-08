#ifndef CDAPARAMETRE_H
#define CDAPARAMETRE_H

#include <QDialog>

namespace Ui {
class CDAParametre;
}

class CDAParametre : public QDialog
{
    Q_OBJECT

public:
    explicit CDAParametre(QWidget *parent = nullptr);
    ~CDAParametre();

private:
    Ui::CDAParametre *ui;
};

#endif // CDAPARAMETRE_H
