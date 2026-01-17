#include <math.h>
#include <stdio.h>

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	int p, q, r;
	p = a;
	q = 2 * b * c;
	r = a * (c * c - a * a + b * b);

	int d = q * q - 4 * p * r;
	if (d < 0) {
		printf("-1");
		return 0;
	}

	double temp = d;
	double x = (-q + sqrt(temp)) / (2 * p);

	if (x < 0) {
		printf("-1");
		return 0;
	} else {
		printf("%d", (int)(x));
	}
	return 0;
}