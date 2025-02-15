

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define name_max 32

typedef struct {
    int row;
    char f_name[name_max];
    char l_name[name_max];
    int zip;
    int age;
    float GPA;

} student;

/*2. Write a C function that displays the content of the array storing the input file.*/
void content(student stud) {
    printf("%d\t%s\t%s\t%d\t%d\t%.2f\n", stud.row, stud.f_name, stud.l_name, stud.zip, stud.age, stud.GPA);

}

/*3. Write a C function that orders the array in the decreasing order of the person’s GPA.*/
void top_GPA(student *stud, int n) {
    int i, j;
    student temp;
    //content(stud[-1]); test simply of stud[i = 9] of *student 
    //content(stud[-10]); test simply of stud[i = 0] of *student
    for (i = -n; i < 0; i++) {
        for (j = -n; j < -1-(n+i); j++) {
            if (stud[j].GPA < stud[j + 1].GPA) {
                temp = stud[j];
                stud[j] = stud[j + 1];
                stud[j + 1] = temp;
            }
        }
    }
}
/*4. Write a C function that orders the array in alphabetic order of the person’s last name.*/
void alph_last_name(student *stud, int n) {
    int i, j;
    student temp;
    for (i = 0; ('a' + i) <= 'z'; i++) {
        for (j = -n; j < 0; j++) {
            if (stud[j].l_name[0] == ('a' + i)) {
                temp = stud[j];
                stud[j] = stud[-n];
                stud[-n] = temp;
                n--;
            }
        }
    }
}

/*5. Write a C function that reads a zip code from the keyboard and then displays all the persons with
this zipcode.*/
void z_code(int zip, student *stud, int n) {
    int i;
    printf("row\tf_name\t\tl_name\t\tzip\tage\tGPA\n");
    
    for (i = -n; i < 0; i++) {
        if (stud[i].zip == zip) {
            content(stud[i]);
        }
    }
}

int main() {
    int code, i, n=0;
    char opt;
    FILE *inp;
    student *stud = (student*)malloc(sizeof(student)*n);

    inp = fopen("text_file.txt", " r");
    printf("row\tf_name\t\tl_name\t\tzip\tage\tGPA\n");

    while(fscanf(inp, "%d %s %s %d %d %f", &stud->row, stud->f_name, stud->l_name, &stud->zip, &stud->age, &stud->GPA) != EOF) {
        content(*stud);
        stud++;
        n++;
    }   /*
        n = 10, but: stud[10] is actually => n = -1 or stud[0] is actually => n = -10; 
        since stud++ note the start of new block of pointer as n = 0, like a stack from  >-10 to 0
        where the top: n = 0 is the start of a new empty block of *student.
        TO ACCESS stud[i] => like i = 0 -> n:
                  stud[-n] = stud[0], n = 10;
                  stud[-n] = stud[9], n = 1;
        */ 

/*6. Write a main program that repeatedly reads and implements the following commands: D for the
function at step 2; O for the function at step 3; A for the function at step 4; Z for the function at
step 5.
*/  
    while(1) {
        printf("------------------------------------------------------------");
        printf("\nD - content\nO - by GPA\nA - by alphaetic of last name\nZ - by zip code\nX - exit\n"); scanf("%c", &opt);getchar();
        
        switch(opt) {
            case 'O':
                printf("\nby GPA\n"); 
                top_GPA(stud,n); break;

            case 'A':  
                printf("\nby alphatic of last name\n" ); 
                alph_last_name(stud, n); break;

            case 'Z':
                printf("\nby zip code: "); scanf("%d", &code); getchar();
                z_code(code, stud, n); break;

            default :
                break;
        }
        
        if(opt != 'X' && opt != 'Z') {
            printf("row\tf_name\t\tl_name\t\tzip\tage\tGPA\n");
            for(i= -n; i < 0; i ++) {
                content(stud[i]);
            } 
        } else if (opt == 'Z'){
        } else {
            break;
        }

    }
    free(stud);
}   
