#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::endProgram()
{
    savePlaylistToFile(currentPlaylist);
    this->close();
}

void MainWindow::musicPlaying(size_t volume, size_t time)
{
    currentVolume = volume;
    ui->volume->setValue(volume);
    qDebug()<<"Volume: "<<volume<<" Time: "<<time<<endl;
}

void MainWindow::playNextSong()
{
    if (mode == playMode::shuffle)
    {
        playRandomSong();
        return;
    }

    if (currentSongIndex == (int)(list.size()-1))
        currentSongIndex = 0;
    else
        currentSongIndex++;
    playItemAtIndex(currentSongIndex);
}

void MainWindow::playPrevSong()
{
    if (mode == playMode::shuffle)
    {
        playRandomSong();
        return;
    }

    if (currentSongIndex == 0)
        currentSongIndex = list.size()-1;
    else
        currentSongIndex--;
    playItemAtIndex(currentSongIndex);
}

void MainWindow::changeVolumeIcon()
{
    if (ui->volume->value() != 0)
    {
        currentVolume = ui->volume->value();
        ui->volume->setValue(0);
    }else
    {
        ui->volume->setValue(currentVolume);
        setVol(currentVolume);
    }
}

void MainWindow::playItemAtRow(QModelIndex i)
{
    playItemAtIndex(i.row());
}

void MainWindow::playItemAtIndex(const int &i)
{
    currentSongIndex = i;
    ui->playBackSpeedSlider->setValue(10);
    ui->playlist->selectRow(i);
    engine->setWhatToPlay(list.at(i).getDirectory());
    engine->play();
}

void MainWindow::setVol(const int &vol)
{
    if (vol != 0 )
    {
        ui->volumeButton->setIcon(volumeIcon);
        currentVolume = vol;
    }
    else
        ui->volumeButton->setIcon(muteIcon);
    engine->setVolume(vol);
}

void MainWindow::askToChoose()
{
    QStringList fileNames = QFileDialog::getOpenFileNames(this, "Open File", "/user", "");
    vector<string> temp;
    for (int i = 0 ; i < fileNames.size() ; ++i)
        temp.push_back(fileNames.at(i).toLocal8Bit().constData());
    readMp3.readFolder(temp, list);
    loadSongsToTable();
}

void MainWindow::updateProgessBar()
{
    if(currentSongIndex != -1 && engine->getPlayingProgess() != -1)
    {
        int val = engine->getPlayingProgess();
        if (val >= 997 &&  (mode == playMode::loop || currentSongIndex != (int)list.size()-1))
        {
            playNextSong();
        }else if (val >= 997 && mode == playMode::shuffle)
        {
            playRandomSong();
        }
        else if (val >= 997 &&
                 mode == playMode::none && currentSongIndex == (int)list.size()-1)
        {
            stop();
            ui->progressBar->setValue(0);
        }else
        {
            ui->timeLabel->setText(engine->getTimeInMinute());
            ui->progressBar->setValue(val);
        }
    }
}

void MainWindow::playRandomSong()
{
    int random = (rand()%list.size());
    if (random != 0)
        random--;
    currentSongIndex = random;
    playItemAtIndex(random);
}

void MainWindow::loadSongsFromFile( string playlistName)
{
    ifstream in;
    in.open(playlistName);
    string line;
    int counter = 1;
    if (in.is_open())
    {
        songInfo inf = songInfo ("", "", "" , "" , "");
        while (getline(in,line))
        {
            if (counter%5 == 1)
                inf.setTitle(line);
            else if (counter%5 == 2)
                inf.setArtist(line);
            else if (counter%5 == 3)
                inf.setYear(line);
            else if (counter%5 == 4)
                inf.setAlbum(line);
            else if (counter%5 ==0){
                inf.setDirectory(line);
                list.push_back(inf);
            }
            counter++;
        }
        in.close();
        loadSongsToTable();
    }
}

void MainWindow::sortTitle()
{
    struct {
        bool operator()(songInfo &song1, songInfo &song2) const
        {
            return song1.getTitle() < song2.getTitle();
        }
    } byTitle;
    sort(list.begin(), list.end(), byTitle);
    loadSongsToTable();
}

