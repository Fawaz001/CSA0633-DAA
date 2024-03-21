#include<stdio.h>
int fact(int n){
	if(n==0)
	return 1;
	else
	return n*fact(n-1);
}
int main(){
	int n;
	printf("enter a non-negative number:");
	scanf("%d",&n);
	if(n<0)
	printf("fatorial of negative number is not defined");
	else{
		int result=fact(n);
	printf("factorial of %d is :%d\n",n,result);
}
return 0;
}
