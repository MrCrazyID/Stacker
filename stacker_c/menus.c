#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <dirent.h>
#include <string.h>

#include "menus.h"
#include "gamesource.h"
#include "playfield.h"
#include "printtext_color.h"

//***************************************************************************************************************************
void main_menu(void)
{
    int iwait_on_input = 0;
	char cinput;
	system("color f");
    system("cls");
    menu_name_print("Main Menu");
    printf("Press 1 to start a new game\n");
    printf("Press 2 to load a game\n");
    printf("Press 3 to open the help menu\n");
    printf("\n");
    printf("Press ESC to Exit the game\n");
    printf("Press 4 for credits\n\n");
    while (iwait_on_input == 0)
    {
        if(kbhit())
        {
            cinput = getch();
            //check for input
            while ( kbhit() ) getch();
            switch(cinput)
            {
                //case is 1
                //start new game
                case 49:
                    difficulty_menu();
                    iwait_on_input = 1;
                    break;

                //case is 2
                //load game
                case 50:
                    load_menu();
                    iwait_on_input = 1;
                    break;

                //case is 3
                //help menu
                case 51:
                    system("cls");
                    menu_name_print("Help menu");
                    printf("Try to stack as many blocks, as high as possible.\n");
                    printf("You will lose the number of blocks\nyou placed incorrectly\n");
                    printf("The game is played with the Space bar.\n");
                    printf("To place the block press space.\n");
                    printf("While in game you can press ESC\n");
                    printf("    Now you are in the pause menu\n");
                    printf("    From here you can save your game,\n");
                    printf("    or start a new one.\n");
                    printf("\nHave fun!\n");
                    printf("\n\nPress any key to go back");
                    while ( kbhit() == '\0' );
                    getch();
                    main_menu();
                    break;

                //case is ESC
                //exit
                case 27:
                    system("cls");
                    printf("\n\n    Bye!!\n\n");
                    Beep(350, 300);
                    Beep(400, 300);
                    Beep(200, 600);
                    iwait_on_input = 1;
                    exit(1);

                //case is 4
                //credits
                case 52:
                    system("cls");
                    menu_name_print("Credits");
                    printf("This game is designed and coded by\n\n");
                    print_color("Ingmar Delsink", "rl", "");
                    printf(" CEO of the worldwide ");
                    print_color("ID Company\n\n", "gl", "");
                    print_color("\n\n                            Stacker V2.0", "r", "");
                    printf("\n\nPress any key to go back");
                    while ( kbhit() == '\0' );
                    getch();
                    main_menu();

                    break;

                //case is default
                //input is incorrect
                default:
                    printf("Choose again");
                    Sleep(800);
                    printf("\r            \r");
                    break;
            }
            Sleep(100);
        }
    }
}

//***************************************************************************************************************************
void pause_menu(void)
{
    int iwait_on_input = 0;
	char cinput;
	system("color f");
    system("cls");
    menu_name_print("Pause Menu");
    printf("Press ESC to resume game\n");
    printf("Press 1 save game\n");
    printf("Press 2 to start a new game\n");
    printf("Press 3 for main menu\n\n");
    while (iwait_on_input == 0)
    {
        if(kbhit())
        {
            cinput = getch();
            //check for input
            while ( kbhit() ) getch();
            switch(cinput)
            {
                //case is ESC
                //resume game
                case 27:
                    iwait_on_input = 1;
                    break;

                //case is 1
                //save game
                case 49:
                    save_menu();
                    iwait_on_input = 1;
                    break;

                //case is 2
                //new game
                case 50:
                    difficulty_menu();
                    iwait_on_input = 1;
                    break;

                //case is 3
                //main menu
                case 51:
                    main_menu();
                    break;

                //case is default
                //input is incorrect
                default:
                    printf("Choose again");
                    Sleep(800);
                    printf("\r            \r");
                    break;
            }
            Sleep(100);
        }
    }
}

