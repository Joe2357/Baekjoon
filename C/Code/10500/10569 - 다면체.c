#include <stdio.h>

int main(t, a, b) {
	for (scanf("%d", &t); t; t--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", b - a + 2);
	}
	return 0;
}