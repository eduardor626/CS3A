#ifndef SONGINFO_H
#define SONGINFO_H
#include <iostream>
#include <cstdlib>

using namespace std;
class songInfo
{
public:
    songInfo();
    songInfo(string artist, string title, string album, string year, string directory);
    ~songInfo();
    void setTitle(string title);
    void setArtist(string artist);
    void setAlbum(string album);
    void setYear(string year);
    void setDirectory (string directory);
    void getInfo(string info[]);
    string getTitle();
    string getArtist();
    string getAlbum();
    string getYear();
    string getDirectory();
private:
    string title,artist, album, year, directory;

};
#endif // SONGINFO_H
