/*
 * 全屏预览窗
 *
*/

#include "components/todayspic.h"
#include "ui_todayspic.h"

TodaysPic::TodaysPic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TodaysPic)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    move(0,0);
    setGeometry(0,0,QApplication::desktop()->width(),QApplication::desktop()->height());
//    setFocus();
}

TodaysPic::~TodaysPic()
{
    delete ui;
}

/*
 * 预览今日壁纸，用label窗件承载，label自适应屏幕大小
 * 考虑到屏幕分辨率差异，放大缩小图像，自适应屏幕尺寸
*/
void TodaysPic::preview(QString filePath)
{
    QPixmap picture(filePath);
    picture = picture.scaled(QApplication::desktop()->width(),QApplication::desktop()->height());
    ui->label->setPixmap(picture);
    ui->label->setGeometry(0,0,QApplication::desktop()->width(),QApplication::desktop()->height());
    show();
}

void TodaysPic::mouseMoveEvent(QMouseEvent *event)
{
    if (movable && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - mousePoint);
        event->accept();
    }
}

void TodaysPic::mousePressEvent(QMouseEvent *event)
{
    movable = false;
    if (ui->label->geometry().contains(event->pos()))
    {
        movable = true;
        mousePoint = event->globalPos() - this->pos();
    }
}

void TodaysPic::mouseReleaseEvent(QMouseEvent *event)
{
    movable = false;
}
