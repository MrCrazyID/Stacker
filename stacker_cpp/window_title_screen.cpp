/**
 * @file window_title_screen.cpp
 * @author Ingmar Delsink
 * @date 2 may 2014
 * @brief File containing the GUI of the Title screen of Stacker.
 * In this file evertyhing of the title screen of Stacker in relation with the GUI
 * can be found.
 */

#include "window_title_screen.h"
#include "ui_window_title_screen.h"

#include "window_main_screen.h"
#include "AppInfo.h"

window_title_screen::window_title_screen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window_title_screen)
{
    ui->setupUi(this);
    this->setWindowTitle(APPNAME_VERSION);  //set window title
    timer.start(100, this);                 //setup timer for color looping
}

window_title_screen::~window_title_screen()
{
    delete ui;
}

//********************************************************************************
//pushButton Start clicked
void window_title_screen::on_pushButton_TitleWindowStart_clicked(void)
{
    timer.stop();
    newWindow_MainScreen = new window_main_screen();
    newWindow_MainScreen->show();
    this->close();
}

//********************************************************************************
//The is a timer functions, it does tasks on a timer
void window_title_screen::timerEvent(QTimerEvent *event)
{
    int delay_time = 1200;
    if (event->timerId() == timer.timerId())
    {
        ui->label_TitleWindowStacker->setStyleSheet("QLabel#label_TitleWindowStacker { color: rgb(255, 0, 0); font: 75 12pt Lucida Console;}");
        ui->pushButton_TitleWindowStart->setText("PRESS");
        delay(delay_time);

        ui->label_TitleWindowStacker->setStyleSheet("QLabel#label_TitleWindowStacker { color: rgb(255, 255, 0); font: 75 12pt Lucida Console;}");
        ui->pushButton_TitleWindowStart->setText("TO");
        delay(delay_time);

        ui->label_TitleWindowStacker->setStyleSheet("QLabel#label_TitleWindowStacker { color: rgb(0, 255, 0); font: 75 12pt Lucida Console;}");
        ui->pushButton_TitleWindowStart->setText("PLAY");
        delay(delay_time);

        ui->label_TitleWindowStacker->setStyleSheet("QLabel#label_TitleWindowStacker { color: rgb(255, 0, 255); font: 75 12pt Lucida Console;}");
        ui->pushButton_TitleWindowStart->setText("☟☟");
        delay(delay_time);
    }
    else
    {
        QWidget::timerEvent(event);
    }
}
