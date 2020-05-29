#include <stdio.h>

int main() {
	int x, i = 1, sum = 0;
	scanf("%d", &x);
	while (x > sum + i)									// target denominator search
		sum += i++;
	if (i % 2)											// ascending
		printf("%d/%d", i + sum - x + 1, x - sum);
	else												// descending
		printf("%d/%d", x - sum, i + sum - x + 1);
	return 0;
}