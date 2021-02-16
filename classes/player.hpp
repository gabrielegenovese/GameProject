#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

struct Coordinate
{
    int x;
    int y;
};

typedef Coordinate *coord;

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
        coord move(int keyPressed);
        void setX(int x);
        void setY(int y);
        int getX();
        int getY();
        char getChar();
};

#endif