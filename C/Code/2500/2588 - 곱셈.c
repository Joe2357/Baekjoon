#include <stdio.h>

int main(a, b) {
	scanf("%d %d", &a, &b);
	int
		b1 = b / 100,                               //  digit of b
		b2 = b / 10 % 10,
		b3 = b % 10,
		r1 = a * b1,                                // digit of b * a
		r2 = a * b2,
		r3 = a * b3,
		result = r1 * 100 + r2 * 10 + r3;           // a * b
	printf("%d\n%d\n%d\n%d", r3, r2, r1, result);
	return 0;
}