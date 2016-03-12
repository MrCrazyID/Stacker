#ifndef GAMESOURCE_H_INCLUDED
#define GAMESOURCE_H_INCLUDED

#define EASY 40
#define MEDIUM 20
#define HARD 7

/**
* @author Ingmar Delsink
* @brief fuction to change whole array with one value
* @param ivalue = value
*/
void change_whole_array(int ivalue);

/**
* @author Ingmar Delsink
* @brief fuction to start new game with dificulty setting
*/
void start_game(void);

/**
* @author Ingmar Delsink
* @brief fuction to print field in console
*/
void playfield_show(void);

/**
* @author Ingmar Delsink
* @brief fuction to check user input while in game
* @return 1 if user pressed space, 2 if user pressed ESC
*/
int check_input(void);

/**
* @author Ingmar Delsink
* @brief fuction to check if you lost, and print if you lost
*/
void lose_check(void);

/**
* @author Ingmar Delsink
* @brief fuction print you won
*/
void winner(void);

#endif // GAMESOURCE_H_INCLUDED
