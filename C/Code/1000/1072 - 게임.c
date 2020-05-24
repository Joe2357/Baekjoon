#include <stdio.h>
#include <math.h>		// using ceil() function

int main() {
	double x, y;
	while (~scanf("%lf %lf", &x, &y)) {		// until EOF
		int z = 100 * y / x;
		if (z >= 99)						// ratio never change
			printf("-1\n");
		else
			printf("%d\n", (int)ceil((x * (z + 1) - 100 * y) / (99 - z)));	// calc
	}
	return 0;
}