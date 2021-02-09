#include "field.hpp"
#include "room.hpp"
#include <ncurses.h>

Field::Field(int width, int height) {
    this->width = width;
    this->height =height;
    levels = NULL;
    add_room();
};

void Field::add_room() {
    room_list * old = NULL;
    room_list * p = levels;
    int counter = 0;
    while(p != NULL) {
        old=p;
        p=p->next;
        counter++;
    }

    room_list * tmp = new room_list;
    tmp->value = Room(width, height, counter);
    tmp->next=NULL;
    tmp->prec = old;
};

char** Field::get_screen(int x, int y, int width, int height) {
    return levels->value.get_content();
}