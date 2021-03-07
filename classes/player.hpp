#include "misc.hpp"

#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

class Player
{
    private:
        int x, y;
        int life;
        char character;
        
    public:
        Player(int startingX, int startingY);
        bool isDead();
        void addHealth(int n);
        void subHealth(int n);
        coordinate* move(int keyPressed);
        void setX(int x);
        void setY(int y);
        int getX();
        int getY();
        char getChar();
};

#endif