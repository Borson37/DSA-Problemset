#include <stdio.h>

// insert function (insertion sort style)
void insert(int *out, int *size, int value) {
    int i = *size - 1;

    while(i >= 0 && out[i] > value) {
        out[i+1] = out[i];
        i--;
    }

    out[i+1] = value;
    (*size)++;
}

// merge function
void merge_sorted(int *a, int n, int *b, int m, int *out) {
    int size = 0;

    for(int i = 0; i < n; i++) {
        insert(out, &size, a[i]);
    }

    for(int i = 0; i < m; i++) {
        insert(out, &size, b[i]);
    }
}

int main() {
    int a[] = {5, 1, 9};
    int b[] = {3, 7, 2, 6};

    int n = 3, m = 4;
    int out[100];

    merge_sorted(a, n, b, m, out);

    printf("Merged Array: ");
    for(int i = 0; i < n + m; i++) {
        printf("%d ", out[i]);
    }

    return 0;
}
