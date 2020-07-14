#include <stdio.h>

int main() {
	long a, b;
	scanf("%ld %ld", &a, &b);	// input
	a -= b;						// subtract
	if (a < 0)					// absolute value
		a *= -1;
	printf("%ld", a);			// print result
	return 0;
}