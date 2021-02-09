#include "./classes/controller.hpp"
#include "./classes/player.hpp"
#include "./classes/printer.hpp"
//#include <ncurses.h>

int main()
{
    int altezza = 22;
    int larghezza = 82;

    int game_x = 2;
    int game_y = 2;
    int game_width = 50;
    int game_heigth = 16;

    Controller controller(game_x, game_y, game_width, game_heigth, larghezza, altezza);
    Player player; //game_x, game_y, game_width, game_heigth);
    Printer printer;

    controller.run(player, printer);

    return 0;
}