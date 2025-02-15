/*
Extend the previous C program to include decimal numbers that also have a positive or 
negative exponent. Both lower case ‘e’ and capital ‘E’ are accepted. 
Examples: 45.04e2; 5.67e-2; 34.5E3; 90.3E-09. 
*/

#include<stdio.h>
#include<stdlib.h>

int main() {
    FILE *inp, *oup;
    int n = 0, m = 0, i = 0, val = 0, num = 0, sum = 0, max_denom = 1, cond = 0, sign = 1, cond_e = 0, e = 0, sign_e = 1;
    /*
    i: # of element of num
    val: temporary 'num' value
    num: whole number value build from val
    n: nth decimal position
    m: max nth decimal position
    max_denom: store largest common denominator (to not lose/truncate data in num),
        i.e., (156/10 + 3419/100) = 1560/100 + 3419/100

    cond: condition true or false if '.' is scanned
    sign: condition true if '+' and false if '-' is scanned
    */

    inp = fopen("input02.txt", "r");
    oup = fopen("output02.txt", "w");

    if (inp != NULL) {
        printf("number: ");
        while (fscanf(inp, "%c", &val) != EOF) { // Scan all characters and store as ASCII integer value 
            if (((val >= '0') && (val <= '9'))) { // If scanned character is 0 -> 9 in ASCII
                if (cond_e == 0) {
                    num *= 10;
                    num += (val - '0'); // Build the 'num' whole number value 
                } else {
                    e *= 10;
                    e += (val - '0');
                    continue;
                }

                if (cond == 1) { // If '.' was realized + current character(0 -> 9 from above 'if')
                    n++;
                }

                continue; // Continue to next character
            } else if (val == '+') { // If character '+', note to [add]
                if (cond_e == 1) {
                    sign_e = 1;
                    continue;
                } else {
                    sign = 1;
                }
                continue; // Continue to next character
            } else if (val == '-') { // If character '-', note to [minus]
                if (cond_e == 1) {
                    sign_e = 0;
                    continue;
                } else {
                    sign = 0;
                }
                continue; // Continue to next character
            } else if (val == '.') { // If character '-', note '.' is now realized
                cond = 1;
                continue; // Continue to next character
            } else if ((val == 'e') || (val == 'E')) {
                cond_e = 1;
                continue;
            } else { // Continue to next character, ignoring 'junk' character
                if (cond_e == 1) {
                    if (sign_e == 1) {
                        n -= e;
                    } else if (sign_e == 0) {
                        n += e;
                    }
                }

                if (cond == 1) { // If '.' was realized + scanned a junk character, 'num' finished building
                    if ((n > m)) { // Find largest common denominator of 2-num for the case of (current sum = 19/10 then 3/100), or aligning where the decimal point should be before operation
                        while ((n - m) > 0) {
                            sum *= 10; // sum * 10 => 19 
                            max_denom *= 10; // Get to the largest common denominator by increment of *10, and end the loop
                            m++;
                        }
                    i++;
                    } else if ((n < m)) { // Find largest common denominator of 2-num for the case of (current sum = 3/100 end num = 19/10)
                        while ((m - n) > 0) {
                            num *= 10; // num * 10 => 19 
                            n++; // To end the loop
                        }
                    }
                    i++;
                }
                if (sign == 1) { // If realized sign '+'
                    sum += num;

                } else if (sign == 0) {
                    sum -= num; // If realized sign '-'
                }
                // Reset for new set of num
                cond = 0; // Condition for "." set false
                cond_e = 0;
                num = 0; // Value for num rest => 0
                e = 0;
                n = 0;
                sign = 1;
                sign_e = 1;
                
            }
        }
        //'sum' is the raw total added from all element of 'num' aligned correctly without decimal point 
        //>> i.e. input: 1999.0 + 0.01 = 1999.01 | sum = 199900 + 1 = 199901; max_denom = 100
        printf("\nsum = %d.%0*d", (sum) / max_denom, m, (sum) % max_denom); // 199901/100 =199 and 199901%100 = 1 to 'n' position for front 0 
        printf("\naverage = %d.%0*d", ((sum) / i) / max_denom, m, ((sum) / i) % max_denom); // Taking average from 'i' element of num

        fprintf(oup, "sum = %d.%0*d", (sum) / max_denom, m, (sum) % max_denom);
        fprintf(oup, "\naverage = %d.%0*d", ((sum) / i) / max_denom, m, ((sum) / i) % max_denom);
    } else {
        printf("NULL ERROR"); // NULL file error, i.e. file cannot be open
    }
}
