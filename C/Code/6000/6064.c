#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int m, n, x, y;
		scanf("%d %d %d %d", &m, &n, &x, &y);
		int year = 0;
		while (1) {
			if (x == y) {
				year = x;
				break;
			} else if (x > (m * n) || y > (m * n)) {
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