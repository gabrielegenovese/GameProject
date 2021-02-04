#include "./classes/controller.hpp"
#include "./classes/player.hpp"
#include "./classes/printer.hpp"
//#include <ncurses.h>

int main()
{
    int altezza = 18;
    int larghezza = 76;

    int game_x = 2;
    int game_y = 2;
    int game_width = 46;
    int game_heigth = 14;

    Controller controller(game_x, game_y, game_width, game_heigth, larghezza, altezza);
    Player player(game_x, game_y, game_width, game_heigth);
    Printer printer;

    controller.run(player, printer);

    return 0;
}