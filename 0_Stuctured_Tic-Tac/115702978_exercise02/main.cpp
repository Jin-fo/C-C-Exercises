#include "TicTacToe.h"


int main() {
    TicTacToe game;

    while(game.check_Condition() <= 0) {
        game.switch_Player();
        game.put_Mark();
        game.display_Board();
    }
    
    if (game.get_Condition() == 1) {
        std::cout << "\n[!]Congraulation, x wins";
    } else if (game.get_Condition() == 2) {
        std::cout << "\n[!]Congraulation, o wins";
    } else if (game.get_Condition() == 3) {
        std::cout << "\n[o]Its a draw";
    }

    return 0;
}