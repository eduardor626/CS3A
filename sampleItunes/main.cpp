#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

string extractName(char charArray[227], unsigned int bytesize, unsigned int bytesize2);


int main(int argc, char *argv[])
{
    string filename = "Death Grips - No Love.mp3";
    ifstream in;
    char charArray[227];
    string title, artist, album;

    in.open(filename, ios::in | ios::binary);
    if(in.is_open())
    {
        cout<<"File opened succesfully..\n";
        in.seekg (0, in.end);
        int length = in.tellg();
        in.seekg (0, in.beg);
        char *buffer = new char [length];
        cout<<"reading "<<length<<" characters.\n";
        in.read(buffer,length);
        for(unsigned int i =0; i<227; ++i)
        {
            charArray[i] = buffer[i];
            cout<<(char)charArray[i];
        }
        cout<<endl;
        title = extractName(charArray,4,60);
        cout<<"TITLE = "<<title<<endl;
        artist = extractName(charArray,60,120);
        cout<<"ARTIST = "<<artist<<endl;
        album = extractName(charArray,120,180);
        cout<<"ALBUM = "<<artist<<endl;

        delete[] buffer;
    }else
        cout<<"File was not able to be opened!\n";

    return 0;
}


string extractName(char charArray[227], unsigned int bytesize, unsigned int bytesize2)
{

    string title;
    for(bytesize; bytesize < bytesize2; ++bytesize)
        title.push_back(charArray[bytesize]);
    return title;
}
