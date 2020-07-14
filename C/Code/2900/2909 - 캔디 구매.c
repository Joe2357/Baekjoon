#include <stdio.h>

int main(n, k, i) {
	scanf("%d %d", &n, &k);
	for (i = 1; k; k--)
		i *= 10;
	k = n % i,
		n = (n / i + (k >= i / 2)) * i; // Rounds standard = i
	printf("%d", n);
	return 0;
}