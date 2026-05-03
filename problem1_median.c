
#include <stdio.h>

int find_median(int *arr, int size) {
    for(int i = 0; i <= size/2; i++) {
        int min_idx = i;

        for(int j = i+1; j < size; j++) {
            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }

    return arr[size/2];
}

int main() {
    int arr[] = {7, 2, 10, 9, 1};
    int size = 5;

    int median = find_median(arr, size);
    printf("Median = %d\n", median);

    return 0;
}
Added Problem 1 - Median using Selection Sort
