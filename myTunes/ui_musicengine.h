/********************************************************************************
** Form generated from reading UI file 'musicengine.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSICENGINE_H
#define UI_MUSICENGINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_musicEngine
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *volumeLabel;
    QLabel *deviceListLabel;
    QLabel *balanceLabel;
    QComboBox *deviceList;
    QSlider *volume;
    QSlider *balance;

    void setupUi(QWidget *musicEngine)
    {
        if (musicEngine->objectName().isEmpty())
            musicEngine->setObjectName(QStringLiteral("musicEngine"));
        musicEngine->resize(600, 150);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(musicEngine->sizePolicy().hasHeightForWidth());
        musicEngine->setSizePolicy(sizePolicy);
        musicEngine->setMinimumSize(QSize(600, 150));
        musicEngine->setMaximumSize(QSize(600, 150));
        QFont font;
        font.setPointSize(10);
        musicEngine->setFont(font);
        gridLayoutWidget = new QWidget(musicEngine);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 581, 131));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        volumeLabel = new QLabel(gridLayoutWidget);
        volumeLabel->setObjectName(QStringLiteral("volumeLabel"));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        volumeLabel->setFont(font1);
        volumeLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(volumeLabel, 3, 1, 1, 1);

        deviceListLabel = new QLabel(gridLayoutWidget);
        deviceListLabel->setObjectName(QStringLiteral("deviceListLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(deviceListLabel->sizePolicy().hasHeightForWidth());
        deviceListLabel->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        deviceListLabel->setFont(font2);
        deviceListLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(deviceListLabel, 2, 1, 1, 1);

        balanceLabel = new QLabel(gridLayoutWidget);
        balanceLabel->setObjectName(QStringLiteral("balanceLabel"));
        balanceLabel->setFont(font1);
        balanceLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(balanceLabel, 4, 1, 1, 1);

        deviceList = new QComboBox(gridLayoutWidget);
        deviceList->setObjectName(QStringLiteral("deviceList"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(deviceList->sizePolicy().hasHeightForWidth());
        deviceList->setSizePolicy(sizePolicy2);
        deviceList->setFocusPolicy(Qt::ClickFocus);
        deviceList->setEditable(true);

        gridLayout->addWidget(deviceList, 2, 2, 1, 1);

        volume = new QSlider(gridLayoutWidget);
        volume->setObjectName(QStringLiteral("volume"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(volume->sizePolicy().hasHeightForWidth());
        volume->setSizePolicy(sizePolicy3);
        volume->setMaximum(100);
        volume->setPageStep(5);
        volume->setOrientation(Qt::Horizontal);
        volume->setTickPosition(QSlider::TicksBelow);

        gridLayout->addWidget(volume, 3, 2, 1, 1);

        balance = new QSlider(gridLayoutWidget);
        balance->setObjectName(QStringLiteral("balance"));
        sizePolicy3.setHeightForWidth(balance->sizePolicy().hasHeightForWidth());
        balance->setSizePolicy(sizePolicy3);
        balance->setMinimum(-50);
        balance->setMaximum(50);
        balance->setOrientation(Qt::Horizontal);
        balance->setTickPosition(QSlider::TicksBelow);

        gridLayout->addWidget(balance, 4, 2, 1, 1);


        retranslateUi(musicEngine);

        QMetaObject::connectSlotsByName(musicEngine);
    } // setupUi

    void retranslateUi(QWidget *musicEngine)
    {
        musicEngine->setWindowTitle(QApplication::translate("musicEngine", "Form", Q_NULLPTR));
        volumeLabel->setText(QApplication::translate("musicEngine", "Volume", Q_NULLPTR));
        deviceListLabel->setText(QApplication::translate("musicEngine", "Device List", Q_NULLPTR));
        balanceLabel->setText(QApplication::translate("musicEngine", "Balance", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class musicEngine: public Ui_musicEngine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICENGINE_H
