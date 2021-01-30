#ifndef PRINTER_H_INCLUDED
#define PRINTER_H_INCLUDED


//classe che esegue metodi di stampa su schermo
class Printer {

    public:
        Printer();
        void startDraw();
        void endDraw();
        void setPlayerRoom(const char *name, int n, int time);
        void print(int x, int y, char ch);
        void drawRect(int startX, int startY, int mlength, int mheigth);

        //da implementare
        //void printRoom(char **room);  -> stampa la stanza di gioco
};

#endif