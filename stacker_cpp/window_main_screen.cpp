/**
 * @file window_main_screen.cpp
 * @date 2 may 2014
 * @brief File containing the GUI of the main screen of Stacker.
 * In this file evertyhing of the main screen of Stacker in relation with the GUI
 * can be found.
 */

#include "window_main_screen.h"
#include "ui_window_main_screen.h"

#include "AppInfo.h"
#include "gameinfo.h"
#include "gamesource.h"

#include <string>
#include <QApplication>
#include <QFileDialog>
#include <QTime>
#include <QTableWidget>
#include <QKeyEvent>
#include <QFontDatabase>
#include <QDesktopWidget>



window_main_screen::window_main_screen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::window_main_screen)
{
    ui->setupUi(this);
    initializeStacker();//initialize stacker
}

window_main_screen::~window_main_screen()
{
    delete ui;
}

//--------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------action buttons
//--------------------------------------------------------------------------------------------

//********************************************************************************
//Action Main Menu Clicked, the window will go to main menu
void window_main_screen::on_actionMain_Menu_triggered(void)
{
    //set screen to main menu
    ui->stackedWidget_mainscreen->setCurrentIndex(MAINMENU);
}

//********************************************************************************
//Action Settings Clicked, the window will go to settings
void window_main_screen::on_actionSettings_triggered(void)
{
    //go to settings
    ui->stackedWidget_mainscreen->setCurrentIndex(SETTINGS);
}

//********************************************************************************
//Action Quit Clicked, the window will close
void window_main_screen::on_actionQuit_triggered(void)
{
    //Quit Stacker
    this->close();
}

//********************************************************************************
//Action Help Clicked, the window will go to help
void window_main_screen::on_actionHelp_triggered(void)
{
    //show help
    //set screen to help screen
    ui->stackedWidget_mainscreen->setCurrentIndex(HELP);
}

//********************************************************************************
//Action About Clicked, the window will go to About
void window_main_screen::on_actionAbout_triggered(void)
{
    //show About
    //set screen to About screen
    ui->stackedWidget_mainscreen->setCurrentIndex(ABOUT);
    ui->pushButton_AboutStackerEasterEgg->setFocus();
}

//--------------------------------------------------------------------------------------------
//----------------------------------------------------------------------Stacked Widget Screens
//--------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------Main Menu
//********************************************************************************
//PushButton New Game clicked on Main Menu
void window_main_screen::on_pushButton_MainMenuNewGame_clicked(void)
{
    //set screen to difficulty menu
    ui->stackedWidget_mainscreen->setCurrentIndex(DIFFICULTYMENU);
}

//********************************************************************************
//PushButton Load Game clicked on Main Menu
void window_main_screen::on_pushButton_MainMenuLoadGame_clicked(void)
{
    //load game in
    QString qsFileName;
    qsFileName = QFileDialog::getOpenFileName(this, tr("Open File"),"",tr("Stacker files (*.stack)"));

    if(loadGame(qsFileName) != 0)
    {
        startGame();
    }
}

//********************************************************************************
//PushButton About clicked on Main Menu
void window_main_screen::on_pushButton_MainMenuAbout_clicked(void)
{
    //set screen to About screen
    ui->stackedWidget_mainscreen->setCurrentIndex(ABOUT);
    ui->pushButton_AboutStackerEasterEgg->setFocus();
}

//********************************************************************************
//PushButton Help clicked on Main Menu
void window_main_screen::on_pushButton_MainMenuHelp_clicked(void)
{
    //set screen to help screen
    ui->stackedWidget_mainscreen->setCurrentIndex(HELP);
}

//********************************************************************************
//PushButton Quit clicked on Main Menu
void window_main_screen::on_pushButton_MainMenuQuit_clicked(void)
{
    this->close();
}

//-----------------------------------------------------------------------------Difficulty Menu
//********************************************************************************
//PushButton Easy clicked on Difficulty Menu
void window_main_screen::on_pushButton_DifficultyMenuEasy_clicked(void)
{
    //play screen open easy mode
    gameinfo.setNewGame(1);
    startGame();
}

//********************************************************************************
//PushButton Medium clicked on Difficulty Menu
void window_main_screen::on_pushButton_DifficultyMenuMedium_clicked(void)
{
    gameinfo.setNewGame(2);
    //play screen open medium mode
    startGame();
}

//********************************************************************************
//PushButton Hard clicked on Difficulty Menu
void window_main_screen::on_pushButton_DifficultyMenuHard_clicked(void)
{
    //play screen open medium mode
    gameinfo.setNewGame(3);
    startGame();
}

//---------------------------------------------------------------------------------Play Screen
//********************************************************************************
//PushButton Pause clicked on Play Screen
void window_main_screen::on_pushButton_PlayScreenPause_clicked(void)
{
    ui->stackedWidget_mainscreen->setCurrentIndex(PAUSEMENU);
    clearStackerPlayfield();
}

