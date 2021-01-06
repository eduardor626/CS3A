#ifndef GETMP3_H
#define GETMP3_H
#include <ostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <dirent.h>
#include <songinfo.h>
#include <fstream>

using namespace std;

class getMp3
{
public:
    getMp3();
    void readFolder(vector<string> list, vector<songInfo> &songList);
    string readFile(string directory);
    int listdir(const char *path);
private:
    const string path = "/Users/vunguyen/Dropbox/C++/Fall 2017/myTunes/myMusic.app/contents/MacOS/music/";
    vector<string> validMp3;
    void checkExtension(vector<string> &list);
    string findTag(char *file, const unsigned int &size);
    string getStringFrom (char* file, const int &start, const int &end);
    void extractInfoV1 (vector<songInfo> &songList, char *ID3, const string &directory);
    void extractInfoV2 (vector<songInfo> &songList, char *ID3, const string &directory);
    void trim (string &word);
};

#endif // GETMP3_H
