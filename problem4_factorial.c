#include <stdio.h>

long long factorial(int n) {
    if(n == 0)
        return 1;

    return n * factorial(n - 1);
}

int main() {
    int n = 5;

    long long result = factorial(n);
    printf("Factorial = %lld\n", result);

    return 0;
}