//********************************************************************************
//PushButton Stack clicked on Play Screen
void window_main_screen::on_pushButton_PlayScreenStack_pressed(void)
{
    //move block up
    int iReturnWinOrLose, iRandomEndImg;
    iReturnWinOrLose = moveBlockUp();   //moves block up and returns if won or lost
    if(iReturnWinOrLose)                //the player has won or lost
    {
        iRandomEndImg = rand()%5;       //generates random for random image switch
        if(iReturnWinOrLose == 1)       //the player has won
        {
            ui->label_EndGameMessage->setText("You just won");  //set message for player
            switch (iRandomEndImg) {
            case 0:
                ui->frame_EndGameImg->setStyleSheet("image: url(:/images/EndGame/won/EpicWin.jpg);");
                break;
            case 1:
                ui->frame_EndGameImg->setStyleSheet("image: url(:/images/EndGame/won/FredMercury.png);");
                break;
            case 2:
                ui->frame_EndGameImg->setStyleSheet("image: url(:/images/EndGame/won/ObamaVictory.jpeg);");
                break;
            case 3:
                ui->frame_EndGameImg->setStyleSheet("image: url(:/images/EndGame/won/ThanksObama.jpg);");
                break;
            case 4:
                ui->frame_EndGameImg->setStyleSheet("image: url(:/images/EndGame/won/WinAllTheGames.jpg);");
                break;
            default:
                ui->frame_EndGameImg->setStyleSheet("image: url(:/images/EndGame/won/Winner.jpg;)");
                break;
            }
        }
        else                            //the player has lost
        {
            ui->label_EndGameMessage->setText("You just lost");  //set message for player
            switch (iRandomEndImg) {
            case 0:
                ui->frame_EndGameImg->setStyleSheet("image: url(:/images/EndGame/lost/DadYouLost.jpg);");
                break;
            case 1:
                ui->frame_EndGameImg->setStyleSheet("image: url(:/images/EndGame/lost/IAmA.jpg);");
                break;
            case 2:
                ui->frame_EndGameImg->setStyleSheet("image: url(:/images/EndGame/lost/JesusSaysYouJustLostTheGame.jpg);");
                break;
            case 3:
                ui->frame_EndGameImg->setStyleSheet("image: url(:/images/EndGame/lost/RosesAreRedVioletsAreBlue.jpg);");
                break;
            case 4:
                ui->frame_EndGameImg->setStyleSheet("image: url(:/images/EndGame/lost/youjustlost.jpg);");
                break;
            default:
                ui->frame_EndGameImg->setStyleSheet("image: url(:/images/EndGame/lost/YouLostTheGame.jpg);");
                break;
            }

        }
        showPlayfield();                                            //shows the playfield
        delay(200);                                                 //delays and go to end game screen
        gameinfo.clearPlayfield();                                  //clears the playfield
        showPlayfield();                                            //show playfield so it is empty
        ui->lcdNumber_EndGameScore->display(gameinfo.getScore());   //display score on endgame screen
        ui->stackedWidget_mainscreen->setCurrentIndex(ENDGAME);     //set the window to the end game screen
    }
}

