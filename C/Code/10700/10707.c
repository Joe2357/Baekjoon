#include <stdio.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) > (b)) ? (b) : (a))

int main(r1, r2) {
	int a, b, c, d, p;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &p);

	printf("%d", min(a * p, b + d * max(0, p - c)));
	return 0;
}