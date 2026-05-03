#include <stdio.h>

double power(double base, int exp) {
    if(exp == 0)
        return 1;

    return base * power(base, exp - 1);
}

int main() {
    double base = 2.5;
    int exp = 3;

    double result = power(base, exp);
    printf("Power = %lf\n", result);

    return 0;
}
