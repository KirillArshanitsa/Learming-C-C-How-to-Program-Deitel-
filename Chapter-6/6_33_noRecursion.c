#include <stdio.h>

int testPalindrome(char[]);

int testPalindrome(char String[]) {
    int charCount = 0;
    while (String[charCount] != '\0')
        ++charCount;

    for (int count = charCount / 2, left = 0, right = charCount - 1; count > 0; left++, right--, count--) {
        if (String[left] == ' ' || String[left] == ',' || String[left] == '.')
            ++left;
        if (String[right] == ' ' || String[right] == ',' || String[right] == '.')
            --right;
        if ((String[left] == String[right]) || (String[left] + 32 == String[right]) || (String[left] == String[right] + 32)) {
            continue;
        }

        printf("String[left] = %c left = %d String[right] = %c right =%d\n", String[left], left, String[right], right);
        return 0;
        
    }
    return 1;

}

int main(void) {
    //char myString[] = "a man a plan a canal Panama";
    char myString[] = "able was i ere i saw elba";
    printf("%d", testPalindrome(myString));
    return 0;
}