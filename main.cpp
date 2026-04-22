#include "gui/arrera/arreraui.h"

#include <QApplication>
#include <QStyleHints>
#include <QObject>
#include <QIcon>

int main(int argc, char *argv[])
{
    #ifdef Q_OS_LINUX
        qunsetenv("QT_QPA_PLATFORMTHEME");

        qputenv("QT_QPA_PLATFORMTHEME", "xdgdesktopportal");
    #endif

    QApplication a(argc, argv);
    QApplication::setStyle("fusion");

    ArreraUI w;

    #ifdef Q_OS_LINUX
        w.setWindowIcon(QIcon(":/arrera/img/icon-linux-win.png"));
    #endif

    #ifdef Q_OS_WIN
        w.setWindowIcon(QIcon(":/arrera/img/icon-linux-win.png"));
    #endif

    w.show();
    return a.exec();
}
