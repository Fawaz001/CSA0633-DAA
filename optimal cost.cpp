#include <stdio.h>
#include <limits.h>

int min(int a, int b);

int sum(int freq[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++)
        s += freq[k];
    return s;
}

int optimalCost(int keys[], int freq[], int n) {
    int cost[n][n];

    for (int i = 0; i < n; i++)
        cost[i][i] = freq[i];

    for (int L = 2; L <= n; L++) {
        for (int i = 0; i <= n - L; i++) {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;

            for (int r = i; r <= j; r++) {
                int c = ((r > i) ? cost[i][r - 1] : 0) +
                        ((r < j) ? cost[r + 1][j] : 0) +
                        sum(freq, i, j);
                cost[i][j] = min(cost[i][j], c);
            }
        }
    }
    return cost[0][n - 1];
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int n;
    printf("Enter the number of keys: ");
    scanf("%d", &n);
    
    int keys[n], freq[n];
    printf("Enter the keys:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &keys[i]);
    
    printf("Enter the frequencies:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &freq[i]);
    
    printf("Optimal cost: %d\n", optimalCost(keys, freq, n));
    return 0;
}