//********************************************************************************
//Shows the playfield in the Qtablewidget
void window_main_screen::showPlayfield(void)
{
    int iRow, iColumn, iRandomBack, iRandomBlock;
    for(iRow = 0; iRow < PLAYFIELDHEIGHT; iRow++)                                               //go through all the rows of the playfield
    {
        for(iColumn = 0; iColumn < PLAYFIELDWIDTH; iColumn++)                                   //go through all the columns of the playfield
        {
            if((gameinfo.getPlayfield(iRow, iColumn)) == true)                                  //if there needs to be a block on this place
            {
                if(ui->checkBox_SettingsPartyMode->isChecked())                                 //check if the party mode is set in the settings
                {
                    iRandomBlock = rand()%6;                                                    //generate random for random block color
                }
                else                                                                            //if the party mode is not set use the value of the block dropdown menu in the settings
                {
                    iRandomBlock = ui->comboBox_SettingsPlayScreenColorBlock->currentIndex();   //gets the index from the dropdown box in the settings
                }
                switch (iRandomBlock){                                                          //set the color of the current cell
                case RED:
                    ui->tableWidget_PlayScreenPlayfield->setItem(iRow, iColumn,  new QTableWidgetItem);
                    ui->tableWidget_PlayScreenPlayfield->item(iRow, iColumn)->setBackground(Qt::red);
                    break;
                case GREEN:
                    ui->tableWidget_PlayScreenPlayfield->setItem(iRow, iColumn,  new QTableWidgetItem);
                    ui->tableWidget_PlayScreenPlayfield->item(iRow, iColumn)->setBackground(Qt::green);
                    break;
                case YELLOW:
                    ui->tableWidget_PlayScreenPlayfield->setItem(iRow, iColumn,  new QTableWidgetItem);
                    ui->tableWidget_PlayScreenPlayfield->item(iRow, iColumn)->setBackground(Qt::yellow);
                    break;
                case BLUE:
                    ui->tableWidget_PlayScreenPlayfield->setItem(iRow, iColumn,  new QTableWidgetItem);
                    ui->tableWidget_PlayScreenPlayfield->item(iRow, iColumn)->setBackground(Qt::blue);
                    break;
                case CYAN:
                    ui->tableWidget_PlayScreenPlayfield->setItem(iRow, iColumn,  new QTableWidgetItem);
                    ui->tableWidget_PlayScreenPlayfield->item(iRow, iColumn)->setBackground(Qt::cyan);
                    break;
                case MAGENTA:
                    ui->tableWidget_PlayScreenPlayfield->setItem(iRow, iColumn,  new QTableWidgetItem);
                    ui->tableWidget_PlayScreenPlayfield->item(iRow, iColumn)->setBackground(Qt::magenta);
                    break;
                case LIGHTGRAY:
                    ui->tableWidget_PlayScreenPlayfield->setItem(iRow, iColumn,  new QTableWidgetItem);
                    ui->tableWidget_PlayScreenPlayfield->item(iRow, iColumn)->setBackground(Qt::lightGray);
                    break;
                case WHITE:
                    ui->tableWidget_PlayScreenPlayfield->setItem(iRow, iColumn,  new QTableWidgetItem);
                    ui->tableWidget_PlayScreenPlayfield->item(iRow, iColumn)->setBackground(Qt::white);
                    break;
                case BLACK:
                    ui->tableWidget_PlayScreenPlayfield->setItem(iRow, iColumn,  new QTableWidgetItem);
                    ui->tableWidget_PlayScreenPlayfield->item(iRow, iColumn)->setBackground(Qt::black);
                    break;
                default:
                    ui->tableWidget_PlayScreenPlayfield->setItem(iRow, iColumn,  new QTableWidgetItem);
                    ui->tableWidget_PlayScreenPlayfield->item(iRow, iColumn)->setBackground(Qt::white);
                    break;
                }
            }
            else                                                                                                    //if there doesn't needs to be a block on this place
            {
                QTableWidgetItem *icon_item = new QTableWidgetItem;                                                 //construct tablewidget item for a icon
                QIcon icon("://images/doge.jpeg");                                                                  //Constructs an icon from a pixmap
                ui->tableWidget_PlayScreenPlayfield->setIconSize(QSize(PLAYSCREENROWHEIGHT, PLAYSCREENCOLMNWIDTH)); //set the icon size
                icon_item->setIcon(icon);                                                                           //set incon in the tablewidget item
                if(ui->pushButton_PlayScreenStack->text() == "Doge")                                                //check if the eastereggbutton was clicked by checking a label
                {
                    iRandomBack = DOGE_IMG;                                                                         //set the Icon as the background of the block
                }
                else if(ui->checkBox_SettingsDoge->isChecked())                                                     //if Doge is checked in the settings
                {
                    if(rand()%9002)                                                                                 //make random number between 0 and 9001
                    {
                        iRandomBack = ui->comboBox_SettingsPlayScreenColorBack->currentIndex();                     //gets the index from the dropdown box in the settings
                    }
                    else                                                                                            //if the random number is equal to 0 set the icon as background
                    {
                        iRandomBack = DOGE_IMG;
                    }
                }
                else                                                                                                //nonthing special, use normal color
                {
                    iRandomBack = ui->comboBox_SettingsPlayScreenColorBack->currentIndex();                         //gets the index from the dropdown box in the settings
                }
                switch (iRandomBack) {                                                                              //set the color of the current cell
                case RED:
                    ui->tableWidget_PlayScreenPlayfield->setItem(iRow, iColumn,  new QTableWidgetItem);
                    ui->tableWidget_PlayScreenPlayfield->item(iRow, iColumn)->setBackground(Qt::red);
                    break;
                case GREEN:
                    ui->tableWidget_PlayScreenPlayfield->setItem(iRow, iColumn,  new QTableWidgetItem);
                    ui->tableWidget_PlayScreenPlayfield->item(iRow, iColumn)->setBackground(Qt::green);
                    break;
                case YELLOW:
                    ui->tableWidget_PlayScreenPlayfield->setItem(iRow, iColumn,  new QTableWidgetItem);
                    ui->tableWidget_PlayScreenPlayfield->item(iRow, iColumn)->setBackground(Qt::yellow);
                    break;
                case BLUE:
                    ui->tableWidget_PlayScreenPlayfield->setItem(iRow, iColumn,  new QTableWidgetItem);
                    ui->tableWidget_PlayScreenPlayfield->item(iRow, iColumn)->setBackground(Qt::blue);
                    break;
                case CYAN:
                    ui->tableWidget_PlayScreenPlayfield->setItem(iRow, iColumn,  new QTableWidgetItem);
                    ui->tableWidget_PlayScreenPlayfield->item(iRow, iColumn)->setBackground(Qt::cyan);
                    break;
                case MAGENTA:
                    ui->tableWidget_PlayScreenPlayfield->setItem(iRow, iColumn,  new QTableWidgetItem);
                    ui->tableWidget_PlayScreenPlayfield->item(iRow, iColumn)->setBackground(Qt::magenta);
                    break;
                case LIGHTGRAY:
                    ui->tableWidget_PlayScreenPlayfield->setItem(iRow, iColumn,  new QTableWidgetItem);
                    ui->tableWidget_PlayScreenPlayfield->item(iRow, iColumn)->setBackground(Qt::lightGray);
                    break;
                case WHITE:
                    ui->tableWidget_PlayScreenPlayfield->setItem(iRow, iColumn,  new QTableWidgetItem);
                    ui->tableWidget_PlayScreenPlayfield->item(iRow, iColumn)->setBackground(Qt::white);
                    break;
                case BLACK:
                    ui->tableWidget_PlayScreenPlayfield->setItem(iRow, iColumn,  new QTableWidgetItem);
                    ui->tableWidget_PlayScreenPlayfield->item(iRow, iColumn)->setBackground(Qt::black);
                    break;
                case DOGE_IMG:
                    ui->tableWidget_PlayScreenPlayfield->setItem(iRow, iColumn, icon_item);
                    ui->tableWidget_PlayScreenPlayfield->item(iRow, iColumn)->setBackground(Qt::transparent);
                    break;
                default:
                    ui->tableWidget_PlayScreenPlayfield->setItem(iRow, iColumn,  new QTableWidgetItem);
                    ui->tableWidget_PlayScreenPlayfield->item(iRow, iColumn)->setBackground(Qt::white);
                    break;
                }

            }
        }
    }
}

