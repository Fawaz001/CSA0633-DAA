#include <stdio.h>

int binarySearch(int arr[], int target, int left, int right) {
    if (left > right) {
        return -1; 
    }
    int mid = (left + right) / 2;
    if (arr[mid] == target) {
        return mid; 
    } else if (arr[mid] < target) {
        return binarySearch(arr, target, mid + 1, right);  
    } else {
        return binarySearch(arr, target, left, mid - 1); 
    }
} 
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 7;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, target, 0, n - 1);
    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found\n", target);
    }
    return 0;
}
