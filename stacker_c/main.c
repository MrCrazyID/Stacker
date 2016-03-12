#include <stdio.h>
#include <stdlib.h>
#include "start_screen.h"
#include "menus.h"

/**
*@class Stacker
*@brief This is the game Stacker
*@author Ingmar Delsink
*@date 17-01-2013
*/

int main()
{
    start_screen(); /**<On start of program, show start screen*/
    main_menu(); /**<Call main menu*/
    return 0;
}
