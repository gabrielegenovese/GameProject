#include "room.hpp"

Room::Room(int width, int height, int level) {
    this->width = width;
    this->height = height;
    this->level = level;
    this->content = generate_room();
};

char** Room::get_content() {
    return content;
};

char** Room::generate_room() {
    char** start = new char * [height];
    for (int row = 0; row < height; row++) {
        *(start+row) = new char [width];
        for (int col = 0; col < width; col++) {
            if ((row == 0 && col == 0) || (row == height-1 && col == 0) || (row == 0 && col == width-1) || (row == height-1 && col == width-1)) {
                *(*(start+row) + col) = (char)((int)'a' + level);
            }
        }
    }
    return start;
}