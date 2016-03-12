#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "menus.h"
#include "gamesource.h"
#include "playfield.h"
#include "printtext_color.h"

//***************************************************************************************************************************
//change whole array function
void change_whole_array(int ivalue)
{
    int irow, icolmn;
    for (irow = 0; irow < HEIGHT; irow++)
    {
        for (icolmn = 0; icolmn < WIDTH; icolmn++)
        {
            stgameinfo.aiplayfield[irow][icolmn] = ivalue;
        }
    }
}

//***************************************************************************************************************************
//start game function
void start_game(void)
{
    int ispeed, iteller_clear_row, istartpoint, idirection, iteller_length_of_block, isteps, icheck_input_teller, iinput, iteller_check_if_not_missed;
    if(stgameinfo.idifficulty <= 3)
    {
        change_whole_array(0);
    }
    //set difficulty
    if(stgameinfo.idifficulty == 1)
    {
        //easy
        stgameinfo.ilength_block = 7;
        ispeed = EASY;
        stgameinfo.iscore = 0;
    }
    else if(stgameinfo.idifficulty == 2)
    {
        stgameinfo.ilength_block = 5;
        ispeed = MEDIUM;
        stgameinfo.iscore = 0;
    }
    else if(stgameinfo.idifficulty == 3)
    {
        stgameinfo.ilength_block = 3;
        ispeed = HARD;
        stgameinfo.iscore = 0;
    }
    else
    {
        if(stgameinfo.idifficulty == 4)
        {
            //easy
            ispeed = EASY;
        }
        else if(stgameinfo.idifficulty == 5)
        {
            ispeed = MEDIUM;
        }
        else if(stgameinfo.idifficulty == 6)
        {
            ispeed = HARD;
        }
    }
    if(stgameinfo.idifficulty <= 3)
    {
        stgameinfo.iarray_row = HEIGHT-1;
    }
    istartpoint = 0;
    while(stgameinfo.iarray_row >= 0)
    {
        isteps = WIDTH - stgameinfo.ilength_block;
        //clearing array row
        for (iteller_clear_row = 0; iteller_clear_row < WIDTH; iteller_clear_row++)
        {
            stgameinfo.aiplayfield[stgameinfo.iarray_row][iteller_clear_row] = 0;
        }
        //set blocks in array
        for (iteller_length_of_block = 0; iteller_length_of_block < stgameinfo.ilength_block; iteller_length_of_block++)
        {
            stgameinfo.aiplayfield[stgameinfo.iarray_row][istartpoint + iteller_length_of_block] = 1;
        }
        //slide to direction
        if (istartpoint == 0)
        {
            //slide to right
            idirection = 0;
        }
        else if (istartpoint == isteps)
        {
            //slide to left
            idirection = 1;
        }
        if (idirection == 0)
        {
            istartpoint++;
        }
        else
        {
            istartpoint--;
        }
        playfield_show();
        for(icheck_input_teller = 0; icheck_input_teller < ispeed; icheck_input_teller++)
        {
            iinput = check_input();
            if(iinput == 1)
            {
                if (stgameinfo.iarray_row < HEIGHT-1)
                {
                    for(iteller_check_if_not_missed = 0; iteller_check_if_not_missed < WIDTH; iteller_check_if_not_missed++)
                    {
                        if (stgameinfo.aiplayfield[stgameinfo.iarray_row][iteller_check_if_not_missed] == 1 && stgameinfo.aiplayfield[stgameinfo.iarray_row+1][iteller_check_if_not_missed] == 1)
                        {
                            stgameinfo.aiplayfield[stgameinfo.iarray_row][iteller_check_if_not_missed] = 1;
                        }
                        else
                        {
                            stgameinfo.aiplayfield[stgameinfo.iarray_row][iteller_check_if_not_missed] = 0;
                            if ((stgameinfo.aiplayfield[stgameinfo.iarray_row][iteller_check_if_not_missed] == 1 && stgameinfo.aiplayfield[stgameinfo.iarray_row+1][iteller_check_if_not_missed] == 0) || (stgameinfo.aiplayfield[stgameinfo.iarray_row][iteller_check_if_not_missed] == 0 && stgameinfo.aiplayfield[stgameinfo.iarray_row+1][iteller_check_if_not_missed] == 1))
                            {
                                stgameinfo.ilength_block--;
                                lose_check();
                            }
                        }
                    }
                }
                stgameinfo.iscore = stgameinfo.iscore + ((WIDTH-stgameinfo.ilength_block)*(500-ispeed));
                stgameinfo.iarray_row--;
            }
            else if(iinput == 2)
            {
                pause_menu();
            }
            Sleep(10);
        }
    }
    winner();
}

//***************************************************************************************************************************
//playfield print
void playfield_show()
{
    system("cls");
    int irow = 0, icolumn = 0, iborder = 0;

    system("color 9");
    printf("\t\t");print_color("Score : ", "rgb", "r");print_color_number(stgameinfo.iscore, "gl", "r");printf("\n");
    //left top cornor
    printf("%c", 201);
    for (iborder = 0; iborder <= WIDTH-1; iborder++)
    {
        //horizontal bar
        printf("%c", 205);
    }
    //right top cornor
    printf("%c\n", 187);

    for ( irow = 0; irow < HEIGHT; irow++ )
    {
        //vertical bar
        printf("%c", 186);
        for ( icolumn = 0; icolumn < WIDTH; icolumn++ )
        {
            if (stgameinfo.aiplayfield[irow][icolumn] == 0)
            {
                //no block visable
                printf(" ");
            }
            else
            {
                //a block visable
                print_color_specialcharacter(219, "rgl", "");
                 //printf("%c", 219);
            }

        }
        //vertical bar
        printf("%c", 186);
        printf("\n");
    }
    //left bottom cornor
    printf("%c", 200);
    for (iborder = 0; iborder <= WIDTH-1; iborder++)
    {
        //horizotal bar
        printf("%c", 205);
    }
    //right bottom cornor
    printf("%c\n", 188);
}

//***************************************************************************************************************************
int check_input(void)
{
    int ireturn = 0;
    char cinput;
    if(kbhit())
    {
        cinput = getch();
        while ( kbhit() ) getch();
        if (cinput == ' ')
        {
            ireturn = 1;
        }
        else if (cinput == 27)//27 = ESC key
        {
            ireturn = 2;
        }
    }
    return ireturn;
}

//***************************************************************************************************************************
void lose_check(void)
{
    if (stgameinfo.ilength_block < 1)
    {
        system("cls");
        printf("\nyou lose!\n With a score of ");
        print_color_number(stgameinfo.iscore, "rl", "");
        Sleep(3000);
        main_menu();
    }
}

//***************************************************************************************************************************
void winner(void)
{
    system("cls");
    printf("\nYou won!!\n With an amazing score of: ");
    print_color_number(stgameinfo.iscore, "gl", "");
    Beep(1480,200);
    Beep(1568,200);
    Beep(1656,200);
    Beep(1744,200);
    Sleep(300);
    Beep(1656,200);
    Beep(1744,200);
    Sleep(3000);
    main_menu();
}
