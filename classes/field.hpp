#include "room.hpp"
#include "misc.hpp"
#include "player.hpp"
#include <ncurses.h>

#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED

struct room_list {
    Room * value;
    room_list * next;
    room_list * prec;
};

class Field {
    private:
        int width, height;
        room_list * first_level;
        room_list * current_level;
        void add_room();
        
    public:
        Field (int width, int height);
        void print_screen(int x_player, boxCoordinate gameBox);
        void move_player(Player& player, int dest_y, int dest_x);
        bool check_movement(int start_x, int start_y, int& dest_x, int& dest_y);
        int reloc_x_player(int x_p);
};

#endif