#include "./classes/controller.hpp"
#include "./classes/player.hpp"
using namespace std;


int main()
{
    int temp;
    Controller controller;
    Player player(100);

    controller.initTer();

    while (!player.isDead())
    {
        temp = controller.getKey();
        controller.printScreen(temp);
        player.subHealth(10);
    }

    controller.endTer();

    return 0;
}