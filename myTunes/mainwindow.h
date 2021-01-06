#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/*******************************************************************************
*******************************************************************************/
#include <QApplication>
#include <QDesktopWidget>
#include <QFileDialog>
#include <QMainWindow>
#include <QRect>
#include <QStringList>
#include <QFont>
#include <QInputDialog>
#include <QMessageBox>
#include <QMenu>
#include <QAction>
#include <QCloseEvent>
#include <QDebug>
#include <QStringListModel>
#include <QTableWidgetItem>
#include <QFileDialog>
/*******************************************************************************
*******************************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <ctime>
/*******************************************************************************
*******************************************************************************/
#include "musicengine.h"
#include "songinfo.h"
#include "getmp3.h"


enum playMode {none = 404, shuffle = 505 , loop = 606};

namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

public slots:
    void endProgram();
    void musicPlaying(size_t volume, size_t time);
    void playNextSong();
    void playPrevSong();
    void changeVolumeIcon();
    void playItemAtRow(QModelIndex i);
    void playItemAtIndex(const int &i);
    void setVol(const int &vol);
    void askToChoose();
    void updateProgessBar();
    void loadSongsToTable();
    void loadSongsFromFile(string playlistName);
    void savePlaylistToFile(string path);
    void sortTitle();
    void sortArtist();
    void sortAlbum();
    void sortYear();
    void shuffle();
    void loop();
    void none();
    void makeNewPlaylist();
    void makeSlotForQAction(QAction *triggeredAction);
    void deletePlaylist();
    void stop();
    void changeSongInfo(const int row, const int col);
    void deleteCurrentSong();
    void clickARowOnce(const QModelIndex &index);
    void deleteAllSongs();
    void play();
    void setPlayBackSpeed(const int &i);
    void displayInfo();

private:
    Ui::MainWindow *ui;
    musicEngine *engine;
    vector<songInfo> list;
    getMp3 readMp3;
    QStringListModel *model;
    QIcon volumeIcon, muteIcon;
    QTimer *timer;
    vector<string> playlists;
    int currentSongIndex = -1 ,currentVolume;
    string currentPlaylist;
    const string defaultPlaylist = "Default_Playlist.txt";
    const string fileContainsPlaylists = "playlists.txt";
    int mode;
    void closeEvent(QCloseEvent *event);
    void setupSignalsSlots();
    void setupUI();
    void setDeviceList();
    void loadingIcons();
    void makeUIForPlaylists(const string &name);
    void addPlaylistToFile(const string &fileName);
    void reValidatePlaylists();
    void playRandomSong();
};

#endif // MAINWINDOW_H
