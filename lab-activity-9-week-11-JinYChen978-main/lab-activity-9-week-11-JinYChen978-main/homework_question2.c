#include <stdio.h>
#define Max_Word 25
#define Max_Letter 32

int state[][6] = {
//  C  Y  B  O  T  n
    1, 0, 0, 0, 0, 0, //state0    n<C
    1, 2, 0, 0, 0, 0, //state1    C<Y
    1, 0, 3, 0, 0, 0, //state2   CY<B
    1, 0, 0, 4, 0, 0, //state3  CYB<O
    1, 0, 0, 0, 0, 0, //state4 CYBO<T
};

int output[][6] = {
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0,
};

int checkstate(char str[]) {
    int i, inp, oup=0, cur_state=0;

    for(i = 0; str[i] != '\0'; i++) {
        switch(str[i]) {
            case 'C': inp = 0; break;
            case 'Y': inp = 1; break;
            case 'B': inp = 2; break;
            case 'O': inp = 3; break;
            case 'T': inp = 4; break;
            default:
                inp=5; break;
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