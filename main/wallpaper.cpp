/*
 * 自动下载bing首页图片并设为桌面背景
 * 作者：陶旭牧野
 * 日期：2016/11/05
*/

/*
 * 20170530更新日志：
 * Ubuntu: 设置当前任意图片为桌面壁纸
 *
 * 20170526更新日志：
 * 1.跨平台：扩展至Ubuntu平台
 * 方案一：GNOME的GConfClient的库与API：①手动下载。②如何include本地任意库文件。③API函数测试 (FAILED)
 * 备选方案：Qt函数内，调用Ubuntu命令行(SHELL文件)，SHELL文件负责设置桌面背景功能，输入为filepath (BINGO)
 * 2.窗口背景色识别错误，透明窗口变黑，两OS在此处不统一
 * 3.加入dll文件，便于直接启动exe？
 *
 * --------------------I am a separating line----------------
 * 步骤：
 * 1.图片的存储与读取_20161121
 * 2.http请求获取必应壁纸_20161121
 * 3.将图片设置为桌面背景_20161121
 * 4.左侧添加黑色渐变
 * 5.自动找到每天都变的url_20161122
 * 6.确认更改 / 撤销还原（删）
 * 7.设置一个通用的保存路径及文件名_20161123
 * 8.downloadPic后发送一个信号，连接槽函数setWallPaper
 * 9.创建一个DataCenter，存储每一张壁纸的url？（删）
 * 10.检测网络连接
 *
 * 20161126更新日志：
 * 1.增加错误提示
 * 2.修改其他提示信息
 *
 * 20161126计划日志：（左侧添加黑色渐变）
 * RGB基础知识，黑色、灰色像素的值
 * 像素点的数据结构，每个像素点由几个变量组成
 * QImage等类的用法
 * 操作像素点的值，左侧添加黑色渐变条
 *
 * 20161128更新日志：
 * 1.美化界面，同时增加“删除”按钮
 * 2.增加鼠标拖动功能（窗口可移动）
 *
 * 20161129更新日志：
 * 1.壁纸全屏预览
 * 2.预览窗口可拖拽移动（考虑是否要去除该功能）
 * 3.简化提示消息Downloading...
 *
 * 20161201更新日志：
 * 1.整理所有的消息提示
 * 2.动态显示downloading和setWallpaper
 *
 * 20161202更新日志：
 * 1.黑色半透明背景（QLabel(Pixmap)，建议试试paintEvent()）
 * 2.其余qss与背景相匹配
 *
 * 20161209更新日志：
 * 1.加了一个标签（名句）
 * 2.首次自定义信号signal函数！
 *
 * 20161215更新日志：
 * 1.修改优化“寻找图片url网址”的算法
 *
 * 20161216更新日志：
 * 1.从整体上优化本程序
 *
 * 20161223问题日志：
 * 1.最近必应网页源码发生了较大改动，壁纸的url再无法在源码中找到。百度后得知，在源码中找不到的代码，那是在浏览器执行js动态生成的！
 * 从审查元素和查看网页源码的区别谈起：
 * 审查元素是浏览器执行js动态生成的内容，这个区别可以说是源代码和DOM的区别，我们审查元素，实际上是查看DOM，DOM渲染过了，查看网页源码看到的才是未解析的源代码。
 *
 * 20170104更新日志：
 * 1.查找关键字符串更新：url: "/az/hprichbg/rb/XXXXXX_1920x1080.jpg"
 * 2.手动添加 cn.bing.com/XXX
 *
 * 20170105更新日志：
 * 1.左右翻页按钮
 * 2.添加按钮按下与释放效果
 *
 * 20170106更新日志：
 * 1.重做左右翻页按钮：改为单独的两个窗口dialog，背景透明
 * 2.左右按钮icon用ps描边，投影效果
 *
 * 20170109计划日志：已完成
 * 由于prev和next都会调用本地图片列表，需要一个DataCenter类，存储当前图片序号，使得两者都可以找到正确序号的图片
 *
 * 20170324更新日志：
 * 新增DataCenter，功能如上
 *
 * 20170327更新日志：
 * 1.DataCenter存储所有图片路径
 * 2.左右翻页按钮——实现翻页功能
 *
 * 20170327计划日志：已完成
 * 键盘左右键实现翻页功能，即触发相应信号
 *
 * 20170329计划日志：
 * 做成WIN10的应用
 *
 * 20170330计划日志：
 * random按钮
 *
 * 20170330更新日志：
 * 已完成左右键翻页。方式：事件过滤器eventFilter，响应键盘事件。一处定义，多处install
 * 但存在关于setFocus的小BUG
 *
 * 20170331更新日志：
 * BUG已解决：构造函数中加setFocus。原因不明？！！！
 *
 * 20170331计划日志（版本4）：暂否
 * 取消预览窗口？改为桌面直接显示？
 *
 * 20170413更新日志：
 * 20秒后设为当前图片，并关闭！
 *
 * 20170314问题日志：
 * 回车键功能失败！！！！！
 *
 * 20170414更新日志：
 * 1.QTimer显示倒计时
 * 2.修改提示语，未联网时提醒浏览本机图片
 * 3.按任意键退出倒计时
 * 4.倒计时关闭后，秒数会停住，而非消失
 *
*/


