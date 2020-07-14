#include <stdio.h>

int main() {
	int l, a, b, c, d;
	scanf("%d %d %d %d %d", &l, &a, &b, &c, &d);
	while (1) {
		if (((a - c) <= 0) && (b - d) <= 0) {
			printf("%d", --l);
			return 0;
		}
		else
			a -= c, b -= d, l--;
	}
}