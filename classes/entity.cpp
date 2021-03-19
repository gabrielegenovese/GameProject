#include <ncurses.h>
#include "misc.hpp"
#include "entity.hpp"

Entity::Entity(int x, int y, int health){
    coord=new coordinate;
    coord->x=x;
    coord->y=y;
    this->health=health;
}

pCoordinate Entity::move(){
    pCoordinate rng=new coordinate;

    rng->x=-1;
    rng->y=-1;

    return rng;
}

void Entity::addHealth(int n){
    health += n;
}

void Entity::subHealth(int n){
    health -= n;
}

void Entity::setHealth(int n){
    health = n;
}

int Entity::getHealth(){
    return health;
}

void Entity::setCoord(int x, int y){
    coord->x=x;
    coord->y=y;
}

int Entity::getY(){
    return coord->y;
}

int Entity::getX(){
    return coord->x;
}

void Entity::setY(int y){
    coord->y=y;
}

void Entity::setX(int x){
    coord->x=x;
}

pCoordinate Entity::getCoord(){
    return coord;
}