//********************************************************************************
//Sets a random image in the playscreen Stacker logo frame
void window_main_screen::randomImgPlayfield(int iRandomImg)
{
    switch (iRandomImg) {
    case 1:  //img red
        ui->frame_PlayScreenStackerLogo->setStyleSheet("image: url(:/images/logo/StackerLogoRed.png);");
        break;
    case 2:  //img green
        ui->frame_PlayScreenStackerLogo->setStyleSheet("image: url(:/images/logo/StackerLogoGreen.png);");
        break;
    case 3:  //img yellow
        ui->frame_PlayScreenStackerLogo->setStyleSheet("image: url(:/images/logo/StackerLogoYellow.png);");
        break;
    case 4:  //img purple
        ui->frame_PlayScreenStackerLogo->setStyleSheet("image: url(:/images/logo/StackerLogoPurple.png);");
        break;
    default:  //neutral img
        ui->frame_PlayScreenStackerLogo->setStyleSheet("image: url(:/images/logo/StackerLogoNeutral.png);");
        break;
    }
}

//----------------------------------------------------------------------------------Pause Menu
//********************************************************************************
//PushButton Resume clicked on Pause Menu
void window_main_screen::on_pushButton_PauseMenuResume_clicked(void)
{
    startGame();
}

//********************************************************************************
//PushButton Main Menu clicked on Pause Menu
void window_main_screen::on_pushButton_PauseMenuMainMenu_clicked(void)
{
    ui->stackedWidget_mainscreen->setCurrentIndex(MAINMENU);
}

//********************************************************************************
//PushButton Save Game clicked on Pause Menu
void window_main_screen::on_pushButton_PauseMenuSaveGame_clicked(void)
{
    QString qsFileName;
    qsFileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Stacker files (*.stack)"));    //gets a location from the user
    if(saveGame(qsFileName))                                                                                //the file was saved
    {
        ui->label_PauseMenuStatus->setText("The File is saved!");
    }
    else                                                                                                    //somthing went wrong, the file was not saved
    {
        ui->label_PauseMenuStatus->setText("The File is not saved!");
    }
    delay(2000);
    ui->label_PauseMenuStatus->clear();                                                                     //clears the status label
}

//********************************************************************************
//PushButton Quit clicked on Pause Menu
void window_main_screen::on_pushButton_PauseMenuQuit_clicked(void)
{
    this->close();
}

//----------------------------------------------------------------------------------------Help
//********************************************************************************
//PushButton Main Menu clicked on Help
void window_main_screen::on_pushButton_HelpMainMenu_clicked(void)
{
    ui->stackedWidget_mainscreen->setCurrentIndex(MAINMENU);
}

//---------------------------------------------------------------------------------------About
//********************************************************************************
//PushButton Main Menu clicked on About
void window_main_screen::on_pushButton_AboutMainMenu_clicked(void)
{
    ui->stackedWidget_mainscreen->setCurrentIndex(MAINMENU);
}

