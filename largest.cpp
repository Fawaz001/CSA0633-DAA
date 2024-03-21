#include<stdio.h>
int find_largest(int arr[],int size){
	int largest=arr[0];
	for(int i=1;i<size;i++){
		if(arr[i]>largest){
			largest=arr[i];
		}
	}
	return largest;
}
int main(){
	int arr[]={10,20,30,40,50};
	int size=sizeof(arr)/sizeof(arr[0]);
	int largest=find_largest(arr,size);
	printf("largest element in the array is:%d\n",largest);
	return 0;
}
