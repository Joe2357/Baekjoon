#include <stdio.h>

int main(t, a, b, c, d, i) {
	for (scanf("%d", &t); t; t--) {
		a = 0, b = 0;
		for (i = 9; i; i--) { // add all points
			scanf("%d %d", &a, &b);
			c += a, d += b;
		}
		if (c > d)
			printf("Yonsei\n");
		else if (c == d)
			printf("Draw\n");
		else
			printf("Korea\n");
	}
	return 0;
}