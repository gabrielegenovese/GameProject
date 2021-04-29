#include "shoots.hpp"
#include <ncurses.h>
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
    int where_to_go;
    if(shoots != NULL) {
        if(shoots->next != NULL) {
            SHOOTS tmp = shoots, prec = shoots;
            while(tmp != NULL) {
                where_to_go = tmp->x+3;
                if(!field.check_movement(tmp->x, tmp->y, where_to_go, tmp->y)){
                    prec->next = NULL;
                    delete(tmp);
                    return(shoots);
                } else {
                    //controllo con cosa ho sbattuto e se è un nemico gli tolgo vita
                }
                prec = tmp;
                tmp = tmp->next;
            }
        }else{
            where_to_go = shoots->x+3;
            if(!field.check_movement(shoots->x, shoots->y, where_to_go, shoots->y)){
                delete(shoots);
                return NULL;
            } else {
                //controllo con cosa ho sbattuto e se è un nemico gli tolgo vita
            }
        }
    }
    return shoots;
}

void printShoots(SHOOTS shoots, int maxX) {
    SHOOTS tmp = shoots;
    while (tmp != NULL)
    {
        tmp->x += tmp->speed;
        if(tmp->x < maxX)
            print_string(tmp->x, tmp->y, "---");
        tmp = tmp->next;
    }
}

// per ora non viene usata
void eCD(int& cECD, bool eCoolDown) {
    if(eCoolDown) {
        if (cECD < 0){
            cECD = 3;
            eCoolDown = false;
        } else {
            --cECD;
        }
    }
}