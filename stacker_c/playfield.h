#ifndef PLAYFIELD_H_INCLUDED
#define PLAYFIELD_H_INCLUDED

#define WIDTH 10 ///<defines the Width of the game
#define HEIGHT 15 ///<defines the Height of the game


typedef struct gameinfo
{
    int ispeed; ///<ispeed stores the speed of the block
    int idifficulty; ///<idifficulty stores the difficulty of the game, like easy, medium and hard
    int iarray_row; ///<iarray_row stores the row/level of where the block is
    int ilength_block; ///<ilength_block stores the width of the block
    int iscore; ///<iscore stores the current game score
    int aiplayfield[HEIGHT][WIDTH]; ///<aiplayfield is the 2 dimensional array where the game is stored
}gameinfo; ///<in thist struct all of the game info is saved, like speed of the block, row, length and the array

extern struct gameinfo stgameinfo;///<makes the struckt extern usable for multiple files

#endif // PLAYFIELD_H_INCLUDED
