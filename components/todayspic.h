#ifndef TODAYSPIC_H
#define TODAYSPIC_H

#include <QDialog>
#include <QDesktopWidget>
#include <QMouseEvent>

namespace Ui {
class TodaysPic;
}

class TodaysPic : public QDialog
{
    Q_OBJECT

public:
    explicit TodaysPic(QWidget *parent = 0);
    ~TodaysPic();

public slots:
    void preview(QString filePath);

private:
    Ui::TodaysPic *ui;
    bool movable = false;
    QPoint mousePoint; // to move it

private:
//    void process();
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
};

#endif // TODAYSPIC_H
