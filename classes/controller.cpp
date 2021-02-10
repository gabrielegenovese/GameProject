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

SHOOTS Controller::newShoot(int x, int y) {
    SHOOTS tmp = new shooting;
    tmp->x = x;
    tmp->y = y;
    tmp->speed = 1;
    tmp->next = this->shoots;
    return tmp;
}

void Controller::printShoots() {
    SHOOTS tmp = this->shoots;
    while (tmp != NULL)
    {
        tmp->x += tmp->speed;
        move(tmp->y, tmp->x);
        printw("---");
        tmp = tmp->next;
    }
}

SHOOTS Controller::removeShoots() {
    if(this->shoots != NULL) {
        if(this->shoots->next != NULL) {
            SHOOTS tmp = this->shoots, prec = this->shoots;
            while(tmp != NULL) {
                if(!isEmpty(tmp->x+3,tmp->y)){
                    prec->next = NULL;
                    delete(tmp);
                    return(this->shoots);
                }
                prec = tmp;
                tmp = tmp->next;
            }
        }else{
            if(this->shoots->x+3  > game_width){
                delete(this->shoots);
                return NULL;
            }
        }
    }
    return this->shoots;
}

//controllo che la posizione x y sia uno spazio vuoto
bool Controller::isEmpty(int x, int y) {
    if(mvinch(y, x) == ' ') return true;
    else return false;
    return true;
}

void Controller::eCD(int& cECD) {
    if(this->eCoolDown) {
        if (cECD < 0){
            cECD = 3;
            this->eCoolDown = false;
        } else {
            cECD--;
        }
    }
}


/*
volevo provare a togliere il dalay che c'è se tengo premuto un tasto
ma non si riesce a fare con ncurses, si riesce solo con un comando
linux. Segui link sotto se vuoi saperne di più:
https://unix.stackexchange.com/questions/58651/adjusting-keyboard-sensitivity-in-a-command-line-terminal

Ho cercato anche un modo per sparare mentre ci si muove ma non si riesce a fare
*/
void Controller::move_player(Player& player, int keyPressed) {
    int x = player.getX();
    int y = player.getY();
    switch (keyPressed)
    {
    case KEY_UP:
        player.goUp(isEmpty(x, --y));
        break;
    
    case KEY_DOWN:
        player.goDown(isEmpty(x, ++y));
        break;

    case KEY_RIGHT:
        player.goRight(isEmpty(++x, y));
        break;
    
    case KEY_LEFT:
        player.goLeft(isEmpty(--x, y));
        break;
    
    case KEY_F(4):
        exit = true;
        break;

    case 'e':
        if(!this->eCoolDown) {
            this->shoots = newShoot(x, y);
            this->eCoolDown = true;
        }
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

void Controller::run(Player player, Printer printer) {
    int keyPressed, x, y;
    char name[20];

    //temporary var
    const char *r_names[] = {"Geronimo", "Gianni", "Gigio", "Giornix", "Geppo"};
    int r_points[] = {1421, 123, 23, 4, 1};
    const char *weapon = "Glock";

    //TEMP 2
    Field r1(game_width, game_heigth);

    this->getName(name);

    init_main_ter();
    
    int cECD = 5;

    while (!player.isDead() && !exit) {
        
        // evito lo spam di spari così non ho più quell'errore
        // pezza orribile
        eCD(cECD);

        keyPressed = getch();
        
        // muove il personaggio
        move_player(player, keyPressed);
        x = player.getX();
        y = player.getY();
        
        printer.startDraw();
        printer.print_room(r1.get_screen(-1, -1, -1, -1), game_x, game_y, game_width, game_heigth);

        printer.printUI(name, 0, time_passed/(20), 43, 100, 10, weapon, r_names, r_points, game_x+game_width+1, game_y+game_heigth+1);
        //riquadro gui
        printer.drawRect(0, 0, this->width, this->heigth);      
        //riquadro campo                
        printer.drawRect(this->game_x-1, this->game_y-1, this->game_width+2, this->game_heigth+2);  

        printer.print(x, y, ch);

        printShoots();

        printer.endDraw();

        this->shoots = removeShoots();
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