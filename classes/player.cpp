#include <ncurses.h>
#include "player.hpp"

Player::Player(int life)
{
    this->x = 0;
    this->y = 0;
    this->character = '*';
    this->life = life;
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
    this->y--;
}

void Player::goDown() {
    this->y++;
}

void Player::goRight() {
    this->x++;
}

void Player::goLeft() {
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