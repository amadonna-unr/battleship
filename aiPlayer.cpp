#include "aiPlayer.h"

Ai::Ai(){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            board[i][j] = 1;
        }
    }
}
Ai::Ai(string n, int** b){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            board[i][j] = b[i][j];
        }
    }
}
Ai::Ai(const Ai& rhs){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            board[i][j] = rhs.board[i][j];
        }
    }
}

void Ai::placeShips() {
    bool ships[5] = {true, true, true, true, true};
    for(int i = 0; i < 5; i++){
        while(ships[i]){
            int size = i + 1;
            int orientation = rand() % 2;
            int x = rand() % MAX;
            int y = rand() % MAX;
            if(checkPlacement(x, y, size, orientation)){
                place(x, y, size, orientation);
                ships[i] = false;
            }
        }
    }
}

bool Ai::checkPlacement(int x, int y, int c, int o){
    if(o == 1){ // Horizontal placement
        for(int i = 0; i < c; i++){
            // Check if the ship fits within the board
            if(x + i >= MAX || y >= MAX){
                return false;
            }
            // Check the cell and the surrounding cells
            for(int dx = -1; dx <= 1; dx++){
                for(int dy = -1; dy <= 1; dy++){
                    int nx = x + i + dx;
                    int ny = y + dy;
                    // Check if the cell is within the board
                    if(nx >= 0 && nx < MAX && ny >= 0 && ny < MAX){
                        // Check if the cell is already occupied
                        if(board[nx][ny] == 2){
                            return false;
                        }
                    }
                }
            }
        }
    } else if(o == 0){ // Vertical placement
        for(int i = 0; i < c; i++){
            // Check if the ship fits within the board
            if(x >= MAX || y + i >= MAX){
                return false;
            }
            // Check the cell and the surrounding cells
            for(int dx = -1; dx <= 1; dx++){
                for(int dy = -1; dy <= 1; dy++){
                    int nx = x + dx;
                    int ny = y + i + dy;
                    // Check if the cell is within the board
                    if(nx >= 0 && nx < MAX && ny >= 0 && ny < MAX){
                        // Check if the cell is already occupied
                        if(board[nx][ny] == 2){
                            return false;
                        }
                    }
                }
            }
        }
    }
    // If we've reached this point, the placement is valid
    return true;
}

void Ai::place(int x, int y, int size, int orientation){
    do {
        if(checkPlacement(x, y, size, orientation)){
            if(orientation == 1){
                for(int i = 0; i < size; i++){
                    board[x+i][y] = 2;
                }
            } else if (orientation == 0){
                for(int i = 0; i < size; i++){
                    board[x][y+i] = 2;
                }
            }
            break;
        }
    } while (true);
}
void Ai::displayBoard(){
    char temp;
    cout << "Ai Board" << endl << "   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10" << endl;
    for(int i = 0; i < MAX; i++){
        cout << "---+---+---+---+---+---+---+---+---+---+---" << endl;
        if(i != 9) {cout << " ";}
        cout << i+1 << ".|";
        for(int j = 0; j < MAX; j++){
            if(board[i][j] == 2){
                temp = ' ';
            } else if (board[i][j] == 3){
                temp = 'O';
            } else if (board[i][j] == 4){
                temp = 'X';
            }else{
                temp = ' ';
            }
            cout << " " << temp << " ";
            if(j != MAX - 1){
                cout << "|";
            }
        }
        cout << endl; 
    }
    cout << "---+---+---+---+---+---+---+---+---+---+---" << endl;
}

bool Ai::checkHit(int x, int y){
    if(board[x][y] == 2){
        board[x][y] = 4;
        return true;
    } else{
        board[x][y] = 3;
        return false;
    }
}
void Ai::makeGuess(){
    int x, y;
    
    cout << "Give the coordinate of your guess (x y): ";
    do{
        cin >> x >> y;
        x--;
        y--;
        if(guessedAlready(x, y)){
            cout << "You have already guessed this, try again: ";
        } else if ( x < -1 || y < -1 || x > 10 || y > 10){
            cout << "Number out of bounds, try again: ";
        }
    }while(guessedAlready(x, y) ||  x < -1 || y < -1 || x > 10 || y > 10);
    bool hit = checkHit(x, y);
}
bool Ai::guessedAlready(int x, int y){
    if(board[x][y] == 3 || board[x][y] == 4){return true;}
    return false;
}

bool Ai::isGameOver(){
    for(int i = 0; i < MAX; i ++){
        for(int j = 0; j < MAX; j++){
            if(board[i][j] == 2){
                return false;
            }
        }
    }
    return true;
}

