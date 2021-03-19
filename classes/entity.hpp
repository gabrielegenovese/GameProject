#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED
#include "misc.hpp"

typedef coordinate *pCoordinate;

class Entity{
    protected:
    pCoordinate coord;
    int health;
    public:
    Entity(int x, int y, int health);
    pCoordinate move();
    void addHealth(int value);
    void subHealth(int value);
    void setHealth(int value);
    int getHealth();
    void setCoord(int x,int y);
    pCoordinate getCoord();
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
};



#endif