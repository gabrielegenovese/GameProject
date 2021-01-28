#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

class Player
{
    private:
        int life;
    public:
        Player(int life = 100)
        {
            this->life = life;
        }

        bool isDead()
        {
            if(life <= 0) return true;
            else return false;
        }

        void addHealth(int n)
        {
            this->life += n;
        }

        void subHealth(int n)
        {
            this->life -= n;
        }
};

#endif