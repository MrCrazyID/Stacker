/**
 * @mainpage  Stacker
 * This is the game Stacker.<br/><br/>
 * Date: 25-04-2014<br/>
 * Author: Ingmar Delsink
 * <br/>
 */

#include "window_title_screen.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    window_title_screen w;
    w.show();

    return a.exec();
}
