#include<stdio.h>

typedef struct {
  char board[3][3];
  int condition;
} Game;

void clear_board(Game *game) {
  int i, j;
  game->condition = 0;
  for(i = 0; i < 3; i++) { //set board
      printf("\n----------\n");
    for(j = 0; j < 3; j++) {
      game->board[i][j] = ' ';
      printf("|%c|", game->board[i][j]);
    }
  }
}

void put_Mark(Game *game, int i, int j, char mark) {
  if(game->board[i][j] == ' ') {
      game->board[i][j] = mark;
    } else {
      printf("you can't draw there");
      printf("\nPlayer %c (i, j): ", mark);
      scanf("%d, %d", &i, &j); getchar();
      put_Mark(game, i, j, mark);
    }
}

void update_board(Game *game) {
  int i, j;
  for(i = 0; i < 3; i++) { //update board
      printf("\n----------\n");
    for(j = 0; j < 3; j++) {
      printf("|%c|", game->board[i][j]);
    }
  }
}

void check_winner(Game *game, char mark) {
  int i, j;
  for(i = 0; i < 3; i++) {
    // Check rows and columns
    if(game->board[i][0] == mark && game->board[i][1] == mark && game->board[i][2] == mark) {
        if (mark == 'x') {
          game->condition = 1; 
        } else {
          game->condition = 2;
        }
        return;
    }
    if(game->board[0][i] == mark && game->board[1][i] == mark && game->board[2][i] == mark) {
        if (mark == 'x') {
          game->condition = 1; 
        } else {
          game->condition = 2;
        }
        return;
    }
  }

  // Check diagonals
  if(game->board[0][0] == mark && game->board[1][1] == mark && game->board[2][2] == mark) {
    if (mark == 'x') {
      game->condition = 1; 
    } else {
      game->condition = 2;
    }
    return;
  }

  if(game->board[0][2] == mark && game->board[1][1] == mark && game->board[2][0] == mark) {
    if (mark == 'x') {
      game->condition = 1; 
    } else {
      game->condition = 2;
    }
    return;
  }

  // check draws
  for(i = 0; i < 3; i++) {
    for(j = 0; j < 3; j++) {
        if(game->board[i][j] == ' ') {
            return;
        }
    }
  }
  game->condition = 3;
}

int main() {
  int i, j;
  Game game;

  clear_board(&game);
  while (game.condition == 0) {
      printf("\nPlayer x (i, j): ");
      scanf("%d, %d", &i, &j); getchar();
      put_Mark(&game, i, j, 'x');
      update_board(&game);
      check_winner(&game, 'x');

      if (game.condition == 0) {
        printf("\nPlayer o (i, j): ");
        scanf("%d, %d", &i, &j); getchar();
        put_Mark(&game, i, j, 'o');
        update_board(&game);
        check_winner(&game, 'o');
      }
  }

  if (game.condition == 1) {
    printf("\ncongraulation, x wins");
  } else if (game.condition == 2) {
    printf("\ncongraulation, o wins");
  } else if (game.condition == 3) {
    printf("\nIts draw");
  }
}