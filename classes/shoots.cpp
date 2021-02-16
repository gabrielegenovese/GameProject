/*#include <ncurses.h>
#include "printer.hpp"
#include "field.hpp"

SHOOTS newShoot(SHOOTS shoots, int x, int y) {
    SHOOTS tmp = new shooting;
    tmp->x = x;
    tmp->y = y;
    tmp->speed = 1;
    tmp->next = shoots;
    return tmp;
}

SHOOTS removeShoots(SHOOTS shoots, Field field) {
    if(shoots != NULL) {
        if(shoots->next != NULL) {
            SHOOTS tmp = shoots, prec = shoots;
            while(tmp != NULL) {
                if(!field.check_movement(tmp->x, tmp->y, tmp->x+3, tmp->y)){
                    prec->next = NULL;
                    delete(tmp);
                    return(shoots);
                }
                prec = tmp;
                tmp = tmp->next;
            }
        }else{
            if(!field.check_movement(shoots->x, shoots->y, shoots->x+3, shoots->y)){
                delete(shoots);
                return NULL;
            }
        }
    }
    return shoots;
}

void printShoots(SHOOTS shoots) {
    SHOOTS tmp = shoots;
    while (tmp != NULL)
    {
        tmp->x += tmp->speed;
        my_print(tmp->x, tmp->y, '-');
        tmp = tmp->next;
    }
}

void eCD(int& cECD, bool eCoolDown) {
    if(eCoolDown) {
        if (cECD < 0){
            cECD = 3;
            eCoolDown = false;
        } else {
            --cECD;
        }
    }
}*/