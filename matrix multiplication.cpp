#include<stdio.h>
#define N 2
void multiplyMatrices(int A[][N],int B[][N],int C[][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			C[i][j]=0;
			for(int k=0;k<N;k++){
				C[i][j]=A[i][k]*B[k][j];
			}
		}
	}
}
int main(){
	int A[N][N]={{1,2},{3,4}};
	int B[N][N]={{3,4},{5,6}};
	int C[N][N];
	multiplyMatrices(A,B,C);
	printf("Resultant Matrix:\n");
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			printf("%d",C[i][j]);
		}
		printf("\n");
	}
	return 0;
}
