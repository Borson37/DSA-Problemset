#include <stdio.h>

int array_sum(int *arr, int size) {
    if(size == 1)
        return arr[0];

    return arr[size - 1] + array_sum(arr, size - 1);
}

int main() {
    int arr[] = {1,2,3,4,5};
    int size = 5;

    int result = array_sum(arr, size);
    printf("Sum = %d\n", result);

    return 0;
}
