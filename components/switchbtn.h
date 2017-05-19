#ifndef SWITCHBTN_H
#define SWITCHBTN_H

#include "data/datacenter.h"
#include "components/todayspic.h"

#include <QDialog>
#include <QKeyEvent>

namespace Ui {
class SwitchBtn;
}

class SwitchBtn : public QDialog
{
    Q_OBJECT

public:
    explicit SwitchBtn(QString icon_name, QPoint mainWidget_pos, QSize mainWidget_size, bool isLeft, QWidget *parent = 0);
    ~SwitchBtn();
    void setTodaysPic(TodaysPic *todaysPic);

private:
    bool eventFilter(QObject *parent, QEvent *event);

private slots:
    void buttonPressed();
    void buttonReleased();
    void nextPic();
    void prevPic();
//    int currentOrder();

private:
    Ui::SwitchBtn *ui;
    TodaysPic *picWall;
};

#endif // SWITCHBTN_H
