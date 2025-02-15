#include <iostream>

class TicTacToe {
    private:
        char board[3][3];
        int condition;
        char current_Player = 'o';


    public:
        TicTacToe();
        void put_Mark();
        void display_Board();
        int check_Condition();
            
        void switch_Player();
        int get_Condition();
        char get_Player(int point);
};

TicTacToe::TicTacToe() {
    for(int i = 0; i < 3; i++) { //set board
        std::cout << "\n---------\n";
        for(int j = 0; j < 3; j++) {
        board[i][j] = ' ';
        std::cout << '|' << board[i][j] << '|';
        }
    }
    condition = -1;
};

void TicTacToe::put_Mark() {
    int i, j;
    std::cout << "\n[>]Player " << get_Player(0) << " placed his mark: ";
    std::cin >> i >>j;

    if (board[i][j] == ' ' && ((i < 3 && j < 3) && (i >=0 && j >= 0))) {
        board[i][j] = current_Player;
        return;
    } else {
        std::cout << "[!]Invalid move\n";
        put_Mark();
    }
    
};

void TicTacToe::display_Board() {  
    bool empty = true;
    for(int i = 0; i < 3; i++) { //update board
        std::cout << "\n----------\n";
        for(int j = 0; j < 3; j++) {
            std::cout << '|' << board[i][j] << '|';
            if (empty && (board[i][j] == 'x' || board[i][j] == 'o')) {
                empty = false;
            } 
        }
    }

    if (empty) {
        condition = -1;
    } else if (!empty) {
        condition = 0;
    }
}

int TicTacToe::check_Condition() {
    for(int i = 0; i < 3; i++) {
        // Check rows and columns
        if(board[i][0] == current_Player && board[i][1] == current_Player && board[i][2] == current_Player) {
            if (current_Player == 'x') {
            condition = 1; 
            } else {
            condition = 2;
            }
            return condition;
        }
        if(board[0][i] == current_Player && board[1][i] == current_Player && board[2][i] == current_Player) {
            if (current_Player == 'x') {
            condition = 1; 
            } else {
            condition = 2;
            }
            return condition;
        }
    }
    //check diagonals
    if(board[0][0] == current_Player && board[1][1] == current_Player && board[2][2] == current_Player) {
        if (current_Player == 'x') {
        condition = 1; 
        } else {
        condition = 2;
        }
        return condition;
    }

    if(board[0][2] == current_Player && board[1][1] == current_Player && board[2][0] == current_Player) {
        if (current_Player == 'x') {
        condition = 1; 
        } else {
        condition = 2;
        }
        return condition;
    }
    //check draw
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == ' ') {
                return -1;
            }
        }
    }
    condition = 3;
    return condition;
};

void TicTacToe::switch_Player() {
    if (current_Player == 'x') {
        current_Player = 'o';
    } else if (current_Player == 'o') {
        current_Player = 'x';
    }
};

int TicTacToe::get_Condition() {
    return condition;
};

char TicTacToe::get_Player(int point) {// 1 for next player, else current player
    if (point == 1) {
        if (current_Player == 'x') {
            return 'o';
        } else if (current_Player == 'o') {
            return 'x';
        }
    }
    return current_Player;
}