#include <stdio.h>

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	while (a) {
		a *= a, b *= b, c *= c;
		if (c == (a + b) || b == (a + c) || a == (b + c))
			printf("right\n");
		else
			printf("wrong\n");
		scanf("%d %d %d", &a, &b, &c);
	}
	return 0;
}