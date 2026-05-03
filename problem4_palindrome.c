#include <stdio.h>

int is_palindrome(char *str, int left, int right) {
    if(left >= right)
        return 1;

    if(str[left] != str[right])
        return 0;

    return is_palindrome(str, left + 1, right - 1);
}

int main() {
    char str[] = "racecar";

    int len = 0;
    while(str[len] != '\0') len++;

    int result = is_palindrome(str, 0, len - 1);

    printf("Result = %d\n", result);

    return 0;
}
