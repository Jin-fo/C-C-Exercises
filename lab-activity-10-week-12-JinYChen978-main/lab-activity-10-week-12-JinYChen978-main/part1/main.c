#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define Maze_X 8
#define Maze_Y 8

int main() {
    int cond = 0, i, xo=0, yo=0, x, y;

    char maze[Maze_Y][Maze_X], wall = '*';
    FILE *inp;
    inp = fopen("maze.txt", "r");

    if (inp == NULL) {
        printf("File does not exit");
        exit(1);
    }

    for (int i = 0; i < Maze_Y; i++) { // read map
        for (int j = 0; j< Maze_X+1; j++) { // +1 for "\n"
            maze[i][j] = fgetc(inp);
            printf("%c", maze[i][j]);
        }
    }

    fclose(inp);

    while(1) {
        printf("\nPosition: "); scanf("%d %d", &yo, &xo); getchar();
        printf("desintation: "); scanf("%d %d", &y, &x); getchar();

        if ((maze[yo][xo] != ' ' || maze[y][x] != ' ')) {
            printf("[!]invalid location");
        } else {
            _add(yo,xo);
            break;
        }
    }

    while(!is_empty()) {
        for (int i = 0; i < Maze_Y; i++) { // update map
            printf("\n");
            for (int j = 0; j < Maze_X; j++) {
                if(i == yo && j == xo) {
                    printf("o");
                    maze[i][j] = '+';
                } else {
                    printf("%c", maze[i][j]);
                }
            }
        }

        if (yo == y && xo == x) {
            cond = 1;
            break;
        }

        if (maze[yo-1][xo] == ' ' && y-1 >= 0) {// more efficient if check that next step is the exit, instead of physical be there to know
            _add(yo-1, xo);
        }

        if (maze[yo+1][xo] == ' ' && yo+1 < Maze_Y) {
            _add(yo+1, xo);
        } 

        if (maze[yo][xo+1] == ' ' && xo+1 < Maze_X) {
            _add(yo, xo+1);
        }

        if (maze[yo][xo-1] == ' ' && xo-1 >= 0) {
            _add(yo, xo-1);
        }

        xo = top_x();
        yo = top_y();
        
        printf("\n\nPosition: %s", str_top());
        _remove();
    }

    if (cond) {
        printf("solved");

    } else {
        printf("no solution");
    }
}

