#include <stdio.h>

int main() {
	int c, k, p;
	scanf("%d %d %d", &c, &k, &p);

	int wine = 0;
	for (int n = 1; n <= c; ++n) {
		wine += (k * n + p * n * n);
	}

	printf("%d", wine);
	return 0;
}