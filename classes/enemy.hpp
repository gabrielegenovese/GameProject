#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED



//cerca il "tipo" del nemico e assegna il relativo carattere
struct ene{
    char identifier;
    int life;
    int dmg;
    bool movement;//da gestire
    bool shooting;//i boss potrebbero muoversi e sparare
    int type;
    ene *next;
};

struct alive{
    int type;
    int life;
    int room;
    int x;
    int y;
    alive *next;
};

//aggiungere il gestore della lista di nemici
//avere max 20 nemici diversi (in realtà si fa anche con 5)
//usare moltiplicatori per l'estensione infinita della stanza
//es. numero di stanza /10 + 1 (aumenta ongi 5 stanze)

typedef ene *enemies;

typedef alive *eneliving;

class Enemy{
    private:
        enemies catalogue;
        eneliving living;
    public:
        Enemy();
        void newEnemy (char identifier,int life,int dmg,int type);
        void printEnemy (int room, int type, int x, int y);
        void removeEnemy ();//dipende da l'implementazione di shoots


};




#endif