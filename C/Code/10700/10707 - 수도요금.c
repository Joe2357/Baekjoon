#include <stdio.h>

int main(a, b, c, d, p, r1, r2) {
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &p);
	r1 = a * p, r2 = b + (c < p) * d * (p - c); // calc cost
	printf("%d", (r1 > r2) ? r2 : r1);			// print minimum value
	return 0;
}