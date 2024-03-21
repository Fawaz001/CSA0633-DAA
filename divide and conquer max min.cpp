#include <stdio.h> 
void findMaxMin(int list[], int low, int high, int *max, int *min) {
    if (low == high) {
        *max = *min = list[low];
        return;
    }
    if (high - low == 1) {
        *max = (list[low] > list[high]) ? list[low] : list[high];
        *min = (list[low] < list[high]) ? list[low] : list[high];
        return;
    }

    int mid = (low + high) / 2;
    int max1, min1, max2, min2;
    findMaxMin(list, low, mid, &max1, &min1);
    findMaxMin(list, mid + 1, high, &max2, &min2);

    *max = (max1 > max2) ? max1 : max2;
    *min = (min1 < min2) ? min1 : min2;
}

int main() {
    int list[] = {3, 2, 5, 1, 7, 4, 9, 6};
    int n = sizeof(list) / sizeof(list[0]);
    int max, min;
    findMaxMin(list, 0, n - 1, &max, &min);
    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);
    return 0;
}
