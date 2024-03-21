#include<stdio.h>
int fibonacci(int n){
	if(n<=1)
	return n;
	else
	return fibonacci(n-1)+fibonacci(n-2);
}
int main()
{
	int num_terms;
	printf("enter the number of terms:");
	scanf("%d",&num_terms);
	printf("Fibonacci series:\n");
	for(int i=0;i<num_terms;i++)
	{
		printf("%d",fibonacci(i));
	}
	return 0;
}