#include "main/wallpaper.h"
#include "ui_wallpaper.h"

WallPaper::WallPaper(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WallPaper)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setWindowOpacity(1.0);
    setAttribute(Qt::WA_TranslucentBackground);

    QString appDirPath = "";
#if defined(Q_OS_LINUX)
    appDirPath = qApp->applicationDirPath() + "/";
#endif
    ui->label_backgr->setGeometry(this->geometry());
    ui->label_backgr->setPixmap(QPixmap(appDirPath + "pics/0.6.png"));

    move((qApp->desktop()->width() - width()) / 2,
         (qApp->desktop()->height() - height()) / 2);

    prev = new SwitchBtn(appDirPath + "pics/prev.png", pos(), size(), true, parent);
    next = new SwitchBtn(appDirPath + "pics/next.png", pos(), size(), false, parent);
    prev->setTodaysPic(&todaysPic);
    next->setTodaysPic(&todaysPic);

    QList<QPushButton*> btnList = findChildren<QPushButton*>();
    for(auto button: btnList)
    {
        connect(button, SIGNAL(pressed()), this, SLOT(buttonPressed()));
        connect(button, SIGNAL(released()), this, SLOT(buttonReleased()));
    }

    connect(closeTimer, SIGNAL(timeout()), this, SLOT(on_setWallPaper_clicked()));
    connect(countTimer, SIGNAL(timeout()), this, SLOT(countDownAndSet()));

    connect(this, SIGNAL(urlFound(QUrl)), this, SLOT(downloadPic(QUrl)));
    connect(this, SIGNAL(picSaved(QString)), &todaysPic, SLOT(preview(QString)));

    //test
//    qDebug()<<DataCenter::getInstance().getPicFilePaths();

    todaysPic.installEventFilter(prev);
    installEventFilter(prev);

    installEventFilter(this);
    todaysPic.installEventFilter(this);
    prev->installEventFilter(this);
    next->installEventFilter(this);

    setFocus();
}

WallPaper::~WallPaper()
{
    delete ui;
}

