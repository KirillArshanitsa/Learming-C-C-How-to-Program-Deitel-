#include <stdio.h>

int testPalindrome(char[]);

int testPalindrome(char String[]){
    int charCount = 0;
    while(String[charCount] != '\0')
        ++charCount;
    if (charCount % 2){
        for (int count = charCount / 2, left = 0, right = charCount; count > 0;left++, right--, count--){
            if (String[left] != String[right])
                return 0;
        }
    }
    else{

    }


    return 1;

}

int main(void){
    char myString[] = "radar";
    printf("%s", myString);
    return 0;
}