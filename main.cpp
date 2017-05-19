#include "main/wallpaper.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WallPaper w;
    w.show();
    w.getWholeWebSource();

    return a.exec();
}
