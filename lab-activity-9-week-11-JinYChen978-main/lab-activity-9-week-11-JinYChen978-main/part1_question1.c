#include <stdio.h>

#define state0 0
#define state1 1
#define state2 2
#define state3 3

int state[][3] = {
    state1, state0, state0, //f
    state1, state2, state0,//fr
    state3, state0, state0,//frf
    state1, state2, state0 //frfr
};

int output[][3] = {
    0, 0, 0,
    0, 0, 0,
    0, 0, 0,
    0, 1, 0
};

int main() {
    char c;
    int inp, oup = 0, cur_state = 0;

    while(1) {
        printf("input: "); scanf("%c", &c); getchar();
        if (c == 'F') {
            inp = 0;
        } else if (c == 'R') {
            inp = 1;
        } else {
            inp = 2;
        }
        oup = output[cur_state][inp];
        cur_state = state[cur_state][inp];
        printf("output: %d\n", oup);
    }
}