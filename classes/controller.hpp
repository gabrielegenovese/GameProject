#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include "player.hpp"
#include "printer.hpp"
#include <ncurses.h>

/*
Controller class -> interfaccia fa la classe printer e le varie altre classi
*/
class Controller
{
    private:
        int width, heigth, game_x, game_y, game_width, game_heigth;
        int time_passed;

    public:
        Controller(int game_x, int game_y, int game_width, int game_heigth, int width, int heigth);
        void init_main_ter();  
        void getName(char *name);
        void run(Player player, Printer printer);

        //get method
        int getMaxX();
        int getMaxY();
        
};

#endif