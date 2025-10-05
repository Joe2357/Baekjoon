#include <stdio.h>

int main() {
	// init
	int a, b, c, d, e, f;
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
	int x, y;

	// case search
	if (a == 0) {
		y = c / b;
		x = (f - e * y) / d;
	} else if (d == 0) {
		y = f / e;
		x = (c - b * y) / a;
	} else if (b == 0) {
		x = c / a;
		y = (f - d * x) / e;
	} else if (e == 0) {
		x = f / d;
		y = (c - a * x) / b;
	} else {
		int b1 = b * d, c1 = c * d, e1 = e * a, f1 = f * a;
		b1 -= e1, c1 -= f1;
		y = c1 / b1;
		x = (c - b * y) / a;
	}

	// print result
	printf("%d %d", x, y);
	return 0;
}