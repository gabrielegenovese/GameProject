#include <ncurses.h>
#include "player.hpp"

Player::Player() {
    //starting point
    this->x = 5;
    this->y = 5;
    //character sprite
    this->character = '@';
    this->life = 100;
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

void Player::goUp(bool can) {
    if(can)
        this->y--;
}

void Player::goDown(bool can) {
    if(can)
        this->y++;
}

void Player::goRight(bool can) {
    if(can)
        this->x++;
}

void Player::goLeft(bool can) {
    if(can)
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