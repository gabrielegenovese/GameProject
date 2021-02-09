/*

*/

#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

class Room {
    private:
        int width, heigth;
        int level;
        char** content;

    public:
        Room(int width, int heigth, int level);
        char** generate_room();
        char** get_content();



};

#endif