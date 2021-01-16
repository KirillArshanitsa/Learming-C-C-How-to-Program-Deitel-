#include <stdio.h>

int main(void)
{
    int hour;
    int seconds;
    int minute;
    char s[100];
    int hex;
    printf("%-15.8d\n", 40000);
    scanf("%x", &hex);
    printf("%x\n", hex);
    printf("%+d\n",200);
    printf("%+d\n",-200);
    printf("%#x\n",100);
    scanf("%[^p]",s);
    puts(s);
    printf("%09f",1.234);
    scanf("%d%*c%d%*c%d",&hour,&minute,&seconds);
    printf("%d:%d:%d",hour, minute, seconds);
    scanf("\"%10s\"",s);
    puts(s);
    scanf("%d:%d:%d",&hour,&minute,&seconds);
    printf("%d:%d:%d",hour, minute, seconds);
    return 0;
}