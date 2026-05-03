#include <stdio.h>

long long fibonacci(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;

    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int n = 7;

    long long result = fibonacci(n);
    printf("Fibonacci = %lld\n", result);

    return 0;
}
