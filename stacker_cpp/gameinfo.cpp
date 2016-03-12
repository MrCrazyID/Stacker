/**
 * @file gameinfo.cpp
 * @author Ingmar Delsink
 * @date 2 may 2014
 * @brief File containing all the current info of Stacker.
 * In this file all the gameinfo is stored like the curretnt height of the block,
 * the current width and the current difficulty of the game.
 */

#include "gameinfo.h"

Gameinfo gameinfo;  /**< Class declaration */

//********************************************************************************
//sets a new game
void Gameinfo::setNewGame(int iDifficulty)
{
    switch (iDifficulty)
    {
    case 1:  //easy
        clearGameData();
        iDifficulty_ = 1;
        iCurrentBlockLength_ = iEasyBlockLength_;
        break;
    case 2:  //medium
        clearGameData();
        iDifficulty_ = 2;
        iCurrentBlockLength_ = iMediumBlockLength_;
        break;
    case 3:  //hard
        clearGameData();
        iDifficulty_ = 3;
        iCurrentBlockLength_ = iHardBlockLength_;
        break;
    default:
        clearGameData();
        iDifficulty_ = 1;
        iCurrentBlockLength_ = iEasyBlockLength_;
        break;
    }
}

//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------Private Variable Setters
//--------------------------------------------------------------------------------------------

//********************************************************************************
//sets one value in the PlayField
void Gameinfo::setPlayfield(int iHeight,
                            int iWidth,
                            bool bValue)
{
    if(bValue == true)
    {
        abPlayfield_[iHeight][iWidth] = true;
    }
    else
    {
        abPlayfield_[iHeight][iWidth] = false;
    }
}

//********************************************************************************
//Sets the current score
void Gameinfo::setScore(int iScore)
{
    if(iScore < 0)              //the score canot go lower as 0
    {
        iScore_ = 0;
    }
    else if(iScore > 10000)     //the score canot go higher as 10000
    {
        iScore_ = 10000;
    }
    else
    {
        iScore_ = iScore;
    }
}

//********************************************************************************
//Sets the current row of the block in the array
void Gameinfo::setCurrentArrayRow(int iCurrentArrayRow)
{
    if(iCurrentArrayRow > PLAYFIELDHEIGHT)      //the block canot go lower as the max height-1
    {
        iCurrentArrayRow_ = PLAYFIELDHEIGHT-1;
    }
    else if(iCurrentArrayRow < -1)              //the block canot go higher as the min height, -1 because after the last row, 0, there will be a check if the user reached the end, so -1
    {
        iCurrentArrayRow_ = 0;
    }
    else
    {
        iCurrentArrayRow_ = iCurrentArrayRow;
    }
}

//********************************************************************************
//Sets the current length of the block
void Gameinfo::setBlockLength(int iCurrentBlockLength)
{
    if(iCurrentBlockLength < 0)                     //the block canot be smaller than 0
    {
        iCurrentBlockLength_ = 0;
    }
    else if(iCurrentBlockLength > PLAYFIELDWIDTH-1) //the block canot be bigger than the max width-1
    {
        iCurrentBlockLength_ = PLAYFIELDWIDTH-1;
    }
    else
    {
        iCurrentBlockLength_ = iCurrentBlockLength;
    }
}

//********************************************************************************
//Sets the current direction of the block
void Gameinfo::setCurrentDirection(bool bCurrentDirection)
{
    if(bCurrentDirection == true)
    {
        bCurrentDirection_ = true;
    }
    else if(bCurrentDirection == false)
    {
        bCurrentDirection_ = false;
    }
    else
    {
        bCurrentDirection_ = true;
    }
}

//********************************************************************************
//Sets the current block position
void Gameinfo::setCurrentPosition(int iCurrentPosition)
{
    if(iCurrentPosition < 0)                                        //the position of the block cannot be smaller than 0, because that is the border
    {
        iCurrentPosition_ = 0;
    }
    else if(iCurrentPosition > (PLAYFIELDWIDTH-getBlockLength()))   //the position of the start of the block cannot be larger than the max width-block lenght, bacause that is the border
    {
        iCurrentPosition_ = (PLAYFIELDWIDTH-getBlockLength());
    }
    else
    {
        iCurrentPosition_ = iCurrentPosition;
    }
}

