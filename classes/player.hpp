#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

class Player
{
    private:
        int minX, minY, maxX, maxY, x, y;
        int life;
        char character;
        
    public:
        Player(int minX, int minY, int maxX, int maxY);
        bool isDead();
        void addHealth(int n);
        void subHealth(int n);
        void move(int keyPressed);
        void goUp();
        void goDown();
        void goRight();
        void goLeft();
        int getX();
        int getY();
        char getChar();
};

#endif