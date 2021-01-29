#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <ncurses.h>

class Player
{
    private:
        int x, y;
        int life;
        char character;
    public:
        Player(int life = 100)
        {
            this->x = 0;
            this->y = 0;
            this->character = '*';
            this->life = life;
        }

        bool isDead()
        {
            if(life <= 0) return true;
            else return false;
        }

        void addHealth(int n)
        {
            this->life += n;
        }

        void subHealth(int n)
        {
            this->life -= n;
        }

        void goUp()
        {
            this->y--;
        }
        
        void goDown()
        {
            this->y++;
        }

        void goRight()
        {
            this->x++;
        }

        void goLeft()
        {
            this->x--;
        }

        int getX()
        {
            return x;
        }

        int getY()
        {
            return y;
        }

        char getChar()
        {
            return character;
        }
};

#endif