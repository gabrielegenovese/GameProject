#include "./classes/controller.hpp"
#include "./classes/player.hpp"
#include <ncurses.h>

int main()
{
    int keyPressed, x, y;
    char ch, *name;
    bool quit = false;
    Player player(100);
    Controller controller;
    //controller.getName(name);

    while (!player.isDead() && !quit)
    {
        controller.StartDraw();

        controller.contorno(20,30);

        controller.SetPlayerRoom("Geno", 0);  //scrive nome del giocatore e stanza sopra al campo

        keyPressed = controller.getKey();
        
        // muove il personaggio
        player.move(keyPressed);
        x = player.getX();
        y = player.getY();
        ch = player.getChar();
        controller.print(x, y, ch);

        controller.EndDraw();
    }

    controller.endTer();

    return 0;
}