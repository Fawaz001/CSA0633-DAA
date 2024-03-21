#include<stdio.h>
#include<math.h>
int order(int num){
int count=0;
while(num!=0){
	count++;
	num/=10;
}	
return count;
}
int isarmstrong(int num,int order){
	if(num==0)
	return 0;
	else
	return pow(num%10,order)+isarmstrong(num/10,order);
}
int armstrong(int num){
	int ord=order(num);
	if(num==isarmstrong(num,ord))
	return 1;
	else
	return 0;
}
int main(){
	int num;
	printf("enter a number:");
	scanf("%d",&num);
	if(armstrong(num))
	printf("%d is an armstrong number",num);
	else
	printf("%d is not an armstrong number",num);
	return 0;
}
