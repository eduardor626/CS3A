#include "songinfo.h"

songInfo::songInfo(string artist, string title, string album, string year, string directory)
{
    this->artist = artist;
    this->title = title;
    this->album = album;
    this->year = year;
    this->directory = directory;
}

songInfo::~songInfo()
{
    artist.clear();
    title.clear();
    album.clear();
    year.clear();
    directory.clear();
}

void songInfo::setTitle(string title){
    this->title = title;
}
void songInfo::setArtist(string artist){
    this->artist = artist;
}

void songInfo::setAlbum(string album){
    this->album = album;
}

void songInfo::setYear(string year){
    this->year = year;
}

void songInfo::setDirectory (string directory) {
    this->directory = directory;
}

void songInfo::getInfo(string info[]){
    info[0] = title;
    info[1] = artist;
    info[2] = album;
    info[3] = year;
}

string songInfo::getTitle(){
    return title;
}

string songInfo::getArtist(){
    return artist;
}

string songInfo::getAlbum(){
    return album;
}

string songInfo::getYear(){
    return year;
}

string songInfo::getDirectory(){
    return directory;
}