void WallPaper::showStatusTips(STATUS status, QString errorString)
{
    switch (status)
    {
    case NETWORK_CONNECTION_FAILED:
        qDebug()<<"获取网页源码失败，QNetworkReply错误代码："<<endl<<errorString;
//        ui->label_load->setText("检测到未连网，或网络不稳定\n\n请先连接网络，然后重启软件");
        ui->label_load->setText("检测到未连网\n\n单击左右键，浏览本机图片");
        ui->label_load->show();
        text = "Set wallpaper!";
        ui->setWallPaper->setEnabled(true);
        ui->setWallPaper->setText(text);
        textAppeared = "";
        textAppearedNum = 0;
        textAppear();
        break;
    case URL_NOT_FOUND:
        qDebug("未找到今日的壁纸的url！");
        ui->label_load->setText("未找到今日壁纸的url！");
        ui->label_load->show();
        break;
    case PICTURE_DOWNLOADING:
        text = "Downloading...";
        ui->setWallPaper->setEnabled(false);
        ui->setWallPaper->setText(text);
        ui->label_load->hide();
        textAppeared = "";
        textAppearedNum = 0;
        textAppear();
        break;
    case DOWNLOAD_FAILED:
        qDebug()<< "获取壁纸失败，QNetworkReply错误代码：" << endl << errorString;
        ui->label_load->setText("获取壁纸失败，错误代码：\n..." + errorString.right(25) + "\n\n可在当日(即今天)联系软件作者\ntfy.hi@163.com");
        ui->label_load->show();
        break;
    case LOAD_FROM_DATA_FAILED:
        qDebug("图片加载失败！");
        ui->label_load->setText("加载图片失败，数据大小：" + errorString);
        ui->label_load->show();
        break;
    case WALLPAPER_READY:
        text = "Set wallpaper!";
        ui->setWallPaper->setEnabled(true);
        ui->setWallPaper->setText(text);
        ui->label_load->hide();
        textAppeared = "";
        textAppearedNum = 0;
        textAppear();

        closeTimer->setSingleShot(true);
        closeTimer->start(countDownNum * 1000);
//        QTimer::singleShot(countDownNum * 1000, this, SLOT(on_setWallPaper_clicked()));
        break;
    case COUNT_DOWN_TO_CLOSE:
        ui->label_countDown->setText(QString("%1").arg(countDownNum));
//        QTimer::singleShot(1000, this, SLOT(countDownAndSet()));
        countTimer->setSingleShot(true);
        countTimer->start(1000);
        break;
    default:
        ui->setWallPaper->setEnabled(false);
        ui->setWallPaper->setText("Downloading...");
        ui->label_load->hide();
        break;
    }
}

/*
 * 输入本地图片文件的全路径
 * 调用windows系统函数SystemParametersInfo设置当前路径下的图片为桌面背景
 */
#if defined(Q_OS_WIN)
void WallPaper::setWallPaper(QString filePath)
{
    const char *tmp = filePath.toStdString().c_str(); //QDir::currentPath().append("/").append(currentFileName_).toStdString().c_str();
    std::wstringstream wss;
    wss << tmp;
    const wchar_t *filename = wss.str().c_str();
    if( !SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, (void*)filename, SPIF_UPDATEINIFILE) )
    {
        qDebug("设置桌面背景失败!");
//        emit message(FAILED_SET_WALLPAPER);
    }
}

#elif defined(Q_OS_LINUX)
#include <QProcess>
void WallPaper::setWallPaper(QString filePath)
{
//
    QFile file(qApp->applicationDirPath() + "/setwallpaperforUbuntu");
    file.open(QIODevice::ReadWrite);
    QTextStream textStream(&file);
    QString text = textStream.readAll();
    int start = text.indexOf("/home");
    textStream.seek(start);
    textStream << filePath << "'                                                ";
    file.close();

    QProcess *setWallPaperSHELL = new QProcess;
    QString command = qApp->applicationDirPath() + "/setwallpaperforUbuntu";
    qDebug()<< command;
    setWallPaperSHELL->start(command);
    qDebug()<<setWallPaperSHELL->errorString();

//    qDebug()<<setWallPaperSHELL->execute("saveDir=$HOME'/'");
//    qDebug()<<setWallPaperSHELL->execute("picOpts=\"zoom\"");
//    qDebug()<<setWallPaperSHELL->execute("picName=\"Fiddleheads_ZH-CN14463697077_1920x1200.jpg\"");
//    qDebug()<<setWallPaperSHELL->execute("DISPLAY=:0 GSETTINGS_BACKEND=dconf gsettings set org.gnome.desktop.background picture-uri '\"file://'$saveDir$picName'\"'");
//    qDebug()<<setWallPaperSHELL->execute(" DISPLAY=:0 GSETTINGS_BACKEND=dconf gsettings set org.gnome.desktop.background picture-options $picOpts");

//    qDebug()<<setWallPaperSHELL->execute("./setwallpaperforUbuntu");
//    system("/home/yinhe/develop/DeskWallPaper/setwallpaperforUbuntu");
//    system("opt/setwallpaperforUbuntu");
    qDebug("ubuntu");
}
#endif

