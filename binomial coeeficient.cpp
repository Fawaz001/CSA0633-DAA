#include <stdio.h> 
int binomialCoeff(int n, int k)
{ 
	if (k > n)
		return 0;
	if (k == 0 || k == n)
		return 1; 
	return binomialCoeff(n - 1, k - 1)
		+ binomialCoeff(n - 1, k);
} 
int main()
{
	int n = 5, k = 2;
	printf("Value of C(%d, %d) is %d ", n, k,
		binomialCoeff(n, k));
	return 0;
}

