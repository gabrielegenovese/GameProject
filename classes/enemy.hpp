#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include "player.hpp"

//uaglio è l'hpp sposta tutto sul cpp

//cerca il "tipo" del nemico e assegna il relativo carattere
struct ene{
    char identifier;
    int life;
    int dmg;
    int type;
    ene *next;
};

typedef ene *enemies;

class Enemy{
    private:
        enemies list;
    public:
        Enemy();
        void newEnemy (char identifier,int life,int dmg,int type);
        


};




#endif