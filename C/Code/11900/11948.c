#include <stdio.h>

#define min(a, b) (((a) > (b)) ? (b) : (a))

int main() {
	int a, b, c, d, e, f;
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

	int sum = a + b + c + d + e + f;
	sum -= min(min(a, b), min(c, d));
	sum -= min(e, f);
	printf("%d", sum);
	return 0;
}