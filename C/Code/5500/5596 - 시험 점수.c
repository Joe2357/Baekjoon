#include <stdio.h>

int main(a, b, c, d, e, f) {
	scanf("%d %d %d %d", &a, &b, &c, &d);
	e = a + b + c + d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	f = a + b + c + d;
	printf("%d", (e > f) ? e : f);
	return 0;
}