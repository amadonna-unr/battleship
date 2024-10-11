#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "player.h"

class Human : public Player {
    string name;
    int board[MAX][MAX];
    bool checkPlacement(int x, int y, int c, int o);
    bool checkHit(int y, int x);
    
    public:
        Human();
        Human(string name, int**);
        Human(const Human& rhs);

        string getName();
        void setName(string);
        int** getBoard();

        bool isGameOver();
        void makeGuess();
        void placeShips();
        void getPlacement(int);
        void guess();
        void displayBoard(bool);
        void place(int x, int y, int size, int orientation);
        
        
};

#endif