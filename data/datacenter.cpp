/*
 * 唯一实例，数据共享
 * 获取本地图片地址
 *
*/

#include "data/datacenter.h"

DataCenter::DataCenter()
{

}

DataCenter &DataCenter::getInstance()
{
    static DataCenter dc;
    dc.picFilePaths = dc.getPicFilePaths(QDir::homePath() + "/Pictures/");
    return dc;
}

QStringList DataCenter::getPicFilePaths(QString basePath)
{
    QDir dir = QDir(basePath, "*.jpg", QDir::Name, QDir::Files);
    QStringList picFilePaths = dir.entryList();
    for(int i = 0; i < picFilePaths.count(); i++)
        picFilePaths[i] = basePath + picFilePaths[i];
    return picFilePaths;
}

QStringList DataCenter::getPicFilePaths()
{
    return picFilePaths;
}

void DataCenter::setCurrentIndex(int current)
{
    currentIndex = current;
}

int DataCenter::getCurrentIndex()
{
    return currentIndex;
}
