#include "field.hpp"
#include "room.hpp"
#include "printer.hpp"
#include "misc.hpp"
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
    //generiamo immediatamente la prossima stanza
    add_room();
};

void Field::add_room() {
    room_list * p = first_level;
    int counter = 1;
    
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

void Field::print_screen(int x_player, boxCoordinate gameBox) {
    int x = gameBox.x;
    int y = gameBox.y;
    int width = gameBox.width;
    int height = gameBox.height;
    int diff = x_player - this->width/4;
    char ** res;

    if (this->current_level == this->first_level && diff <= 0) {
        res = (*(current_level->value)).get_content();
        print_room(res, x, y, width, height);
    } else {
        //get the two room from which i get the screen
        char ** part1 = (*(current_level->value)).get_content();
        char ** part2;
        if (diff > 0) part2 = (*(current_level->next->value)).get_content();
        else part2 = (*(current_level->prec->value)).get_content();

        //combine the two room 
        res = new char * [this->height];
        for (int row = 0; row < this->height; row++) {
            *(res+row) = new char [this->width];
            for (int col = 0; col < this->width; col++) {
                if (diff > 0) {
                    if (col < width-diff) res[row][col] = part1[row][col+diff];
                    else res[row][col] = part2[row][col-width+diff];
                }
                else if (diff < 0) {
                    if (col+diff < 0) res[row][col] = part2[row][col+width+diff];
                    else res[row][col] = part1[row][col+diff];
                } 
                else res[row][col] = part1[row][col];
            }
        }
        print_room(res, x, y, width, height);
        delete res;
    }
};

void Field::move_player(Player& player, int dest_x, int dest_y) {
    //dest_x and dest_y may be modified to reposition the character;
    if (check_movement(player.getX(), player.getY(), dest_x, dest_y)) {
        player.setX(dest_x);
        player.setY(dest_y);
    } else {
        // dovremo rimettere il giocatore al a destra/sinistra o sopra/sotto al muro
        // perché sennò si ferma a mezz'aria come spiderman
        // per fabio: dovrebbe essere gestito da field o da pleyer sta cosa?
    }
};

bool Field::check_movement(int start_x, int start_y, int& dest_x, int& dest_y) {
    //boundary check...
    if (dest_y < 0 || dest_y >= height) {
        return false;
    } else {
        if (dest_x < 0) {
            if (current_level->prec == NULL) return false;
            else {
                current_level = current_level->prec;
                dest_x = width+dest_x;
            }
        } else if (dest_x >= width) {
            if (current_level->next->next == NULL) {
                add_room();
                current_level = current_level->next;
            }
            else {
                current_level = current_level->next;
            }
            dest_x = dest_x-width;
        }
    }
    if ((*(current_level->value)).is_free(dest_x, dest_y)) {
        return true;
    } else {
        return false;
    }
    
}

int Field::reloc_x_player(int x_p) {
    if (this->current_level == this->first_level && x_p - width/4 <= 0)
        return x_p;
    else
        return width/4;
}

bool Field::isThereFloor(int y) {
    if (y == height-1)
        return true;
    return (*(current_level->value)).is_floor(y-1);
}