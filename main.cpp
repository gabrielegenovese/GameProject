#include "./classes/controller.hpp"
#include "./classes/player.hpp"
#include "./classes/misc.hpp"

int main()
{
    boxCoordinate gameBox {1, 1, 78, 22};       //leave 1 fore the border
    Controller controller(gameBox);
    Player player(1, 1);

    controller.getPlayerName();
    controller.initMainTerminal();
    controller.run(player);

    return 0;
}