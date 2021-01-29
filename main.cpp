#include "./classes/controller.hpp"
#include "./classes/player.hpp"
#include "./classes/printer.hpp"
#include <ncurses.h>

int main()
{
    int altezza = 25;
    int larghezza = 70;

    Controller controller(larghezza, altezza);
    Player player(larghezza, altezza);
    Printer printer;

    controller.run(player, printer);

    return 0;
}