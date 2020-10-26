#include<stdio.h>

int myGetchar(void);
char *myGets(char*);
int myPutchar(int);
int myPuts(const char*);

int main(void){
    char str[100];
    char myStr[] = "TetsStr";
    printf("%d\n", myGetchar());
    puts(myGets(str));
    myPutchar('2');
    puts("");
    myPuts(myStr);
    return 0;
}


int myPuts(const char *str){
    for (int i = 0 ;str[i] != '\0';i++)
        printf("%c", str[i]);

    printf("\n");
    return '\n';
}

int myPutchar(int e){
    printf("%c", e);
    return e;
}

char *myGets(char *s){
    char e;
    size_t i = 0;
    scanf("%c",&e);
    while(e != '\n' && e != EOF) {
        s[i++] = e;
        scanf("%c", &e);
    }
    s[i] = '\0';
    return s;
}

int myGetchar(void){
    int result;
    scanf("%c",&result);
    return result;
}