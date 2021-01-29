#include "./classes/controller.hpp"
#include "./classes/player.hpp"
#include <ncurses.h>

int main()
{
    int keyPressed, x, y;
    char ch, name[80];
    bool quit = false;


    Controller controller;
    Player player(controller.getMaxX(), controller.getMaxY());
    
    controller.getName(name);
    controller.initTer();

    while (!player.isDead() && !quit)
    {
        keyPressed = controller.getKey();
        
        // muove il personaggio
        player.move(keyPressed);
        x = player.getX();
        y = player.getY();
        ch = player.getChar();

        controller.StartDraw();

        controller.contorno(20,49);
        controller.SetPlayerRoom(name, 0);  //scrive nome del giocatore e stanza
        controller.print(x, y, ch);

        controller.EndDraw();

    }

    controller.endTer();

    return 0;
}