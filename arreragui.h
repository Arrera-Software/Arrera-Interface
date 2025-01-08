#ifndef ARRERAGUI_H
#define ARRERAGUI_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class ArreraGUI;
}
QT_END_NAMESPACE

class ArreraGUI : public QMainWindow
{
    Q_OBJECT

public:
    ArreraGUI(QWidget *parent = nullptr);
    ~ArreraGUI();

private:
    Ui::ArreraGUI *ui;
};
#endif // ARRERAGUI_H
