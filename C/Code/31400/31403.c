#include <stdio.h>

const int DIGIT = 10;

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	printf("%d\n", a + b - c);

	for (int tmp = b; tmp > 0; tmp /= DIGIT) {
		a *= DIGIT;
	}
	printf("%d", a + b - c);

	return 0;
}