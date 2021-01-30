#include <ncurses.h>
#include "printer.hpp"

Printer::Printer(){
    //nothing
}

//stampa dati sopra la campo di gioco
void Printer::setPlayerRoom(const char *name, int n, int time) {
    move(1, 1);
    printw(" Player: %s\tStanza N°%d\tTime: %d", name, n, time);
}

//cancella tutto quello che c'è sullo schermo
void Printer::startDraw() {
    clear();
}

//disegna le tutto in una volta quello che c'è nel buffer
void Printer::endDraw() {
    refresh();
}

//disegna un carattere ch in una posizione definita (x,y)
void Printer::print(int x, int y, char ch) {
    move(y, x);
    printw("%c", ch);
}

/*
temporary stuff

char *video[] = {"-------------------------------------------------------------------",
                "|                                                                  |",
                "|                                                                  |",
                "|                                                                  |",
                "|                                                                  |",
                "|                                                                  |",
                "|                                                                  |",
                "|                                                                  |",
                "|                X                                                 |",
                "|        XXXXXXXXXXXXXXX                                           |",
                "|                                                                  |",
                "--------------------------------------------------------------------"};

*/






//date basi e altezza disegna un rettangolo 
void Printer::drawRect(int startX, int startY, int mlength, int mheigth) {
    for(int y = 0; y < mheigth; y++) {
        for(int x = 0; x < mlength; x++) {
            if(y == 0 ||  y == (mheigth - 1)) {
                move(startX+x, startY+y);
                printw("|");
            }
            if(x == (mlength - 1) || x == 0){
                move(startX+x, startY+y);
                printw("-");
            }
        }
    }
}