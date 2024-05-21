#include "carrerainterface.h"
#include "ui_carrerainterface.h"

CArreraInterface::CArreraInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CArreraInterface)
{
    ui->setupUi(this);
    mainPageIndex = ui->PagesArrera->indexOf(ui->Mainpage);
    libIndex =  ui->PagesArrera->indexOf(ui->ArreraLibPage);
    PostiteIndex = ui->PagesArrera->indexOf(ui->PostitePage);
    ui->PagesArrera->setCurrentIndex(mainPageIndex);
}

CArreraInterface::~CArreraInterface()
{
    delete ui;
}

void CArreraInterface::on_IDC_DRAWERAPP_clicked()
{
    ui->PagesArrera->setCurrentIndex(libIndex);
}

