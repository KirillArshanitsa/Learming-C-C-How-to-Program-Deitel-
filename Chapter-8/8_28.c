#include<string.h>
#include<stdio.h>

char *myStrcopy(char *, const char *);
char *myStrncopy(char *, const char *, size_t);
char *myStrcopyPtr(char *, const char *);
char *myStrncopyPtr(char *, const char *, size_t);

int main(void){
    char firstStr[21] = "FirstStr";
    char secondStr[7] = "Second";
    puts(myStrcopy(firstStr, secondStr));
    puts(myStrncopy(firstStr, secondStr, 3));
    puts(myStrcopyPtr(firstStr, secondStr));
    puts(myStrncopyPtr(firstStr, secondStr, 4));
    return 0;
}

char *myStrncopyPtr(char *s1, const char *s2, size_t n) {
    char *biginChar = s1;
    for ( s1 += n; n > 0; s1++, s2++, n-- )
        *s1 = *s2;
    *(s1 + 1) = '\0';
    return biginChar;
}

char *myStrcopyPtr(char *s1, const char *s2) {
    char *biginChar = s1;
    size_t s1Size = strlen(s1);
    for ( s1 += s1Size; *s2 != '\0'; s1++, s2++ )
       *s1 = *s2;

    *(s1 + 1) = '\0';
    return biginChar;
}

char *myStrcopy(char *s1, const char *s2){
    size_t s1Size = strlen(s1);
    size_t s2Size = strlen(s2);

    for (size_t e = 0; s2Size > e; e++){
        s1[s1Size++] = s2[e];
    }
    return s1;
}

char *myStrncopy(char *s1, const char *s2, size_t n){
    size_t s1Size = strlen(s1);

    for (size_t e = 0; n > e; e++){
        s1[s1Size++] = s2[e];
    }

    return s1;
}