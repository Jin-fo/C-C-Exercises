/*
Devise a C program that reads an input text file and recognizes the decimal numbers in the
file. It ignores the rest of the characters. For each decimal number, it computes the associated
value.

A decimal number is a sequence of digits (the integer part) followed by an optional decimal
part. The decimal part starts with the character ‘.’ (dot) followed by a sequence of digits. Each
number might or might not have a sign (‘+’ or ‘-‘). The value of each recognized number is
output to an output text file.

The sum and average of all number values is also computed and copied to the output file.
Examples: 25.06; +567.009; -305.678
*/

#include<stdio.h>
#include<stdlib.h>
int main() {
  FILE *inp, *oup;
  int n=0, m=0, i=0, val=0, num=0, sum=0, max_denom=1, cond=0, sign=1;
  /*
  i: # of element of num
  val: temporarly 'num' value
  num: whole number value build from val
  n: nth decimal position
  m: max nth decimal position
  max_denom: store largest common demonator(to not loss/trucate data in num),
    i.e. (156/10 + 3419/100) = 1560/100 + 3419/100

  cond: condition true or false if '.' is scanned
  sign: condition true if '+' and false if '-' is scanned
  */

  inp = fopen("input01.txt", "r");
  oup = fopen("output01.txt", "w");

  if (inp != NULL) {
    printf("num: "); 
    while (fscanf(inp, "%c", &val) != EOF) { //scan all character store as ASCII Int value
      if (((val >= '0') && (val <= '9'))) { //if scanned character is 0 -> 9 in ASCII
          num *=10;
          num += (val - '0'); // building the 'num' whole number value

          if (cond == 1) {    // if '.' was realized + current character(0 -> 9 from above 'if')
            n++;
          }
          continue; // continue to next character

      } else if (val == '+' ) { // if character '+', note to [add]
        sign = 1;
        continue; // continue to next character

      } else if (val == '-') { // if character '-', note to [minus]
        sign = 0;
        continue; // continue to next character

      } else if (val == '.') { // if character '-'. note '.' is now relaized 
        cond = 1;
        continue; // continue to next character

      } else { // continue to next character, ignoring 'junk' character 
          if(cond == 1) { //if '.' was realized + scanned a junk character, 'num' finished building
            if((n > m)) { //find largest common denominator of 2-num for case of (current sum = 19/10 then 3/100), or aligning where the decimal point should be before operation 
              while((n-m) > 0) {
                sum*=10; // sum * 10 => 19 
                max_denom *=10; // Get to the largest common denominator by increment of *10, and end the loop
                m++;
              }
            } else if ((n < m)) { //find largest common denominator of 2-num for case of (current sum = 3/100 end num = 19/10)
              while ((m-n) > 0) { 
                num *= 10; // num * 10 => 19 
                n++; //to end the loop
              }
            }
            
          // 'num' is align correctly with pervious 'sum' or 'num' by largest common deniminator for operation
          if (sign == 1) { //if realized sing '+' 
            sum += num; 

          } else {
            sum -= num; //if realized sign '-'
          }
          printf("%d.%0*d ", num/max_denom, m,num%max_denom); //check for file corruption, not scanning or stop scanning early
          //reset for new set of num
          cond = 0; //condition for "." set false
          num = 0; //value for num rest => 0
          sign = 1;
          n = 0;
          i++;
          //i++; //increment # of element of num
        }
      }
    }
    //'sum' is the raw total added from all element of 'num' align correctly without decimial point 
    //>> i.e. input: 1999.0 + 0.01 = 1999.01 | sum = 199900 + 1 = 199901; max_demon = 100
    printf("\nsum = %d.%0*d", sum/max_denom, m, sum%max_denom); // 199901/100 =199 and 199901%100 = 1 to 'n' position for front 0 
    printf("\naverage = %d.%0*d", (sum/i)/max_denom, m, (sum/i)%max_denom); //taking avergae fron 'i' element of num

    fprintf(oup,"sum = %d.%0*d", sum/max_denom, m, sum%max_denom);
    fprintf(oup,"\naverage = %d.%0*d", (sum/i)/max_denom, m, (sum/i)%max_denom);

  } else {
    printf("NULL EORROR"); //NULL file error, i.e. file cannot be open

  }

}
