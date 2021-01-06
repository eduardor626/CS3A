#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::loadSongsToTable()
{
    ui->playlist->setRowCount(list.size());
    for ( size_t i = 0 ; i < list.size() ; ++i)
    {
        QTableWidgetItem *col1 =  new QTableWidgetItem(QString::fromStdString(list[i].getTitle()), 20);
        ui->playlist->setItem(i,0,col1 );
        QTableWidgetItem *col2 =  new QTableWidgetItem(QString::fromStdString(list[i].getArtist()), 20);
        ui->playlist->setItem(i,1,col2 );
        QTableWidgetItem *col3 =  new QTableWidgetItem(QString::fromStdString(list[i].getYear()), 20);
        ui->playlist->setItem(i,2,col3 );
        QTableWidgetItem *col4 =  new QTableWidgetItem(QString::fromStdString(list[i].getAlbum()), 20);
        ui->playlist->setItem(i,3,col4 );
        col1 = col2 = col3 = col4 = NULL;
    }
}

void MainWindow::addPlaylistToFile(const string &fileName)
{
    ofstream out;
    out.open(fileContainsPlaylists, ios_base::app);
    out <<endl<< fileName << endl;
    out.close();
}

void MainWindow::reValidatePlaylists()
{
    ofstream out;
    out.open(fileContainsPlaylists);
    for (unsigned int i = 0 ; i < playlists.size() ; ++i)
        out << playlists[i] << endl;
    out.close();
    makeUIForPlaylists(fileContainsPlaylists);
}

void MainWindow::deletePlaylist()
{
    if (currentPlaylist == defaultPlaylist)
    {
        QMessageBox::information(this, "Warning",
                                 "You can't delete default playlist.",QMessageBox::Ok);
        return;
    }

    QMessageBox::StandardButton input = QMessageBox::question(this, "Warning! ",
                          "Please confirm: ", QMessageBox::Yes|QMessageBox::No);
    if (input == QMessageBox::Yes) {
        stop();
        for (unsigned int i = 0 ; i < playlists.size() ; ++i)
        {
            if (playlists[i] == currentPlaylist)
            {
                playlists.erase( playlists.begin() + i);
                break;
            }
        }
        reValidatePlaylists();
        currentPlaylist = defaultPlaylist;
        list.clear();
        loadSongsFromFile(currentPlaylist);
    }
}

void MainWindow::makeNewPlaylist()
{
    bool exist = false;
    QString fileName = QInputDialog::getText(this, "Message", "Enter name of new playlist:", QLineEdit::Normal,
                                             "", NULL);
    string s = fileName.toStdString();

    if (s.empty())
        return;
    else if (s.find(".txt") > s.size())
        s +=".txt";

    for (unsigned int i = 0 ; i < playlists.size() ; ++i)
    {
        if (s.find(playlists[i]) < s.size())
        {
            exist = true;
            break;
        }
    }

    if (exist)
    {
        QMessageBox::information(this, "Playlist already exists", "Playlist already exists", QMessageBox::Ok);
        return;
    }else
    {
        playlists.push_back(s);
        reValidatePlaylists();
    }
    stop();
    list.clear();
    currentPlaylist = s;
    for (int i = ui->playlist->rowCount() ; i >= 0   ;i--)
        ui->playlist->removeRow(i);
}

void MainWindow::savePlaylistToFile(string path)
{
    ofstream out;
    out.open(path);
    if (out.is_open())
    {
        for (unsigned int i = 0 ; i < list.size() ; ++i)
        {
            out<<list[i].getTitle()<<endl;
            out<<list[i].getArtist()<<endl;
            out<<list[i].getYear()<<endl;
            out<<list[i].getAlbum()<<endl;
            out<<list[i].getDirectory()<<endl;
        }
        out.close();
    }
}

void MainWindow::makeUIForPlaylists(const string &name)
{
    ui->loadPlaylistMenu->clear();
    ifstream in;
    string line;
    in.open(name);
    if (in.is_open())
    {
        QActionGroup* groupAction = new QActionGroup(ui->loadPlaylistMenu);
        while(getline(in, line))
        {
            if (!line.empty())
            {
                groupAction->addAction( ui->loadPlaylistMenu->
                                     addAction(QString::fromStdString(line)))->setData(QString::fromStdString(line));
                if (std::find(playlists.begin(), playlists.end(), line) == playlists.end())
                    playlists.push_back(line);
            }
        }
        connect(groupAction, SIGNAL(triggered(QAction*)), this, SLOT(makeSlotForQAction(QAction*)));
    }
    in.close();
}
