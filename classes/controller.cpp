#include <ncurses.h>
#include "controller.hpp"

Controller::Controller()
{
    initscr();
    raw();
    keypad(stdscr, true);
    noecho();
    getmaxyx(stdscr,maxY,maxX);
}

void Controller::initTer()
{
    initscr();
}

void Controller::StartDraw() {
    clear();
}

void Controller::EndDraw() {
    refresh();
}

void Controller::print(int x, int y, char ch) {
    move(y, x);
    printw("*");
}

int Controller::getKey() {
    return getch();
}

int Controller::getMaxX() {
    return this->maxX;
}

int Controller::getMaxY() {
    return this->maxY;
}

void Controller::endTer() {
    endwin();
}
