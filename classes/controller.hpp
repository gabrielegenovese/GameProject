#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED


class Controller
{
    private:
        int maxX, maxY;

    public:
    Controller();
    void initTer();
    void StartDraw();
    void EndDraw() ;
    void print(int x, int y, char ch) ;
    int getKey() ;
    int getMaxX() ;
    int getMaxY() ;
    void endTer() ;
};

#endif