#include "arreraui.h"
#include "ui_arreraui.h"

ArreraUI::ArreraUI(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ArreraUI)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
}

ArreraUI::~ArreraUI()
{
    delete ui;
}
