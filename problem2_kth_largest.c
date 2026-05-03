#include <stdio.h>

int find_kth_largest(int *arr, int size, int k) {
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return arr[size - k];
}

int main() {
    int arr[] = {3, 1, 7, 4, 9, 2};
    int size = 6;
    int k = 2;

    int ans = find_kth_largest(arr, size, k);
    printf("K-th Largest = %d\n", ans);

    return 0;
}
