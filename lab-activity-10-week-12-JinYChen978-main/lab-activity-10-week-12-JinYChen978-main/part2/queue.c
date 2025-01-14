#include <stdio.h>
#include <stdlib.h>
#define MAX 32

static int queue[MAX];
static int top, i, temp;

int is_empty() {
    if (top == 0) {
        return 1;
    }
    return 0;
}

int is_full () {
    if (top == MAX) {
        return 1;
    }
    return 0;
}

int _top() {
    return queue[(top-1)%MAX];
}

void _queue() {
    printf("survivors queue: ");
    for (i = 0; i < top; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void _add(int n) {
    if(!is_full()) {
        queue[top%MAX] = n;
        top++;
    } else {
        printf("error: stack is full");
        exit(1);
    }
}

int _remove(int k) {
    temp = queue[k-1];
    while (k < top) {
        queue[k-1] = queue[k];
        k++;
    }
    top--;

    return temp;
}