//********************************************************************************
//PushButton EasterEgg clicked on About
void window_main_screen::on_pushButton_AboutStackerEasterEgg_clicked(void)
{
    QString qsDogeStyleButton = "font: 10pt 'Arial Rounded MT Bold';",
            qsDogeImg = "image: url(:/images/doge.jpeg);",
            //mainmenu
            qsDogeMainVersion = QString ("<font color='red'>%1.<font color='#D8A54A'>Doge</font>").arg(VERSION),
            qsDogeMainMenuNewGame = "So New",
            qsDogeMainMenuLoadGame = "So Load",
            qsDogeMainMenuAbout = "Much Abouts",
            qsDogeMainMenuHelp = "Y U Know nothing",
            qsDogeMainMenuQuit = "wow.. Quit",
            //diff menu
            qsDogeDiffTitle = "wow.. so choice",
            qsDogeDiffEasy = "Such ease",
            qsDogeDiffMedium = "So medium",
            qsDogeDiffHard  = "Much Hard",
            //About
            qsDogeAboutTitle = "Much About",
            qsDogeAboutMainText = "<font color='#00FF00'>Such game</font><br>&nbsp;&nbsp;&nbsp;&nbsp;Good programmer<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;much <font color='#FF0000'>Ingmar</font>",
            qsDogeAboutStackerVersion = QString ("V%1.<font color='#D8A54A'>Doge</font>").arg(VERSION),
            qsDogeAboutMainMenu = "... Main Doge",
            //help
            qsDogeHelpMainText = "Try to Doge as many Doges, as high as Doge-able.<br>You will lose the number of Doges<br>you placed Dogecorrectly.<br><br>The game is played with the Doge bar or the Doge button.<br>To place the Doge press Doge or press Doge.<br>While in game you can press Doge<br>&nbsp;&nbsp;Now you are in the Doge menu<br>&nbsp;&nbsp;From here you can Doge your game,<br>&nbsp;&nbsp;or go back to the Doge menu.<br><br>Have Doge!",
            qsDogeHelpTitle = "Doge",
            qsDogeHelpMainMenu = "gotha me outta here",
            //playscreen
            qsDogePlayScreenStack = "Doge",
            //Pause Menu
            qsDogePauseMenuTitle = "Stahp",
            qsDogePauseMenuSave = "So Save",
            qsDogePauseMenuMainMenu = "Ur wanna go back?",
            qsDogePauseMenuQuit = "Such sad, much quit",
            //settings menu
            qsDogeSettingsTitle = "Doge-ins",
            qsDogeSettingsPartyMode = "Doge-mode",
            qsDogeSettingsDoge = "Doge ?!!",
            qsDogeSettingsFullScreen = "Full doge",
            qsDogeSettingsPickBlockColor = "Choose Wisely:",
            qsDogeSettingsPickBackColor = "Hmm... Colors?",
            qsDogeSettingsSaveSettings = "Save Doge-ins",
            //end game
            qsDogeEndPoints = "Doges",
            //Action Menu
            qsDogeActionMainMenu = "Doge",
            qsDogeActionSettings = "Doge-ins",
            qsDogeActionQuit = "Dogeit",
            qsDogeActionHelp = "Y U Know nothing John Snow",
            qsDogeActionAbout = "it's me Doge",
            //Main Window
            qsDogeMainWindowTitle = QString ("Much Doge.........Much Stacker %1.......so much WOW").arg(VERSION);


    //mainmenu
    ui->frameLogoMain->setStyleSheet(qsDogeImg);
    ui->label_MainMenuStackerVersion->setText(qsDogeMainVersion);
    ui->label_MainMenuStackerVersion->setStyleSheet(qsDogeStyleButton);
    ui->pushButton_MainMenuNewGame->setText(qsDogeMainMenuNewGame);
    ui->pushButton_MainMenuNewGame->setStyleSheet(qsDogeStyleButton);
    ui->pushButton_MainMenuLoadGame->setText(qsDogeMainMenuLoadGame);
    ui->pushButton_MainMenuLoadGame->setStyleSheet(qsDogeStyleButton);
    ui->pushButton_MainMenuAbout->setText(qsDogeMainMenuAbout);
    ui->pushButton_MainMenuAbout->setStyleSheet(qsDogeStyleButton);
    ui->pushButton_MainMenuHelp->setText(qsDogeMainMenuHelp);
    ui->pushButton_MainMenuHelp->setStyleSheet(qsDogeStyleButton);
    ui->pushButton_MainMenuQuit->setText(qsDogeMainMenuQuit);
    ui->pushButton_MainMenuQuit->setStyleSheet(qsDogeStyleButton);

    //diff menu
    ui->label_DifficultyMenuTitle->setText(qsDogeDiffTitle);
    ui->pushButton_DifficultyMenuEasy->setText(qsDogeDiffEasy);
    ui->pushButton_DifficultyMenuEasy->setStyleSheet(qsDogeStyleButton);
    ui->pushButton_DifficultyMenuMedium->setText(qsDogeDiffMedium);
    ui->pushButton_DifficultyMenuMedium->setStyleSheet(qsDogeStyleButton);
    ui->pushButton_DifficultyMenuHard->setText(qsDogeDiffHard);
    ui->pushButton_DifficultyMenuHard->setStyleSheet(qsDogeStyleButton);

    //About
    ui->pushButton_AboutStackerEasterEgg->setEnabled(false);
    ui->frame_AboutLogo->setStyleSheet(qsDogeImg);
    ui->label_AboutTitle->setText(qsDogeAboutTitle);
    ui->label_AboutMainText->setText(qsDogeAboutMainText);
    ui->label_AboutStackerVersion->setText(qsDogeAboutStackerVersion);
    ui->pushButton_AboutMainMenu->setStyleSheet(qsDogeStyleButton);
    ui->pushButton_AboutMainMenu->setText(qsDogeAboutMainMenu);

    //help
    ui->label_HelpMainText->setText(qsDogeHelpMainText);
    ui->label_HelpTitle->setText(qsDogeHelpTitle);
    ui->pushButton_HelpMainMenu->setStyleSheet(qsDogeStyleButton);
    ui->pushButton_HelpMainMenu->setText(qsDogeHelpMainMenu);

    //playscreen
    ui->pushButton_PlayScreenStack->setText(qsDogePlayScreenStack);
    ui->pushButton_PlayScreenPause->setFlat(false);

    //settings
    ui->label_SettingsTitle->setText(qsDogeSettingsTitle);
    ui->checkBox_SettingsPartyMode->setText(qsDogeSettingsPartyMode);
    ui->checkBox_SettingsDoge->setText(qsDogeSettingsDoge);
    ui->checkBox_SettingsFullScreen->setText(qsDogeSettingsFullScreen);
    ui->label_SettingsPickBlockColor->setText(qsDogeSettingsPickBlockColor);
    ui->label_SettingsPickBackColor->setText(qsDogeSettingsPickBackColor);
    ui->pushButton_SettingsSaveSettings->setText(qsDogeSettingsSaveSettings);
    ui->checkBox_SettingsPartyMode->setChecked(true);

    //pause menu
    ui->label_PauseMenuTitle->setText(qsDogePauseMenuTitle);
    ui->pushButton_PauseMenuMainMenu->setText(qsDogePauseMenuMainMenu);
    ui->pushButton_PauseMenuMainMenu->setStyleSheet(qsDogeStyleButton);
    ui->pushButton_PauseMenuSaveGame->setText(qsDogePauseMenuSave);
    ui->pushButton_PauseMenuSaveGame->setStyleSheet(qsDogeStyleButton);
    ui->pushButton_PauseMenuQuit->setText(qsDogePauseMenuQuit);
    ui->pushButton_PauseMenuQuit->setStyleSheet(qsDogeStyleButton);

    //end game menu
    ui->label_EndGamePoints->setText(qsDogeEndPoints);

    //action menu
    ui->actionMain_Menu->setText(qsDogeActionMainMenu);
    ui->actionSettings->setText(qsDogeActionSettings);
    ui->actionQuit->setText(qsDogeActionQuit);
    ui->actionAbout->setText(qsDogeActionAbout);
    ui->actionHelp->setText(qsDogeActionHelp);

    //Main Window Settigs
    this->setWindowIcon(QIcon(":/images/doge_logo.png"));
    this->setWindowTitle(qsDogeMainWindowTitle);
    ui->checkBox_SettingsInstantEpilepsy->setChecked(true);
    timer.start(1, this);
}

