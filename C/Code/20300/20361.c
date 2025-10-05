#include <stdio.h>

int main() {
	int n, x, k;
	scanf("%d %d %d", &n, &x, &k);

	while (k--) {
		int a, b;
		scanf("%d %d", &a, &b);

		if (a == x) {
			x = b;
		} else if (b == x) {
			x = a;
		}
	}
	printf("%d", x);
	return 0;
}