#include <stdio.h>

int count_digits(int n) {
    if(n == 0)
        return 1;

    if(n < 10)
        return 1;

    return 1 + count_digits(n / 10);
}

int main() {
    int n = 98765;

    int result = count_digits(n);
    printf("Digits = %d\n", result);

    return 0;
}
