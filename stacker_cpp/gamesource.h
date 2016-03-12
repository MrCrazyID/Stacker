/**
 * @file gamesource.h
 * @author Ingmar Delsink
 * @date 2 may 2014
 * @brief File containing gamesource of Stacker.
 * In this file the gamesource of Stacker can be found.
 * Like moving the block up or sideways till saving and loading
 * save files.
 */

#ifndef GAMESOURCE_H
#define GAMESOURCE_H

#include <QString>

//********************************************************************************
//fuction to move the block to the sides
/**
* @author Ingmar Delsink
* @brief fuction to move the block to the sides
*
*/
void moveBlockSide(void);

//********************************************************************************
//fuction to move the block up and check if lost or won
/**
 * @author Ingmar Delsink
 * @brief fuction to move the block up and check if lost or won
 *
 * @return int = win or lost, 0 is not win or lost, 1 is win and 2 is lost
 */
int moveBlockUp(void);

//********************************************************************************
//function to load a game
/**
 * @author Ingmar Delsink
 * @brief function to load a game
 *
 * @param qsFileNameAndPath = the file path + the filename
 * @return int = qsFileName empty, 0 if empty, 1 if not empty
 */
int loadGame(QString qsFileNameAndPath);

//********************************************************************************
//function to save a game
/**
 * @author Ingmar Delsink
 * @brief function to save a game
 *
 * @param qsFileNameAndPath = the file path + the filename
 * @return int = qsFileName empty, 0 if empty, 1 if not empty
 */
int saveGame(QString qsFileNameAndPath);

#endif // GAMESOURCE_H
