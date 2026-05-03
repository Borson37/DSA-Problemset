#include <stdio.h>

typedef struct {
    int weight;
    int value;
} Item;

double fractional_knapsack(Item *items, int n, int capacity) {
    double total = 0.0;

    // sort by ratio
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {

            double r1 = (double)items[j].value / items[j].weight;
            double r2 = (double)items[j+1].value / items[j+1].weight;

            if(r1 < r2) {
                Item temp = items[j];
                items[j] = items[j+1];
                items[j+1] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(capacity >= items[i].weight) {
            capacity -= items[i].weight;
            total += items[i].value;
        }
        else {
            total += ((double)items[i].value / items[i].weight) * capacity;
            break;
        }
    }

    return total;
}

int main() {
    Item items[] = {{10,60}, {20,100}, {30,120}};
    int n = 3;
    int capacity = 50;

    double result = fractional_knapsack(items, n, capacity);

    printf("Max Value = %.2lf\n", result);

    return 0;
}
