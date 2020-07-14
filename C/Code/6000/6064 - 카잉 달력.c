#include <stdio.h>

int main(t) {
	for (scanf("%d", &t); t; t--) {
		int m, n, x, y;
		scanf("%d %d %d %d", &m, &n, &x, &y);
		int year = 0;
		while (1) {
			if (x == y) {
				year = x; // result
				break;
			}
			else if (x > (m * n) || y > (m * n)) { // can't make year with m, n
				year = -1;
				break;
			}
			if (x > y)
				y += n;
			else if (x < y)
				x += m;
		}
		printf("%d\n", year);
	}
	return 0;
}