#include <iostream>
using namespace std;

int board [7][7];
int input , player = 1;
int row_index = 6 ;
bool game_end = false;



bool checkDraw() {
    for (int row = 0; row < 7; row++) {
        for (int col = 0; col < 7; col++) {
            if (board[row][col] == 0) {
                return false;
            }
        }
    }
    return true;
}

void handleInput(int input) {
    if (input < 0 || input > 6) {
        cout << "Column out of range\n" ;
        cout << "Try from (1-7)\n" ;
        player = player == 1 ? 2 : 1 ;
        return;
    }
    if (row_index >= 0) {
        if (board[row_index][input] != 0) {
            row_index--;
            handleInput(input);
        } else {
            board[row_index][input] = player;
            row_index = 6 ;
        }
    } else {
        cout << "Wrong input!" << "\n" ;
        player = player == 1 ? 2 : 1 ;
        row_index = 6 ;
    }
}

void checkWinner() {
    for (int row = 0; row < 7; row++) {
        for (int col = 0; col < 7; col++) {
            if (board[row][col] == 0) {
                continue;
            }
            if (col >= 3 && board[row][col] == player && board[row][col-1] == player && board[row][col-2] == player && board[row][col-3] == player) {
                game_end = true;
                cout << "\nPlayer " << player << " Win!" << "\n" ;

            } else if (row >= 3 && board[row][col] == player && board[row-1][col] == player && board[row-2][col] == player && board[row-3][col] == player) {
                game_end = true;
                cout << "\nPlayer " << player << " Win!" << "\n" ;

            }  else if (row >= 3 && col >= 3 && board[row][col] == player && board[row-1][col-1] == player && board[row-2][col-2] == player && board[row-3][col-3] == player) {
                game_end = true;
                cout << "\nPlayer " << player << " Win!" << "\n" ;

            }  else if (row >= 3 && col <= 3 &&board[row][col] == player && board[row-1][col+1] == player && board[row-2][col+2] == player && board[row-3][col+3] == player) {
                game_end = true;

                cout << "\nPlayer " << player << " Win!" << "\n" ;
            }
        }
    }
}

void draw() {
    for (int col = 0 ; col < 7 ; col++) {
        cout << "--" << col + 1 << "--" ;
    }
    cout << "\n" ;
    for (int row = 0 ; row < 7 ; row++) {
        for (int col = 0 ; col < 7 ; col++) {
            if (board[row][col] == 0){
            cout << "|   |";
            }else if (board[row][col] == 1) {
            cout << "| X |";
            } else if (board[row][col] == 2) {
                cout << "| O |";
            }
        }
        cout << "\n" ;
    }
    for (int col = 0 ; col < 7 ; col++) {
        cout << "=====" ;
    }
    cout << "\n";
}

int main() {
    draw();
    while (!game_end) {
        cout << "Player " << player << ": " ;
        if (!(cin >> input)) {
            cin.clear();
            cin.ignore(1000 , '\n');
            cout << "Invalid input!" << "\n" ;
            continue;
        }
        handleInput(input - 1);

        checkWinner();

        if (!game_end && checkDraw()) {
            cout << "\nDraw!\n";
            draw();
            break;
        }

        player = player == 1 ? 2 : 1 ;

        draw();

    }
    return 0;
}