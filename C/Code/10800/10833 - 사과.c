#include <stdio.h>

int main(a, b, t, c) {
	c = 0;
	for (scanf("%d", &t); t; t--) {
		scanf("%d %d", &a, &b);
		c += b % a;
	}
	printf("%d", c);
	return 0;
}