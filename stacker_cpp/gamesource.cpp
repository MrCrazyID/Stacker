/**
 * @file gamesource.cpp
 * @author Ingmar Delsink
 * @date 2 may 2014
 * @brief File containing gamesource of Stacker.
 * In this file the gamesource of Stacker can be found.
 * Like moving the block up or sideways till saving and loading
 * save files.
 */

#include "gamesource.h"
#include "gameinfo.h"

#include <math.h>
#include <QString>
#include <QSettings>




//********************************************************************************
//fuction to move the block to the sides
void moveBlockSide(void)
{
    int iClearColmnCount, iBlockCount, iStepsFromBlockToSide, iNextPosition;
    //clear the array row
    for(iClearColmnCount = 0; iClearColmnCount < PLAYFIELDWIDTH; iClearColmnCount++)
    {
        gameinfo.setPlayfield(gameinfo.getCurrentArrayRow(), iClearColmnCount, false);
    }

    //place blocks in array
    for(iBlockCount = 0; iBlockCount < gameinfo.getBlockLength(); iBlockCount++)
    {
        gameinfo.setPlayfield(gameinfo.getCurrentArrayRow(), (gameinfo.getCurrentPosition() + iBlockCount), true);
    }

    //get steps
    iStepsFromBlockToSide = PLAYFIELDWIDTH - (gameinfo.getCurrentPosition() + gameinfo.getBlockLength());
    if(iStepsFromBlockToSide == 0)
    {
        gameinfo.setCurrentDirection(false);
    }
    else if(iStepsFromBlockToSide == (PLAYFIELDWIDTH - gameinfo.getBlockLength()))
    {
        gameinfo.setCurrentDirection(true);
    }

    //write current position
    if(gameinfo.getCurrentDirection() == true)
    {
        iNextPosition = gameinfo.getCurrentPosition() + 1;
        gameinfo.setCurrentPosition(iNextPosition);
    }
    else
    {
        iNextPosition = gameinfo.getCurrentPosition() - 1;
        gameinfo.setCurrentPosition(iNextPosition);
    }
}

//********************************************************************************
//fuction to move the block up and check if lost or won
int moveBlockUp(void)
{
    int iTellerCheckBlocks, iBlockLengthNew, iScoreNew, iCurrentRowNew;
    //check if block is suported
    if(gameinfo.getCurrentArrayRow() < PLAYFIELDHEIGHT-1)
    {
        for(iTellerCheckBlocks = 0; iTellerCheckBlocks < PLAYFIELDWIDTH; iTellerCheckBlocks++)
        {
            if(gameinfo.getPlayfield(gameinfo.getCurrentArrayRow(), iTellerCheckBlocks) == true && gameinfo.getPlayfield((gameinfo.getCurrentArrayRow() + 1), iTellerCheckBlocks) == false)
            {
                //block is not suported lengt block minus 1
                gameinfo.setPlayfield(gameinfo.getCurrentArrayRow(), iTellerCheckBlocks, false);
                iBlockLengthNew = gameinfo.getBlockLength() - 1;
                gameinfo.setBlockLength(iBlockLengthNew);
            }
            //else all is fine
        }
    }

    //write score
    //score = old score + BlockLength^Difficulty
    iScoreNew = gameinfo.getScore() + pow(gameinfo.getBlockLength(), gameinfo.getDifficulty());
    gameinfo.setScore(iScoreNew);

    //current row --
    iCurrentRowNew = gameinfo.getCurrentArrayRow() - 1;
    gameinfo.setCurrentArrayRow(iCurrentRowNew);

    //check if win or lost
    //returns 0 if nothing happend
    //returns 1 if won
    //returns 2 if lost

    if(gameinfo.getBlockLength() <= 0)
    {
        //lost
        return 2;
    }
    else if((gameinfo.getCurrentArrayRow() <= -1) && (gameinfo.getBlockLength() >= 1))
    {
        //won
        return 1;
    }
    else
    {
        //nothing happend
        return 0;
    }
}

//********************************************************************************
//function to load a game
int loadGame(QString qsFileNameAndPath)
{
    int iRow, iColumn;
    QString qsPlayFieldValueVarName;
    QSettings qsGameDataFile(qsFileNameAndPath, QSettings::IniFormat);

    if(qsFileNameAndPath != NULL)
    {
        //load array in
        qsGameDataFile.beginGroup("PlayField");
        for(iRow = 0; iRow < PLAYFIELDHEIGHT; iRow++)
        {
            for(iColumn = 0; iColumn < PLAYFIELDWIDTH; iColumn++)
            {
                qsPlayFieldValueVarName = "PlayFieldValue" + QString::number(iRow) + QString::number(iColumn);
                gameinfo.setPlayfield(iRow, iColumn, qsGameDataFile.value(qsPlayFieldValueVarName).toBool());
            }
        }
        qsGameDataFile.endGroup();
        qsGameDataFile.beginGroup("Variables");
        gameinfo.setGameDataVariables(qsGameDataFile.value("Score").toInt(),
                                      qsGameDataFile.value("ArrayRow").toInt(),
                                      qsGameDataFile.value("BlockLength").toInt(),
                                      qsGameDataFile.value("BlockSpeed").toInt(),
                                      qsGameDataFile.value("Direction").toBool(),
                                      qsGameDataFile.value("position").toInt(),
                                      qsGameDataFile.value("Difficulty").toInt());
        return 1;
    }
    else
    {
        return 0;
    }
}

//********************************************************************************
//function to save a game
int saveGame(QString qsFileNameAndPath)
{
    int iRow, iColumn;
    QString qsPlayFieldValueVarName;
    QSettings qsGameDataFile(qsFileNameAndPath, QSettings::IniFormat);

    if(qsFileNameAndPath != NULL)
    {
        //set group inside ini file
        //playfield
        qsGameDataFile.beginGroup("PlayField");                                 //Set group PlayField
        for(iRow = 0; iRow < PLAYFIELDHEIGHT; iRow++)                           //save playfield to file with PlayField[ROW][COLUMN] = bool
        {
            for(iColumn = 0; iColumn < PLAYFIELDWIDTH; iColumn++)
            {
                qsPlayFieldValueVarName = "PlayFieldValue" + QString::number(iRow) + QString::number(iColumn);
                qsGameDataFile.setValue(qsPlayFieldValueVarName, gameinfo.getPlayfield(iRow, iColumn));
            }
        }
        qsGameDataFile.endGroup();                                              //end playfield group
        //set header/label inside ini file
        //variables
        qsGameDataFile.beginGroup("Variables");                                 //Set Group Variables
        qsGameDataFile.setValue("Score", gameinfo.getScore());                  //score
        qsGameDataFile.setValue("ArrayRow", gameinfo.getCurrentArrayRow());     //current array row
        qsGameDataFile.setValue("BlockLength", gameinfo.getBlockLength());      //block length
        qsGameDataFile.setValue("BlockSpeed", gameinfo.getCurrentBlockSpeed()); //block speed
        qsGameDataFile.setValue("Direction", gameinfo.getCurrentDirection());   //block direction
        qsGameDataFile.setValue("Position", gameinfo.getCurrentPosition());     //block position
        qsGameDataFile.setValue("Difficulty", gameinfo.getDifficulty());        //difficulty
        return 1;
    }
    else
    {
        return 0;
    }
}
