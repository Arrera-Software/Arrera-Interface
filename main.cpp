#include "arreraui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
     QApplication a(argc, argv);
    ArreraUI w;
    w.show();
    return a.exec();
}
