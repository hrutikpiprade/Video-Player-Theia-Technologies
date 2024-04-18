
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Player = new QMediaPlayer();
    AudioOutput = new QAudioOutput;
    Player->setAudioOutput(AudioOutput);

    ui->pushButton_Play_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->pushButton_Stop->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
    ui->pushButton_Seek_Backward->setIcon(style()->standardIcon(QStyle::SP_MediaSeekBackward));
    ui->pushButton_Seek_Forward->setIcon(style()->standardIcon(QStyle::SP_MediaSeekForward));
    ui->pushButton_Volume->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
    ui->horizontalSlider_Volume->setMinimum(0);
    ui->horizontalSlider_Volume->setMaximum(100);
    ui->horizontalSlider_Volume->setValue(30);
    AudioOutput->setVolume(ui->horizontalSlider_Volume->value());

    connect(Player, &QMediaPlayer::durationChanged, this, &MainWindow::durationChanged);
    connect(Player, &QMediaPlayer::positionChanged, this, &MainWindow::positionChanged);

    ui->horizontalSlider_Duration->setRange(0, Player->duration() / 1000);

    // Create overlay widget
    m_overlayWidget = new OverlayWidget(ui->groupBox_Video); // Assuming groupBox_Video is your video display widget
    m_overlayWidget->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::durationChanged(qint64 duration)
{
    mDuration = duration / 1000;
    ui->horizontalSlider_Duration->setMaximum(mDuration);
}

void MainWindow::positionChanged(qint64 duration)
{
    if (!ui->horizontalSlider_Duration->isSliderDown()) {
        ui->horizontalSlider_Duration->setValue(duration / 1000);
    }
    updateDuration(duration / 1000);
}

void MainWindow::updateDuration(qint64 Duration)
{
    if (Duration || mDuration) {
        int hours = Duration / 3600;
        int minutes = (Duration / 60) % 60;
        int seconds = Duration % 60;

        QString format;
        if (mDuration > 3600)
            format = "hh:mm:ss";
        else
            format = "mm:ss";

        QTime CurrentTime(hours, minutes, seconds);
        QTime TotalTime(mDuration / 3600, (mDuration / 60) % 60, mDuration % 60);

        ui->label_current_Time->setText(CurrentTime.toString(format));
        ui->label_Total_Time->setText(TotalTime.toString(format));
    }
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select Video File"), "", tr("MP4 Files (*.mp4)"));
    if (!fileName.isEmpty()) {
        // Create a new video widget and set its geometry
        Video = new QVideoWidget();
        Video->setGeometry(5, 5, ui->groupBox_Video->width() - 10, ui->groupBox_Video->height() - 10);
        Video->setParent(ui->groupBox_Video);

        // Set the video output for the player and load the video file
        Player->setVideoOutput(Video);
        Player->setSource(QUrl::fromLocalFile(fileName));

        // Make the video widget visible
        Video->setVisible(true);
        Video->show();
    }
}

void MainWindow::on_pushButton_Play_Pause_clicked()
{
    if (IS_Pause) {
        IS_Pause = false;
        Player->play();
        ui->pushButton_Play_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
        m_overlayWidget->hide(); // Hide overlay when playing
    } else {
        IS_Pause = true;
        Player->pause();
        ui->pushButton_Play_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
        m_overlayWidget->setLogo(QPixmap("C:\\Users\\Hi\\Downloads\\logo.png")); // Set overlay logo
        m_overlayWidget->show(); // Show overlay when paused
    }
}

void MainWindow::on_pushButton_Stop_clicked()
{
    Player->stop();
}

void MainWindow::on_pushButton_Volume_clicked()
{
    if (IS_Muted == false) {
        IS_Muted = true;
        ui->pushButton_Volume->setIcon(style()->standardIcon(QStyle::SP_MediaVolumeMuted));
        // Mute the player by setting volume to 0
        AudioOutput->setMuted(true);
    } else {
        IS_Muted = false;
        ui->pushButton_Volume->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
        // Restore the volume to the previous level or a default level
        AudioOutput->setMuted(false); // You may replace DEFAULT_VOLUME with your desired non-zero volume value
    }
}

void MainWindow::on_horizontalSlider_Volume_valueChanged(int value)
{
    AudioOutput->setVolume(value);
}

void MainWindow::on_pushButton_Seek_Backward_clicked()
{
    ui->horizontalSlider_Duration->setValue(ui->horizontalSlider_Duration->value() - 20);
    Player->setPosition(ui->horizontalSlider_Duration->value() * 1000);
}

void MainWindow::on_pushButton_Seek_Forward_clicked()
{
    ui->horizontalSlider_Duration->setValue(ui->horizontalSlider_Duration->value() + 20);
    Player->setPosition(ui->horizontalSlider_Duration->value() * 1000);
}

void MainWindow::on_horizontalSlider_Duration_valueChanged(int value)
{
    Player->setPosition(value * 1000);
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    on_pushButton_Play_Pause_clicked(); // Toggle play/pause on double-click
}
