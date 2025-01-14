#include <stdio.h>
#define Max_Word 25
#define Max_Letter 32

int state[][2] = {
//  A  n
    1, 0, //state0  <A
    2, 0, //state1 A<A
    0, 0, //state2 AA<A
};

int output[][2] = {
    0, 0,
    0, 0,
    1, 0,
};

int checkstate(char str[]) {
    int i, inp, oup=0, cur_state=0;
    for (i = 0; str[i] != '\0'; i++) {
        if(str[i] == 'A') {
            inp = 0;
        } else {
            inp = 1;
        }
        
        oup = output[cur_state][inp];
        cur_state = state[cur_state][inp];

        if (oup) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int i;
    char sent[Max_Word][Max_Letter];

    printf("input setence:");

    for(i = 0; i < Max_Word; i++) {
        scanf("%s", &sent[i]);
        printf("\nWord %d condition: %d", i, checkstate(sent[i]));
    }

}