#-------------------------------------------------
#
# Project created by QtCreator 2014-03-30T17:43:46
# Made by: Ingmar Delsink
#
#-------------------------------------------------

QT       += core
QT       += gui

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Stacker
TEMPLATE = app

RC_FILE = myapp.rc                      #resource file for app icon

SOURCES +=  main.cpp \                  #source files
            window_title_screen.cpp \
            window_main_screen.cpp \
            gamesource.cpp \
            gameinfo.cpp

HEADERS  += window_title_screen.h \     #header files
            window_main_screen.h \
            gamesource.h \
            gameinfo.h \
            AppInfo.h

FORMS    += window_title_screen.ui \    #form files
            window_main_screen.ui

OTHER_FILES += myapp.rc                 #resource file for icon

RESOURCES += resource.qrc               #resource file for images
