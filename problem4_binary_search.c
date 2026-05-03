#include <stdio.h>

int binary_search(int *arr, int left, int right, int target) {
    if(left > right)
        return -1;

    int mid = (left + right) / 2;

    if(arr[mid] == target)
        return mid;

    if(target < arr[mid])
        return binary_search(arr, left, mid - 1, target);

    return binary_search(arr, mid + 1, right, target);
}

int main() {
    int arr[] = {1,3,5,7,9};
    int size = 5;
    int target = 7;

    int result = binary_search(arr, 0, size - 1, target);

    printf("Index = %d\n", result);

    return 0;
}
