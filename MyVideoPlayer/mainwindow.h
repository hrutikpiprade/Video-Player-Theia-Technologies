// mainwindow.h

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMultimedia>
#include <QtMultimediaWidgets>
#include <QAudioOutput>
#include <QFileDialog>
#include <QStyle>
#include <QTime>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class OverlayWidget : public QWidget {
    Q_OBJECT
public:
    OverlayWidget(QWidget *parent = nullptr) : QWidget(parent) {}

    void setLogo(const QPixmap &logo) {
        m_logo = logo;
        update();
    }

protected:
    void paintEvent(QPaintEvent *event) override {
        Q_UNUSED(event);
        QPainter painter(this);
        painter.setOpacity(0.5); // Set the opacity of the overlay
        painter.drawPixmap(rect(), m_logo, m_logo.rect()); // Draw the logo pixmap
    }

private:
    QPixmap m_logo;
};

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void durationChanged(qint64 duration);
    void positionChanged(qint64 position);
    void on_actionOpen_triggered();
    void on_horizontalSlider_Duration_valueChanged(int value);
    void on_pushButton_Play_Pause_clicked();
    void on_pushButton_Stop_clicked();
    void on_pushButton_Volume_clicked();
    void on_horizontalSlider_Volume_valueChanged(int value);
    void on_pushButton_Seek_Backward_clicked();
    void on_pushButton_Seek_Forward_clicked();

protected:
    void mouseDoubleClickEvent(QMouseEvent *event) override;

private:
    Ui::MainWindow *ui;
    QMediaPlayer *Player;
    QVideoWidget *Video;
    QAudioOutput *AudioOutput;
    qint64 mDuration;
    bool IS_Pause = true;
    bool IS_Muted = false;
    OverlayWidget *m_overlayWidget;

    void updateDuration(qint64 Duration);
};

#endif // MAINWINDOW_H
