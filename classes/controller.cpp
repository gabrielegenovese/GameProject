#include <ncurses.h>
#include <iostream>
#include "controller.hpp"
#include "player.hpp"
#include "printer.hpp"
#include "field.hpp"
#include "misc.hpp"

Controller::Controller(boxCoordinate gameBox) {
    this->gameBox = gameBox;
    this->fieldManager = new Field(gameBox.width, gameBox.height);
    setupInternalState();
}

void Controller::initMainTerminal() {
    initscr();
    cbreak();
    nodelay(stdscr, TRUE);
    curs_set(FALSE);
    keypad(stdscr, true);
    noecho();
}

void Controller::keyManage(int keyPressed, int x, int y) {
    switch (keyPressed)
    {
    case KEY_UP:
    case KEY_DOWN:
    case KEY_LEFT:
    case KEY_RIGHT:
        break;
    case 'e':
        this->shoots = newShoot(this->shoots, x, y);
        break;
    case KEY_F(4):
        exit = true;
        break;
    
    default:
        break;
    }
}


void Controller::getPlayerName(){
    initscr();
    mvprintw(1, 1,"Nome Giocatore (max 20 char): ");
    getstr(this->playerName);
    endwin();
}


void Controller::setupInternalState() {
    this->time_passed = 0;
    this->exit = false;
    this->eCoolDown = false;
    this->shoots = NULL;
}


void Controller::printGameBorder() {
    boxCoordinate gameBorder {gameBox.x-1, gameBox.y-1, gameBox.width+2, gameBox.height+2};
    drawRect(gameBorder);  
}


void Controller::gameLogic(int keyPressed, Player& player) {
    coordinate* desLocation = player.move(keyPressed, (*fieldManager).isThereFloor(player.getY()));
    (*fieldManager).move_player(player, desLocation->x, desLocation->y);
    keyManage(keyPressed, (*fieldManager).reloc_x_player(player.getX())+1, player.getY()+1);
    this->shoots = removeShoots(this->shoots, (*fieldManager));
    this->time_passed += 1;
    timeout(50);            
}


void Controller::printEverything(Player& player) {
    startDraw();
    printGameBorder();
    (*fieldManager).print_screen(player.getX(), gameBox);
    //NON VA BENE
    my_print((*fieldManager).reloc_x_player(player.getX())+gameBox.x, player.getY()+gameBox.y, player.getChar());
    printShoots(this->shoots, this->gameBox.width);
    endDraw();
}


void Controller::run(Player player) {
    int keyPressed;
    while (!player.isDead() && !exit) {
        keyPressed = getch();
        gameLogic(keyPressed, player);
        printEverything(player);
    }
    endwin();
}