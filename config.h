#ifndef CONFIG_H
#define CONFIG_H

using namespace std;
#include <QString>
#include <QPushButton>


struct ModeConfig {
    QPushButton* button;
    function<bool()> isSet;
    function<bool()> iconIsSet;
    function<QString()> getIcon;
    function<QString()> getName;
    QString defaultIcon;
    int index;
};

struct LieuConfig{
    QPushButton* button;
    function<bool()> isSet;
    function<bool()> iconIsSet;
    function<QString()> getIcon;
    function<QString()> getName;
    QString defaultIcon;
    int index;
};

#endif // CONFIG_H
