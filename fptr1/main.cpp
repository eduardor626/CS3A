#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

typedef void (*fptr)();

void up();
void down();
void left();
void right();
void shoot();
void quit();
void nothing();
void play(fptr whatToDo);
void initialize(fptr keys[]);

int main(int argc, char *argv[])
{
    fptr input[128];
    srand(time(NULL));
    initialize(input);
    while(1)
    {
        int key = rand()%128;
        cout<<"current key is "<<key;
        if(32 <= key && key <= 127)
            cout<<" Which is "<<(char)key; //use (char)key to get character value of key
                                          //we can also do (int)key to get integer value of key
                                          //if we wanted to
        cout<<endl;
        play(input[key]);
    }
    return 0;
}

void up()
{
    cout<<"up!!!!"<<endl;
}

void down()
{
    cout<<"down!!!!"<<endl;
}

void left()
{
    cout<<"left!!!!"<<endl;
}

void right()
{
    cout<<"right!!!!"<<endl;
}

void shoot()
{
    cout<<"bang!!!!"<<endl;
}

void quit()
{
    cout<<"Au revior!"<<endl;
    exit(0);
}

void nothing()
{

}

void play(fptr whatToDo)
{
    whatToDo();
}

void initialize(fptr keys[])
{
    for(unsigned int i = 0; i < 127; ++i)
        keys[i] = nothing;
    keys['U'] = keys['u'] = up;
    keys['D'] = keys['d'] = down;
    keys['L'] = keys['l'] = left;
    keys['R'] = keys['r'] = right;
    keys['Q'] = keys['q'] = quit;
    keys[' '] = keys['e'] = shoot;
}
