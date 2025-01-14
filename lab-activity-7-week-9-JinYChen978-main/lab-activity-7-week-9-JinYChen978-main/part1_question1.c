/*
Design and implement a C program that performs the following operations on a 2D array with 5
rows and 5 columns. The array elements are decimal numbers that are read from an input file.
Every array row appears on a separate line of the input file.

Input File:
2.3 2.0 2 3.1415 -10.2
-5 20.2 99.997 2.0 2.41
100 99 -305 3.1415 5
65 -32.2 306 2.5 666.67
-11 0.667 44 -13 54.5

1. The program finds the sum of three rows" of the 2D array. The row numbers are read from
the keyboard. The sum is displayed.
Input Sequence: 0 1 3

Output: 1126.818481

2. Displays the upper triangular part of the 2D arrays, and then compute the sum of its
elements.

Output Sequence:
2.300 2.000 2.0 3.1415 -10.200000
20.200001 99.997002 2.000 2.4100
-305.00 3.1415 5.000
2.500 666.669983
54.50
Sum: 550.659973

Note: this output is a sequence of numbers for each row. It does not imply triangular
array formatting

Swaps rows m and n in the 2D array. The values of m and n are read from the keyboard.
The resulting 2D array is displayed.

Input Sequence:
m: 1 n: 3

Output:
2.300000 2.000000 2.000000 3.141500 -10.200000
65.000000 -32.200001 306.000000 2.500000 666.669983
100.000000 99.000000 -305.000000 3.141500 5.000000
-5.000000 20.200001 99.997002 2.000000 2.410000
-11.000000 0.667000 44.000000 -13.000000 54.500000

4. Multiplies the 2D arrays with its transpose. The resulting array is displayed.

Output:
127.199020 -6095.080078 -223.130981 210.595016 -532.705444
-6095.080078 543353.000000 -86676.593750 31235.316406 49028.539063
-223.130981 -86676.593750 112860.867188 -28980.951172 -14222.306641
210.595016 31235.316406 -28980.951172 10442.248047 4573.687012
-532.705444 49028.539063 -14222.306641 4573.687012 5196.694824

*/
#include<stdio.h>
#define Max 5

int main() {
  FILE * inp;
  int opt, i, j, k, a, b, c;

  float ray[Max][Max], newray[Max][Max], temp[Max], sum;

  inp = fopen("input01.txt", "r");

  for(i = 0; i < Max; i++) {
    for (j = 0; j < Max; j++) {
      fscanf(inp, "%f", &ray[i][j]);
    }
  }

  while (opt != 0) {
    printf("\n\ncheck task(1 to 3 and 4), 0 to quite: "); scanf("%d", &opt); getchar();
    sum = 0;
  //Task 1-----------------------------------//
    if (opt == 1) {

      printf("input sequence: "); scanf("%d %d %d", &a, &b, &c); getchar();

      for (i = 0; i < Max; i++) {
        for(j = 0; j < Max; j++) {
          if (i == a || i == b || i == c) {
            sum += ray[i][j];

          } else {
            continue;
          }
        }
      }

    printf("output: %f", sum);
  //Task 2-----------------------------------//
    } else if (opt == 2) {
      int h;
      for(i = 0; i < Max; i++) {
        for (h = 0; h < i; h++) {
          printf("         ");
        }
          for (j = i; j < Max; j++) {
            printf("%f ", ray[i][j]);
            sum +=  ray[i][j];
          }
        printf("\n");
      }

      printf("sum = %f", sum);
 //Task 3-----------------------------------//
    } else if (opt == 3) {
      
      printf("m: "); scanf("%d", &a); getchar();
      printf("n: "); scanf("%d", &b); getchar();

      printf("\ntask3:\n");

      for (int h = 0; h < Max; h++) {
        temp[h] = ray[a][h];
        ray[a][h] = ray[b][h];
        ray[b][h] = temp[h];
      }
      
      for(i = 0; i < Max; i++) { 
        for (j = 0; j < Max; j++) {
          printf("%f ", ray[i][j]);
        }
        printf("\n");
      }
 //Task 4-----------------------------------//
      printf("\ntask 4:\n");
      for (int i = 0; i < Max; i++) {
          for (int j = 0; j < Max; j++) {
            newray[i][j] = 0;
            for (int k = 0; k < Max; k++) {
                newray[i][j] += (ray[i][k]) * (ray[j][k]); 
            }
            printf("%f ", newray[i][j]);
          }
          printf("\n");
      }

    }
  }
}
