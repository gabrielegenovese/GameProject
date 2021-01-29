#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include "player.hpp"
#include "printer.hpp"

/*
Controller class -> interfaccia fa la classe printer e le varie altre classi
*/
class Controller
{
    private:
        int length, heigth;
        int time_passed;

    public:
        Controller(int length, int heigth);
        void initTer();
        void endTer() ;
        void getName(char *name);
        void run(Player player, Printer printer);

        //get method
        int getKey();
        int getMaxX();
        int getMaxY();
        
};

#endif