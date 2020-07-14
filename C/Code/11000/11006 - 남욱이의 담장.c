#include <stdio.h>

int main(t) {
	for (scanf("%d", &t); t; t--) {
		int a, b;
		scanf("%d %d", &a, &b);
		a -= b, b -= a;
		printf("%d %d\n", b, a);
	}
	return 0;
}