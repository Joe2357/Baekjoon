#include <stdio.h>

int main() {
	int n, w, h, a;
	for (scanf("%d %d %d", &n, &w, &h); n; n--) {
		scanf("%d", &a);
		if (a * a <= w * w + h * h)
			printf("DA\n");
		else
			printf("NE\n");
	}
	return 0;
}