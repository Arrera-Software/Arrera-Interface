#include "gui/arrera/arreraui.h"

#include <QApplication>
#include <QStyleHints>
#include <QObject>

static QPalette darkPalette(){
    QPalette pal;
    pal.setColor(QPalette::Window, QColor("#0E1116"));
    pal.setColor(QPalette::WindowText, QColor("#E8EDF2"));
    pal.setColor(QPalette::Base, QColor("#0F1318"));
    pal.setColor(QPalette::AlternateBase, QColor("#12161F"));
    pal.setColor(QPalette::ToolTipBase, QColor("#11151C"));
    pal.setColor(QPalette::ToolTipText, QColor("#E8EDF2"));
    pal.setColor(QPalette::Text, QColor("#E8EDF2"));
    pal.setColor(QPalette::Button, QColor("#11151C"));
    pal.setColor(QPalette::ButtonText, QColor("#E8EDF2"));
    pal.setColor(QPalette::Highlight, QColor("#6D5EFC"));
    pal.setColor(QPalette::HighlightedText, QColor("#0B0F14"));
    return pal ;
}

static QPalette lightPalette(){
    QPalette pal;
    pal.setColor(QPalette::Window,         QColor("#FFFFFF"));
    pal.setColor(QPalette::WindowText,     QColor("#0E1726"));
    pal.setColor(QPalette::Base,           QColor("#FFFFFF"));
    pal.setColor(QPalette::AlternateBase,  QColor("#F6F7FB"));
    pal.setColor(QPalette::ToolTipBase,    QColor("#FFFFFF"));
    pal.setColor(QPalette::ToolTipText,    QColor("#0E1726"));
    pal.setColor(QPalette::Text,           QColor("#0E1726"));
    pal.setColor(QPalette::Button,         QColor("#FFFFFF"));
    pal.setColor(QPalette::ButtonText,     QColor("#0E1726"));
    pal.setColor(QPalette::Highlight,      QColor("#4F46E5"));  // Indigo
    pal.setColor(QPalette::HighlightedText,QColor("#FFFFFF"));
    pal.setColor(QPalette::PlaceholderText,QColor(14,23,38,140));
    // Optionnel: légers gris pour bords
    pal.setColor(QPalette::Midlight,       QColor("#EDF1F7"));
    pal.setColor(QPalette::Mid,            QColor("#E3E8F0"));
    return pal;
}

static void applyPaletteForScheme(Qt::ColorScheme scheme) {
    if (scheme == Qt::ColorScheme::Dark)
        qApp->setPalette(darkPalette());
    else
        qApp->setPalette(lightPalette());
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setStyle("fusion");

    ArreraUI w;

    // 1) Appliquer en fonction du schéma courant
    applyPaletteForScheme(qApp->styleHints()->colorScheme());

    // 2) Écouter les changements du système en live
    QObject::connect(qApp->styleHints(), &QStyleHints::colorSchemeChanged,
                     &a, [](Qt::ColorScheme scheme){
                         applyPaletteForScheme(scheme);
                     });

    w.show();
    return a.exec();
}
