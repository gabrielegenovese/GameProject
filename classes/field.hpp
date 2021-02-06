/*

*/

#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED

#include "room.hpp"

//lista bilinkata di "stanze" 
struct room_list {
    Room value;
    room_list * prec;
    room_list * next;
};

class Field {
    private:
        room_list game_level;

    public:

};

#endif