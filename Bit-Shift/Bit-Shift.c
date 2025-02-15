/* Jin Yuan Chen, 115702978 */
#include <stdio.h>

int main () {
	
	//lab ended
	unsigned int temp, hex, mask; //increase storage size for hexadecimal from 1 bytes to 4 bytes 
	unsigned char oper;
	int p, n; //p<32, n<32
	
	printf("enter hexadecimal: 0x");
	scanf("%x", &temp); getchar();
	hex = temp;
	
	printf("enter p: ");
	scanf("%d", &p); getchar();
	
	printf("enter n: ");
	scanf("%d", &n); getchar();
	
	while(1) {
		mask = (0xff << (p-n+1)) & (0xff >> (7-p));
		
		printf("enter operation: ");
		scanf("%c", &temp); getchar();
		oper = temp;
		
		switch(oper) { 
			case 'S':
				hex = (hex | mask);
				printf("output: 0x%04x\n-------------\n", hex);
				break;
			
			case 'R':
				hex = (hex & (mask ^ 0xff)); 
				printf("output: 0x%04x\n-------------\n", hex);
				break;
				
			case 'F':
				hex = (hex ^ mask);
				printf("output: 0x%04x\n-------------\n", hex);
				break;
			
			case 'D':
				printf("Displaying value: %d\n-------------\n", hex);
				break;
			
			case 'I':
				printf("enter hexadecimal: 0x");
				scanf("%x", &temp); getchar();
				hex = temp;
				break;
			
			default:
				printf("invalid input\n");
				break; 
		}
	}
	
	
}
