/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QWidget *centralwidget;
    QGroupBox *groupBox_Video;
    QStackedWidget *stackedWidget_logo;
    QWidget *page;
    QWidget *page_2;
    QPushButton *pushButton_Seek_Backward;
    QPushButton *pushButton_Play_Pause;
    QPushButton *pushButton_Stop;
    QPushButton *pushButton_Seek_Forward;
    QPushButton *pushButton_Volume;
    QSlider *horizontalSlider_Volume;
    QSlider *horizontalSlider_Duration;
    QLabel *label_current_Time;
    QLabel *label_Total_Time;
    QMenuBar *menubar;
    QMenu *menuSelect_Video_File;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox_Video = new QGroupBox(centralwidget);
        groupBox_Video->setObjectName("groupBox_Video");
        groupBox_Video->setEnabled(true);
        groupBox_Video->setGeometry(QRect(15, 5, 761, 441));
        groupBox_Video->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"	border: 1px solid black;\n"
"}"));
        stackedWidget_logo = new QStackedWidget(groupBox_Video);
        stackedWidget_logo->setObjectName("stackedWidget_logo");
        stackedWidget_logo->setGeometry(QRect(219, 119, 311, 171));
        page = new QWidget();
        page->setObjectName("page");
        stackedWidget_logo->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget_logo->addWidget(page_2);
        pushButton_Seek_Backward = new QPushButton(centralwidget);
        pushButton_Seek_Backward->setObjectName("pushButton_Seek_Backward");
        pushButton_Seek_Backward->setGeometry(QRect(30, 510, 31, 24));
        pushButton_Play_Pause = new QPushButton(centralwidget);
        pushButton_Play_Pause->setObjectName("pushButton_Play_Pause");
        pushButton_Play_Pause->setGeometry(QRect(80, 510, 31, 24));
        pushButton_Stop = new QPushButton(centralwidget);
        pushButton_Stop->setObjectName("pushButton_Stop");
        pushButton_Stop->setGeometry(QRect(130, 510, 31, 24));
        pushButton_Seek_Forward = new QPushButton(centralwidget);
        pushButton_Seek_Forward->setObjectName("pushButton_Seek_Forward");
        pushButton_Seek_Forward->setGeometry(QRect(180, 510, 31, 24));
        pushButton_Volume = new QPushButton(centralwidget);
        pushButton_Volume->setObjectName("pushButton_Volume");
        pushButton_Volume->setGeometry(QRect(630, 510, 31, 24));
        horizontalSlider_Volume = new QSlider(centralwidget);
        horizontalSlider_Volume->setObjectName("horizontalSlider_Volume");
        horizontalSlider_Volume->setGeometry(QRect(670, 510, 111, 20));
        horizontalSlider_Volume->setOrientation(Qt::Horizontal);
        horizontalSlider_Duration = new QSlider(centralwidget);
        horizontalSlider_Duration->setObjectName("horizontalSlider_Duration");
        horizontalSlider_Duration->setGeometry(QRect(80, 480, 631, 20));
        horizontalSlider_Duration->setOrientation(Qt::Horizontal);
        label_current_Time = new QLabel(centralwidget);
        label_current_Time->setObjectName("label_current_Time");
        label_current_Time->setGeometry(QRect(20, 480, 49, 16));
        label_Total_Time = new QLabel(centralwidget);
        label_Total_Time->setObjectName("label_Total_Time");
        label_Total_Time->setGeometry(QRect(730, 480, 49, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuSelect_Video_File = new QMenu(menubar);
        menuSelect_Video_File->setObjectName("menuSelect_Video_File");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuSelect_Video_File->menuAction());
        menuSelect_Video_File->addAction(actionOpen);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        groupBox_Video->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        pushButton_Seek_Backward->setText(QString());
        pushButton_Play_Pause->setText(QString());
        pushButton_Stop->setText(QString());
        pushButton_Seek_Forward->setText(QString());
        pushButton_Volume->setText(QString());
        label_current_Time->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        label_Total_Time->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        menuSelect_Video_File->setTitle(QCoreApplication::translate("MainWindow", "Select Video File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
