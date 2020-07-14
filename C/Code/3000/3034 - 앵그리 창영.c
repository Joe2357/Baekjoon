#include <stdio.h>

int main(n, w, h, a) {
	for (scanf("%d %d %d", &n, &w, &h); n; n--) {
		scanf("%d", &a);
		// length of a march is smaller than Rectangular diagonal, we can put march in the box
		if (a * a <= w * w + h * h)
			printf("DA\n");
		else
			printf("NE\n");
	}
	return 0;
}