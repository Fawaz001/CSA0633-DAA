#include <stdio.h>
int linearSearch(int* arr, int size, int key)
{ 
	for (int i = 0; i < size; i++) { 
		if (arr[i] == key) {
			return i;
		}
	}
	return -1;
} 
int main()
{
	int arr[10] = { 2,3,4,10,40};
	int size = sizeof(arr) / sizeof(arr[0]);
	int key = ; 
	int index = linearSearch(arr, size, key); 
	if (index == -1) {
		printf("The element is not present in the arr.");
	}
	else {
		printf("The element is present at arr[%d].", index);
	}

	return 0;
}

