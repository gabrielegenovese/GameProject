#include "./classes/controller.hpp"
#include "./classes/player.hpp"
#include "./classes/printer.hpp"
//#include <ncurses.h>

int main()
{
    int altezza = 22;
    int larghezza = 82;

    int game_x = 3;
    int game_y = 3;
    int game_width = 50;
    int game_heigth = 14;

    Controller controller(game_x, game_y, game_width, game_heigth, larghezza, altezza);
    Player player(1, 1);

    controller.run(player);
    

    return 0;
}