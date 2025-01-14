#include <stdio.h>
#include <math.h>

float integral(double(*p)(double), float l, float r, int n) {
    float i, sum, delX = (l+r)/n;

    for(i = l; i < r; i += delX) {
        sum += (p(i) + p(i + delX)) * delX / 2;
    }
    return sum;
}

float integral2(double(*p)(double, double), int c, float l, float r, int n) {
    float i, sum, delX = (l+r)/n;

    for(i = l; i < r; i += delX) {
        sum += (p(i, c) + p(i + delX, c)) * delX / 2;
    }
    return sum;
}

int main() {
    int cond = 1, function, n;
    float result, l, r;
    printf("[!]List of Integeral function");
    printf("\n[o] 1 for      (x)^2");
    printf("\n[o] 2 for  sqrt(x)");
    printf("\n[o] 3 for      (x)^3");
    printf("\n[o] 4 for  cbrt(x)");
    printf("\n[o] 5 for   sin(x)");
    printf("\n[o] 6 for   cos(x)");
    printf("\n[o] 7 for   tan(x)");
    printf("\n[o] 8 for    ln(x)");
    printf("\n[o] 9 for    e^(x)");
    printf("\n[>]Integeral of #(L R n):");
    
    scanf("%d %f %f %d", &function, &l, &r, &n); getchar();

    printf("\n[o]Integeral of %d(%f %f %d) = ", function, l, r, n);
    switch(function) {
        case 1: result = integral2(pow, 2, l, r, n); break;
        case 2: result = integral(sqrt, l, r, n); break;
        case 3: result = integral2(pow, 3, l, r, n ); break;
        case 4: result = integral(cbrt, l, r, n); break;
        case 5: result = integral(sin, l, r, n); break;
        case 6: result = integral(cos, l, r, n); break;
        case 7: result = integral(tan, l, r, n); break;
        case 8: result = integral(log, l, r, n); break;
        case 9: result = integral(exp, l, r, n); break;
        default: 
            cond = 0; break;
    }
    
    if (cond == 1) {
        printf("%f", result);
    } else {
        printf("\nNUll function error");
    }
}