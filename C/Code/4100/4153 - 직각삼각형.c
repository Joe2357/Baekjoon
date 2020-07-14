#include <stdio.h>

int main(a, b, c) {
	scanf("%d %d %d", &a, &b, &c);
	while (a) { // while a != 0
		a *= a, b *= b, c *= c; // pow(int, 2)
		if (c == (a + b) || b == (a + c) || a == (b + c))
			printf("right\n");
		else
			printf("wrong\n");
		scanf("%d %d %d", &a, &b, &c);  // reload
	}
	return 0;
}