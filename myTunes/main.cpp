#include "mainwindow.h"
#include "getmp3.h"
#include "songinfo.h"
#include <QApplication>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    return a.exec();
}
