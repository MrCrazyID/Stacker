#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "printtext_color.h"

/*
                               Text color                       Background color
print_color("String of text", "RED OR GREEN OR BLUE OR LIGHT", "RED OR GREEN OR BLUE OR LIGHT")

a few examples
print_color("Text\n", "rgbl", "rgbl");
print_color("Text\n", "r", "");
print_color("Text\n", "g", "");
print_color("Text\n", "b", "");
print_color("Text\n", "rl", "");
print_color("Text\n", "gl", "");
print_color("Text\n", "bl", "");
print_color("Text\n", "", "r");
print_color("Text\n", "", "g");
print_color("Text\n", "", "b");
print_color("Text\n", "", "rl");
print_color("Text\n", "", "gl");
print_color("Text\n", "", "bl");

print_color("Text\n", "r", "g");
print_color("Text\n", "g", "r");
print_color("Text\n", "b", "gb");
print_color("Text\n", "rl", "gl");
print_color("Text\n", "gl", "b");
print_color("Text\n", "bl", "rl");
*/

void print_color(char *ctext, char *ctext_color, char *ctext_back)
{
    int iteller, itext = 0, iback = 0, itotaal = 0, icheck_text, icheck_back;
    icheck_text = strlen(ctext_color);
    icheck_back = strlen(ctext_back);
    for(iteller = 0; iteller < 4; iteller++)
    {
        if(iteller <= icheck_text)
        {
            if(ctext_color[iteller] == 'r')
            {
                itext = itext | 4;
            }
            else if(ctext_color[iteller] == 'g')
            {
                itext = itext | 2;
            }
            else if(ctext_color[iteller] == 'b')
            {
                itext = itext | 1;
            }
            else if(ctext_color[iteller] == 'l')
            {
                itext = itext | 8;
            }
        }

        if(iteller <= icheck_back)
        {
            if(ctext_back[iteller] == 'r')
            {
                iback = iback | 64;
            }
            else if(ctext_back[iteller] == 'g')
            {
                iback = iback | 32;
            }
            else if(ctext_back[iteller] == 'b')
            {
                iback = iback | 16;
            }
            else if(ctext_back[iteller] == 'l')
            {
                iback = iback | 128;
            }
        }
    }
    //total HEX value
    itotaal = itext | iback;
    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    WORD wOldColorAttrs;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

    //First save the current color information
    GetConsoleScreenBufferInfo(h, &csbiInfo);
    wOldColorAttrs = csbiInfo.wAttributes;

    //Set the new color information
    SetConsoleTextAttribute ( h, itotaal );

    //print text in color format
    printf("%s", ctext);

    //Restore the original colors
    SetConsoleTextAttribute ( h, wOldColorAttrs);
}

void print_color_specialcharacter(int itext_input, char *ctext_color, char *ctext_back)
{
    int iteller, itext = 0, iback = 0, itotaal = 0, icheck_text, icheck_back;
    icheck_text = strlen(ctext_color);
    icheck_back = strlen(ctext_back);
    for(iteller = 0; iteller < 4; iteller++)
    {
        if(iteller <= icheck_text)
        {
            if(ctext_color[iteller] == 'r')
            {
                itext = itext | 4;
            }
            else if(ctext_color[iteller] == 'g')
            {
                itext = itext | 2;
            }
            else if(ctext_color[iteller] == 'b')
            {
                itext = itext | 1;
            }
            else if(ctext_color[iteller] == 'l')
            {
                itext = itext | 8;
            }
        }

        if(iteller <= icheck_back)
        {
            if(ctext_back[iteller] == 'r')
            {
                iback = iback | 64;
            }
            else if(ctext_back[iteller] == 'g')
            {
                iback = iback | 32;
            }
            else if(ctext_back[iteller] == 'b')
            {
                iback = iback | 16;
            }
            else if(ctext_back[iteller] == 'l')
            {
                iback = iback | 128;
            }
        }
    }
    //total HEX value
    itotaal = itext | iback;
    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    WORD wOldColorAttrs;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

    //First save the current color information
    GetConsoleScreenBufferInfo(h, &csbiInfo);
    wOldColorAttrs = csbiInfo.wAttributes;

    //Set the new color information
    SetConsoleTextAttribute ( h, itotaal );

    //print text in color format
    printf("%c", itext_input);

    //Restore the original colors
    SetConsoleTextAttribute ( h, wOldColorAttrs);
}

void print_color_number(int itext_input, char *ctext_color, char *ctext_back)
{
    int iteller, itext = 0, iback = 0, itotaal = 0, icheck_text, icheck_back;
    icheck_text = strlen(ctext_color);
    icheck_back = strlen(ctext_back);
    for(iteller = 0; iteller < 4; iteller++)
    {
        if(iteller <= icheck_text)
        {
            if(ctext_color[iteller] == 'r')
            {
                itext = itext | 4;
            }
            else if(ctext_color[iteller] == 'g')
            {
                itext = itext | 2;
            }
            else if(ctext_color[iteller] == 'b')
            {
                itext = itext | 1;
            }
            else if(ctext_color[iteller] == 'l')
            {
                itext = itext | 8;
            }
        }

        if(iteller <= icheck_back)
        {
            if(ctext_back[iteller] == 'r')
            {
                iback = iback | 64;
            }
            else if(ctext_back[iteller] == 'g')
            {
                iback = iback | 32;
            }
            else if(ctext_back[iteller] == 'b')
            {
                iback = iback | 16;
            }
            else if(ctext_back[iteller] == 'l')
            {
                iback = iback | 128;
            }
        }
    }
    //total HEX value
    itotaal = itext | iback;
    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    WORD wOldColorAttrs;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

    //First save the current color information
    GetConsoleScreenBufferInfo(h, &csbiInfo);
    wOldColorAttrs = csbiInfo.wAttributes;

    //Set the new color information
    SetConsoleTextAttribute ( h, itotaal );

    //print text in color format
    printf("%d", itext_input);

    //Restore the original colors
    SetConsoleTextAttribute ( h, wOldColorAttrs);
}
