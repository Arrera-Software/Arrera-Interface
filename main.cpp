#include "arreraui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ArreraUI w;

    if (w.dectOS.getosApple()){
        QFile styleFile(":/style/MacOS.qss");
        if (styleFile.open(QIODevice::ReadOnly | QIODevice::Text)){
            w.setStyleSheet(QString::fromUtf8(styleFile.readAll()));
            styleFile.close();
        }
    }

    w.show();
    return a.exec();
}
