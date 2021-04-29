#include "misc.hpp"
#include "entity.hpp"

#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

class Player:public Entity
{
    private:
        //int x, y;
        //int life;
        char character;
        bool isJumping;
        int n_jump;
        int precKey;
        
    public:
        Player(int startingX, int startingY);
        bool isDead();
        coordinate* move(int keyPressed, bool isThereFloor);
        void setX(int x);
        void setY(int y);
        void setPrecKey(int setPrecKey);
        int getX();
        int getY();
        char getChar();
};

#endif