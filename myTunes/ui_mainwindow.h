/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *addtoLibrary;
    QAction *exit;
    QAction *sortByTitle;
    QAction *sortByArtist;
    QAction *sortByAlbum;
    QAction *sortByYear;
    QAction *addNewPlaylistMenu;
    QAction *deletePlaylistMenu;
    QAction *actionPlaylist1;
    QAction *actionPlaylist2;
    QAction *deleteCurrentSongMenu;
    QAction *clearPlaylistMenu;
    QAction *about;
    QWidget *outerPanel;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *control;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout;
    QLabel *timeLabel;
    QProgressBar *progressBar;
    QHBoxLayout *horizontalLayout_6;
    QGridLayout *gridLayout;
    QPushButton *stopButton;
    QPushButton *pauseButton;
    QPushButton *rewindButton;
    QPushButton *previousButton;
    QPushButton *forwardButton;
    QPushButton *nextButton;
    QPushButton *playButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QPushButton *volumeButton;
    QVBoxLayout *verticalLayout_2;
    QSlider *volume;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *deviceListLabel;
    QComboBox *deviceList;
    QLabel *playBackSpeedLabel;
    QSlider *playBackSpeedSlider;
    QLabel *label_2;
    QRadioButton *noneRadioButton;
    QRadioButton *loopRadioButton;
    QRadioButton *shuffleRadioButton;
    QLabel *balanceLabel;
    QVBoxLayout *verticalLayout_8;
    QLabel *label;
    QSlider *balance;
    QLabel *label_4;
    QTableWidget *playlist;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *fileMenu;
    QMenu *menuSort;
    QMenu *menuPlayList;
    QMenu *loadPlaylistMenu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(1026, 723);
        MainWindow->setMouseTracking(true);
        MainWindow->setFocusPolicy(Qt::ClickFocus);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/64X64buttons/banana.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(true);
        MainWindow->setDockOptions(QMainWindow::AllowNestedDocks|QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks|QMainWindow::ForceTabbedDocks|QMainWindow::GroupedDragging|QMainWindow::VerticalTabs);
        MainWindow->setUnifiedTitleAndToolBarOnMac(true);
        addtoLibrary = new QAction(MainWindow);
        addtoLibrary->setObjectName(QStringLiteral("addtoLibrary"));
        exit = new QAction(MainWindow);
        exit->setObjectName(QStringLiteral("exit"));
        sortByTitle = new QAction(MainWindow);
        sortByTitle->setObjectName(QStringLiteral("sortByTitle"));
        sortByArtist = new QAction(MainWindow);
        sortByArtist->setObjectName(QStringLiteral("sortByArtist"));
        sortByAlbum = new QAction(MainWindow);
        sortByAlbum->setObjectName(QStringLiteral("sortByAlbum"));
        sortByYear = new QAction(MainWindow);
        sortByYear->setObjectName(QStringLiteral("sortByYear"));
        addNewPlaylistMenu = new QAction(MainWindow);
        addNewPlaylistMenu->setObjectName(QStringLiteral("addNewPlaylistMenu"));
        deletePlaylistMenu = new QAction(MainWindow);
        deletePlaylistMenu->setObjectName(QStringLiteral("deletePlaylistMenu"));
        actionPlaylist1 = new QAction(MainWindow);
        actionPlaylist1->setObjectName(QStringLiteral("actionPlaylist1"));
        actionPlaylist2 = new QAction(MainWindow);
        actionPlaylist2->setObjectName(QStringLiteral("actionPlaylist2"));
        deleteCurrentSongMenu = new QAction(MainWindow);
        deleteCurrentSongMenu->setObjectName(QStringLiteral("deleteCurrentSongMenu"));
        clearPlaylistMenu = new QAction(MainWindow);
        clearPlaylistMenu->setObjectName(QStringLiteral("clearPlaylistMenu"));
        about = new QAction(MainWindow);
        about->setObjectName(QStringLiteral("about"));
        outerPanel = new QWidget(MainWindow);
        outerPanel->setObjectName(QStringLiteral("outerPanel"));
        verticalLayout = new QVBoxLayout(outerPanel);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        control = new QHBoxLayout();
        control->setSpacing(6);
        control->setObjectName(QStringLiteral("control"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        timeLabel = new QLabel(outerPanel);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(timeLabel->sizePolicy().hasHeightForWidth());
        timeLabel->setSizePolicy(sizePolicy);
        timeLabel->setMinimumSize(QSize(100, 40));
        timeLabel->setMaximumSize(QSize(100, 40));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        timeLabel->setFont(font);

        horizontalLayout->addWidget(timeLabel);

        progressBar = new QProgressBar(outerPanel);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setMaximum(1000);
        progressBar->setValue(0);

        horizontalLayout->addWidget(progressBar);


        verticalLayout_7->addLayout(horizontalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        stopButton = new QPushButton(outerPanel);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setMinimumSize(QSize(64, 64));
        stopButton->setMaximumSize(QSize(64, 64));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/64X64buttons/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        stopButton->setIcon(icon1);
        stopButton->setIconSize(QSize(50, 50));

        gridLayout->addWidget(stopButton, 1, 6, 1, 1);

        pauseButton = new QPushButton(outerPanel);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));
        pauseButton->setMinimumSize(QSize(64, 64));
        pauseButton->setMaximumSize(QSize(64, 64));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/64X64buttons/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        pauseButton->setIcon(icon2);
        pauseButton->setIconSize(QSize(50, 50));

        gridLayout->addWidget(pauseButton, 1, 8, 1, 1);

        rewindButton = new QPushButton(outerPanel);
        rewindButton->setObjectName(QStringLiteral("rewindButton"));
        sizePolicy.setHeightForWidth(rewindButton->sizePolicy().hasHeightForWidth());
        rewindButton->setSizePolicy(sizePolicy);
        rewindButton->setMinimumSize(QSize(64, 64));
        rewindButton->setMaximumSize(QSize(64, 64));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/64X64buttons/rewind.png"), QSize(), QIcon::Normal, QIcon::Off);
        rewindButton->setIcon(icon3);
        rewindButton->setIconSize(QSize(50, 50));

        gridLayout->addWidget(rewindButton, 1, 1, 1, 1);

        previousButton = new QPushButton(outerPanel);
        previousButton->setObjectName(QStringLiteral("previousButton"));
        previousButton->setMinimumSize(QSize(64, 64));
        previousButton->setMaximumSize(QSize(64, 64));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/64X64buttons/previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        previousButton->setIcon(icon4);
        previousButton->setIconSize(QSize(40, 40));

        gridLayout->addWidget(previousButton, 1, 0, 1, 1);

        forwardButton = new QPushButton(outerPanel);
        forwardButton->setObjectName(QStringLiteral("forwardButton"));
        forwardButton->setMinimumSize(QSize(64, 64));
        forwardButton->setMaximumSize(QSize(64, 64));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/64X64buttons/forward.png"), QSize(), QIcon::Normal, QIcon::Off);
        forwardButton->setIcon(icon5);
        forwardButton->setIconSize(QSize(50, 50));

        gridLayout->addWidget(forwardButton, 1, 11, 1, 1);

        nextButton = new QPushButton(outerPanel);
        nextButton->setObjectName(QStringLiteral("nextButton"));
        nextButton->setMinimumSize(QSize(64, 64));
        nextButton->setMaximumSize(QSize(64, 64));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/new/64X64buttons/skip.png"), QSize(), QIcon::Normal, QIcon::Off);
        nextButton->setIcon(icon6);
        nextButton->setIconSize(QSize(40, 40));

        gridLayout->addWidget(nextButton, 1, 16, 1, 1);

        playButton = new QPushButton(outerPanel);
        playButton->setObjectName(QStringLiteral("playButton"));
        playButton->setMinimumSize(QSize(64, 64));
        playButton->setMaximumSize(QSize(64, 64));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/new/64X64buttons/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        playButton->setIcon(icon7);
        playButton->setIconSize(QSize(50, 50));

        gridLayout->addWidget(playButton, 1, 7, 1, 1);


        horizontalLayout_6->addLayout(gridLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_5 = new QLabel(outerPanel);
        label_5->setObjectName(QStringLiteral("label_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setMinimumSize(QSize(250, 64));
        label_5->setMaximumSize(QSize(1500, 64));

        horizontalLayout_2->addWidget(label_5);


        horizontalLayout_6->addLayout(horizontalLayout_2);

        volumeButton = new QPushButton(outerPanel);
        volumeButton->setObjectName(QStringLiteral("volumeButton"));
        sizePolicy.setHeightForWidth(volumeButton->sizePolicy().hasHeightForWidth());
        volumeButton->setSizePolicy(sizePolicy);
        volumeButton->setMinimumSize(QSize(64, 64));
        volumeButton->setMaximumSize(QSize(64, 64));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/new/64X64buttons/volume.png"), QSize(), QIcon::Normal, QIcon::Off);
        volumeButton->setIcon(icon8);
        volumeButton->setIconSize(QSize(64, 64));

        horizontalLayout_6->addWidget(volumeButton);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        volume = new QSlider(outerPanel);
        volume->setObjectName(QStringLiteral("volume"));
        sizePolicy.setHeightForWidth(volume->sizePolicy().hasHeightForWidth());
        volume->setSizePolicy(sizePolicy);
        volume->setMinimumSize(QSize(200, 40));
        volume->setMaximumSize(QSize(200, 40));
        volume->setContextMenuPolicy(Qt::DefaultContextMenu);
        volume->setLayoutDirection(Qt::LeftToRight);
        volume->setMaximum(101);
        volume->setSingleStep(1);
        volume->setPageStep(25);
        volume->setSliderPosition(0);
        volume->setTracking(true);
        volume->setOrientation(Qt::Horizontal);
        volume->setInvertedAppearance(false);
        volume->setInvertedControls(false);
        volume->setTickPosition(QSlider::TicksAbove);
        volume->setTickInterval(25);

        verticalLayout_2->addWidget(volume);

        label_3 = new QLabel(outerPanel);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(200, 15));
        label_3->setMaximumSize(QSize(200, 15));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_2->addWidget(label_3);


        horizontalLayout_6->addLayout(verticalLayout_2);


        verticalLayout_7->addLayout(horizontalLayout_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        deviceListLabel = new QLabel(outerPanel);
        deviceListLabel->setObjectName(QStringLiteral("deviceListLabel"));
        sizePolicy.setHeightForWidth(deviceListLabel->sizePolicy().hasHeightForWidth());
        deviceListLabel->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        deviceListLabel->setFont(font1);
        deviceListLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(deviceListLabel);

        deviceList = new QComboBox(outerPanel);
        deviceList->setObjectName(QStringLiteral("deviceList"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(deviceList->sizePolicy().hasHeightForWidth());
        deviceList->setSizePolicy(sizePolicy2);
        deviceList->setMinimumSize(QSize(125, 25));
        deviceList->setMaximumSize(QSize(1500, 25));
        deviceList->setFocusPolicy(Qt::ClickFocus);
        deviceList->setEditable(true);

        horizontalLayout_8->addWidget(deviceList);

        playBackSpeedLabel = new QLabel(outerPanel);
        playBackSpeedLabel->setObjectName(QStringLiteral("playBackSpeedLabel"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(playBackSpeedLabel->sizePolicy().hasHeightForWidth());
        playBackSpeedLabel->setSizePolicy(sizePolicy3);
        playBackSpeedLabel->setMinimumSize(QSize(45, 30));
        playBackSpeedLabel->setMaximumSize(QSize(45, 30));
        playBackSpeedLabel->setFont(font);
        playBackSpeedLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_8->addWidget(playBackSpeedLabel);

        playBackSpeedSlider = new QSlider(outerPanel);
        playBackSpeedSlider->setObjectName(QStringLiteral("playBackSpeedSlider"));
        sizePolicy.setHeightForWidth(playBackSpeedSlider->sizePolicy().hasHeightForWidth());
        playBackSpeedSlider->setSizePolicy(sizePolicy);
        playBackSpeedSlider->setMinimumSize(QSize(30, 60));
        playBackSpeedSlider->setMaximumSize(QSize(30, 60));
        playBackSpeedSlider->setMinimum(0);
        playBackSpeedSlider->setMaximum(20);
        playBackSpeedSlider->setValue(10);
        playBackSpeedSlider->setOrientation(Qt::Vertical);
        playBackSpeedSlider->setTickPosition(QSlider::TicksBothSides);
        playBackSpeedSlider->setTickInterval(5);

        horizontalLayout_8->addWidget(playBackSpeedSlider);

        label_2 = new QLabel(outerPanel);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(100, 0));
        label_2->setMaximumSize(QSize(100, 16777215));
        label_2->setFont(font);
        label_2->setLayoutDirection(Qt::RightToLeft);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_2);

        noneRadioButton = new QRadioButton(outerPanel);
        noneRadioButton->setObjectName(QStringLiteral("noneRadioButton"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(noneRadioButton->sizePolicy().hasHeightForWidth());
        noneRadioButton->setSizePolicy(sizePolicy4);
        noneRadioButton->setMinimumSize(QSize(60, 30));
        noneRadioButton->setMaximumSize(QSize(60, 30));
        QFont font2;
        font2.setBold(false);
        font2.setWeight(50);
        noneRadioButton->setFont(font2);
        noneRadioButton->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_8->addWidget(noneRadioButton);

        loopRadioButton = new QRadioButton(outerPanel);
        loopRadioButton->setObjectName(QStringLiteral("loopRadioButton"));
        sizePolicy4.setHeightForWidth(loopRadioButton->sizePolicy().hasHeightForWidth());
        loopRadioButton->setSizePolicy(sizePolicy4);
        loopRadioButton->setMinimumSize(QSize(75, 30));
        loopRadioButton->setMaximumSize(QSize(75, 30));
        loopRadioButton->setFont(font2);
        loopRadioButton->setLayoutDirection(Qt::LeftToRight);
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/new/64X64buttons/loop.png"), QSize(), QIcon::Normal, QIcon::Off);
        loopRadioButton->setIcon(icon9);
        loopRadioButton->setIconSize(QSize(45, 30));

        horizontalLayout_8->addWidget(loopRadioButton);

        shuffleRadioButton = new QRadioButton(outerPanel);
        shuffleRadioButton->setObjectName(QStringLiteral("shuffleRadioButton"));
        sizePolicy4.setHeightForWidth(shuffleRadioButton->sizePolicy().hasHeightForWidth());
        shuffleRadioButton->setSizePolicy(sizePolicy4);
        shuffleRadioButton->setMinimumSize(QSize(75, 30));
        shuffleRadioButton->setMaximumSize(QSize(75, 30));
        shuffleRadioButton->setFont(font2);
        shuffleRadioButton->setLayoutDirection(Qt::LeftToRight);
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/new/64X64buttons/random.png"), QSize(), QIcon::Normal, QIcon::Off);
        shuffleRadioButton->setIcon(icon10);
        shuffleRadioButton->setIconSize(QSize(45, 30));

        horizontalLayout_8->addWidget(shuffleRadioButton);

        balanceLabel = new QLabel(outerPanel);
        balanceLabel->setObjectName(QStringLiteral("balanceLabel"));
        sizePolicy.setHeightForWidth(balanceLabel->sizePolicy().hasHeightForWidth());
        balanceLabel->setSizePolicy(sizePolicy);
        balanceLabel->setMinimumSize(QSize(55, 30));
        balanceLabel->setMaximumSize(QSize(55, 16777215));
        balanceLabel->setFont(font);
        balanceLabel->setLayoutDirection(Qt::LeftToRight);
        balanceLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_8->addWidget(balanceLabel);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label = new QLabel(outerPanel);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMaximumSize(QSize(0, 16777215));

        verticalLayout_8->addWidget(label);

        balance = new QSlider(outerPanel);
        balance->setObjectName(QStringLiteral("balance"));
        sizePolicy.setHeightForWidth(balance->sizePolicy().hasHeightForWidth());
        balance->setSizePolicy(sizePolicy);
        balance->setMinimumSize(QSize(200, 20));
        balance->setMaximumSize(QSize(200, 20));
        balance->setMinimum(-50);
        balance->setMaximum(50);
        balance->setOrientation(Qt::Horizontal);
        balance->setTickPosition(QSlider::TicksBelow);

        verticalLayout_8->addWidget(balance);

        label_4 = new QLabel(outerPanel);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(200, 15));
        label_4->setMaximumSize(QSize(200, 15));

        verticalLayout_8->addWidget(label_4);


        horizontalLayout_8->addLayout(verticalLayout_8);


        verticalLayout_7->addLayout(horizontalLayout_8);


        control->addLayout(verticalLayout_7);


        verticalLayout->addLayout(control);

        playlist = new QTableWidget(outerPanel);
        if (playlist->columnCount() < 4)
            playlist->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        playlist->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        playlist->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        playlist->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        playlist->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        playlist->setObjectName(QStringLiteral("playlist"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(playlist->sizePolicy().hasHeightForWidth());
        playlist->setSizePolicy(sizePolicy5);
        playlist->setMinimumSize(QSize(100, 100));
        playlist->setMaximumSize(QSize(1920, 1080));

        verticalLayout->addWidget(playlist);

        MainWindow->setCentralWidget(outerPanel);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1026, 22));
        fileMenu = new QMenu(menuBar);
        fileMenu->setObjectName(QStringLiteral("fileMenu"));
        menuSort = new QMenu(menuBar);
        menuSort->setObjectName(QStringLiteral("menuSort"));
        menuPlayList = new QMenu(menuBar);
        menuPlayList->setObjectName(QStringLiteral("menuPlayList"));
        loadPlaylistMenu = new QMenu(menuPlayList);
        loadPlaylistMenu->setObjectName(QStringLiteral("loadPlaylistMenu"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(fileMenu->menuAction());
        menuBar->addAction(menuSort->menuAction());
        menuBar->addAction(menuPlayList->menuAction());
        fileMenu->addAction(addtoLibrary);
        fileMenu->addAction(about);
        fileMenu->addAction(exit);
        menuSort->addAction(sortByTitle);
        menuSort->addAction(sortByArtist);
        menuSort->addAction(sortByAlbum);
        menuSort->addAction(sortByYear);
        menuPlayList->addAction(addNewPlaylistMenu);
        menuPlayList->addAction(loadPlaylistMenu->menuAction());
        menuPlayList->addAction(deleteCurrentSongMenu);
        menuPlayList->addAction(clearPlaylistMenu);
        menuPlayList->addAction(deletePlaylistMenu);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "myTunes", Q_NULLPTR));
        addtoLibrary->setText(QApplication::translate("MainWindow", "Add To Library", Q_NULLPTR));
        exit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        sortByTitle->setText(QApplication::translate("MainWindow", "By Title", Q_NULLPTR));
        sortByArtist->setText(QApplication::translate("MainWindow", "By Artist", Q_NULLPTR));
        sortByAlbum->setText(QApplication::translate("MainWindow", "By Album", Q_NULLPTR));
        sortByYear->setText(QApplication::translate("MainWindow", "By Year", Q_NULLPTR));
        addNewPlaylistMenu->setText(QApplication::translate("MainWindow", "Add New Playlist", Q_NULLPTR));
        deletePlaylistMenu->setText(QApplication::translate("MainWindow", "Delete Current Playlist", Q_NULLPTR));
        actionPlaylist1->setText(QApplication::translate("MainWindow", "playlist1", Q_NULLPTR));
        actionPlaylist2->setText(QApplication::translate("MainWindow", "playlist2", Q_NULLPTR));
        deleteCurrentSongMenu->setText(QApplication::translate("MainWindow", "Delete Current Song", Q_NULLPTR));
        clearPlaylistMenu->setText(QApplication::translate("MainWindow", "Clear the Current Playlist", Q_NULLPTR));
        about->setText(QApplication::translate("MainWindow", "About", Q_NULLPTR));
        timeLabel->setText(QApplication::translate("MainWindow", "00:00 - 00:00", Q_NULLPTR));
        progressBar->setFormat(QString());
        pauseButton->setText(QString());
        rewindButton->setText(QString());
        previousButton->setText(QString());
        forwardButton->setText(QString());
        nextButton->setText(QString());
        playButton->setText(QString());
        label_5->setText(QString());
        volumeButton->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "0         25         50         75       100", Q_NULLPTR));
        deviceListLabel->setText(QApplication::translate("MainWindow", "Device List", Q_NULLPTR));
        playBackSpeedLabel->setText(QApplication::translate("MainWindow", "1.0X", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Play mode:", Q_NULLPTR));
        noneRadioButton->setText(QApplication::translate("MainWindow", "None", Q_NULLPTR));
        loopRadioButton->setText(QString());
        shuffleRadioButton->setText(QString());
        balanceLabel->setText(QApplication::translate("MainWindow", "                                         Balance", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "-50                     0                     50", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = playlist->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Title", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = playlist->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Artist", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = playlist->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Year", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = playlist->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Album", Q_NULLPTR));
        fileMenu->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuSort->setTitle(QApplication::translate("MainWindow", "Sort Playlist", Q_NULLPTR));
        menuPlayList->setTitle(QApplication::translate("MainWindow", "Playlist Managment", Q_NULLPTR));
        loadPlaylistMenu->setTitle(QApplication::translate("MainWindow", "Load A Playlist", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
