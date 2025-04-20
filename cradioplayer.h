#ifndef CRADIOPLAYER_H
#define CRADIOPLAYER_H

#include <QObject>
#include <QMediaPlayer>

class CRadioPlayer : public QObject
{
    Q_OBJECT
private :
    QMediaPlayer *radioPlayer;
    void setUrl(const QString url);
    void play();
public:
    explicit CRadioPlayer(QObject *parent = nullptr);
    ~CRadioPlayer();
    void playEurope1();
    void playEurope2();
    void playFranceInfo();
    void playFranceInter();
    void playFranceMusique();
    void playFranceCulture();
    void playFunRadio();
    void playNRJ();
    void playRFM();
    void playNostalgi();
    void playSkyrock();
    void playRTL();
    bool isPlaying() const;
    void stop();
};

#endif // CRADIOPLAYER_H
