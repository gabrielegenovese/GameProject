#include <ncurses.h>
#include "player.hpp"

Player::Player(int minX, int minY, int maxX, int maxY) {
    //starting point
    this->x = minX+1;
    this->y = maxY-1;
    //character sprite
    this->character = '@';
    this->life = 100;
    //borders
    this->maxX = minX+maxX-1;
    this->maxY = minY+maxY-1;
    this->minX = minX;
    this->minY = minY;
}

void Player::move(int keyPressed) {
    switch (keyPressed)
        {
        case KEY_UP:
            this->goUp();
            break;
        
        case KEY_DOWN:
            this->goDown();
            break;

        case KEY_RIGHT:
            this->goRight();
            break;
        
        case KEY_LEFT:
            this->goLeft();
            break;
        
        case KEY_F(4):
            this->life = 0;
            break;

        default:
            break;
        }
}

bool Player::isDead() {
    if(life <= 0) return true;
    else return false;
}

void Player::addHealth(int n) {
    this->life += n;
}

void Player::subHealth(int n)
{
    this->life -= n;
}

void Player::goUp() {
    if(y-1 > minY)
        this->y--;
}

void Player::goDown() {
    if(y+1 < maxY)
        this->y++;
}

void Player::goRight() {
    if(x+1 < maxX)
        this->x++;
}

void Player::goLeft() {
    if(x-1 > minX)
        this->x--;
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