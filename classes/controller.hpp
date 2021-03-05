#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include "player.hpp"
#include "printer.hpp"
#include "shoots.hpp"
#include <ncurses.h>

/*
Controller class -> interfaccia fa la classe printer e le varie altre classi
*/
class Controller
{
    private:
        int width, heigth, game_x, game_y, game_width, game_heigth, time_passed;
        bool exit, eCoolDown;
        SHOOTS shoots;

    public:
        Controller(int game_x, int game_y, int game_width, int game_heigth, int width, int heigth);

        //ncurses methods
        void init_main_ter();  
        void getName(char *name);

        //main method
        void run(Player player);
        void keyManage(int keyPressed, int x, int y);

        //method just to compress code
        void print_borders();

        //get method
        int getMaxX();
        int getMaxY();
        
};

#endif