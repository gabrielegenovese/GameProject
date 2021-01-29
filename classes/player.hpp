#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

class Player
{
    private:
        int x, y;
        int life;
        char character;
        
    public:
        Player(int life = 100);
        bool isDead();
        void addHealth(int n);
        void subHealth(int n);
        void goUp();
        void goDown();
        void goRight();
        void goLeft();
        int getX();
        int getY();
        char getChar();
};

#endif