/* Jin Yuan Chen, ID: 115702978 */

#include <stdio.h> 
#include <stdlib.h>
#define Max 30

/*
Devise a C program that reads up to 30 decimal numbers from an input file, and then sorts them 
in decreasing order. Then sorted decimal values are saved in an output file. Perform sorting using 
the bubble-sort algorithm.  
*/

int main() {
	FILE *inp, *oup;
	
	float dec[Max], temp;
	int count=0, i,j;
	
	inp = fopen("input_file.txt", "r");
	oup = fopen("output_file.txt", "w");
	
	while (fscanf(inp, "%f", &dec[count]) != EOF) { //builting the array of random float
		count++;
	}
	
	for (i = 0; i<count; i++) { //passes 
		for(j=0; j <(count-1)-i; j++) {
			if (dec[j] > dec[j+1]) {
				
				temp = dec[j]; //swap
				dec[j] = dec[j+1];
				dec[j+1] = temp;
				
			}
		}
	}
	
	for(i = count-1; i >=0; i--) { //print by decreasing order 
			printf("%f\n", dec[i]);
			fprintf(oup, "%f\n", dec[i]);
	}
	
}
	

