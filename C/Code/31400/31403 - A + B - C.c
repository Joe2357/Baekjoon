#include <stdio.h>

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	printf("%d\n", a + b - c);

	int temp = b;
	while (temp > 0) {
		temp /= 10;
		a *= 10;
	}
	printf("%d", a + b - c);

	return 0;
}