#include "arreragui.h"
#include "ui_arreragui.h"

ArreraGUI::ArreraGUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ArreraGUI)
{
    ui->setupUi(this);
}

ArreraGUI::~ArreraGUI()
{
    delete ui;
}
