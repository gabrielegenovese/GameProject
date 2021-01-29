#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED


class Controller
{
    private:
        //length and height
        int length, heigth;     

    public:
        Controller();
        void initTer();
        void SetPlayerRoom(const char *name, int n);
        void StartDraw();
        void EndDraw() ;
        void print(int x, int y, char ch) ;
        int getKey() ;
        int getMaxX() ;
        int getMaxY() ;
        void endTer() ;
        void getName(char *name);
        int contorno(int mlength, int mheigth);
};

#endif