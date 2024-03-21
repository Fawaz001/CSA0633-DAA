#include<stdio.h>
void copyString(char source[],char destination[],int index){
	if(source[index]=='\0'){
		destination[index]='\0';
		return;
	}
	destination[index]=source[index];
	copyString(source,destination,index+1);
}
int main(){
	char source[]="Saveetha";
	char destination[20];
	copyString(source,destination,0);
	printf("Source:%s\n",source);
	printf("Destination:%s\n",destination);
	return 0;
}

