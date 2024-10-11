#include "game.h"

Game::Game(){
    Human p1;
    Human p2;
    Ai ai;
}

void Game::StartGame(){
    int over;
    initialize();//starts the game, gets placements and sets up boards to play
    cout << "\n\n\n\n\n\n\n\n\n\n\n\nTIME FOR THE BATTLESHIP GAME TO COMMENCE!\nYou must guess where the ai has placed their ships! \nX signifies a hit!\nO signifies a miss.\n\n";
    do{ //while the game is not over, go turn by turn
        playTurn(); //displays board and gets placement of guess and returns hit or miss
    }while (gg() == 0);
    displayWinner(gg()); //displays who won the game and the final boards
}
void Game::displayWinner(int over){
    if(over == 2){
        cout << "AI wins!" << endl;
    } else if (over == 1) {
        cout << "Player 1 wins!" << endl;
    }
}
void Game::displayBoard() {
    cout << "Board!" << endl;
}

void Game::playTurn() {
    int row, col; //plays a turn
    do{
        ai.displayBoard();
        ai.makeGuess();//guesses on the ai's board
        p1.displayBoard(false);
        p1.makeGuess();//guesses on the player's board
    }while(row > -1 && row < 10 && col > -1 && col < 10);

}

//starts the game with player1 placing ships then player2 or AI
void Game::initialize(){ 
    p1.placeShips(); //places ships for player
    ai.placeShips(); //places ships for AI (uses random)
    p1.displayBoard(false); //displays player board and then ai board
    ai.displayBoard();
}

int Game::gg(){
    bool aiB = ai.isGameOver();
    bool p1B = p1.isGameOver();
    if(aiB){
        return 1;
    } else if (p1B){
        return 2;
    }
    return 0;
}