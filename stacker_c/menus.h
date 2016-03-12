#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

/**
* @author Ingmar Delsink
* @brief this is the main menu of the game
*/
void main_menu(void);

/**
* @author Ingmar Delsink
* @brief this is the pause menu of the game
*/
void pause_menu(void);

/**
* @author Ingmar Delsink
* @brief this is the save menu of the game
*/
void save_menu(void);

/**
* @author Ingmar Delsink
* @brief this is the load menu of the game
*/
void load_menu(void);

/**
* @author Ingmar Delsink
* @brief this is the difficulty menu of the game, here you can choose easy, medium or hard mode to play the game
*/
void difficulty_menu(void);

/**
* @author Ingmar Delsink
* @brief this is a function that will make all of the menu headers with color
* @param cmenu_name = string with menu name
*/
void menu_name_print(char *cmenu_name);

#endif // MENUS_H_INCLUDED
