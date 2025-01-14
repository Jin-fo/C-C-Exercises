#include <stdio.h>
#define Max 32

int main() {
    char str[Max];
    int i;

    printf("inpute string: ");
    scanf("%s", str); getchar();

    for(i=0; str[i] != '\0'; i++) {
        printf("%s \n", &str[i]);
    }
    getchar();
}