//***************************************************************************************************************************
void save_menu(void)
{
    int irow = 0, icolumn = 0;
    char ctime_string[11], cfile_name_input[7], cfile_extension[] = ".stack", cfile_name[24];
    time_t now;

	system("color f");
    system("cls");
    menu_name_print("Save Menu");
    FILE *fp;

    printf("Give the save file a name\n");
    printf("max 6 characters\n");
    scanf("%s", &*cfile_name_input);
    while(strlen(cfile_name_input) > 6)
    {
        printf("This filename is too long, try again");
        Sleep(1000);
        printf("\r                                     \r");
        scanf("%s", &*cfile_name_input);
    }

    now = time(NULL);
    strftime(ctime_string, 12, " %d-%m-%Y", localtime(&now));

    strcpy(cfile_name, cfile_name_input);       // copies "one" into str_output
    strcat(cfile_name, ctime_string);
    strcat(cfile_name, cfile_extension);    //  attaches str_two to str_output

    fp = fopen(cfile_name,"w"); // read mode

    if( fp == NULL )
    {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
    }

    for ( irow = 0; irow < HEIGHT; irow++ )
    {
        for ( icolumn = 0; icolumn < WIDTH; icolumn++ )
        {
            if (stgameinfo.aiplayfield[irow][icolumn] == 0)
            {
                //no block visable
                fprintf(fp, "0");
            }
            else
            {
                //a block visable
                fprintf(fp, "1");
            }
        }
        fprintf(fp, "\n");
    }
    if(stgameinfo.idifficulty > 3)
    {
        stgameinfo.idifficulty = stgameinfo.idifficulty - 3;
    }
    fprintf(fp, "%d\n%d\n%d\n%d\n", stgameinfo.idifficulty, stgameinfo.iarray_row, stgameinfo.ilength_block, stgameinfo.iscore);
    //print mode/speed, print level, print block_length, print score?

    //close file
    fclose(fp);
    print_color("\nThe file is now saved!\n", "rgl", "l");
    Sleep(2000);
    pause_menu();
}

//***************************************************************************************************************************
void load_menu(void)
{
    int irow = 0, icolumn = 0, ivalue, idirectory_counter = 1, ifoldernumber = 0, iinput_wait = 0, icheck_if_out_of_while = 0;
    char ch, cfile_name[25],carray_row[3] ,cscore[10], cfoldernumber;
    DIR * directory_pointer;

	system("color f");
    system("cls");
    menu_name_print("Load Menu");

    //open the current directory
    directory_pointer = opendir (".");

    //if error!
    if (! directory_pointer)
    {
        printf ("Cannot open directory, return to main menu\n");
        Sleep(2000);
        main_menu();
    }
    //check directory
    while (1)
    {
        struct dirent * entry;

        entry = readdir (directory_pointer);
        if (! entry)
        {
            if(! entry && idirectory_counter == 1)
            {
                printf("Tbere where no saves!\n");
                print_color("\n\nReturing to main menu", "gl", "r");
                Sleep(1500);
                main_menu();
            }
            break;
        }
        //if file name contains .stack
        if (strstr(entry->d_name, ".stack") != NULL)
        {
            printf ("%d: %s\n",idirectory_counter, entry->d_name);
            idirectory_counter++;
        }
    }
     /* Close the directory. */
    if (closedir (directory_pointer))
    {
        printf ("Could not close\n");
        exit (EXIT_FAILURE);
    }
    //wait on input
    while(iinput_wait == 0)
    {
        scanf("%c", &cfoldernumber);// get input
        while (getchar() != '\n');// clear char buffer for error loop
        ifoldernumber = cfoldernumber-'0'; //convert user input to int
        if(ifoldernumber > 0 && ifoldernumber < idirectory_counter)
        {
            idirectory_counter = 1;
            iinput_wait = 1;
        }
        else
        {
            printf("Choose an existing file!");
            Sleep(1500);
            printf("\r                        \r");
        }
    }

    //pick the file
    // Open the current directory
    directory_pointer = opendir (".");

    if (! directory_pointer) {
        printf ("Cannot open directory, return to main menu\n");
        Sleep(2000);
        main_menu();
    }
    while (1)
    {
        struct dirent * entry;

        entry = readdir (directory_pointer);
        if (! entry)
        {
            break;
        }
        if (strstr(entry->d_name, ".stack") != NULL)
        {
            if(ifoldernumber != 0)
            {
                if(idirectory_counter == ifoldernumber)
                {
                    strcpy(cfile_name, entry->d_name);
                }
            }
            idirectory_counter++;
        }
    }
    /* Close the directory. */
    if (closedir (directory_pointer))
    {
        printf ("Could not close\n");
        exit (EXIT_FAILURE);
    }
    printf("\n\nThe file '");
    print_color(cfile_name, "gl", "");
    printf("'\nwill be loaded into the game");
    Sleep(2500);


    //read file
    FILE *fp;

    fp = fopen(cfile_name,"r"); // read mode

    if( fp == NULL )
    {
        printf("Error while opening the file, return to main menu\n");
        Sleep(2000);
        main_menu();
    }

    while( ( ch = fgetc(fp) ) != EOF )
    {
        //if the arrray is loading
        if(irow < HEIGHT)
        {
            if(ch == '\n' && icolumn == WIDTH)
            {
                irow++;
                icolumn = 0;
            }
            else
            {
                icolumn++;
            }
            if(ch == '0')
            {
                ivalue = 0;
            }
            else if(ch == '1')
            {
                ivalue = 1;
            }
            stgameinfo.aiplayfield[irow][icolumn-1] = ivalue;
        }
        //load idifficulty
        if(irow == HEIGHT)
        {
            if(ch == '1')
            {
                stgameinfo.idifficulty = 4;
                irow++;
            }
            else if(ch == '2')
            {
                stgameinfo.idifficulty = 5;
                irow++;
            }
            else if(ch == '3')
            {
                stgameinfo.idifficulty = 6;
                irow++;
            }
            icheck_if_out_of_while = 1;
            icolumn = 0;
        }
        //load iarray_row
        if(irow == HEIGHT+1)
        {
            if(icheck_if_out_of_while != 1 && ch != '\n')
            {
                carray_row[icolumn] = ch;
                icolumn++;
            }
            else if(icheck_if_out_of_while != 1 && ch == '\n' && icolumn != 0)
            {
                stgameinfo.iarray_row = atoi(carray_row);
                irow++;
                icheck_if_out_of_while = 1;
            }
        }
        //load ilengthblock
        if(irow == HEIGHT+2)
        {
            if(icheck_if_out_of_while != 1 && ch != '\n')
            {
                stgameinfo.ilength_block = ch - '0';
                irow++;
                icheck_if_out_of_while = 1;
                icolumn = 0;
            }
        }
        //load score
        if(irow == HEIGHT+3)
        {
            if(icheck_if_out_of_while != 1 && ch != '\n')
            {
                cscore[icolumn] = ch;
                icolumn++;
            }
            else if(icheck_if_out_of_while != 1 && ch == '\n' && icolumn != 0)
            {
                stgameinfo.iscore = atoi(cscore);
                irow++;
            }
        }
        icheck_if_out_of_while = 0;
    }
    fclose(fp);

    //game is loaded
    start_game();
}

