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
    void show();

private:
    Ui::ArreraSettingUI *ui;
    void closeEvent(QCloseEvent *event);
    // Id de mainstaked
    int idMainPage,idModePage;
    // id de modestaked
    int idMainModePage;

signals:
    void parametresFerme();
};

#endif // ARRERASETTINGUI_H
