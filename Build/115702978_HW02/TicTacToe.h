#include <iostream>

class TicTacToe {
    private:
        char board[3][3];
        int condition;
        char current_Player = 'o';

        int record[2][8];
        int delay_on;
        int x_index;
        int o_index;
        int turn;
        

    public:
        TicTacToe();
        void put_Mark(int i, int j);
        void display_Board();
        int check_Condition();
            
        void switch_Player();
        int get_Condition();
        char get_Player(int number);
        //HW Part 1,2 
        void remove_Mark(int i, int j);
        void mark_Decay();
        void Single_Player();
};

TicTacToe::TicTacToe() {
    for(int i = 0; i < 3; i++) { //set board
        std::cout << "\n---------\n";
        for(int j = 0; j < 3; j++) {
        board[i][j] = ' ';
        std::cout << '|' << board[i][j] << '|';
        }
    }
    x_index = 0;
    o_index = 0;
    turn = 0;
    condition = -1;
    delay_on = 3;
    
};

void TicTacToe::put_Mark(int i, int j) {
    if (board[i][j] == ' ' && ((i < 3 && j < 3) && (i >=0 && j >= 0))) {
        board[i][j] = current_Player;

        if (current_Player == 'x') {
            record[0][x_index] = i;
            record[0][x_index+1] = j;
            x_index +=2;
        } else if (current_Player == 'o') {
            record[1][o_index] = i;
            record[1][o_index+1] = j;
            o_index +=2;
        }
        if (x_index >  2*(delay_on)) {
            x_index = 0;
        } else if (o_index > 2*(delay_on)) {
            o_index = 0;
        }

        for (int i = 0; i < 2; i++) {
            if (i == 0) {
                std::cout << "[x record]";  
            } else if (i == 1) {
                std::cout << "]\n[o record]";
            }
            for (int j = 0; j < 8; j+=2) {
              std::cout << "(" << record[i][j] << "," << record[i][j+1] << ")";
            } // New line after each row
        }
        turn++;
        return;
    } else {
        std::cout << "[!]Invalid move\n";
        std::cout << "\n[>]Player " << get_Player(0) << " placed his mark: ";
        std::cin >> i >>j;
        put_Mark(i, j);
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

char TicTacToe::get_Player(int number) {// 1 for next player, else current player
    if (number == 1) {
        if (current_Player == 'x') {
            return 'o';
        } else if (current_Player == 'o') {
            return 'x';
        }
    }
    return current_Player;
}

//HW Part 1:
// Extend the lab exercise 2 by introducing a method that would allow a player to remove a mark
// of the opponent from the board as an additional option to placing his / her own mark
void TicTacToe::remove_Mark(int i, int j) {
    if (board[i][j] != current_Player && board[i][j] != ' ') {
        board[i][j] = ' ';
        if (current_Player == 'x') {
            record[0][x_index] = -1;
            record[0][x_index+1] = -1;
            x_index+=2;
        } else if (current_Player == 'o') {
            record[1][o_index] = -1;
            record[1][o_index+1] = -1;
            o_index+=2;
        }
        if (x_index >  2*(delay_on)) {
            x_index = 0;
        } else if (o_index > 2*(delay_on)) {
            o_index = 0;
        }
        turn++;
        return;
    } else {
        std::cout << "[!]Invalid move\n";
        std::cout << "\n[>]Player " << get_Player(0) << " removed " << get_Player(1)<<"'s mark: ";
        std::cin >> i >>j;
        remove_Mark(i, j);
    }
};
// HW Part 2:
//  Extend the lab exercise 2 for the situation in which a mark exists only for the next three moves
// [ of the player and opponent ], after which it disappears
void TicTacToe::mark_Decay() {
    std::cout << "\n[o]turn: " << turn;
    if ((turn > 2*(delay_on)) && (delay_on > 1)) {
        if (current_Player == 'x') {
            
            if ((record[0][x_index] >= 0 && record[0][x_index+1] >= 0)) {
                board[record[0][x_index]][record[0][x_index+1]] = ' ';
                std::cout << "removed " << current_Player << " at " << "(" << record[0][x_index] << ',' << record[0][x_index+1]<< ')';
            }
            
            
        } else if (current_Player =='o') {
            if ((record[1][o_index] >= 0 && record[1][o_index+1] >= 0)) {
                board[record[1][o_index]][record[1][o_index+1]] = ' ';
                std::cout << "removed " << current_Player << " at " << "(" << record[1][o_index] << ',' << record[1][o_index+1]<< ')';
            }
        }
    }
    
};
