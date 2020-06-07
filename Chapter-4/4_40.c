#include <stdio.h>

int main(void) {
    int a=0, b=0, c=0, grade, inl=0;
    puts("Please enter letter.");
    while ((grade = getchar()) != 'Z'){
        //printf("You enter %d\n", grade);
            switch (grade) {
                case 'A':
                    ++a;
                    --b;
                case 'B':
                    ++b;
                    --c;
                case 'C':
                    ++c;
                default:
                    if (grade !='A' & grade !='B' & grade !='C' & grade !='\n') {
                        ++inl;
                        printf("%s", "Incorrect letter.\n");
                    }
            }
        }
        printf("A count = %d, B count = %d, C count = %d, Incorrect = %d", a,b,c, inl);
        return 0;
    }
  }  
