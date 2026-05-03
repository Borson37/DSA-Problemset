#include <stdio.h>

int array_max(int *arr, int size) {
    if(size == 1)
        return arr[0];

    int max = array_max(arr, size - 1);

    return (arr[size - 1] > max) ? arr[size - 1] : max;
}

int main() {
    int arr[] = {3, 1, 9, 2, 7};
    int size = 5;

    int result = array_max(arr, size);
    printf("Max = %d\n", result);

    return 0;
}
