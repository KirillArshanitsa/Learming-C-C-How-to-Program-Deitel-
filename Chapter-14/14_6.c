#include<signal.h>
#include<stdio.h>
#include<stdlib.h>

void abort(int );

int main()
{
    puts("Start");
    
    signal(SIGABRT, abort);
    signal(SIGINT, abort);

    raise(SIGABRT);
    raise(SIGINT);
    
    puts("Finish");
    return 0;
}


void abort(int signalValue)
{
    int response;
    printf("Recive %d signal\n", signalValue);
    do{
        puts("Enter 1 for continue or 2 for exit:");
        scanf("%d", &response);
    }
    while((response != 1) && (response != 2));
    if(response == 1)
        signal(SIGINT, abort);
    else
        exit(EXIT_SUCCESS);

}