//------------------------------------------------------------------------------------End Game
//********************************************************************************
//PushButton Main Menu clicked on End Game
void window_main_screen::on_pushButton_EndGameMainMenu_clicked(void)
{
    ui->stackedWidget_mainscreen->setCurrentIndex(MAINMENU);
}

//------------------------------------------------------------------------------------Settings
//********************************************************************************
//PushButton Save Settings clicked on Settings
void window_main_screen::on_pushButton_SettingsSaveSettings_clicked(void)
{
    int iScreenOffsetX, iScreenOffsetY;
    if(ui->checkBox_SettingsFullScreen->isChecked())                                                                                            //if fulscreen is set
    {
        this->setWindowState(Qt::WindowFullScreen);                                                                                             //set window fullscreen
        iScreenOffsetX = ((window_main_screen::width()) - MAINWINDOWWIDTH)/2;                                                                   //get the offset for the stacked widget X
        iScreenOffsetY = ((window_main_screen::height()) - MAINWINDOWHEIGHT)/2;                                                                 //get the offset for the stacked widget Y
        ui->stackedWidget_mainscreen->setGeometry(iScreenOffsetX, iScreenOffsetY, MAINWINDOWWIDTH, MAINWINDOWHEIGHT);                           //set the offset of the stacked widget
    }
    else                                                                                                                                        //fullscreen is not set
    {
        if(this->isFullScreen())                                                                                                                //if this window is fullscreen
        {
            ui->stackedWidget_mainscreen->setGeometry(MAINWINDOWDEFAULTOFFSETX, MAINWINDOWDEFAULTOFFSETY, MAINWINDOWWIDTH, MAINWINDOWHEIGHT);   //set default offset settings
            this->setWindowState(Qt::WindowMaximized);                                                                                          //set the window normal
        }
    }
    if(ui->checkBox_SettingsInstantEpilepsy->isChecked())                                                                                       //if in the settings Instant Epilepy is checked
    {
        timer.start(1, this);                                                                                                                   //start the timer for changing background
    }
    else                                                                                                                                        //if instant epilepsy is not checked, set no style
    {
        this->setStyleSheet("");
    }
    ui->stackedWidget_mainscreen->setCurrentIndex(MAINMENU);
}

