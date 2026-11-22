#include <stdio.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int main() {
	int a, t;
	scanf("%d %d", &a, &t);
	printf("%d", max(10 + 2 * (25 - a + t), 0));
	return 0;
}