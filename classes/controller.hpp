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
        int length, heigth, minX, minY;
        int time_passed;

    public:
        Controller(int minX, int minY, int length, int heigth);
        void init_main_ter();  
        void getName(char *name);
        void run(Player player, Printer printer);

        //get method
        int getMaxX();
        int getMaxY();
        
};

#endif