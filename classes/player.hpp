#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

class Player
{
    private:
        int x, y;
        int life;
        char character;
        
    public:
        Player();
        bool isDead();
        void addHealth(int n);
        void subHealth(int n);
        void goUp(bool can);
        void goDown(bool can);
        void goRight(bool can);
        void goLeft(bool can);
        int getX();
        int getY();
        char getChar();
};

#endif