#include "./classes/controller.hpp"
#include "./classes/player.hpp"
#include <ncurses.h>


int main()
{
    int keyPressed, x, y;
    char ch;
    bool quit = false;
    Player player(100);
    Controller controller;

    while (!player.isDead() && !quit)
    {
        keyPressed = controller.getKey();
        
        switch (keyPressed)
        {
        case KEY_UP:
            player.goUp();
            break;
        
        case KEY_DOWN:
            player.goDown();
            break;

        case KEY_RIGHT:
            player.goRight();
            break;
        
        case KEY_LEFT:
            player.goLeft();
            break;
        
        case KEY_F(4):
            quit = true;
            break;

        default:
            break;
        }

        x = player.getX();
        y = player.getY();
        ch = player.getChar();
        
        controller.StartDraw();
        controller.print(x, y, ch);
        controller.EndDraw();
    }

    controller.endTer();

    return 0;
}