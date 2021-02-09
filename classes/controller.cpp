#include <ncurses.h>
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
}

void Controller::init_main_ter() {
    initscr();
    cbreak();
    nodelay(stdscr, TRUE);
    curs_set(FALSE);
    keypad(stdscr, true);
    noecho();
}

//controllo che la posizione x y sia uno spazio vuoto
bool Controller::can_player_move(int x, int y) {
    if(mvinch(y, x) == ' ') return true;
    else return false;
}

void Controller::move_player(Player& player, int keyPressed) {
    int x = player.getX();
    int y = player.getY();
    switch (keyPressed)
    {
    case KEY_UP:
        player.goUp(can_player_move(x, --y));
        break;
    
    case KEY_DOWN:
        player.goDown(can_player_move(x, ++y));
        break;

    case KEY_RIGHT:
        player.goRight(can_player_move(++x, y));
        break;
    
    case KEY_LEFT:
        player.goLeft(can_player_move(--x, y));
        break;
    
    case KEY_F(4):
        exit = true;
        break;

    default:
        break;
    }
}

int Controller::getMaxY() {
    return this->heigth;
}

int Controller::getMaxX() {
    return this->width;
}

//prende il nome del giocatore dal terminale
void Controller::getName(char *name){
    initscr();
    mvprintw(1, 1,"Nome Giocatore: ");
    getstr(name);
    endwin();
}

void Controller::run(Player player, Printer printer) {
    int keyPressed, x, y;
    char ch, name[80];

    //temporary
    const char *r_names[] = {"a", "b", "C", "d", "e"};
    int r_points[] = {1421, 123, 23, 4, 1};
    const char *weapon = "Glock";

    //TEMP 2
    Field r1 (50, 1);
        

    this->getName(name);

    init_main_ter();
    
    while (!player.isDead() && !exit) {
        
        

        keyPressed = getch();
        
        // muove il personaggio
        move_player(player, keyPressed);
        x = player.getX();
        y = player.getY();
        ch = player.getChar();

        printer.startDraw();
        printer.print_room(r1.get_screen(-1, -1, -1, -1), game_x, game_y, game_width, game_heigth);

        printer.printUI(name, 0, time_passed/(20), 43, 100, 10, weapon, r_names, r_points, game_x+game_width, game_y+game_heigth);
        
        printer.drawRect(0, 0, this->width, this->heigth);                                  //riquadro gui
        printer.drawRect(this->game_x, this->game_y, this->game_width, this->game_heigth);  //riquadro campo 

        printer.print(x, y, player.getChar());

        printer.endDraw();

        this->time_passed += 1;
        timeout(50);    //50 millisecond
    }
    endwin();
}


