#include "player.h"
using namespace std;

Player::Player(int life = 100)
{
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