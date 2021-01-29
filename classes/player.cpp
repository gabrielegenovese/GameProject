#include <ncurses.h>
#include "player.hpp"

Player::Player(int maxX, int maxY)
{
    this->x = 2;
    this->y = 2;
    this->character = '@';
    this->life = 100;
    this->maxX = maxX;
    this->maxY = maxY;
}

void Player::move(int keyPressed)
{
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

bool Player::isDead()
{
    if(life <= 0) return true;
    else return false;
}

void Player::addHealth(int n)
{
    this->life += n;
}

void Player::subHealth(int n)
{
    this->life -= n;
}

void Player::goUp() {
    if(y-2 > 0)
        this->y--;
}

void Player::goDown() {
    if(y+2 < maxY)
        this->y++;
}

void Player::goRight() {
    if(x+2 < maxX)
        this->x++;
}

void Player::goLeft() {
    if(x-1 > 0)
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