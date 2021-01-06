#include "getmp3.h"

getMp3::getMp3()
{
    //DONE
}

void getMp3::readFolder(vector<string> list, vector<songInfo> &songlist)
{
    checkExtension(list);
    ifstream readFile;
    string tag, path;
    int length;
    char* ID3 = new char [227];
    for (unsigned int i = 0 ; i < list.size() ; ++i)
    {
        readFile.open(list[i]);
        path = list[i];
        char* file;
        if (readFile.is_open())
        {
                readFile.seekg (0, readFile.end);
                length = readFile.tellg();
                readFile.seekg (0, readFile.beg);
                file = new char[length];
                readFile.read(file,length);
         }

        if (length >= 227)
        {
            tag = findTag(file, length);
            if (tag == "TAG")
            {
                for (int i = 0 ; i < 128 ; ++i)
                    ID3[i] = file[length-128+i];
                 extractInfoV1( songlist, ID3, path);
            }
            else if (tag == "TAG+")
            {
                for (int i = 0 ; i < 227 ; ++i)
                    ID3[i] = file[i];
                extractInfoV2(songlist, ID3, path);
            }
            else
            {
                path = path.substr(0,path.find(".mp3"));
                songlist.push_back(songInfo ("Unkown",
                                               path.substr(path.find_last_of("/")+1,path.size()-1) , "unknown" , "unkown", list[i]));
            }
        }
        delete[] file;
        readFile.close();
    }
}

void getMp3::extractInfoV1(vector<songInfo> &songList, char *ID3, const string &directory)
{
    string title = getStringFrom(ID3, 3, 33);
    string artist = getStringFrom(ID3, 33, 63);
    string album = getStringFrom(ID3, 63, 93);
    string year = getStringFrom(ID3,93,97);
    songList.push_back(songInfo( artist,  title,  album,  year,  directory));
}

void getMp3::extractInfoV2(vector<songInfo> &songList, char *ID3, const string &directory)
{
    string title = getStringFrom(ID3, 4, 60);
    string artist = getStringFrom(ID3, 60, 120);
    string album = getStringFrom(ID3, 120, 180);
    songList.push_back(songInfo( artist,  title,  album,  "unkown",  directory));
}

void getMp3::checkExtension(vector<string> &list)
{
    string ext = ".mp3";
    vector<string> temp;
    for (int i = list.size() - 1; i >= 0; --i)
    {
        if (list[i].find(ext) > list[i].size())
           list.erase(list.begin() + i);
        else
            temp.push_back(list[i]);
    }
    list = temp;
}

string getMp3::findTag(char *file, const unsigned int &size)
{
    string tag = getStringFrom(file,0, 4);
    if (tag == "TAG+")
    {
        return tag;
    }else
    {
        tag = getStringFrom(file,size -128, size - 125 );
        if(tag == "TAG")
            return tag;
        else
            return "";
    }
}

string getMp3::getStringFrom (char* file, const int &start, const int &end)
{
    string s;
    for (int i = start; i < end ; ++i)
        s.push_back(file[i]);
    trim(s);
    return s;
}

void getMp3::trim (string &word)
{
    while (word[0] == ' ')
        word.erase(0,1);
    while (word[word.size()-1] == ' ')
        word.erase(word.size()-1,1);
}


