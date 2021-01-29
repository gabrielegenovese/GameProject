#include <ncurses.h>
#include <iostream>
#include <string.h>
#include "controller.hpp"


Controller::Controller()
{
    this->length = 50;
    this->heigth = 20;
}

void Controller::initTer() {
    initscr();
    resize_term(heigth, length);
    raw();
    keypad(stdscr, true);
    noecho();
}

void Controller::SetPlayerRoom(const char *name, int n) {
    move(1,1);
    printw(" Player: %s\tStanza N°%d ", name, n);
}

void Controller::StartDraw() {
    clear();
}

void Controller::EndDraw() {
    refresh();
}

void Controller::print(int x, int y, char ch) {
    move(y, x);
    printw("@");
}

int Controller::getKey() {
    return getch();
}

int Controller::getMaxX() {
    return this->length;
}

int Controller::getMaxY() {
    return this->heigth;
}

void Controller::endTer() {
    endwin();
}

//prende il nome del giocatore dal terminale
void Controller::getName(char *name){
    initscr();
    mvprintw(1, 1,"Nome Giocatore: ");
    getstr(name);
    endwin();
}


//date basi e altezza disegna un rettangolo 
int Controller::contorno(int mlength, int mheigth) {
    for(int y = 0; y < mheigth; y++) {
        for(int x = 0; x < mlength; x++) {
            if(y == 0 || x == 0 || x == (mlength - 1) || y == (mheigth - 1)) {
                move(x, y);
                printw("X");
            }
        }
    }
    return 0;
}
