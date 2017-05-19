/*
 * 左右翻页键
 * 20170330计划：或许可以改成1个基类与2个派生类
 *
*/

#include "components/switchbtn.h"
#include "ui_switchbtn.h"

SwitchBtn::SwitchBtn(QString icon_name, QPoint mainWidget_pos, QSize mainWidget_size, bool isLeft, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SwitchBtn)
{
    ui->setupUi(this);

    if(isLeft)
        move(mainWidget_pos + QPoint(- width() - 50, (mainWidget_size.height() - height()) / 2));//
    else
        move(mainWidget_pos + QPoint(mainWidget_size.width() + 50, (mainWidget_size.height() - height()) / 2));//

    ui->pushButton->setIcon(QIcon(QPixmap(icon_name)));
    ui->pushButton->resize(this->size());
    ui->pushButton->setIconSize(ui->pushButton->size());
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);

    setWindowOpacity(1.0);
    setAttribute(Qt::WA_TranslucentBackground);

    QList<QPushButton*> btnList = findChildren<QPushButton*>();
    for(auto button: btnList)
    {
        connect(button, SIGNAL(pressed()), this, SLOT(buttonPressed()));
        connect(button, SIGNAL(released()), this, SLOT(buttonReleased()));
        if(isLeft)
            connect(button, SIGNAL(clicked(bool)), this, SLOT(prevPic()));
        else
            connect(button, SIGNAL(clicked(bool)), this, SLOT(nextPic()));
    }
    show();
    this->installEventFilter(this);
//    setFocus();
}

SwitchBtn::~SwitchBtn()
{
    delete ui;
}

void SwitchBtn::setTodaysPic(TodaysPic *todaysPic)
{
    picWall = todaysPic;
}

bool SwitchBtn::eventFilter(QObject *parent, QEvent *event)
{
    if(event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        switch(keyEvent->key())
        {
        case Qt::Key_Left:
            qDebug("test_left");
            prevPic();
            return true;
            break;
        case Qt::Key_Right:
            qDebug("test_right");
            nextPic();
            return true;
            break;
        default:
            return QObject::eventFilter(parent, event);
        }
    }
    else
        return QObject::eventFilter(parent, event);
}

void SwitchBtn::buttonPressed()
{
    QPushButton *button = (QPushButton*)sender();
    button->move(button->pos() + QPoint(3,3));
    qApp->processEvents();
}

void SwitchBtn::buttonReleased()
{
    QPushButton *button = (QPushButton*)sender();
    button->move(button->pos() - QPoint(3,3));
    qApp->processEvents();
}

void SwitchBtn::nextPic()
{
    qDebug("next pic!");
    DataCenter &dc = DataCenter::getInstance();
    int index = dc.getCurrentIndex();
    index++;
    QStringList paths = dc.getPicFilePaths();
    if(index >= paths.count())
        index = 0;
    picWall->preview(paths.at(index));
    dc.setCurrentIndex(index);
    setFocus();
}

void SwitchBtn::prevPic()
{
    qDebug("prev pic!");
    DataCenter &dc = DataCenter::getInstance();
    int index = dc.getCurrentIndex();
    index--;
    QStringList paths = dc.getPicFilePaths();
    if(index < 0)
        index = paths.count() - 1;
    picWall->preview(paths.at(index));
    dc.setCurrentIndex(index);
    setFocus();
}

