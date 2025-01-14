/*
Exercise 1 [ Devised by Thomas Plourde ]: In this problem we are going to recreate the game WORDLE. 
WORDLE is a game where you try to guess a hidden 5 letter word by randomly guessing other 5 letter 
words. The game then tells you if any of the letters of the word you entered are in the correct position, 
by highlighting them green. It will also tell you if a letter you entered exists in the word but is in the wrong 
position by highlighting it yellow. The player only gets 6 guesses to win.
*/
 
#include<stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 6 // 5 characters plus '\0'

int main() {

    char guess[max], word[max] = "apple";
    int live = 5;

    printf("Welcome to WORDLE!\n");
    printf("Try to guess the hidden 5-letter word.\n");
    printf("You have 6 lives.\n");

    while (live > 0) {
        printf("\nEnter your guess (5-letter word): ");
        scanf("%s", guess);

        if (strlen(guess) != max - 1) {
            printf("Please enter a 5-letter word.\n");
            continue;
        }

        live--;

        if (strcmp(guess, word) == 0) {
            printf("Congratulations! You guessed the word '%s' correctly with %d live left!\n", word, live);
            return 0;
        } else {
            printf("Feedback: ");
            for (int i = 0; i < max - 1; i++) {
                if (guess[i] == word[i])
                    printf("\033[0;32m"); // Ggreen color for correct position
                else if (strchr(word, guess[i]))
                    printf("\033[0;33m"); // yellow color for misplaced letter
                printf("%c ", guess[i]);
                printf("\033[0m"); // reset color
            }
            printf("\n");
        }
    }

    printf("Sorry, you've run out of live. The word was '%s'.\n", word);
    return 0;
}
