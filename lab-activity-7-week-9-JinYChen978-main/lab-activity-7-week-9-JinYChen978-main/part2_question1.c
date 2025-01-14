#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE 10
#define WORD 10
#define LETTER 32

int main() {
    char text[LINE][WORD * LETTER];
    char opt;
    int lines = 0, m, n;

    // Read initial text from input file
    FILE *inp, *oup;
    inp = fopen("input02.txt", "r");
    oup = fopen("output02.txt", "w");
    if (inp == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    while (lines < LINE && fgets(text[lines], WORD * LETTER, inp) != NULL) {//fgets read until new line
        lines++;
    }
    fclose(inp);

    // Display original text
    printf("\nOriginal text:\n");
    for (int i = 0; i < lines; i++) {
        printf("%s", text[i]);
    }

    // Main loop for text editing
    while (opt != 'E') {
        printf("\nCommand:\n");
        printf("(I m)   - Inserts new line after line m\n");
        printf("(D m n) - Deletes all lines between and including line m and n\n");
        printf("(R m n) - Replaces the lines between and including line m and n with new lines input\n");
        printf("(E)     - Terminates editing\n");

        scanf(" %c", &opt); // Note the space before %c to consume any whitespace characters including newline

        switch(opt) {
            case 'I':
                scanf("%d", &m);
                if (lines >= LINE || m < 1 || m > lines) {
                    printf("Invalid operation.\n");
                    break;
                }
                for (int i = lines - 1; i >= m; i--) {
                    strcpy(text[i + 1], text[i]);
                }
                printf("Enter the new line to insert:\n"); getchar();
                scanf(" %s", text[m]); getchar();// Read new line
                lines++;
                break;
            case 'D':
                scanf("%d %d", &m, &n);
                if (m < 1 || n > lines || m > n) {
                    printf("Invalid operation.\n");
                    break;
                }
                for (int i = m - 1; i <= lines - (n - m + 1); i++) {
                    strcpy(text[i], text[i + (n - m + 1)]);
                }
                lines -= (n - m + 1);
                break;
            case 'R':
                scanf("%d %d", &m, &n);
                if (m < 1 || n > lines || m > n) {
                    printf("Invalid operation.\n");
                    break;
                }
                for (int i = m - 1; i < n; i++) {
                    printf("Newline %d: ", i + 1);
                    scanf(" %[^\n]s", text[i]); // scan string until new line
                }
                break;
            case 'E':
                printf("Exiting...\n");
                if (oup == NULL) {
                    printf("Error opening output file.\n");
                    return 1;
                }
                for (int i = 0; i < lines; i++) {
                    fputs(text[i], oup);
                }
                fclose(oup);
                return 0;
            default:
                printf("Invalid command. Please try again.\n");
        }

        // Display the updated text
        printf("\nUpdated text:\n");
        for (int i = 0; i < lines; i++) {
          printf("%s", text[i]);
          // Add an extra newline character if the current line was inserted via "R"
          if (opt == 'I' && i == m) {
              printf("\n");
          // Add an extra newline character if the current line was inserted via "I"
          } else if (opt == 'R' && i < m+n-1)
              printf("\n");
        }
    }

    return 0;
}
