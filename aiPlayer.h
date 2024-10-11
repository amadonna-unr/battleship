#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "player.h"

class Ai : public Player {
    bool checkPlacement(int x, int y, int c, int o);
    bool checkHit(int y, int x);

    int board[MAX][MAX];
    
    public:
        Ai();
        Ai(string, int**);
        Ai(const Ai& rhs);

        
        bool isGameOver();
        void makeGuess();
        void randomGuess();
        void placeShips();
        void displayBoard();
        void place(int x, int y, int size, int orientation);
        bool guessedAlready(int x, int y);
};

#endif