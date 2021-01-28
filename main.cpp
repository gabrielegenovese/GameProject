#include "./classes/controller.h"
#include "./classes/player.h"
using namespace std;


int main()
{
    
    Controller controller;
    Player player(100);

    controller.initTer();

    while (!player.isDead())
    {
        controller.getKey();
        player.subHealth(10);
    }

    controller.endTer();

    return 0;
}