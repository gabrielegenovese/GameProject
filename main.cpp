#include "./classes/controller.h"
#include "./classes/player.h"
using namespace std;


int main()
{
    
    Controller controller;
    Player player;

    controller.initTer();

    while (!player.isDead())
    {
        
    }

    controller.endTer();

    return 0;
}