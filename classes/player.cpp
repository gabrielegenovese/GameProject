#include <ncurses.h>
#include "player.hpp"

Player::Player(int startingX, int startingY) {
    //starting point
    this->x = startingX;
    this->y = startingY;
    //character sprite
    this->character = '@';
    this->life = 100;
}


coord Player::move(int keyPressed) {
    coord tmp = new Coordinate;
    switch (keyPressed)
    {
    case KEY_UP:
        tmp->x = this->x;
        tmp->y = this->y-1;
        break;
    
    case KEY_DOWN:
        tmp->x = this->x;
        tmp->y = this->y+1;
        break;

    case KEY_RIGHT:
        tmp->y = this->y;
        tmp->x = this->x+1;
        break;
    
    case KEY_LEFT:
        tmp->y = this->y;
        tmp->x = this->x-1;
        break;

    default:
        tmp->y = this->y;
        tmp->x = this->x;
        break;
    }
    // da mettere apposto
    /*case 'e':
        if(!this->eCoolDown) {
            this->shoots = newShoot(x, y);
            this->eCoolDown = true;
        }
        break;*/
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

