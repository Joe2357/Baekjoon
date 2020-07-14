#include <stdio.h>

int main(a, b, c) {
	scanf("%d %d %d", &a, &b, &c);
	a *= b * c;							// A * B * C
	int result[10] = { 0 };				// digit count
	while (a)							// divide & count
		result[a % 10]++, a /= 10;
	for (int i = 0; i < 10; i++)		// print result
		printf("%d\n", result[i]);
	return 0;
}