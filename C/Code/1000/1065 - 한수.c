#include <stdio.h>

int main(n) {
	int count = 0;
	for (scanf("%d", &n); n; n--)
		count += ((n < 100) || ((n % 10) - (n % 100) / 10 == (n % 100) / 10 - n / 100));		// condition of hansu
	printf("%d", count);
	return 0;
}