#include <stdio.h>

char str[3][10] = { "neither",
				   "factor",
				   "multiple" };

int main(a, b) {
	while (scanf("%d %d", &a, &b) && a && b) {
		int r = 0;
		// a can divide by b
		if (!(a % b))
			r = 2;
		// b can divide by a
		else if (!(b % a))
			r = 1;
		printf("%s\n", str[r]);
	}
}