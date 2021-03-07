#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include "player.hpp"
#include "printer.hpp"
#include "shoots.hpp"
#include <ncurses.h>
#include "misc.hpp"

/*
Controller class -> interfaccia fa la classe printer e le varie altre classi
*/
class Controller
{
    private:
        boxCoordinate gameBox;

        char *playerName;
        Field* fieldManager;
        int time_passed;
        bool exit, eCoolDown;
        SHOOTS shoots;
        
        void setupInternalState();
        void gameLogic(int keyPressed, Player& player);
        void printEverything(Player& player);
        void printGameBorder();

    public:
        Controller(boxCoordinate gameBox);
        void getPlayerName();
        void initMainTerminal();  
        void run(Player player);
        void keyManage(int keyPressed, int x, int y);
};

#endif