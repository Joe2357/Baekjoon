#include <stdio.h>

int main(a, b) {
	int max = 0, min = 0, digit = 1;
	scanf("%d %d", &a, &b);
	while (a)
		max += (a % 10) * digit,
		min += (a % 10) * digit,
		max += digit * (a % 10 == 5), // maximun value will be sum of 2 values that 5 cahnges to 6
		min -= digit * (a % 10 == 6), // minimum value will be sum of 2 values that 6 cahnges to 5
		a /= 10, digit *= 10;
	digit = 1;
	while (b)
		max += (b % 10) * digit,
		min += (b % 10) * digit,
		max += digit * (b % 10 == 5),
		min -= digit * (b % 10 == 6),
		b /= 10, digit *= 10;
	printf("%d %d", min, max);
	return 0;
}