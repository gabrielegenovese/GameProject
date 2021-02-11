#include "room.hpp"
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
        bool check_movement(int player_x, int player_y, int dest_y, int dest_x);
        
    public:
        Field (int width, int height);
        char ** get_screen(int x, int y, int width, int height);
        void player_move(int& player_x, int& player_y, int dest_y, int dest_x);


};

#endif