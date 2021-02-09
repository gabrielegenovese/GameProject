/*
<<<<<<< HEAD
The level is devided in many room, each one 
=======

>>>>>>> 1d08489b2d59a763ce3082656ef80f7dd3912e8b
*/

#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

<<<<<<< HEAD


class Room {
    private:


    public:
=======
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


>>>>>>> 1d08489b2d59a763ce3082656ef80f7dd3912e8b

};

#endif