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
    coordinate playerCoord {1,1};
    this->player = new Player(playerCoord);
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
        this->shoots = newShoot(this->shoots, x+3, y+3);
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


void Controller::movePlayer(int keyPressed) {
    coordinate* destination = (*player).move(keyPressed);
    (*fieldManager).move_player((*player), destination->x, destination->y);
    /*
    char code = (*fieldManager).canEntityMove((*player).getLocation(), destination)
    if (strcmp(code, "c") == 0) {
        player.setCoordinate(destination);
    }
    else if (strcmp(code, "r")== 0) {
        player.stopJump();
    }
    else if (strcmp(code, "w") == 0) {
        
    } 
    else if (strcmp(code, "b") == 0) {

    }
    else if (strcmp(code, "e") == 0) {
        
    }
    */
    keyManage(keyPressed, (*fieldManager).reloc_x_player((*player).getX()), (*player).getY());
}


void Controller::gameLogic(int keyPressed) {
    
    movePlayer(keyPressed);
    /*
    moveEnemies()
    spawnBullets()
    moveBullets()
    */

    //ending routine that need to go into a single method
    this->shoots = removeShoots(this->shoots, (*fieldManager));
    this->time_passed += 1;
    timeout(50);            
}


void Controller::printEverything() {
    startDraw();
    printGameBorder();
    (*fieldManager).print_screen((*player).getX(), gameBox);
    //NON VA BENE
    my_print((*fieldManager).reloc_x_player((*player).getX())+gameBox.x, (*player).getY()+gameBox.y, (*player).getChar());
    printShoots(this->shoots, this->gameBox.width);
    endDraw();
}


void Controller::run() {
    int keyPressed;
    while (!(*player).isDead() && !exit) {
        keyPressed = getch();
        gameLogic(keyPressed);
        printEverything();
    }
    endwin();
}