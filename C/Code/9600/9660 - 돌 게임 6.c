#include <stdio.h>

// Same with 9656 - 돌 게임 2
// But we can't make int[100 Billion], can't use DP
// So we have to find some rules

int main() {
	long long n;
	scanf("%lld", &n);
	if (( n % 7 == 0 ) || ( n % 7 == 2 ))
		printf("CY");
	else
		printf("SK");
	return 0;
}