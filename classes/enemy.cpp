#include <ncurses.h>
#include <iostream>
#include "enemy.hpp"

Enemy::Enemy(){
    catalogue=NULL;
    living=NULL;
}


void Enemy::newEnemy(char identifier,int life,int dmg,int type){
    enemies tmp = new ene;
    tmp->identifier=identifier;
    tmp->life=life;
    tmp->dmg=dmg;
    tmp->type=type;
    tmp->next=catalogue;
    catalogue=tmp;
}


void Enemy::printEnemy(int room, int type, int x, int y){
    eneliving tmp = new alive;
    tmp->type=type;
    enemies save=catalogue;
    while(catalogue!=NULL){
        if(type=catalogue->type) tmp->life=catalogue->life;
        catalogue=catalogue->next;
    }
    catalogue=save;
    tmp->room=room;
    tmp->x=x;
    tmp->y=y;
    tmp->next=living;
    living=tmp;
}

void Enemy::removeEnemy(){
    
}