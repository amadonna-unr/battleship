#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cstdlib>
#include <time.h>
#define MAX 10
using namespace std;

class Player{
    virtual bool checkHit(int y, int x) = 0;
    
    public:
        virtual void place(int x, int y, int size, int orientation) = 0;
        virtual void placeShips() = 0;
        virtual bool checkPlacement(int x, int y, int c, int o) = 0;
        virtual void makeGuess() = 0;
        virtual bool isGameOver() = 0;
};
#endif