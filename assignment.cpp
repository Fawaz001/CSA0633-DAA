#include <stdio.h>
#include <limits.h>
#define N 3 
int cost[N][N] = {{7, 9, 6}, 
                  {8, 6, 7},
                  {2, 3, 4},};
int sol[N]; 
int x[N];            
int minCost = INT_MAX; 

void copyArray(int a[], int b[]) {
   int i;
   for(i=0; i<N; i++) 
      a[i] = b[i];
}

void printSolution() {
   int i;
   for(i=0;i<N;i++)
      printf("%d --> %d \n", i, sol[i]);  
}

void solve(int k) {
   int i, j;     
   if(k==N) { 
      int currCost = 0; 
      for(i=0; i<N; i++) {
         currCost += cost[i][x[i]];
      }
      if(currCost < minCost) { 
         minCost = currCost;
         copyArray(sol, x);         
      }        
   }
   else {
      for(j=0; j<N; j++) {
         if(x[j]==-1) {
            x[j] = k;
            solve(k+1);
            x[j]=-1;
         }
      }
   }   
}

int main() {
   int i;
   for(i=0;i<N;i++) x[i]=-1; 
   solve(0); 
   printSolution(); 
   return 0; 
}