//--------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------Other Functions
//--------------------------------------------------------------------------------------------

//********************************************************************************
//function to start the timer and set active window to playscreen
void window_main_screen::startGame(void)
{
    ui->stackedWidget_mainscreen->setCurrentIndex(PLAYSCREEN);  //set window to playscreen
    timer.start(1, this);                                       //setup timer
}

//********************************************************************************
//function to initialize the mainwindow of stacker
void window_main_screen::initializeStacker(void)
{
    int icolmn, irow;

    this->setWindowTitle(APPNAME_VERSION);                      //set the window title with verion number
    ui->label_MainMenuStackerVersion->setText(VERSION);         //set the mainmenu version number
    ui->label_AboutStackerVersion->setText(APPNAME_VERSION);    //set version number in About

                                                                //add Qcombobox color items for settings
    ui->comboBox_SettingsPlayScreenColorBlock->addItem("Red");
    ui->comboBox_SettingsPlayScreenColorBlock->addItem("Green");
    ui->comboBox_SettingsPlayScreenColorBlock->addItem("Yellow");
    ui->comboBox_SettingsPlayScreenColorBlock->addItem("Blue");
    ui->comboBox_SettingsPlayScreenColorBlock->addItem("Cyan");
    ui->comboBox_SettingsPlayScreenColorBlock->addItem("Magenta");
    ui->comboBox_SettingsPlayScreenColorBlock->addItem("LightGray");
    ui->comboBox_SettingsPlayScreenColorBlock->addItem("White");
    ui->comboBox_SettingsPlayScreenColorBlock->addItem("Black");
    ui->comboBox_SettingsPlayScreenColorBlock->setCurrentIndex(RED);    //set Qcombobox color to default

    ui->comboBox_SettingsPlayScreenColorBack->addItem("Red");
    ui->comboBox_SettingsPlayScreenColorBack->addItem("Green");
    ui->comboBox_SettingsPlayScreenColorBack->addItem("Yellow");
    ui->comboBox_SettingsPlayScreenColorBack->addItem("Blue");
    ui->comboBox_SettingsPlayScreenColorBack->addItem("Cyan");
    ui->comboBox_SettingsPlayScreenColorBack->addItem("Magenta");
    ui->comboBox_SettingsPlayScreenColorBack->addItem("LightGray");
    ui->comboBox_SettingsPlayScreenColorBack->addItem("White");
    ui->comboBox_SettingsPlayScreenColorBack->addItem("Black");
    ui->comboBox_SettingsPlayScreenColorBack->setCurrentIndex(WHITE);   //set Qcombobox color to default

    QTime time = QTime::currentTime();                          //seed random number generator
    qsrand((uint)time.msec());

    this->statusBar()->setSizeGripEnabled(false);               //disable/hide resize bar for the mainwindow
    ui->stackedWidget_mainscreen->setCurrentIndex(MAINMENU);    //on load set mainscreen to mainmenu
    ui->pushButton_AboutStackerEasterEgg->setFlat(true);        //set About button flat (easter egg button)

    QFontDatabase ArialRoundedMTBold, Rust, Minercraftory;      //Creates font database objects for custom fonts
    ArialRoundedMTBold.addApplicationFont(":/fonts/Arial Rounded MT Bold Bold.ttf");
    Rust.addApplicationFont(":/fonts/Rust.ttf");
    Minercraftory.addApplicationFont(":/fonts/Minercraftory.ttf");

    ui->tableWidget_PlayScreenPlayfield->horizontalHeader()->hide();    //delete horizontal header of playfield table
    ui->tableWidget_PlayScreenPlayfield->verticalHeader()->hide();      //delete vertical header of playfield table

    for(irow = 0; irow < PLAYFIELDHEIGHT; irow++)                       //makes the PlayField Rows
    {
        ui->tableWidget_PlayScreenPlayfield->insertRow(irow);
        ui->tableWidget_PlayScreenPlayfield->setRowHeight(irow, PLAYSCREENROWHEIGHT);
    }
    for(icolmn = 0; icolmn < PLAYFIELDWIDTH; icolmn++)                  //makes the PlayField Columns
    {
        ui->tableWidget_PlayScreenPlayfield->insertColumn(icolmn);
        ui->tableWidget_PlayScreenPlayfield->setColumnWidth(icolmn, PLAYSCREENCOLMNWIDTH);
    }

    ui->tableWidget_PlayScreenPlayfield->setEditTriggers(QAbstractItemView::NoEditTriggers);      //disable editing in the playfield
    ui->tableWidget_PlayScreenPlayfield->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);      //disable scrollbar vertical in the playfield
    ui->tableWidget_PlayScreenPlayfield->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);    //disable scroll bar horizontal in the playfield
    ui->tableWidget_PlayScreenPlayfield->setSelectionMode(QAbstractItemView::NoSelection);        //disable selection of cells in the playfield
    ui->tableWidget_PlayScreenPlayfield->clearSelection();                                        //clear selection in the playfield
    ui->tableWidget_PlayScreenPlayfield->setFocusPolicy(Qt::NoFocus);                             //clear focus in the playfield
}

