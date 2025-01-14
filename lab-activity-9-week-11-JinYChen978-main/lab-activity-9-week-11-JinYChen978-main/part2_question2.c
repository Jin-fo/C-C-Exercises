#include <stdio.h>

int state[][5] = {
//  M  U  R  S  n
    1, 0, 0, 0, 0, //state0   <M
    1, 2, 0, 0, 0, //state1  M<U
    1, 0, 3, 0, 0, //state2 MU<r
    4, 0, 0, 0, 0, //state3 MUR<M
    1, 5, 0, 0, 0, //state4 MURM<U
    1, 0, 6, 0, 0, //state5 MURMU<R
    4, 0, 0, 0, 0, //state6 MURMUR<S

};

int output[][5] = {
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 1, 0,
};

int main() {
    char c;
    int inp, oup=0, cur_state=0;
    while(1) {
        printf("input: "); scanf("%c", &c); getchar();

        switch(c) {
            case 'M': inp = 0; break;
            case 'U': inp = 1; break;
            case 'R': inp = 2; break;
            case 'S': inp = 3; break;
            default:
                inp = 4; break;
        }

        oup = output[cur_state][inp];
        cur_state = state[cur_state][inp];

        printf("output: %d\n", oup);
    }
}