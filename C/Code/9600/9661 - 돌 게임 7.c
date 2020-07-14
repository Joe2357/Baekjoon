#include <stdio.h>

// we can't make int[100 Billion], can't use DP
// So we have to find some rules

int main() {
	long long n;
	scanf("%lld", &n);
	if (!(n % 5) || (n % 5 == 2))
		printf("CY");
	else
		printf("SK");
	return 0;
}