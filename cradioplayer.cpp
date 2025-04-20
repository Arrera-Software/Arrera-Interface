#include "cradioplayer.h"
// Methode private
void CRadioPlayer::setUrl(const QString url){
    radioPlayer->setSource(url);
}

void CRadioPlayer::play(){
    radioPlayer->play();
}
// Methode public
CRadioPlayer::CRadioPlayer(QObject *parent)
    : QObject{parent}
{
    radioPlayer = new QMediaPlayer(this);
}

CRadioPlayer::~CRadioPlayer()
{
    delete radioPlayer;
}

void CRadioPlayer::playEurope1(){
    setUrl("http://stream.europe1.fr/europe1.aac");
    play();
}

void CRadioPlayer::playEurope2(){}

void CRadioPlayer::playFranceInfo(){}

void CRadioPlayer::playFranceInter(){}

void CRadioPlayer::playFranceMusique(){}

void CRadioPlayer::playFranceCulture(){}

void CRadioPlayer::playFunRadio(){}

void CRadioPlayer::playNRJ(){}

void CRadioPlayer::playRFM(){}

void CRadioPlayer::playNostalgi(){}

void CRadioPlayer::playSkyrock(){}

void CRadioPlayer::playRTL(){}

bool CRadioPlayer::isPlaying() const {
    return radioPlayer->playbackState() == QMediaPlayer::PlayingState;
}

void CRadioPlayer::stop(){}
