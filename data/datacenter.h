#ifndef DATACENTER_H
#define DATACENTER_H

#include <QObject>
#include <QDir>

class DataCenter
{
private:
    explicit DataCenter();
    DataCenter(DataCenter& other);
    QStringList getPicFilePaths(QString basePath);

public:
    static DataCenter& getInstance();
    QStringList getPicFilePaths();
    void setCurrentIndex(int current);
    int getCurrentIndex();

private:
    QStringList picFilePaths;
    int currentIndex = 0;
};

#endif // DATACENTER_H
