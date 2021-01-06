#include "musicengine.h"
#include "ui_musicengine.h"
#include <iostream>

musicEngine::musicEngine(QWidget *parent) :
    QWidget(parent),
    balance(0),
    volume(50)
{
    deviceList = irrklang::createSoundDeviceList();
    int deviceCount = deviceList->getDeviceCount();
    qDebug()<<"Number of devices found: "<<deviceCount;
    for(int i = 0; i < deviceCount; ++i)
    {
        qDebug()<<deviceList->getDeviceDescription(i);
        listOfDevices.append(deviceList->getDeviceDescription(i));
    }
    setDevice(0);
    qDebug()<<"Ended musicengine constructor";
}

musicEngine::~musicEngine()
{
    engine->stopAllSounds();
    deviceList->drop();
    engine->drop();
}

musicEngine::musicEngine(string whatToPlay)
{
    currentPlay = whatToPlay;
}

float musicEngine::getBalance()
{
    return balance;
}

int musicEngine::getPlayingProgess()
{
    float f;
    if( music != NULL && isPlaying)
    {
        unsigned int p = music->getPlayPosition();
        unsigned int l = music->getPlayLength() ;
        f =  (  (float)(p ) / (l ) ) * 1002;
        return (int)(f);
    }
    return -1;
}

QString musicEngine::getTimeInMinute()
{
    if(music != NULL)
    {
        QString current = milliesecondToQString(music->getPlayPosition()+1000);
        QString duration = milliesecondToQString(music->getPlayLength());
        QString sign = " - ";
        return current + sign + duration;
    }
    return QString("00:00");
}

QString musicEngine::milliesecondToQString(const ik_u32 &milliseconds)
{
    int minutes = (int) ((milliseconds/(1000*60))%60);
    int seconds = (int) ((milliseconds/1000) % 60);
    string m = to_string(minutes);
    string s = to_string(seconds);
    if (minutes < 10)
        m = "0"+ m;
    if (seconds < 10)
        s = "0"+ s;
    return QString::fromStdString(m + ":" + s);
}

float musicEngine::getVolume()
{
    return volume;
}

QStringList& musicEngine::getDevices()
{
    return listOfDevices;
}

void musicEngine::play()
{
    engine->stopAllSounds();
    music = engine->play2D((currentPlay).c_str(),true, false, true);
    isPlaying = true;
    if(music)
    {
        qDebug()<<"Attempting to play music";
        music->setPan(balance);
        volume = music->getVolume();
        timer = new QTimer(this);
        timer->setTimerType(Qt::TimerType::CoarseTimer);
        timer->start(500);
        connect(timer,SIGNAL(timeout()),this,SLOT(onSoundStopped()));
        emit songData(music->getVolume()*75,music->getPlayLength());
    }
}

 void musicEngine::playAt(int pos)
 {
     if (pos > 0 && isPlaying)
     {
         ik_f32 p = (float)pos/1000 * music->getPlayLength();
         music->setPlayPosition(p);
     }
 }
void musicEngine::setDevice(int deviceNumber)
{
    //const char* deviceID = deviceList->getDeviceID(deviceNumber);
    engine = createIrrKlangDevice();
}

void musicEngine::pause ()
{
    if(music != NULL && isPlaying)
        music->setIsPaused(music->getIsPaused() ? false : true);
}

void musicEngine::stop ()
{
    if (music != NULL && isPlaying)
    {
        music->stop();
        music->drop();
        isPlaying = false;
    }
}

void musicEngine::fastForward()
{
   if(music != NULL && isPlaying)
   {
       float currPos = music->getPlayPosition() + forwardRate;
       if(currPos >= music->getPlayLength())
            currPos = music->getPlayLength();
        music->setPlayPosition(currPos);
        emit currPositionInSong(music->getPlayPosition());
   }
}

void musicEngine::rewind()
{
    if(music != NULL && isPlaying)
    {
      float currPos = music->getPlayPosition() - forwardRate;
      if(currPos <= 0)
         currPos = 0;
      music->setPlayPosition(currPos);
      emit currPositionInSong(music->getPlayPosition());
    }
}

void musicEngine::restart()
{
    music->setPlayPosition(0);
    emit currPositionInSong(0);
}

void musicEngine::setVolume (int vol)
{
     if(music && isPlaying)
        music->setVolume((float)vol/100);
}

void musicEngine::setPlayingOffset(float timeOffset)
{
    float millisecs = timeOffset/100. * music->getPlayLength();
    music->setPlayPosition(millisecs);
}

void musicEngine::setBalance(int pan)
{
    balance = pan/50.0;
    if(music && isPlaying)
        music->setPan(balance);
}

void musicEngine::setWhatToPlay(string whatToPlay)
{
        currentPlay = whatToPlay;
}

void musicEngine::onTimeOut()
{
    if(music->isFinished())
    {
        delete timer;
        emit songFinished();
    }
}

void musicEngine::onSoundStopped()
{

}

void musicEngine::setPlayBackSpeed(const int &speed)
{
    if (music && isPlaying)
    {
        ik_f32 s = (ik_f32)(speed)/10;
        music->setPlaybackSpeed(s);
    }
}

