#include <ncurses.h>
#include "player.hpp"

Player::Player(int life)
{
    this->x = 0;
    this->y = 0;
    this->character = '*';
    this->life = life;
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

void Player::goUp()
{
    this->y--;
}

void Player::goDown()
{
    this->y++;
}

void Player::goRight()
{
    this->x++;
}

void Player::goLeft()
{
    this->x--;
}

int Player::getX()
{
    return x;
}

int Player::getY()
{
    return y;
}

char Player::getChar()
{
    return character;
}