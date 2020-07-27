#include <stdio.h>

int main(x, y) {
	scanf("%d:%d", &x, &y);
	int a = x, b = y, c;
	while (b) // Euclidean algorithm
		c = a % b, a = b, b = c;
	printf("%d:%d", x / a, y / a);
	return 0;
}