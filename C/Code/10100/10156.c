#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
	int k, n, m;
	scanf("%d %d %d", &k, &n, &m);
	printf("%d", max(k * n - m, 0));
	return 0;
}