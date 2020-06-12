#include <stdio.h>

float getFahrenheitFromСelsius(float fahrenheit){
    return (fahrenheit - 32) / 1.8f;
}

float getСelsiusFromFahrenheit(float celsius) {
    return celsius * 1.8f + 32;
}

int main(void) {
    printf("%s%11s\n", "Celsius", "Fahrenheit");
    for (int c = 0; c <= 100; c++)
        printf("%-8d%.2f\n", c, getСelsiusFromFahrenheit(c));
    printf("\n\n");
    printf("%s%8s\n", "Fahrenheit", "Celsius");
    for (int f = 32; f <= 212; f++)
        printf("%-11.2f%.2f\n", f, getFahrenheitFromСelsius(f));
    return 0;
}