#ifndef GAME_H
#define GAME_H

#include "aiPlayer.h"
#include "humanPlayer.h"

//this is for including functions for running games being vs player
//or vs AI
class Game{
    Human p1;
    Human p2;
    Ai ai;

    void initialize(); //starts game, allows for board creation for player or ai
    int gg(); //checks for the win
    void displayWinner(int); //displays the winner and both boards
    void getPlacement(int a); //gets placement and checks if is valid
     
    public:
        Game();
        Game(Player p1, Player p2, Ai ai);
        Game(const Game & rhs);

        void setP1(Human);
        void setP2(Human);
        void setAi(Ai);
        
        Player getP1();
        Player getP2();
        
        void displayBoard();
        void StartGame();
        void playTurn(); //for player turn, will need to specify p1 or p2
};

#endif