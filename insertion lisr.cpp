#include<stdio.h>
int main()
{
    int arr[100];
    int i, item, pos,size;
    printf("Enter number of elements: ");
    scanf("%d",&size);
    for (i = 0; i < size; i++)
        scanf("%d",&arr[i]);  
    printf("Array before insertion: ");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("Enter the element to be inserted: ");
    scanf("%d",&item);
printf("Enter the position at which the element is to be inserted:");
    scanf("%d",&pos);
    size++;
for (i = size-1; i >= pos; i--)
        arr[i] = arr[i - 1];
      arr[pos - 1] = item;
    printf("Array after insertion: ");
    
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
 
    return 0;
}
