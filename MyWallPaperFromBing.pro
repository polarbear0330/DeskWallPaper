#-------------------------------------------------
#
# Project created by QtCreator 2016-11-05T15:22:11
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyWallPaperFromBing
TEMPLATE = app

#INCLUDEPATH += components \
#    data \
#    main \
#    pics

SOURCES += main.cpp\
        main/wallpaper.cpp \
    components/todayspic.cpp \
    components/switchbtn.cpp \
    data/datacenter.cpp

HEADERS  += main/wallpaper.h \
    components/todayspic.h \
    components/switchbtn.h \
    data/datacenter.h

FORMS    += main/wallpaper.ui \
    components/todayspic.ui \
    components/switchbtn.ui
