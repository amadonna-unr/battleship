#include "humanPlayer.h"

Human::Human() : Player() {
    name = '\0';
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            board[i][j] = 1;
        }
    }
}
Human::Human(string n, int** b) : Player(){
    name = n;
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            board[i][j] = b[i][j];
        }
    }
}
Human::Human(const Human& rhs) : Player(rhs){
    name = rhs.name;
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            board[i][j] = rhs.board[i][j];
        }
    }
}
string Human::getName(){
    return name;
}
void Human::setName(string n){
    name = n;
}

void Human::placeShips() {
    bool one=true, two=true, three=true, four=true, five=true, pass=false;
    do{
        int choice;
        cout << "You have these ships remaining to place: " << endl;
        if(one == true){
            cout << "1. 1 Space Ship" << endl;
        }
        if(two == true){
            cout << "2. 2 Space Ship" << endl;
        }
        if(three == true){
            cout << "3. 3 Space Ship" << endl;
        }
        if(four == true){
            cout << "4. 4 Space Ship" << endl;
        }
        if(five == true){
            cout << "5. 5 Space Ship" << endl;
        }
        cout << "Choose the ship you want to place (1-5): " << endl;
        cin >> choice;
        if(choice <= 5){
            if(choice == 1){;
                one = false;
            } else if(choice == 2){
                two = false;
            }else if(choice == 3){
                three = false;
            }else if(choice == 4){
                four = false;
            }else if(choice == 5){
                five = false;
            }
            if(choice > 0 && choice < 6){
                getPlacement(choice);
            }
        } else if (choice > 5){
            cout << "Choice is incorrect, please retry." << endl;
        }
        if(one == false && two == false && three == false && four == false && five == false){
            pass = true;
        }
        
    }while(!pass);
}
void Human::getPlacement(int size){
    int orientation, x, y;
    bool pass = false;
    do{
        cout << "Do you want the piece 1- horizontal or 2- vertical?: ";
        cin >> orientation;
        orientation--;
    }while(orientation != 0 && orientation != 1);
    do{
        displayBoard(true);
        cout << "Give the coordinate of your placement (x y): ";
        cin >> x >> y;
        x--;
        y--;
        if(checkPlacement(x, y, size, orientation)){
            place(x, y, size, orientation);
            pass = true;
        }  else {
            do{
                pass = false;
                cout << "Invalid placement. Please enter a new position (x y orientation): ";
                cin >> x >> y >> orientation;
                orientation--;
                if(checkPlacement(x, y, size, orientation)){
                    place(x, y, size, orientation);
                    pass = true;
                }
            }while(!pass);
        }

    }while(!pass);
}

bool Human::checkPlacement(int x, int y, int c, int o){
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


void Human::place(int x, int y, int size, int orientation){
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

int** Human::getBoard(){
    int** arr = new int*[MAX];
    for (int i = 0; i < MAX; ++i) {
        arr[i] = new int[MAX];
        for (int j = 0; j < MAX; ++j) {
            arr[i][j] = board[i][j];
        }
    }
    return arr;
}

void Human::makeGuess(){
    int x, y;
    do{
        x = rand() % MAX;
        y = rand() % MAX;
    }while(board[x][y] == 3 || board[x][y] == 4); // ensure we don't guess the same spot twice
    bool hit = checkHit(x, y);
}

bool Human::checkHit(int x, int y){
    if(board[x][y] == 2){
        cout << "Ai hit your boat!" << endl;
        board[x][y] = 4;
        return true;
    } else{
        cout << "Ai missed." << endl;
        board[x][y] = 3;
        return false;
    }
}

void Human::displayBoard(bool show){
    char temp;
    int tempnum;
    if(show){
        cout << "Your Board" << endl << "   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10" << endl;
        for(int i = 0; i < MAX; i++){
            cout << "---+---+---+---+---+---+---+---+---+---+---" << endl;
            if(i != 9) {cout << " ";}
            cout << i+1 << ".|";
            for(int j = 0; j < MAX; j++){
                if(board[i][j] == 2){
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
    } else {
        cout << "Your Board" << endl << "   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10" << endl;
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
}

bool Human::isGameOver(){
    for(int i = 0; i < MAX; i ++){
        for(int j = 0; j < MAX; j++){
            if(board[i][j] == 2){
                return false;
            }
        }
    }
    return true;
}