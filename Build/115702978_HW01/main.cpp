#include "TicTacToe.h"

int main() {
    TicTacToe game;
    char option;

    while(game.check_Condition() <= 0) {
        game.switch_Player();
        option = 0;
        
        if (game.get_Condition() == -1) {
            game.put_Mark();

        } else if (game.get_Condition() == 0) {
            while (true) {
                std::cout << "\n[>]Player " << game.get_Player(0) << "'s option:\n\t- Eneter (a) to put mark\n\t- Eneter (b) to remove " << game.get_Player(1) << "'s mark\n[>]Enter: ";
                std::cin >> option;
                if (option == 'a') {
                    game.put_Mark();
                    break;
                } else if (option == 'b') {
                    game.remove_Mark();
                    break;
                } else {
                    std::cout << "[!]Invalid Option Try Again";
                }
            }
        }
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

