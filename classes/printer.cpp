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

//disegna l'UI del gioco
void Printer::printUI(const char *name, int room, int time, int points, int life, int strength, const char *weapon, const char *r_name[], int r_points[]) {
    move(0, 0);
    printw("--------------------------------------------------------------------------");
    move(1, 0);
    printw("|   Player: %s           Stanza N°%d  Time: %d                \t         |", name, room, time);
    move(2, 0);
    printw("| ----------------------------------------------              \t         |");
    move(3, 0);
    printw("| |                                            |  Punteggio %d\t         |", points);
    move(4, 0);
    printw("| |                                            |              \t         |");
    move(5, 0);
    printw("| |                                            |  Vita      %d\t         |", life);
    move(6, 0);
    printw("| |                                            |               \t         |");
    move(7, 0);
    printw("| |                                            |  Forza     %d\t         |", strength);
    move(8, 0);
    printw("| |                                            |              \t         |");
    move(9, 0); 
    printw("| |                                            |  Arma      %s        |", weapon);
    move(10, 0);
    printw("| |                                            |              \t         |");
    move(11, 0);
    printw("| |                                            |  Classifica:\t         |");
    move(12, 0);
    printw("| |                                            |  1. %s   %d\t         |", r_name[0], r_points[0]);
    move(13, 0);
    printw("| |                                            |  2. %s   %d\t         |", r_name[1], r_points[1]);
    move(14, 0);
    printw("| ----------------------------------------------  3. %s   %d\t         |", r_name[2], r_points[2]);
    move(15, 0);
    printw("|  Comandi:                                       4. %s   %d\t         |", r_name[3], r_points[3]);
    move(16, 0);
    printw("|  F4: exit   arrow keys: move                    5. %s   %d\t         |", r_name[4], r_points[4]);
    move(17, 0);
    printw("|  E: shoot                                                 \t         |");
    move(18, 0);
    printw("--------------------------------------------------------------------------");
}

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