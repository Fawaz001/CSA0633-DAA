#include<stdio.h>
int isprime(int n,int divisor){
	if(n<=1)
	return 0;
	if(divisor==1)
	return 1;
	if(n%divisor==0) 
	return 0;
	return isprime(n,divisor-1);
}
int main(){
	int num;
	printf("enter a positive integer:");
	scanf("%d",&num);
	int result=isprime(num,num/2);
	if(result)
	printf("%d is prime",num);
	else
	printf("%d is not prime",num);
	return 0;
}
