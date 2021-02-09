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
        
    public:
        Field (int width, int height);
        char ** get_screen(int x, int y, int width, int height);


};

#endif