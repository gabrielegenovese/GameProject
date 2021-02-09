#include "room.hpp"
#include <ncurses.h>

Room::Room(int width, int heigth, int level) {
    this->width = width;
    this->heigth = heigth;
    this->level = level;
    this->content = generate_room();
};

char** Room::get_content() {
    return content;
};

char** Room::generate_room() {
    char** start = new char * [heigth];
    for (int row = 0; row < heigth; row++) {
        *(start+row) = new char [width];
        for (int col = 0; col < width; col++) {
            *(*(start+row) + col) = 'c';
        }
    }
    return start;
}