#ifndef CDAPARAARRERALIB_H
#define CDAPARAARRERALIB_H

#include <QDialog>
#include "carrerasetting.h"
#include "carreraopensoft.h"

namespace Ui {
class CDAparaArreraLib;
}

class CDAparaArreraLib : public QDialog
{
    Q_OBJECT

public:
    explicit CDAparaArreraLib(QWidget *parent = nullptr);
    ~CDAparaArreraLib();

private:
    Ui::CDAparaArreraLib *ui;
};

#endif // CDAPARAARRERALIB_H
