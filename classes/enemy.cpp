#include <ncurses.h>
#include <iostream>
#include "enemy.hpp"

Enemy::Enemy(){
    list=NULL;
}


void Enemy::newEnemy(char identifier,int life,int dmg,int type){
    enemies tmp = new ene;
    tmp->identifier=identifier;
    tmp->life=life;
    tmp->dmg=dmg;
    tmp->type=type;
    tmp->next=list;
    list=tmp;
}