//***************************************************************************************************************************
void difficulty_menu(void)
{
    int iwait_on_input = 0;
    char cinput;
	system("color f");
    system("cls");
    menu_name_print("Difficulty Menu");
    printf("Press 1 for easy\n");
    printf("Press 2 for medium\n");
    printf("Press 3 for hard\n");
    while (iwait_on_input == 0)
    {
        if(kbhit())
        {
            cinput = getch();
            //check for input
            while ( kbhit() ) getch();
            switch(cinput)
            {
                //case is 1
                //easy
                case 49:
                    stgameinfo.idifficulty = 1;
                    start_game();
                    iwait_on_input = 1;
                    break;

                //case is 2
                //medium
                case 50:
                    stgameinfo.idifficulty = 2;
                    start_game();
                    iwait_on_input = 1;
                    break;

                //case is 3
                //hard
                case 51:
                    stgameinfo.idifficulty = 3;
                    start_game();
                    iwait_on_input = 1;
                    break;

                //case is default
                //input is incorrect
                default:
                    printf("Choose again");
                    Sleep(800);
                    printf("\r            \r");
                    break;
            }
            Sleep(100);
        }
    }
}

//***************************************************************************************************************************
void menu_name_print(char *cmenu_name)
{
    int imenu_name_length, iteller;
    char cleft_corner_up, cright_corner_up, cleft_corner_down, cright_corner_down, chorizontal_bar, cvertical_bar;
    cleft_corner_up = 218;
    cleft_corner_down = 192;
    cright_corner_up = 191;
    cright_corner_down = 217;
    chorizontal_bar = 196;
    cvertical_bar = 179;

    imenu_name_length = strlen(cmenu_name);

    printf("%c", cleft_corner_up);
    for(iteller = 0; iteller < imenu_name_length; iteller++)
    {
        printf("%c", chorizontal_bar);
    }
    printf("%c\n", cright_corner_up);

    printf("%c", cvertical_bar);
    print_color(cmenu_name, "rl", "");
    printf("%c\n", cvertical_bar);

    printf("%c", cleft_corner_down);
    for(iteller = 0; iteller < imenu_name_length; iteller++)
    {
        printf("%c", chorizontal_bar);
    }
    printf("%c\n\n\n", cright_corner_down);
}