/*
 * Getting "http://cn.bing.com/"
 * Turn to function "findPicUrl()" to read the reply when SIGNAL "finished" arrives.
*/
void WallPaper::getWholeWebSource()
{
    showStatusTips(PICTURE_DOWNLOADING);
//    QUrl url("http://s.cn.bing.net/az/hprichbg/rb/TurdaSalt_ZH-CN8549125738_1920x1080.jpg");//示例图片地址，用于测试程序
    QUrl url("http://cn.bing.com/");
    QNetworkRequest request;
    request.setUrl(url);
    connect(&manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(findPicUrl(QNetworkReply*)));
    manager.get(request);//用finished信号传递reply
}

/*
 * disconnect信号与槽
 * 读取已完成的全部reply
 * 搜索关键字符串，找到完整的目标url，即指向壁纸图片的url
 * emit the SIGNAL: "urlFound", connected with the SLOT: "downloadPic"
*/
void WallPaper::findPicUrl(QNetworkReply *reply)
{
    disconnect(&manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(findPicUrl(QNetworkReply*)));
    if(reply->error() == QNetworkReply::NoError)
    {
        QByteArray webContent = reply->readAll();
        QFile file("测试文件.txt");//写成一个可阅读的txt文档，用于程序测试
        file.open(QIODevice::ReadWrite);
        file.write(webContent);
        file.close();
//        QByteArray targetUrl = "http://s.cn.bing.net/";
        QByteArray targetUrl = "/az/hprichbg/rb/";
        int indexStart = -1;
        int indexEnd = -1;
        indexStart = webContent.indexOf(targetUrl);
        if(indexStart != -1)//若在获取到的网页源码中找到了所需url，则get之
        {
            qDebug("找到了壁纸的url:");
            webContent = webContent.mid(indexStart);
            indexEnd = webContent.indexOf("jpg");
            indexEnd = indexEnd + 2;
            QUrl url("http://cn.bing.com" + webContent.left(indexEnd + 1));
            qDebug()<<url;
            emit urlFound(url);
        }
        else
            showStatusTips(URL_NOT_FOUND);
    }
    else
        showStatusTips(NETWORK_CONNECTION_FAILED, reply->errorString());
}

void WallPaper::downloadPic(QUrl url)
{
    QNetworkRequest request;
    request.setUrl(url);
    connect(&manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(savePic(QNetworkReply*)));
    manager.get(request);//用finished信号传递reply
}

/*
 * 读取已完成的全部reply       保
 * 用QPixmap对象加载读取结果     存
 * 保存jpg图片                   至本地
 * emit the SIGNAL: "picSaved", connected with the SLOT: "todaysPic.preview"
*/
void WallPaper::savePic(QNetworkReply *reply)
{
    disconnect(&manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(savePic(QNetworkReply*)));
    if(reply->error() == QNetworkReply::NoError)
    {
        QPixmap picture;
        QByteArray picData = reply->readAll();
        qDebug()<<"数据大小："<<picData.size();
        if(!picture.loadFromData(picData, "JPG"))
        {
            showStatusTips(LOAD_FROM_DATA_FAILED, QString("%1").arg(picData.size()));
            return;
        }
        filePath = QDir::homePath() + "/" + "Pictures/";
        QDir dir;
        dir.mkdir(filePath);
        filePath += QDateTime::currentDateTime().toString("yyyy-MM-dd") + "_Bing_txmy.jpg";
        qDebug()<<filePath;
        if(!picture.save(filePath))
        {
            qDebug()<<"图片保存失败！";
//            ui->label_load->setText("保存图片失败！");
        }
        else
        {
            showStatusTips(WALLPAPER_READY);
            showStatusTips(COUNT_DOWN_TO_CLOSE);
            emit picSaved(filePath);

            DataCenter &dc = DataCenter::getInstance();
            QStringList paths = dc.getPicFilePaths();
            int index = paths.indexOf(filePath);
            if(index != -1)
                dc.setCurrentIndex(index);

//            float secs = 5;
//            time_t delay = secs * CLOCKS_PER_SEC;
//            time_t start = clock();
//            while(clock() - start < delay)
//                ;
//            on_setWallPaper_clicked();
        }
    }
    else
        showStatusTips(DOWNLOAD_FAILED, reply->errorString());
}

