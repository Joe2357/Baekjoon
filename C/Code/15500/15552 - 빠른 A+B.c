#include <stdio.h>

int main() {
	int t;
	for (scanf("%d", &t); t; t--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}
	return 0;
}