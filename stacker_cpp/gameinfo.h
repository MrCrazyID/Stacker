/**
 * @file gameinfo.h
 * @author Ingmar Delsink
 * @date 2 may 2014
 * @brief File containing all the current info of Stacker.
 * In this file all the gameinfo is stored like the current height of the block,
 * the current width and the current difficulty of the game.
 */

#ifndef GAMEINFO_H
#define GAMEINFO_H

#define PLAYFIELDWIDTH 10  ///<defining of playfield width
#define PLAYFIELDHEIGHT 15 ///<defining of playfield height

/**
 * @author Ingmar Delsink
 * @brief This class holds all the current game information
 *
 * in this class all the current information of the game like the score and the place of the block is stored
 */
class Gameinfo
{
public:
    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief sets a new game
     *
     * @param iDifficulty = the current difficulty, 1 for easy, 2 for medium and 3 for hard
     */
    void setNewGame(int iDifficulty);

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------Private Variable Setters
    //--------------------------------------------------------------------------------------------

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief sets one value in the PlayField
     *
     * @param iHeight = Height/Row of array
     * @param iWidth = Width/Column or array
     * @param bValue = Value of that place, 1 or 0, true or false
     */
    void setPlayfield(int iHeight,
                      int iWidth,
                      bool bValue);

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief Sets the current score
     *
     * @param iScore = current score
     */
    void setScore(int iScore);

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief Sets the current row of the block in the array
     *
     * @param iCurrentArrayRow = current row of the block
     */
    void setCurrentArrayRow(int iCurrentArrayRow);

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief Sets the current length of the block
     *
     * @param iCurrentBlockLength = the current length of the block
     */
    void setBlockLength(int iCurrentBlockLength);

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief Sets the current direction of the block
     *
     * @param bCurrentDirection = direction of the block, true is for right, false is for left
     */
    void setCurrentDirection(bool bCurrentDirection);

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief Sets the current block position
     *
     * @param iCurrentPosition = the current position of the block
     */
    void setCurrentPosition(int iCurrentPosition);

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief sets the difficulty of the game
     *
     * @param iDifficulty = the current difficulty, 1 for easy, 2 for medium and 3 for hard
     */
    void setDifficulty(int iDifficulty);

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief Sets all of the current game info
     *
     * @param iScore = the current score
     * @param iCurrentArrayRow = the current row of the block in the array
     * @param iCurrentBlockLength = the current length of the block
     * @param iCurrentBlockSpeed = the current speed of the block
     * @param bCurrentDirection = direction of the block, true is for right, false is for left
     * @param iCurrentPosition = the current position of the block
     * @param iDifficulty = the current difficulty, 1 for easy, 2 for medium and 3 for hard
     */
    void setGameDataVariables(int iScore,
                              int iCurrentArrayRow,
                              int iCurrentBlockLength,
                              int iCurrentBlockSpeed,
                              bool bCurrentDirection,
                              int iCurrentPosition,
                              int iDifficulty);

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------Private Variable Getters
    //--------------------------------------------------------------------------------------------

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief gets one value in the PlayField
     *
     * @param iHeight = Height/Row of array
     * @param iWidth = Width/Column or array
     * @return bool = Value of that place, 1 or 0, true or false
     */
    bool getPlayfield(int iHeight,
                      int iWidth);

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief gets the current score
     *
     * @return int = current score
     */
    int getScore(void);

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief gets the current row of the block in the array
     *
     * @return int = current row of the block
     */
    int getCurrentArrayRow(void);

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief gets the current length of the block
     *
     * @return int = the current length of the block
     */
    int getBlockLength(void);

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief Gets the current speed of the block
     *
     * @return int = the current speed of the block
     */
    int getCurrentBlockSpeed(void);

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief Gets the current direction of the block
     *
     * @return bool = direction of the block, true is for right, false is for left
     */
    bool getCurrentDirection(void);

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief Gets the current block position
     *
     * @return int = is the current position of the block
     */
    int getCurrentPosition(void);

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief Gets the difficulty of the game
     *
     * @return int = the current difficulty, 1 for easy, 2 for medium and 3 for hard
     */
    int getDifficulty(void);

    //--------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------Clear Functions
    //--------------------------------------------------------------------------------------------

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief Clears the PlayField
     *
     */
    void clearPlayfield(void);

    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief Clears all of the game info
     *
     */
    void clearGameData(void);

protected:
    //empty

private:
    //********************************************************************************
    /**
     * @author Ingmar Delsink
     * @brief Sets the current length of the block from a save file
     *
     * @param iCurrentBlockLength = the current length of the block
     */
    void setBlockLengthFromSaveFile(int iCurrentBlockLength);

    bool abPlayfield_[PLAYFIELDHEIGHT][PLAYFIELDWIDTH]; /**< stores the playfield */
    unsigned int iScore_;                               /**< stores the current game score */
    int iCurrentArrayRow_;                              /**< stores the row/level of where the block is */
    int iCurrentBlockLength_;                           /**< stores the width/length of the block */
    int iCurrentBlockSpeed_;                            /**< stores the speed of the block */
    bool bCurrentDirection_;                            /**< stores the direction of the block 1/true is right, 0/false is left */
    int iCurrentPosition_;                              /**< stores the current block position */
    int iDifficulty_;                                   /**< stores the difficulty represented in a 1, 2 or 3 */

    static const int iEasy_ = 250;                      /**< stores the delay of the moving block in easy mode */
    static const int iEasyBlockLength_ = 7;             /**< stores the lenght of the block if difficulty is easy */

    static const int iMedium_ = 100;                    /**< stores the delay of the moving block in medium mode */
    static const int iMediumBlockLength_ = 5;           /**< stores the lenght of the block if difficulty is medium */

    static const int iHard_ = 50;                       /**< stores the delay of the moving block in hard mode */
    static const int iHardBlockLength_ = 3;             /**< stores the lenght of the block if difficulty is hard */
};

extern Gameinfo gameinfo;   /**< makes the class extern usable for multiple files */

#endif // GAMEINFO_H
