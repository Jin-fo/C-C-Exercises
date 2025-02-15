/* Jin Yuan Chen 115702978 */

#include <stdio.h>
#include <stdlib.h>
#define Max 32

int main () {
	FILE *inp, *outp;
	char c, str[Max];
	
	int i;
	
	
	inp = fopen("Lab_4_in.txt", "r");
	
	outp = fopen("Lab_4_out.txt", "w");
	
	if (inp == NULL) {
		printf("read file: failed\n");
		
	} else {
		printf("read file: success\n");
	}
	
	if (outp == NULL) {
		printf("copy file: failed\n");
		
	} else {
		printf("copy file: success\n");
	}
	
	while((c = fgetc(inp)) != EOF) {
	
		if (((c == '_') ||(c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'))) {
			i = 0;
			while (((c == '_') ||(c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')) || ((c >= '0') && (c <= '9'))) {
				
				if ((c >= 'a') && (c <= 'z')) {
					str[i] = c - 'a' + 'A';
					c = fgetc(inp);
					
				} else {
					str[i] = c;
					c = fgetc(inp);
				}
				i++;
			}
			
			str[i] = '\0';
			fprintf(outp, "%s", str);
			printf("%s", str);
			
		}

		switch(c) {
			case '+': 
				if ((c = fgetc(inp)) != EOF && (c == '+')) {
					printf("(INCREMENT)");
					fprintf(outp, "%s", "(INCREMENT)");
					
				} else if (c == '=') {
					printf("(ADD-ASSIGN)");
					fprintf(outp, "%s", "(ADD-ASSIGN)");
					
				} else {
					printf("PLUS");
					fprintf(outp, "%s", "PLUS");
						
				} break;
			case '-': 
				if ((c = fgetc(inp)) != EOF && (c == '-')) {
					printf("(DECREMENT)"); 
					fprintf(outp, "%s", "(DECREMENT)");
					
				} else if (c == '=') {
					printf("(MINUS-ASSIGN)"); 
					fprintf(outp, "%s", "(MINUS-ASSIGN)");
					
				} else {
					printf("MINUS"); 
					fprintf(outp, "%s", "MINUS");
					
				} break;
			case '=': 
				if((c = fgetc(inp)) != EOF && (c == '=')) {
					printf("(EQUAL)"); 
					fprintf(outp, "%s", "(EQUAL)");
					
				} else {
					printf("ASSIGN"); 
					fprintf(outp, "%s", "ASSIGN");
					
				} break;
			case '*': 
				if ((c = fgetc(inp)) != EOF && (c == '=')) {
					printf("(MULTIPLY-ASSIGN)"); 
					fprintf(outp, "%s", "(MULTIPLY-ASSIGN)");
					
				} else {
					printf("MULTIPLY"); 
					fprintf(outp, "%s", "MULTIPLY");
					
				} break;

			case '/': printf("DIVIDE"); fprintf(outp, "%s", "DIVIDE"); break;
			case '%': printf("MODLUO"); fprintf(outp, "%s", "MODLUO");break;
			case '@': printf("AT"); fprintf(outp, "%s", "AT");break;
			case '^': printf("BIT-XOR"); fprintf(outp, "%s", "BIT-XOR");break;
			case '&': printf("BIT-AND"); fprintf(outp, "%s", "BIT-AND");break;
			case '.': printf("(DOT)"); fprintf(outp, "%s", "(DOT)");break;
			case ',': printf("(COMMA)"); fprintf(outp, "%s", "(COMMA)");break;
			case ';': printf("(SEMICOLON)"); fprintf(outp, "%s", "(SEMICOLON)");break;
			case ':': printf("(COLON)"); fprintf(outp, "%s", "(COLON)");break;
			case '\n': printf("\n"); fprintf(outp, "%c", '\n');break;
			case ' ': printf(" "); fprintf(outp, "%c", ' ');break;
			default:
				break; 
		}
	}
	
	//fprintf(outp,"%c", ch);
	
	fclose(inp);
	fclose(outp);
	
}
