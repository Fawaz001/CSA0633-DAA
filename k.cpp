#include <stdio.h>
#include <stdlib.h> 
struct Item {
    int weight;
    int value;
}; 
int compare(const void *a, const void *b) {
    double ratioA = ((struct Item *)a)->value / (double)((struct Item *)a)->weight;
    double ratioB = ((struct Item *)b)->value / (double)((struct Item *)b)->weight;
    return (ratioB > ratioA) - (ratioB < ratioA);
} 
double fractionalKnapsack(int capacity, struct Item items[], int n) { 
    qsort(items, n, sizeof(struct Item), compare);

    double totalValue = 0.0;   
    int currentWeight = 0;   
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) { 
            totalValue += items[i].value;
            currentWeight += items[i].weight;
        } else {
            int remainingCapacity = capacity - currentWeight;
            totalValue += (double)remainingCapacity * items[i].value / items[i].weight;
            break;   
        }
    }

    return totalValue;
}

int main() {
    struct Item items[] = {{10, 60}, {20, 100}, {30, 120}};  
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;  

    double maxValue = fractionalKnapsack(capacity, items, n);
    printf("Maximum value that can be obtained = %.2f\n", maxValue);

    return 0;
}

