
#include <stdio.h>



int state[][5] = {
//  F  R  O  G  n
    1, 0, 0, 0, 0, //state0 <- F
    1, 2, 0, 0, 0, //FR
    1, 0, 3, 0, 0, //FRO
    1, 0, 0, 0, 0, //FROG
};

int output[][5] = {
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 1, 0,
};

int main() {
    char c;
    int inp, oup = 0, cur_state =0;

    while(1) {
        printf("input: "); scanf("%c", &c); getchar();

        if(c == 'F') {
            inp = 0;
        } else if (c == 'R') {
            inp = 1;
        } else if (c == 'O') {
            inp = 2;
        } else if (c == 'G') {
            inp = 3;
        } else {
            inp = 4;
        }

        oup = output[cur_state][inp];
        cur_state = state[cur_state][inp];

        printf("output: %d\n", oup);
    }
}