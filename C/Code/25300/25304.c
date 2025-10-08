#include <stdio.h>

int main() {
	int x, n;
	scanf("%d %d", &x, &n);
	while (n--) {
		int a, b;
		scanf("%d %d", &a, &b);
		x -= (a * b);
	}

	printf("%s", (x == 0) ? "Yes" : "No");
	return 0;
}