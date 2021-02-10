#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include "player.hpp"
#include "printer.hpp"
#include <ncurses.h>

struct shooting
{
    int x, y;
    int speed;
    shooting *next;
};

typedef shooting *SHOOTS;

/*
Controller class -> interfaccia fa la classe printer e le varie altre classi
*/
class Controller
{
    private:
        int width, heigth, game_x, game_y, game_width, game_heigth;
        int time_passed;
        bool exit;
        bool eCoolDown;
        SHOOTS shoots;

    public:
        Controller(int game_x, int game_y, int game_width, int game_heigth, int width, int heigth);

        //ncurses methods
        void init_main_ter();  
        void getName(char *name);

        //player methods
        bool isEmpty(int x, int y);
        void move_player(Player& player, int keyPressed);

        //testing per lo shooting ed è da spostare e controllare
        void eCD(int& cECD);
        SHOOTS newShoot(int x, int y);
        void printShoots();
        SHOOTS removeShoots();

        //main method
        void run(Player player, Printer printer);

        //get method
        int getMaxX();
        int getMaxY();
        
};

#endif