//********************************************************************************
//function to clear the stacker field of all the blocks
void window_main_screen::clearStackerPlayfield(void)
{
    int iRow, iColumn;
    for(iRow = 0; iRow < PLAYFIELDHEIGHT; iRow++)                                               //go through all the rows of the playfield
    {
        for(iColumn = 0; iColumn < PLAYFIELDWIDTH; iColumn++)                                   //go through all the columns of the playfield
        {
            ui->tableWidget_PlayScreenPlayfield->setItem(iRow, iColumn,  new QTableWidgetItem);
            ui->tableWidget_PlayScreenPlayfield->item(iRow, iColumn)->setBackground(Qt::white);
        }
    }
    showPlayfield();
}

//********************************************************************************
//function to continuously do something on a timer
void window_main_screen::timerEvent(QTimerEvent *event)
{
    int iRandomChangeImg, iRandomRed, iRandomGreen, iRandomBlue;
    QString qsMainWindowStyle;
    if(!(ui->stackedWidget_mainscreen->currentIndex() == PLAYSCREEN))       //if the pplay screen is not active, clear it
    {
        clearStackerPlayfield();
    }
    if(ui->stackedWidget_mainscreen->currentIndex() == PLAYSCREEN)          //if playscreen is the active screen, update the timer
    {
        timer.start(gameinfo.getCurrentBlockSpeed(), this);
    }
    if((ui->stackedWidget_mainscreen->currentIndex() != PLAYSCREEN) &&
       (ui->checkBox_SettingsInstantEpilepsy->isChecked()))                 //if playscreen is not the active screen and Instant Epilepsy is checked, update the timer
    {
        timer.start(EASTEREGGTIMERTIMER, this);
    }
    else if (ui->stackedWidget_mainscreen->currentIndex() != PLAYSCREEN)    //if playscreen is not the active screen stop the timer
    {
        timer.stop();
    }
    if (event->timerId() == timer.timerId())
    {
        if(ui->checkBox_SettingsInstantEpilepsy->isChecked())               //if Instant Epilepsy is checked set a random background color
        {
            iRandomRed = rand()%256;                                        //random rgb value: Red
            iRandomGreen = rand()%256;                                      //random rgb value: Green
            iRandomBlue = rand()%256;                                       //random rgb value: Blue
            qsMainWindowStyle = QString("QMainWindow{ background-color: rgb(%1, %2, %3, );}").arg(iRandomRed).arg(iRandomGreen).arg(iRandomBlue);
            this->setStyleSheet(qsMainWindowStyle);                         //set main window style
        }
        if(ui->stackedWidget_mainscreen->currentIndex() == PLAYSCREEN)      //if playscreen is active
        {
            if(gameinfo.getCurrentPosition() == 1)                          //if block position is 1 set the focus
            {
                ui->pushButton_PlayScreenStack->setFocus();                 //set focus to stack button for use of space
            }
            if(ui->checkBox_SettingsPartyMode->isChecked())                 //if Party Mode is checked change the stacker logo
            {
                iRandomChangeImg = (rand()%6+1);
                randomImgPlayfield(iRandomChangeImg);
            }
            else
            {
                randomImgPlayfield(0);
            }
            ui->lcd_PlayScreenScore->display(gameinfo.getScore());          //display the score
            moveBlockSide();                                                //move the block
            showPlayfield();                                                //show the playfield
        }
        update();                                                           //Updates the widget unless updates are disabled or the widget is hidden, it is not necessary
    }
    else
    {
        QWidget::timerEvent(event);
    }
}

//********************************************************************************
//check what key is pressed
void window_main_screen::keyPressEvent(QKeyEvent *event)
{
    if((event->key() == Qt::Key_Escape) && (ui->stackedWidget_mainscreen->currentIndex() == PLAYSCREEN))        //if playscreen is active and ESC is pressed, go to pause menu
    {
        ui->stackedWidget_mainscreen->setCurrentIndex(PAUSEMENU);
    }
    else if((event->key() == Qt::Key_Escape) && (ui->stackedWidget_mainscreen->currentIndex() == PAUSEMENU))    //if pause menu is active and ESC ispressed, go to playscreen
    {
        startGame();                                                                                            //start the game again
    }
}

//********************************************************************************
//delay function
void delay(int milliseconds)
{
    QTime dieTime = QTime::currentTime().addMSecs( milliseconds );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}