void MainWindow::sortArtist()
{
    struct {
        bool operator()(songInfo &song1, songInfo &song2) const
        {
            return song1.getArtist() < song2.getArtist();
        }
    } byArtist;
    sort(list.begin(), list.end(), byArtist);
    loadSongsToTable();
}

void MainWindow::sortAlbum()
{

    struct {
        bool operator()(songInfo &song1, songInfo &song2) const
        {
            return song1.getAlbum() < song2.getAlbum();
        }
    } byAlbum;
    sort(list.begin(), list.end(), byAlbum);
    loadSongsToTable();
}

void MainWindow::sortYear()
{
    struct {
        bool operator()(songInfo &song1, songInfo &song2) const
        {
            return song1.getYear() < song2.getYear();
        }
    } byYear;
    sort(list.begin(), list.end(), byYear);
    loadSongsToTable();
}

void MainWindow::shuffle()
{
    mode = playMode::shuffle;
}

void MainWindow::loop()
{
    mode = playMode::loop;
}

void MainWindow::none()
{
    mode = playMode::none;
}

void MainWindow::makeSlotForQAction(QAction* triggeredAction)
{
    stop();
    QString qs = triggeredAction->data().toString();
    string s = qs.toStdString();
    for (int i = ui->playlist->rowCount() ; i >= 0   ;i--)
        ui->playlist->removeRow(i);
    savePlaylistToFile(currentPlaylist);
    list.clear();
    currentPlaylist = s;
    loadSongsFromFile(s);
}

void MainWindow::setDeviceList()
{
    QStringList list = engine->getDevices();
    for(int i = 0; i < list.size(); ++i)
        ui->deviceList->addItem(list[i]);
}

void MainWindow::stop()
{
    engine->stop();
    ui->progressBar->setValue(0);
    ui->timeLabel->setText("00:00 - 00:00");
}

void MainWindow::changeSongInfo(const int row, const int col)
{
    QTableWidgetItem *item = ui->playlist->item(row, col);
    QVariant variant = item->data(Qt::EditRole);
    QString qs = variant.toString();
    string s = qs.toStdString();
    switch (col)
    {
    case 0:      list.at(row).setTitle(s);
        break;
    case 1:     list.at(row).setArtist(s);
        break;
    case 2:     list.at(row).setYear(s);
        break;
    case 3:     list.at(row).setAlbum(s);
        break;
    }
}

void MainWindow::deleteCurrentSong()
{
    if (currentSongIndex == -1)
    {
        QMessageBox::information(this, "Warning",
                                 "You didn't select any song to delete. ",QMessageBox::Ok);
    }else{
        stop();
        list.erase(list.begin() + currentSongIndex );
        ui->playlist->removeRow(currentSongIndex);
    }
}

void MainWindow::clickARowOnce(const QModelIndex &index)
{
    currentSongIndex = index.row();
}

void MainWindow::deleteAllSongs()
{
    QMessageBox::StandardButton input;
    input = QMessageBox::question(this, "Warning! ", QString::fromStdString(currentPlaylist)
                                  + " will be wiped out please confirm:" , QMessageBox::Yes|QMessageBox::No);
    if (input == QMessageBox::No)
        return;
    stop();
    list.clear();
    loadSongsToTable();
}

void MainWindow::play()
{
    if (currentSongIndex == -1 && !list.empty())
    {
        playItemAtIndex(0);
        return;
    }else
        engine->play();
}

void MainWindow::setPlayBackSpeed(const int &i)
{
    engine->setPlayBackSpeed(i);
    string s = to_string(i/10) + "." + to_string(i%10) + "X";
    ui->playBackSpeedLabel->setText(QString::fromStdString(s));
}

void MainWindow::displayInfo()
{
    QMessageBox::information(this, "Infomation:", "-Project: myTunes.\n-Class: CS 3A.\n"
    "-Prof: Dr. Paul Wilkinon.\n-Authors: Vu Nguyen - Eduardo Rocha.", QMessageBox::Ok);
}

void MainWindow::loadingIcons()
{
    volumeIcon =  QIcon("volume.png");
    muteIcon =  QIcon("mute.png");
}



