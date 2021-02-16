#include "field.hpp"
#include "room.hpp"
#include "printer.hpp"
#include <ncurses.h>
#include <iostream>

Field::Field(int width, int height) {
    this->width = width;
    this->height = height;
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

void Field::move_player(Player& player, int dest_x, int dest_y) {
    if (check_movement(player.getX(), player.getY(), dest_x, dest_y)) {
        //if (player_x + dest_y < )
        player.setX(dest_x);
        player.setY(dest_y);
    } else {
        //bho
    }
};

bool Field::check_movement(int start_x, int start_y, int dest_x, int dest_y) {
    
    if (dest_y < 0 || dest_y >= height || dest_x < 0 || dest_x >= width) return false;
    if ((*(current_level->value)).is_free(dest_x, dest_y)) {
        return true;
    } else {
        return false;
    }
    
};