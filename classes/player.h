#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

class Player
{
    private:
        int life;
    public:
        Player(int life);
        bool isDead();
};

#endif