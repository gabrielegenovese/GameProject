#ifndef SHOOTS_H_INCLUDED
#define SHOOTS_H_INCLUDED

#include "field.hpp"

struct shooting
{
    int x, y;
    int speed;
    shooting *next;
};

typedef shooting *SHOOTS;

SHOOTS newShoot(SHOOTS shoots, int x, int y);
SHOOTS removeShoots(SHOOTS shoots, Field field);
void printShoots(SHOOTS shoots, int maxX);

// non usata
void eCD(int& cECD, bool eCoolDown);


#endif