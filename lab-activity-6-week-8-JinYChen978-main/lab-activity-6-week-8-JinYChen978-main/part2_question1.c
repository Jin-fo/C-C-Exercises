/*
Combine exercise 1 in Lab activity 6 (this lab activity) with exercise 2 of Part 1 in Lab activity 4, 
(hence, the resulting scanner should recognize identifiers and numbers from an input text file).   
Let’s assume that we are using an input file to describe the movements of a robot. The file 
description follows the following format:  - 
LEFT number means that the robot moves number units to the left from the current position.  - - - - 
RIGHT number means the robot moves number units to the right from the current position.  
UP number means that the robot moves number units up from the current position.  
DOWN number means the robot moves number units down from the current position.  
INITIAL number where number represents the initial coordinates (x and y) of the robot.  
Display on the screen the position after each command read from an input file and the final 
position of the robot after executing all the LEFT, RIGHT, UP, DOWN commands starting from the 
starting point as described by INITIAL. INITIAL is the first command in the file. All commands are 
given in an input file and include only data according to the rules of the above format.    

Input File: 
INITIAL 1 1 
UP 5 
LEFT 3 
DOWN 9 
LEFT 8 
RIGHT 5 
RIGHT 5 
UP 1 

Output File: 
Position: 1 1 
Position: 1 6 
Position: -2 6 
Position: -2 -3 
Position: -10 -3 
Position: -5 -3 
Position: 0 -3 
Position: 0 -2

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max 32

int main() {
    FILE *inp, *outp;
    int ch, x = 0, y = 0, step = 0;
    char str[Max];

    inp = fopen("input03.txt", "r");
    outp = fopen("output03.txt", "w");

    if (inp != NULL) {
        while ((ch = fgetc(inp)) != EOF) {
            if (((ch >= 'a') && (ch <= 'z')) || ((ch >= 'A') && (ch <= 'Z'))) {
                int i = 0;
                while (((ch >= 'a') && (ch <= 'z')) || (((ch >= 'A') && (ch <= 'Z')))) {
                    str[i] = ch;
                    i++;
                    ch = fgetc(inp);
                }
                str[i] = '\0';
                if (strcmp(str, "INITIAL") == 0) {
                    fscanf(inp, "%d %d", &x, &y);
                    printf("position: %d, %d\n", x, y);
                    fprintf(outp, "position: %d, %d\n", x, y);
                } else if (strcmp(str, "UP") == 0) {
                    fscanf(inp, "%d", &step);
                    y += step;
                    printf("position: %d, %d\n", x, y);
                    fprintf(outp, "position: %d, %d\n", x, y);
                } else if (strcmp(str, "DOWN") == 0) {
                    fscanf(inp, "%d", &step);
                    y -= step;
                    printf("position: %d, %d\n", x, y);
                    fprintf(outp, "position: %d, %d\n", x, y);
                } else if (strcmp(str, "LEFT") == 0) {
                    fscanf(inp, "%d", &step);
                    x -= step;
                    printf("position: %d, %d\n", x, y);
                    fprintf(outp, "position: %d, %d\n", x, y);
                } else if (strcmp(str, "RIGHT") == 0) {
                    fscanf(inp, "%d", &step);
                    x += step;
                    printf("position: %d, %d\n", x, y);
                    fprintf(outp, "position: %d, %d\n", x, y);
                }
            }
        }

    } else {
        printf("NULL ERROR\n");
    }

    return 0;
}