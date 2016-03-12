/**
 * @file window_title_screen.h
 * @author Ingmar Delsink
 * @date 2 may 2014
 * @brief File containing the GUI of the Title screen of Stacker.
 * In this file evertyhing of the title screen of Stacker in relation with the GUI
 * can be found.
 */

#ifndef WINDOW_TITLE_SCREEN_H
#define WINDOW_TITLE_SCREEN_H

#include <QMainWindow>
#include <QBasicTimer>

#include "window_main_screen.h"

namespace Ui {
class window_title_screen;
}

/**
 * @brief Title Screen GUI
 *
 */
class window_title_screen : public QMainWindow
{
    Q_OBJECT

public:
    explicit window_title_screen(QWidget *parent = 0);
    ~window_title_screen();

private slots:
    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief pushButton Start clicked
     * when clicked, the user will be send to the Main Window
     */
    void on_pushButton_TitleWindowStart_clicked(void);

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief The is a timer functions, it does tasks on a timer
     *
     * @param event
     */
    void timerEvent(QTimerEvent *event);

private:
    Ui::window_title_screen *ui;                /**< Points to the UI of the Window_title_screen */
    window_main_screen *newWindow_MainScreen;   /**< Points to a new window */

    //timer for screen refresh
    QBasicTimer timer;                  /**< this is a defenition of a timer variable */
};

#endif // WINDOW_TITLE_SCREEN_H
