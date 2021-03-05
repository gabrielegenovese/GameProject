#include <ncurses.h>
#include <iostream>
#include "controller.hpp"
#include "player.hpp"
#include "printer.hpp"
#include "field.hpp"

Controller::Controller(int game_x, int game_y, int game_width, int game_heigth, int width, int heigth) {
    this->game_x = game_x;
    this->game_y = game_y;
    this->game_width = game_width;
    this->game_heigth = game_heigth;
    this->width = width;
    this->heigth = heigth;
    this->time_passed = 0;
    this->exit = false;
    this->eCoolDown = false;
    this->shoots = NULL;
}

void Controller::init_main_ter() {
    initscr();
    cbreak();
    nodelay(stdscr, TRUE);
    curs_set(FALSE);
    keypad(stdscr, true);
    noecho();
}

void Controller::keyManage(int keyPressed, int x, int y) {
    switch (keyPressed)
    {
    case KEY_UP:
    case KEY_DOWN:
    case KEY_LEFT:
    case KEY_RIGHT:
        break;
    case 'e':
        this->shoots = newShoot(this->shoots, x, y);
        break;
    case KEY_F(4):
        exit = true;
        break;
    
    default:
        break;
    }
}

//prende il nome del giocatore dal terminale
void Controller::getName(char *name){
    initscr();
    mvprintw(1, 1,"Nome Giocatore (max 20 char): ");
    getstr(name);
    endwin();
}

void Controller::run(Player player) {
    //init var and object
    int keyPressed;
    char name[20];
    Field campo(game_width, game_heigth);

    //temporary var
    const char *r_names[] = {"Geronimo", "Gianni", "Gigio", "Giornix", "Geppo"};
    int r_points[] = {1421, 123, 23, 4, 1};
    const char *weapon = "Glock";

    //setup method
    this->getName(name);
    init_main_ter();

    while (!player.isDead() && !exit) {

        //muovo il personaggio passando le coordinate a field per controllare
        //se c'è qualcosa in mezzo e imposta le coordinate di conseguenza
        keyPressed = getch();

        startDraw();

        coord des_loc = player.move(keyPressed);
        campo.move_player(player, des_loc->x, des_loc->y);
        keyManage(keyPressed, player.getX(), player.getY());

        
        print_room(campo.get_screen(-1, -1, -1, -1), game_x, game_y, game_width, game_heigth);
        printUI(name, 0, time_passed/(20), 43, 100, 10, weapon, r_names, r_points, game_x+game_width+1, game_y+game_heigth+1);
        print_borders();
        my_print(player.getX()+game_x, player.getY()+game_y, player.getChar());
        printShoots(this->shoots);

        endDraw();

        //game loop ending routine
        this->shoots = removeShoots(this->shoots, campo);
        this->time_passed += 1;
        timeout(50);                    //50 milliseconds
    }

    endwin();
}

int Controller::getMaxY() {
    return this->heigth;
}

int Controller::getMaxX() {
    return this->width;
}

void Controller::print_borders() {
    //stampa il riquadro gui
    drawRect(0, 0, this->width, this->heigth);  
    //stampa il riquadro campo                
    drawRect(this->game_x-1, this->game_y-1, this->game_width+2, this->game_heigth+2);  
}