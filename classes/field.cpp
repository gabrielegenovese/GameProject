#include "field.hpp"
#include "room.hpp"
#include <ncurses.h>
#include <iostream>

Field::Field(int width, int height) {
    this->width = width;
    this->height =height;
    first_level = new room_list;
    first_level->value = new Room(width, height, 0);
    first_level->next=NULL;
    first_level->prec = NULL;
    current_level = first_level;
};

void Field::add_room() {
    room_list * p = first_level;
    int counter = 0;
    
    // p cannot be NULL because of Class constructor
    while(p->next != NULL) {
        p=p->next;
        counter++;
    }

    room_list * tmp = new room_list;
    tmp->value = new Room(width, height, counter);
    tmp->next=NULL;
    tmp->prec = p;
    p->next = tmp;
};

char** Field::get_screen(int x, int y, int width, int height) {
    return (*(current_level->value)).get_content();
};

void Field::player_move(int& player_x, int& player_y, int dest_y, int dest_x) {
    if (check_movement(player_x, player_y, dest_y, dest_x)) {
        //if (player_x + dest_y < )
        player_x = dest_x;
        player_y = dest_y;
    } else {
        //bho
    }
};

bool Field::check_movement(int player_x, int player_y, int dest_y, int dest_x) {
    if ((*(current_level->value)).is_free(dest_x, dest_y)) {
        return true;
    } else {
        return false;
    }
};