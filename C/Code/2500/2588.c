#include <stdio.h>

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int temp = b;

	while (temp > 0) {
		printf("%d\n", a * (temp % 10));
		temp /= 10;
	}
	printf("%d", a * b);
	return 0;
}