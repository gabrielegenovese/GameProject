#include "./classes/controller.hpp"
#include "./classes/player.hpp"
#include "./classes/printer.hpp"
//#include <ncurses.h>

int main()
{
    int altezza = 18;
    int larghezza = 62;
    int minX = 2;
    int minY = 2;

    Controller controller(minX, minY, larghezza, altezza);
    Player player(minY, minX, ((larghezza*3)/4), ((altezza*3)/4));
    Printer printer;

    controller.run(player, printer);

    return 0;
}