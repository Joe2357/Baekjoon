#include <stdio.h>

// Same with 9655 - 돌 게임
// But we can't make int[100 Billion], can't use DP
// So we have to find some rules

int main() {
	long long n;
	scanf("%lld", &n);
	if (n % 2)
		printf("SK");
	else
		printf("CY");
	return 0;
}