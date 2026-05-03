#include <stdio.h>

int swap_count = 0;

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            swap_count++;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    swap_count++;

    return i + 1;
}

void quick_sort(int *arr, int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = 6;

    quick_sort(arr, 0, n - 1);

    printf("Sorted: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nSwaps = %d\n", swap_count);

    return 0;
}
