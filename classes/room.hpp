/*
*/

#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

class Room {
    private:
        int width, height;
        int level;
        char** content;

    public:
        Room ();
        Room(int width, int height, int level);
        char** generate_room();
        char** get_content();
        bool is_free(int x, int y);
        bool is_floor(int y);

};

#endif