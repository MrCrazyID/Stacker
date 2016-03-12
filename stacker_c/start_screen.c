#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "start_screen.h"
#include "printtext_color.h"

void start_screen(void)
{
    int ion_off_press_space = 0, ispace_hit = 0, iteller;
    char cleft_corner_up, cright_corner_up, cleft_corner_down, cright_corner_down, chorizontal_bar, cvertical_bar;
    cleft_corner_up = 218; //ascii char for left top corner
    cleft_corner_down = 192; //ascii char for left bottom corner
    cright_corner_up = 191; //ascii char for right top corner
    cright_corner_down = 217; //ascii char for right bottom corner
    chorizontal_bar = 196; //ascii char for horizontal bar
    cvertical_bar = 179; //ascii char for vertical bar


    system("MODE CON: COLS=71 LINES=19");
    while(ispace_hit == 0)
    {
        printf("\n");
        printf("  %c", cleft_corner_up); for(iteller = 0; iteller < 64; iteller++){printf("%c", chorizontal_bar);} printf("%c\n", cright_corner_up);
        printf("  %c", cvertical_bar);print_color("Super ", "rl", "");print_color("Amazing", "rgl", "");printf("                                                   %c\n", cvertical_bar);
        printf("  %c                                                                %c\n", cvertical_bar, cvertical_bar);
        printf("  %c ######  ########    ###     ######  ##    ## ######## ######## %c\n", cvertical_bar, cvertical_bar);
        printf("  %c##    ##    ##      ## ##   ##    ## ##   ##  ##       ##     ##%c\n", cvertical_bar, cvertical_bar);
        printf("  %c##          ##     ##   ##  ##       ##  ##   ##       ##     ##%c\n", cvertical_bar, cvertical_bar);
        printf("  %c ######     ##    ##     ## ##       #####    ######   ######## %c\n", cvertical_bar, cvertical_bar);
        printf("  %c      ##    ##    ######### ##       ##  ##   ##       ##   ##  %c\n", cvertical_bar, cvertical_bar);
        printf("  %c##    ##    ##    ##     ## ##    ## ##   ##  ##       ##    ## %c\n", cvertical_bar, cvertical_bar);
        printf("  %c ######     ##    ##     ##  ######  ##    ## ######## ##     ##%c\n", cvertical_bar, cvertical_bar);
        printf("  %c                                                                %c\n", cvertical_bar, cvertical_bar);
        printf("  %c                                                 ", cvertical_bar);print_color("Adventure ", "gl", "");print_color("Turbo", "rbl", "");printf("%c\n", cvertical_bar);
        printf("  %c", cleft_corner_down); for(iteller = 0; iteller < 64; iteller++){printf("%c", chorizontal_bar);} printf("%c\n\n", cright_corner_down);
        if(ion_off_press_space == 0)
        {
            printf("                      "); printf("%c", 201); for(iteller = 0; iteller < 25; iteller++){printf("%c", 205);} printf("%c\n", 187);
            printf("                      "); printf("%c", 186);print_color(" Press space to continue ", "", "rgbl");printf("%c\n", 186);
            printf("                      "); printf("%c", 200); for(iteller = 0; iteller < 25; iteller++){printf("%c", 205);} printf("%c\n", 188);
            Beep(300, 300);
            Sleep(1000);
            ion_off_press_space++;
        }
        else
        {
            printf("                      "); printf("%c", cleft_corner_up); for(iteller = 0; iteller < 25; iteller++){printf("%c", chorizontal_bar);} printf("%c\n", cright_corner_up);
            printf("                      "); printf("%c", cvertical_bar);printf("                         ");printf("%c\n", cvertical_bar);
            printf("                      "); printf("%c", cleft_corner_down); for(iteller = 0; iteller < 25; iteller++){printf("%c", chorizontal_bar);} printf("%c\n", cright_corner_down);
            Beep(250, 300);
            Sleep(1000);
            ion_off_press_space--;
        }
        ispace_hit = check_space_hit();
        system("cls");
    }
    system("MODE CON: COLS=50 LINES=20");
}

int check_space_hit(void)
{
    int ispace_hit;
    char cinput;
    if(kbhit())
    {
        cinput = getch();
        while ( kbhit() )
        {
            getch();
        }
        if (cinput == ' ')
        {
            ispace_hit = 1;
        }
        else
        {
            ispace_hit = 0;
        }
    }
    else
    {
        ispace_hit = 0;
    }
    return (ispace_hit);
}
