#include <ncurses.h>
#include "printer.hpp"
#include "misc.hpp"


//cancella tutto quello che c'è sullo schermo
void startDraw() {
    clear();
}

//disegna le tutto in una volta quello che c'è nel buffer
void endDraw() {
    refresh();
}

//disegna un carattere ch in una posizione definita (x,y)
void my_print(int x, int y, char ch) {
    move(y, x);
    printw("%c", ch);
}



void drawRect(boxCoordinate box) {
    for(int y = 0; y < box.height; y++) {
        for(int x = 0; x < box.width; x++) {
            if(y == 0 ||  y == (box.height - 1)) {
                move(box.y+y, box.x+x);
                printw("-");
            }
            else if(x == (box.width - 1) || x == 0){
                move(box.y+y, box.x+x);
                printw("|");
            }
            if((x==0 && y==0)||(x==0 && y==(box.height-1))||(x==(box.width-1) && y==0)||(x==(box.width-1) && y==(box.height-1))) {
                move(box.y+y, box.x+x);
                printw("+");
            }
        }
    }
}


void print_room(char ** cont, int x, int y, int width, int heigth) {
    for (int i = 0; i < heigth; i++) {
        for (int j = 0; j < width; j++) {
            move(i+y, j+x);
            printw((*(cont+i)+j));
        }
    }
}


void print_string(int x, int y, const char* s) {
    move(y, x);
    printw("%s", s);
}

void print_number(int x, int y, int n) {
    move(y, x);
    printw("%d", n);
}