#include <stdio.h>
#include <math.h> 
int isPrime(int num) {
    if (num <= 1)
        return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
} 
void generatePrimes(int start, int end) {
    if (start > end)
        return;
    if (isPrime(start))
        printf("%d ", start);
    generatePrimes(start + 1, end);
}

int main() {
    int n;
    printf("Enter the limit: ");
    scanf("%d", &n);
    printf("prime number up to %d are:",n);
    generatePrimes(2,n);
    printf("\n");
    return 0;
}
	
