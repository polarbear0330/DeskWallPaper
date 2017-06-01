# DeskWallPaper
Get beautiful deskwall paper from cn.bing.com, and make it become yours!  
Original picture size: 1920*1080 <br>
OS supported: Windows 10, Ubuntu<br>
**Notice:** On Ubuntu, the property of the file "setwallpaperforUbuntu" should be set as "can be executed"

## Features:
1. Pictures from Bing changes everyday, they will be downloaded and stored to local by the "DeskWallPaper" everytime when you start it.
1. You can not only view and set today's wall-paper, but also view your history/local pictures and just choose one!
1. If you do not want to take too much care of it, just start it when your PC start, since there is a "**Timer**" to close it after clicking the button by itself. TOTALLY **Automatically**!<br>
**Tips:**Start when PC start:<br>
For windows: put your .exe into the folder "C:\ProgramData\Microsoft\Windows\Start Menu\Programs\StartUp"
1. In fact, there is still 20 seconds left just in case that you forget it. The timer can be stoped by pressing any key! Such as "*Left*" and "*Right*" when toggling pictures. (When it finally come into your mind before closed.)

## Interface:
The operating interface is shown in the following illustration: <br>
![DeskWallPaper interface](https://github.com/polarbear0330/DeskWallPaper/blob/master/README_picture/example1.jpg)

## How to use:
Just as shown below:<br>
![How to use](https://github.com/polarbear0330/DeskWallPaper/blob/master/README_picture/howToUse2_.jpg)

And these are my local pictures, since I develop those codes:<br>
![My local pictures](https://github.com/polarbear0330/DeskWallPaper/blob/master/README_picture/local_pic.jpg)

<br>
update log:<br>
20170526 update:<br>
 * 1.跨平台：扩展至Ubuntu平台<br>
 * 方案一：GNOME的GConfClient的库与API：①手动下载。②如何include本地任意库文件。③API函数测试 (FAIL)<br>
 * 备选方案：Qt函数内，调用Ubuntu命令行(SHELL文件)，SHELL文件负责设置桌面背景功能，输入为filepath (BINGO)<br>
 * 2.窗口背景色识别错误，透明窗口变黑，两OS在此处不统一<br>
3.加入dll文件，便于直接启动exe？<br><br>

-----------------------------I am a separator line--------------------------------<br><br>
update logs before my codes put on the Github:<br>
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
