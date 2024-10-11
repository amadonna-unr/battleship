//Aidan Madonna and Trevor Kaufman
//Project 4

#include "game.h"
//This is the main menu where we start the game and play the game
int main(){
    srand(time(0));  
    Game game;
    game.StartGame();
    cout << "Thank you for playing Aidan and Trevor's C++ Battleship!" << endl;
    return 0;
}
