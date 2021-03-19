#include <ncurses.h>
#include "player.hpp"
#include "misc.hpp"
#include "entity.hpp"

Player::Player(int startingX, int startingY):Entity(startingX,startingY,100) {
    //starting point
    this->isJumping = false;
    this->n_jump = 5;
    this->precKey = 0;
    //character sprite
    this->character = '@';
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
        tmp->x = coord->x;
        tmp->y = coord->y+1;
        // annullo il jump
        isJumping = false;
        n_jump = 5;
        break;
    case KEY_RIGHT:
        tmp->y = coord->y;
        tmp->x = coord->x+2;
        this->precKey = KEY_RIGHT;
        break;
    case KEY_LEFT:
        tmp->y = coord->y;
        tmp->x = coord->x-2;
        this->precKey = KEY_LEFT;
        break;
    default:
        if(isJumping) {
            tmp->y = coord->y-1;
            if(n_jump == 0) {
                isJumping = false;
                n_jump = 5;
                //precKey = 0; serve per evitare che non faccia come spiderman ma vorrei trovare un'altra soluzione
            }
            n_jump--;
            //movimento mentre sale
            if(precKey == KEY_LEFT)
                tmp->x = coord->x-1;
            if(precKey == KEY_RIGHT)
                tmp->x = coord->x+1;
            if(precKey == 0)
                tmp->x = coord->x;
        }
    }
    //gravity e movimento mentre cade
    if(!isThereFloor && !isJumping) {
        tmp->y = coord->y+1;
        if(precKey == KEY_LEFT)
            tmp->x = coord->x-1;
        if(precKey == KEY_RIGHT)
            tmp->x = coord->x+1;
        if(precKey == 0)
            tmp->x = coord->x;
    }
    return tmp;
}

bool Player::isDead() {
    if(health <= 0) return true;
    else return false;
}


void Player::setPrecKey(int precKey) {
    this->precKey = precKey;
}

int Player::getX() {
    return Entity::getX();
}

int Player::getY() {
    return Entity::getY();
}

void Player::setX(int x) {
    Entity::setX(x);
}

void Player::setY(int y) {
    Entity::setY(y);
}

char Player::getChar() {
    return character;
}

