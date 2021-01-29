#include <ncurses.h>
#include "printer.hpp"

Printer::Printer(){
    //nothing
}

void Printer::setPlayerRoom(const char *name, int n, int time) {
    move(1, 1);
    printw(" Player: %s\tStanza N°%d  time: %d", name, n, time);
}

void Printer::startDraw() {
    clear();
}

void Printer::endDraw() {
    refresh();
}

void Printer::print(int x, int y, char ch) {
    move(y, x);
    printw("%c", ch);
}

//date basi e altezza disegna un rettangolo 
int Printer::drawRect(int startX, int startY, int mlength, int mheigth) {
    // da implementare startX e startY
    for(int y = 0; y < mheigth; y++) {
        for(int x = 0; x < mlength; x++) {
            if(y == 0 || x == 0 || x == (mlength - 1) || y == (mheigth - 1)) {
                move(startX+x, startY+y);
                printw("X");
            }
        }
    }
    return 0;
}