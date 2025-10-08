#include <math.h>
#include <stdio.h>

int main() {
	double x, y;
	while (~scanf("%lf %lf", &x, &y)) {
		int z = 100 * y / x;
		if (z >= 99)
			printf("-1\n");
		else
			printf("%d\n", (int)ceil((x * (z + 1) - 100 * y) / (99 - z)));
	}
	return 0;
}