#ifndef ARRERASETTINGUI_H
#define ARRERASETTINGUI_H

#include <QDialog>

namespace Ui {
class ArreraSettingUI;
}

class ArreraSettingUI : public QDialog
{
    Q_OBJECT

public:
    explicit ArreraSettingUI(QWidget *parent = nullptr);
    ~ArreraSettingUI();

private:
    Ui::ArreraSettingUI *ui;
    void closeEvent(QCloseEvent *event);

signals:
    void parametresFerme();
};

#endif // ARRERASETTINGUI_H
