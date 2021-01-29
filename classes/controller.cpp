#include <ncurses.h>
#include "controller.hpp"
#include "player.hpp"
#include "printer.hpp"



Controller::Controller(int length, int heigth) {
    this->length = length;
    this->heigth = heigth;
    this->time_passed = 0;
}

void Controller::initTer() {
    initscr();
    resize_term(heigth, length);
    raw();
    keypad(stdscr, true);
    noecho();
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


void Controller::run(Player player, Printer printer) {
    int keyPressed, x, y;
    char ch, name[80];
    this->time_passed += 1;
    this->getName(name);
    this->initTer();

    while (!player.isDead()) {
        keyPressed = this->getKey();
        
        // muove il personaggio
        player.move(keyPressed);
        x = player.getX();
        y = player.getY();
        ch = player.getChar();

        printer.startDraw();

        printer.drawRect(0,0,heigth,length);
        //printer.drawRect(3, 3, (heigth*3)/4, (length*3)/4);
        printer.setPlayerRoom(name, 0, this->time_passed);  //scrive nome del giocatore e stanza
        printer.print(x, y, player.getChar());

        printer.endDraw();

    }

    this->endTer();
}


