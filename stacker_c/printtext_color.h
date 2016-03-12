#ifndef PRINTTEXT_COLOR_H_INCLUDED
#define PRINTTEXT_COLOR_H_INCLUDED

//Function prototype
/**
* @author Ingmar Delsink
* @brief fuction to print a string in color
* @param ctext = string of text you want to print
* @param ctext_color = string with color value for text
* @param ctext_back = string with color value for back
*/
void print_color(char *ctext, char *ctext_color, char *ctext_back);

/**
* @author Ingmar Delsink
* @brief fuction to print a special character in color
* @param ctext = string of text you want to print
* @param ctext_color = string with color value for text
* @param ctext_back = string with color value for back
*/
void print_color_specialcharacter(int itext_input, char *ctext_color, char *ctext_back);

/**
* @author Ingmar Delsink
* @brief fuction to print a number in color
* @param ctext = string of text you want to print
* @param ctext_color = string with color value for text
* @param ctext_back = string with color value for back
*/
void print_color_number(int itext_input, char *ctext_color, char *ctext_back);

#endif // PRINTTEXT_COLOR_H_INCLUDED
