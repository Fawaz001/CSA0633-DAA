#include <stdio.h>
int findMaxMin(int list[], int n, int max, int min) {
    max = list[0];
    min = list[0];
    for (int i = 1; i < n; i++) {
        if (list[i] >max) {
            max = list[i];
        }
        if (list[i] <min) {
            min = list[i];
        }
    }
    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);
}

int main() {
    int list[] = {5, 10, -3, 8, 2};
    int n = sizeof(list) / sizeof(list[0]);
    int max, min;
    findMaxMin(list, n, max, min);
    return 0;
}
