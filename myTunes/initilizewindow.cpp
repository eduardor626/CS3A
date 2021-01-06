#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    engine(new musicEngine(this))
{
    ui->setupUi(this);
    timer = new QTimer(this);
    srand(time(NULL));
    setupUI();
    currentPlaylist = defaultPlaylist;
    makeUIForPlaylists(fileContainsPlaylists);
    loadSongsFromFile(currentPlaylist);
    setDeviceList();
    setupSignalsSlots();
    loadingIcons();
    ui->noneRadioButton->click();
    timer->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupUI()
{
    //VOLUME AND BALANCE
    ui->volume->setValue(engine->getVolume());
    ui->balance->setValue(engine->getBalance());
    //TABLE
    ui->playlist->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->playlist->setColumnCount(4);
    ui->playlist->horizontalHeader()->resizeSections(QHeaderView::Stretch);
    ui->playlist->horizontalHeader()->setResizeContentsPrecision(4);
    ui->playlist->horizontalHeader()->setStretchLastSection(true);
    ui->playlist->horizontalHeader()->resizeSection(0,350);
    ui->playlist->horizontalHeader()->resizeSection(1,200);
    ui->playlist->horizontalHeader()->resizeSection(2,100);
    ui->playlist->horizontalHeader()->resizeSection(3,50);
    ui->playlist->horizontalHeader()->resizeSection(3,QHeaderView::Stretch);
    //SETTING UP MENUS:
    QRect rec = QApplication::desktop()->screenGeometry();
    this->show();
    this->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    this->setGeometry(rec.width()/2-400,rec.height()/2-300,800,600);
}

void MainWindow::setupSignalsSlots()
{
    connect(ui->deviceList,SIGNAL(currentIndexChanged(int)),engine,SLOT(setDevice(int)));
    connect(ui->volume,SIGNAL(valueChanged(int)),this,SLOT(setVol(int)));
    connect (ui->volumeButton, SIGNAL(clicked(bool)),this , SLOT(changeVolumeIcon()));
    connect(ui->balance,SIGNAL(valueChanged(int)),engine,SLOT(setBalance(int)));
    connect(engine,SIGNAL(songData(size_t,size_t)),this,SLOT(musicPlaying(size_t,size_t)));
    //CONTROL
    connect(ui->playButton, SIGNAL(clicked(bool)), this, SLOT(play()));
    connect(ui->pauseButton, SIGNAL(clicked(bool)), engine, SLOT(pause()));
    connect(ui->nextButton, SIGNAL(clicked(bool)), this, SLOT(playNextSong()));
    connect(ui->previousButton, SIGNAL(clicked(bool)), this, SLOT(playPrevSong()));
    connect(ui->rewindButton, SIGNAL(clicked(bool)),engine, SLOT(rewind()));
    connect(ui->forwardButton, SIGNAL(clicked(bool)),engine, SLOT(fastForward()));
    connect(ui->stopButton, SIGNAL(clicked(bool)), this, SLOT(stop()));
    //MENUS:
    ui->menuBar->setNativeMenuBar(false);
    connect(ui->exit, SIGNAL(triggered(bool)), this, SLOT(endProgram()));
    connect(ui->addtoLibrary, SIGNAL(triggered(bool)),this, SLOT(askToChoose()));
    connect(ui->about, SIGNAL(triggered(bool)), this, SLOT(displayInfo()));
    //PLAY MODE:
    connect(ui->loopRadioButton, SIGNAL(clicked(bool)), this, SLOT(loop()));
    connect(ui->shuffleRadioButton, SIGNAL(clicked(bool)), this, SLOT(shuffle()));
    connect(ui->noneRadioButton, SIGNAL(clicked(bool)), this, SLOT(none()));
    //PROGRESS BAR:
    connect(timer, SIGNAL(timeout()),this, SLOT(updateProgessBar()));
    //PLAYBACK:
    connect(ui->playBackSpeedSlider, SIGNAL(valueChanged(int)), this,SLOT(setPlayBackSpeed(int)));
    //SORTING:
    connect (ui->sortByTitle, SIGNAL(triggered(bool)),this,SLOT(sortTitle()));
    connect (ui->sortByArtist, SIGNAL(triggered(bool)),this,SLOT(sortArtist()));
    connect (ui->sortByAlbum, SIGNAL(triggered(bool)),this,SLOT(sortAlbum()));
    connect (ui->sortByYear, SIGNAL(triggered(bool)),this,SLOT(sortYear()));
    //PLAYLIST MENU BAR:
    connect (ui->addNewPlaylistMenu, SIGNAL(triggered(bool)), this, SLOT(makeNewPlaylist()));
    connect (ui->deletePlaylistMenu, SIGNAL(triggered(bool)), this, SLOT(deletePlaylist()));
    connect(ui->deleteCurrentSongMenu, SIGNAL(triggered(bool)), this, SLOT(deleteCurrentSong()));
    //PLAYLIST:
    connect(ui->playlist, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(playItemAtRow(QModelIndex)));
    connect(ui->playlist, SIGNAL(cellChanged(int,int)), this, SLOT (changeSongInfo(int, int)));
    connect(ui->playlist, SIGNAL(clicked(QModelIndex)), this, SLOT(clickARowOnce(QModelIndex)));
    connect(ui->clearPlaylistMenu, SIGNAL(triggered(bool)), this, SLOT (deleteAllSongs()));
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    event->accept();
    this->endProgram();
}