//********************************************************************************
//sets the difficulty of the game
void Gameinfo::setDifficulty(int iDifficulty)
{
    switch (iDifficulty)
    {
    case 1:  //easy
        iDifficulty_ = 1;
        break;
    case 2:  //medium
        iDifficulty_ = 2;
        break;
    case 3:  //hard
        iDifficulty_ = 3;
        break;
    default:
        iDifficulty_ = 1;
        break;
    }
}

//********************************************************************************
//Sets all of the current game info
void Gameinfo::setGameDataVariables(int iScore,
                                    int iCurrentArrayRow,
                                    int iCurrentBlockLength,
                                    int iCurrentBlockSpeed,
                                    bool bCurrentDirection,
                                    int iCurrentPosition,
                                    int iDifficulty)
{
    setScore(iScore);
    setCurrentArrayRow(iCurrentArrayRow);
    setBlockLengthFromSaveFile(iCurrentBlockLength);
    iCurrentBlockSpeed_ = iCurrentBlockSpeed;
    setCurrentDirection(bCurrentDirection);
    setCurrentPosition(iCurrentPosition);
    setDifficulty(iDifficulty);

}

//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------Private Variable Getters
//--------------------------------------------------------------------------------------------

//********************************************************************************
//gets one value in the PlayField
bool Gameinfo::getPlayfield(int iHeight,
                            int iWidth)
{
    if(abPlayfield_[iHeight][iWidth] == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//********************************************************************************
//gets the current score
int Gameinfo::getScore(void)
{
    return iScore_;
}

//********************************************************************************
//gets the current row of the block in the array
int Gameinfo::getCurrentArrayRow(void)
{
    return iCurrentArrayRow_;
}

//********************************************************************************
//gets the current length of the block
int Gameinfo::getBlockLength(void)
{
    return iCurrentBlockLength_;
}

//********************************************************************************
//Gets the current speed of the block
int Gameinfo::getCurrentBlockSpeed(void)
{
    switch (iDifficulty_)
    {
    case 1:
        return iEasy_;
        break;
    case 2:
        return iMedium_;
        break;
    case 3:
        return iHard_;
        break;
    default:
        return 0;
        break;
    }
}

//********************************************************************************
//Gets the current direction of the block
bool Gameinfo::getCurrentDirection(void)
{
    return bCurrentDirection_;
}

//********************************************************************************
//Gets the current block position
int Gameinfo::getCurrentPosition(void)
{
    return iCurrentPosition_;
}

//********************************************************************************
//Gets the difficulty of the game
int Gameinfo::getDifficulty(void)
{
    return iDifficulty_;
}

//--------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------Clear Functions
//--------------------------------------------------------------------------------------------

//********************************************************************************
//Clears the PlayField
void Gameinfo::clearPlayfield(void)
{
    int iRow, iColmn;
    for (iRow = 0; iRow < PLAYFIELDHEIGHT; iRow++)
    {
        for (iColmn = 0; iColmn < PLAYFIELDWIDTH; iColmn++)
        {
            abPlayfield_[iRow][iColmn] = 0;
        }
    }
}

//********************************************************************************
//Clears all of the game info
void Gameinfo::clearGameData(void)
{
    clearPlayfield();                       //clear array
    iScore_ = 0;                            //clear score
    iCurrentArrayRow_ = PLAYFIELDHEIGHT-1;  //clear current array row
    iCurrentBlockLength_ = 0;               //clear length block
    iCurrentBlockSpeed_ = 0;                //clear speed of the block
    bCurrentDirection_ = true;              //clear block direction to the right
    iCurrentPosition_ = 0;                  //clear current position
    iDifficulty_ = 0;                       //clear the difficulty
}

//********************************************************************************
//Sets the current length of the block from a save file
void Gameinfo::setBlockLengthFromSaveFile(int iCurrentBlockLength)
{
    if(iCurrentBlockLength < 1)                     //the block canot be smaller than 1 to play with
    {
        iCurrentBlockLength_ = 1;
    }
    else if(iCurrentBlockLength > PLAYFIELDWIDTH-1) //the block canot be bigger than the max width-1
    {
        iCurrentBlockLength_ = PLAYFIELDWIDTH-1;
    }
    else
    {
        iCurrentBlockLength_ = iCurrentBlockLength;
    }
}
