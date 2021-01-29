#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include <ncurses.h>

class Controller
{
    private:
        int maxX, maxY;
    public:

    Controller()
    {
        initscr();
        raw();
        keypad(stdscr, true);
        noecho();
        getmaxyx(stdscr,maxY,maxX);
    }

    void initTer()
    {
        initscr();
    }

    void StartDraw() {
        clear();
    }

    void EndDraw() {
        refresh();
    }

    void print(int x, int y, char ch) {
        move(y, x);
        printw("*");
    }

    int getKey() {
        return getch();
    }

    int getMaxX() {
        return this->maxX;
    }

    int getMaxY() {
        return this->maxY;
    }
    
    void endTer() {
        endwin();
    }
};

#endif