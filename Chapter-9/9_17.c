#include <stdio.h>

int main(void){
    char s[] = "1.2345 1.2345 1.2345";
    float numE, numF, numG;
    sscanf(s, "%e%f%g", &numE, &numF, &numG);
    printf("%e %f %g", numE, numF, numG);

    return 0;
}