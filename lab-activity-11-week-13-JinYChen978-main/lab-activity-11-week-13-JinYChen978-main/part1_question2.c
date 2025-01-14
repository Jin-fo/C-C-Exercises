#include <stdio.h>
#include <string.h>
#define Max 32

int main () {
	char str[Max], *p;
	int i, len;
	
	printf("input string: ", str);
	scanf("%s", str); 
	
	len = strlen(str);
	
	p = &str[len-1];
	for (i = 0; i < len; i++, p--) {
		printf("%c", *p);
	}

}