void WallPaper::on_setWallPaper_clicked()
{
    DataCenter &dc = DataCenter::getInstance();
    filePath = dc.getPicFilePaths().at(dc.getCurrentIndex());
    setWallPaper(filePath);
//#if defined(Q_OS_WIN)
//    setWallPaper_windows(filePath);
//    qDebug("win10");
//#elif defined(Q_OS_LINUX)
//    qDebug("ubuntu");
//#endif
    close();
    todaysPic.close();
    next->close();
    prev->close();
}

void WallPaper::textAppear()
{
    if(textAppearedNum == text.size())
    {
//        countDownNum = 5;
//        if(text == "Set wallpaper!")
//            for(int i = 0; i < 6; i++)
//                QTimer::singleShot(1000 * i, this,SLOT(countDown()));
        return;
    }
    textAppeared += text.at(textAppearedNum);
    ui->setWallPaper->setText(textAppeared);
    qDebug()<<textAppeared;
    QTimer::singleShot(100, this, SLOT(textAppear()));
    textAppearedNum++;
}

void WallPaper::countDownAndSet()
{
//    ui->setWallPaper->setText("Set wallpaper!" + QString("  %1s").arg(countDownNum));
//    if(countDownNum == 0)
//        close();todaysPic.close();
//    countDownNum--;
    countDownNum--;
    showStatusTips(COUNT_DOWN_TO_CLOSE);
}

void WallPaper::buttonPressed()
{
    QPushButton* b = (QPushButton*)(sender());
    b->move(b->pos() + QPoint(3, 3));
    qApp->processEvents();
}

void WallPaper::buttonReleased()
{
    QPushButton* b = (QPushButton*)(sender());
    b->move(b->pos() - QPoint(3, 3));
    qApp->processEvents();
}



void WallPaper::mouseMoveEvent(QMouseEvent *event)
{
    if (movable && (event->buttons() && Qt::LeftButton))
    {
        this->move(event->globalPos() - mousePoint);
        prev->move(pos() + QPoint(- prev->width() - 50, (size().height() - prev->height()) / 2));
        next->move(pos() + QPoint(size().width() + 50, (size().height() - next->height()) / 2));
        event->accept();
        closable = false;
    }
}

void WallPaper::mouseReleaseEvent(QMouseEvent *event)
{
    movable = false;
    if (closable && ui->label_Close->geometry().contains(event->pos()))
    {
        closable = false;
        close();
        todaysPic.close();
        prev->close();
        next->close();
    }
}

void WallPaper::mousePressEvent(QMouseEvent *event)
{
    closable = false;
    if (ui->label_backgr->geometry().contains(event->pos()))
    {
        closable = true;
        movable = true;
        mousePoint = event->globalPos() - this->pos();
    }
}

bool WallPaper::eventFilter(QObject *parent, QEvent *event)
{
//    qDebug("test_WallPaper::eventFilter");
    if(event->type() == QEvent::KeyPress)
    {
        if(closeTimer->isActive())
            closeTimer->stop();
//            ui->label_countDown->hide();
        if(countTimer->isActive())
            countTimer->stop();

        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if(keyEvent->key() == Qt::Key_Enter)
        {
            qDebug("Key_Enter_test");
            on_setWallPaper_clicked();
            return true;
        }
        else
            return QObject::eventFilter(parent, event);
    }
    else
        return QObject::eventFilter(parent, event);
}

