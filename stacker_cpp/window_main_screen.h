/**
 * @file window_main_screen.h
 * @author Ingmar Delsink
 * @date 2 may 2014
 * @brief File containing the GUI of the main screen of Stacker.
 * In this file evertyhing of the main screen of Stacker in relation with the GUI
 * can be found.
 */

#ifndef WINDOW_MAIN_SCREEN_H
#define WINDOW_MAIN_SCREEN_H

#include <QMainWindow>
#include <QBasicTimer>
#include <QString>

#include "gameinfo.h"

//defining of all the screens/menus
#define MAINMENU 0          ///<Main Menu
#define DIFFICULTYMENU 1    ///<Difficulty Menu
#define PLAYSCREEN 2        ///<Play Screen
#define PAUSEMENU 3         ///<Pause Menu
#define HELP 4              ///<Help menu
#define ABOUT 5             ///<About
#define ENDGAME 6           ///<End Game
#define SETTINGS 7          ///<Settings

//playfield table defines
#define PLAYSCREENCOLMNWIDTH (300/PLAYFIELDWIDTH)   ///<colmn width for table on playscreen
#define PLAYSCREENROWHEIGHT (525/PLAYFIELDHEIGHT)   ///<row height for table on playscreen

//mainwindow size
#define MAINWINDOWWIDTH 542             ///<window width
#define MAINWINDOWHEIGHT 531            ///<window height
#define MAINWINDOWDEFAULTOFFSETX 20     ///<window default offset X
#define MAINWINDOWDEFAULTOFFSETY 20     ///<window default offsey Y

//Easter Egg define timer time
#define EASTEREGGTIMERTIMER 800        ///<timer for background changing

//defining off all the Qt colors for a switch statement
#define RED 0           ///<Color of the stacker block: Red
#define GREEN 1         ///<Color of the stacker block: Green
#define YELLOW 2        ///<Color of the stacker block: Yellow
#define BLUE 3          ///<Color of the stacker block: Blue
#define CYAN 4          ///<Color of the stacker block: Cyan
#define MAGENTA 5       ///<Color of the stacker block: Magenta
#define LIGHTGRAY 6     ///<Color of the stacker block: Light Gray
#define WHITE 7         ///<Color of the stacker block: White
#define BLACK 8         ///<Color of the stacker block: Black
#define DOGE_IMG 9      ///<Color of the stacker block: An Image

namespace Ui {
class window_main_screen;
}

/**
 * @brief Main window GUI
 *
 */
class window_main_screen : public QMainWindow
{
    Q_OBJECT

public:
    explicit window_main_screen(QWidget *parent = 0);
    ~window_main_screen();

private slots:
    //--------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------action buttons
    //--------------------------------------------------------------------------------------------

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief Action Main Menu Clicked, the window will go to main menu
     *
     */
    void on_actionMain_Menu_triggered(void);

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief Action Settings Clicked, the window will go to settings
     *
     */
    void on_actionSettings_triggered(void);

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief Action Quit Clicked, the window will close
     *
     */
    void on_actionQuit_triggered(void);

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief Action Help Clicked, the window will go to help
     *
     */
    void on_actionHelp_triggered(void);

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief Action About Clicked, the window will go to About
     *
     */
    void on_actionAbout_triggered(void);


    //--------------------------------------------------------------------------------------------
    //----------------------------------------------------------------------Stacked Widget Screens
    //--------------------------------------------------------------------------------------------

    //-----------------------------------------------------------------------------------Main Menu
    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief PushButton New Game clicked on Main Menu
     *
     */
    void on_pushButton_MainMenuNewGame_clicked(void);

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief PushButton Load Game clicked on Main Menu
     *
     */
    void on_pushButton_MainMenuLoadGame_clicked(void);

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief PushButton About clicked on Main Menu
     *
     */
    void on_pushButton_MainMenuAbout_clicked(void);

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief PushButton Help clicked on Main Menu
     *
     */
    void on_pushButton_MainMenuHelp_clicked(void);

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief PushButton Quit clicked on Main Menu
     *
     */
    void on_pushButton_MainMenuQuit_clicked(void);

    //-----------------------------------------------------------------------------Difficulty Menu
    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief PushButton Easy clicked on Difficulty Menu
     *
     */
    void on_pushButton_DifficultyMenuEasy_clicked(void);

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief PushButton Medium clicked on Difficulty Menu
     *
     */
    void on_pushButton_DifficultyMenuMedium_clicked(void);

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief PushButton Hard clicked on Difficulty Menu
     *
     */
    void on_pushButton_DifficultyMenuHard_clicked(void);

    //---------------------------------------------------------------------------------Play Screen
    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief PushButton Pause clicked on Play Screen
     *
     */
    void on_pushButton_PlayScreenPause_clicked(void);

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief PushButton Stack clicked on Play Screen
     *
     */
    void on_pushButton_PlayScreenStack_pressed(void);

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief Shows the playfield in the Qtablewidget
     *
     */
    void showPlayfield(void);

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief Sets a random image in the playscreen Stacker logo frame
     *
     * @param iRandomImg = number which image needs to be selected
     */
    void randomImgPlayfield(int iRandomImg);

    //----------------------------------------------------------------------------------Pause Menu
    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief PushButton Resume clicked on Pause Menu
     *
     */
    void on_pushButton_PauseMenuResume_clicked(void);

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief PushButton Main Menu clicked on Pause Menu
     *
     */
    void on_pushButton_PauseMenuMainMenu_clicked(void);

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief PushButton Save Game clicked on Pause Menu
     *
     */
    void on_pushButton_PauseMenuSaveGame_clicked(void);

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief PushButton Quit clicked on Pause Menu
     *
     */
    void on_pushButton_PauseMenuQuit_clicked(void);

    //----------------------------------------------------------------------------------------Help
    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief PushButton Main Menu clicked on Help
     *
     */
    void on_pushButton_HelpMainMenu_clicked(void);

    //---------------------------------------------------------------------------------------About
    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief PushButton Main Menu clicked on About
     *
     */
    void on_pushButton_AboutMainMenu_clicked(void);

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief PushButton EasterEgg clicked on About
     *
     */
    void on_pushButton_AboutStackerEasterEgg_clicked(void);

    //------------------------------------------------------------------------------------End Game
    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief PushButton Main Menu clicked on End Game
     *
     */
    void on_pushButton_EndGameMainMenu_clicked(void);

    //------------------------------------------------------------------------------------Settings
    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief PushButton Save Settings clicked on Settings
     *
     */
    void on_pushButton_SettingsSaveSettings_clicked(void);

    //--------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------Other Functions
    //--------------------------------------------------------------------------------------------

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief function to start the timer and set active window to playscreen
     *
     */
    void startGame(void);

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief function to initialize the mainwindow of stacker
     *
     */
    void initializeStacker(void);

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief function to clear the stacker field of all the blocks
     *
     */
    void clearStackerPlayfield(void);

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief function to continuously do something on a timer
     *
     * @param event = event holder
     */
    void timerEvent(QTimerEvent *event);

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief check what key is pressed
     *
     * @param event = when key is pressed
     */
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::window_main_screen *ui; /**< Points to the UI of the window_main_screen*/

    QBasicTimer timer;          /**< this is a defenition of a timer variable */
};

//********************************************************************************
/**
 * @author Ingmar Delsink
 * @brief delay function
 *
 * @param milliseconds = delay time in milliseconds
 */
void delay(int milliseconds);

#endif // WINDOW_MAIN_SCREEN_H
