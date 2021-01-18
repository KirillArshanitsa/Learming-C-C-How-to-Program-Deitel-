#include <stdio.h>

int main(void){
    char s[] = "437 437 437 437 437 437";
    int numD, numI, numO, numU, numX;
    sscanf(s, "%d%i%o%u%x", &numD, &numI, &numO, &numU, &numX);
    printf("%d %i %o %u %x", numD, numI, numO, numU, numX);

    return 0;
}