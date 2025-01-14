#include <stdio.h>
#include <stdlib.h>
#define MAX 10

double function(double p[]) {
    int i, j=0;
    double temp = p[j];

    for (i = 1; i < MAX; i++) {
        if(p[i]>temp) {
            j = i;
            temp = p[i];
        }
    }
    return p[j];
}

int main() {
    int n =0;//2147483647 2^31-1
    double *p = (double*) malloc(sizeof(double)*n); //8bytes (4btyes.4bytes .=1bytes?)

    printf("decimal: ");

    while(n < MAX) {
        scanf("%lf", p+n); getchar();
        //printf("%lf ", *p);
        n++;
    }

    printf("decimal: ");
    for(n = 0; n < MAX; n++){
        printf("%lf ", p[n]);
    }

    printf("\nhighest decimal: %lf", function(p));

    free(p);
}
