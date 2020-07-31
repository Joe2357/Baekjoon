#include <stdio.h>

int main(a, b, c) {
	scanf("%d %d %d", &a, &b, &c);
	int result = b * a * (a + 1) / 2 + c * (a * (a + 1) * (2 * a + 1) / 6);
	printf("%d", result);
	return 0;
}