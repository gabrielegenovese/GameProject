#include <ncurses.h>
#include "printer.hpp"

Printer::Printer(){
    //nothing
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
void Printer::printUI(const char *name, int room, int time, int points, int life, int strength, const char *weapon, const char *r_name[], int r_points[], int x_offset, int y_offset) {
    move(1, 3);
    printw("Player: %s           Stanza N°%d  Time: %d", name, room, time);
    move(3, x_offset);
    printw("  Punteggio %d", points);
    move(5, x_offset);
    printw("  Vita      %d", life);
    move(7, x_offset);
    printw("  Forza     %d", strength);
    move(9, x_offset); 
    printw("  Arma      %s", weapon);
    move(12, x_offset);
    printw("  Classifica:");
    move(13, x_offset);
    printw("  1. %s   %d", r_name[0], r_points[0]);
    move(14, x_offset);
    printw("  2. %s   %d", r_name[1], r_points[1]);
    move(15, x_offset);
    printw("  3. %s   %d", r_name[2], r_points[2]);
    move(16, x_offset);
    printw("  4. %s   %d", r_name[3], r_points[3]);
    move(17, x_offset);
    printw("  5. %s   %d", r_name[4], r_points[4]);
    move(y_offset, 0);
    printw("   Comandi:");
    move(y_offset+1, 0);
    printw("   F4: exit   arrow keys: move");
    move(y_offset+2, 0);
    printw("   E: shoot");
}

//date basi e altezza disegna un rettangolo 
void Printer::drawRect(int startX, int startY, int mwidth, int mheigth) {
    for(int y = 0; y < mheigth; y++) {
        for(int x = 0; x < mwidth; x++) {
            if(y == 0 ||  y == (mheigth - 1)) {
                move(startY+y, startX+x);
                printw("-");
            }
            else if(x == (mwidth - 1) || x == 0){
                move(startY+y, startX+x);
                printw("|");
            }
            if((x==0 && y==0)||(x==0 && y==(mheigth-1))||(x==(mwidth-1) && y==0)||(x==(mwidth-1) && y==(mheigth-1))) {
                move(startY+y, startX+x);
                printw("+");
            }
        }
    }
}