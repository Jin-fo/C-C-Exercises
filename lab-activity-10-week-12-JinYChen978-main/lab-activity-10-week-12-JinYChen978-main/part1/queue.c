
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 64

static int queue_x[MAX];
static int queue_y[MAX];
static int top, i;
static char temp[4];

void queue() {
    printf("\nqueue: ");
    for (i = 0; i < top; i++) {
        printf("(%d, %d)", queue_y[i], queue_x[i]);
    }
}

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

char *str_top() {
	if(!is_empty()) {
        sprintf(temp, "%d, %d", queue_y[top-1], queue_x[top-1]);
        return temp;
	} else {
		printf("Error: stack is empty");
		exit(1);
	}
}

int top_x() {
    return queue_x[top-1];
}

int top_y() {
    return queue_y[top-1];
}

void _add(int y, int x) {

    if (!is_full()) {
        queue_x[top] = x;
        queue_y[top] = y;
        top++;
        queue();
    } else {
        printf("error: queue is full");
        exit(1);
    }
}

void _remove() {
    if(!is_empty()) {
        top--;
    } else {
        printf("error: queue is empty");
        exit(1);
    }
}


void _clear () {
    top = 0;
}



