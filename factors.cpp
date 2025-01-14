#include <stdio.h>
void printFactors(int n, int divisor) {
    if (divisor > n / 2)
        return;
    if (n % divisor == 0)
        printf("%d ", divisor); 
    printFactors(n, divisor + 1);
}
int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n); 
    printf("Factors of %d are: ", n);
    printFactors(n, 1); 
    printf("%d\n", n); 
    return 0;
}
