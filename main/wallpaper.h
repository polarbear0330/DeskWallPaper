#ifndef WALLPAPER_H
#define WALLPAPER_H

#include "components/todayspic.h"
#include "components/switchbtn.h"
#include "data/datacenter.h"

#include <QDialog>
#include <windows.h>
#include <sstream>
#include <QtNetwork>
#include <QMouseEvent>
#include <QTimer>
#include <QThread>
#include <ctime>

namespace Ui {
class WallPaper;
}

enum STATUS
{
    NETWORK_CONNECTION_FAILED,
    URL_NOT_FOUND,
    PICTURE_DOWNLOADING,
    DOWNLOAD_FAILED,
    LOAD_FROM_DATA_FAILED,
    WALLPAPER_READY,
    COUNT_DOWN_TO_CLOSE
};

//可分成3部分：①Downloader；②TodaysPic；③setWallPaper::setWallPaper试试静态函数
class WallPaper : public QDialog
{
    Q_OBJECT

public:
    explicit WallPaper(QWidget *parent = 0);
    ~WallPaper();

public:
    void getWholeWebSource();
signals:
    void picSaved(QString filepath);
    void urlFound(QUrl url);
private slots:
    void findPicUrl(QNetworkReply* reply);
    void downloadPic(QUrl url);
    void savePic(QNetworkReply* reply);
    void on_setWallPaper_clicked();
    void textAppear();
    void countDownAndSet();
    void buttonPressed();
    void buttonReleased();

private:
    void setWallPaper_windows(QString filePath);
    void showStatusTips(STATUS status, QString errorString = "");
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    bool eventFilter(QObject *parent, QEvent *event);

private:
    Ui::WallPaper *ui;
    QNetworkAccessManager manager;
    QString filePath;
    bool movable; // to move it
    bool closable;
    QPoint mousePoint; // to move it
    TodaysPic todaysPic;
    QString text, textAppeared;
    int textAppearedNum;
    int countDownNum = 20; //注：单位是秒，毫秒要x1000
    QTimer *countTimer = new QTimer(this);
    QTimer *closeTimer = new QTimer(this);
    SwitchBtn* prev;
    SwitchBtn* next;
};

#endif // WALLPAPER_H
