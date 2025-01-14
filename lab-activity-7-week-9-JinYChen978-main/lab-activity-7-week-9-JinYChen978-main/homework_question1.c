/*
Design the C program to play the Tic-Tac-Toe game. The game is played on a 3 x 3 board. Two players, X
and O, alternate in placing their marks in the cells of the board, starting with player X. If either player
succeeds in getting three pf his / her marks in a row, column, or diagonal, then the player wins. Write a C
program so that two players can play the Tic-Tac-Toe game.
*/
#include<stdio.h>
#define Max 3

int main() {
  char board[Max][Max];

  int i, j, condition = 0, turn =2, count=0, full=1;
  char temp = 'x';

  for(i = 0; i < Max; i++) { //set board
      printf("\n----------\n");
    for(j = 0; j < Max; j++) {
      board[i][j] = ' ';
      printf("|%c|", board[i][j]);
    }
  }

  while(condition == 0) {
    printf("\nPlayer %c (x, y): ", temp);
    scanf("%d, %d", &i, &j); getchar();

    if(board[i][j] == ' ') {
      board[i][j] = temp;

    } else {
      printf("you can't draw there");
    }

    for(i = 0; i < Max; i++) { //update board
        printf("\n----------\n");
      for(j = 0; j < Max; j++) {
        printf("|%c|", board[i][j]);
      }
    }
    // Check for winning condition
    for(i = 0; i < Max; i++) {
        // Check rows and columns
        if(board[i][0] == temp && board[i][1] == temp && board[i][2] == temp) {
            condition = turn;
            break;
        }
        if(board[0][i] == temp && board[1][i] == temp && board[2][i] == temp) {
            condition = turn;
            break;
        }
    }

    // Check diagonals
    if(board[0][0] == temp && board[1][1] == temp && board[2][2] == temp) {
        condition = turn;
    }
    if(board[0][2] == temp && board[1][1] == temp && board[2][0] == temp) {
      condition = turn;
    }
    // check draws
    for(i = 0; i < Max; i++) {
      for(j = 0; j < Max; j++) {
          if(board[i][j] == ' ') {
              full = 0;
              break;
          }
      }
      if(!full) break;
    }

    if(full && condition == 0) {
        printf("It's a draw!\n");
        break;
    }

    if (turn == 1) {
      turn = 2;
      temp = 'x';
    } else if (turn == 2) {
      turn = 1;
      temp = 'o';
    }
  }

  if (condition == 1) {
    printf("\ncongraulation, o wins");
  } else if (condition == 2) {
    printf("\ncpngraulation, x wins");
  }

  return 0;
}