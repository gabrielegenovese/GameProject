#include <ncurses.h>
#include "player.hpp"
#include "misc.hpp"

Player::Player(int startingX, int startingY) {
    //starting point
    this->x = startingX;
    this->y = startingY;
    this->isJumping = false;
    this->n_jump = 5;
    //character sprite
    this->character = '@';
    this->life = 100;
}


coordinate* Player::move(int keyPressed, bool isThereFloor) {
    coordinate* tmp = new coordinate;
    switch (keyPressed)
    {
    case KEY_UP:
        if(!isJumping && isThereFloor) {
            isJumping = true;
        }
        break;
    case KEY_DOWN:
        tmp->x = this->x;
        tmp->y = this->y+1;
        break;
    case KEY_RIGHT:
        tmp->y = this->y;
        tmp->x = this->x+2;
        break;
    case KEY_LEFT:
        tmp->y = this->y;
        tmp->x = this->x-2;
        break;
    default:
        if(!isJumping)
            tmp->y = this->y+1;
        else {
            tmp->y = this->y-1;
            n_jump--;
            if(n_jump == 0) {
                isJumping = false;
                n_jump = 5;
            }
        }
        tmp->x = this->x;
    }
    return tmp;
}

bool Player::isDead() {
    if(life <= 0) return true;
    else return false;
}

void Player::addHealth(int n) {
    this->life += n;
}

void Player::subHealth(int n) {  
    this->life -= n;
}

void Player::setX(int x) {
    this->x = x;
}

void Player::setY(int y) {
    this->y = y;
}

int Player::getX() {
    return x;
}

int Player::getY() {
    return y;
}

char Player::getChar() {
    return character;
}

