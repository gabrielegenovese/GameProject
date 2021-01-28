#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include <ncurses.h>

class Controller
{
    public:

    Controller(){}

    void initTer()
    {
        initscr();
    }

    void refr()
    {
        refresh();
    }

    void printScreen(int n)
    {
        mvprintw(0,0,"%c", (char)n);
    }

    int getKey()
    {
        return getch();
    }
    
    void endTer()
    {
        endwin();
    }
};

#endif