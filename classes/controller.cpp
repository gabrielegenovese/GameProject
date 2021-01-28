#include "controller.h"
#include <ncurses.h>
using namespace std;

Controller::Controller(){}

void Controller::initTer()
{
    initscr();
}

int Controller::getKey()
{
    return getch();
}

void Controller::endTer()
{
    endwin();
}