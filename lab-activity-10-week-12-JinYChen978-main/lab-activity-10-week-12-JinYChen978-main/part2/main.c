#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main() {
    int i, j, n, k; 

    printf("n: "); scanf("%d", &n); getchar();

    for (i = 1; i <= n; i++) {
        _add(i);
    }

    _queue();

    printf("k: "); scanf("%d", &k); getchar();

    for(i = 0; i < n-1; i++) {
        _remove(1);
        _queue();
        for (j = 0; j < k-1; j++) {
            _add(_remove(1));
            printf("[cycle]");
            _queue();
        }
    }

    printf("survivor: %d", _top());
}