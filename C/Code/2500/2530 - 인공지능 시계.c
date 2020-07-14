#include <stdio.h>

int main(a, b, c, d) {
	scanf("%d %d %d %d", &a, &b, &c, &d);
	c += d % 60, d /= 60;						// second
	b += d % 60 + c / 60, c %= 60, d /= 60;		// minute
	a += d + b / 60, b %= 60, a %= 24;			// hour
	printf("%d %d %d", a, b, c);
	return 0;
}