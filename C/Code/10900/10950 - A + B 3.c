#include <stdio.h>

int main(t) {
	for (scanf("%d", &t); t; t--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}
	return 0;
}