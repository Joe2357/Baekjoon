#include <stdio.h>

int main(n, x, t) {
	for (scanf("%d %d", &n, &x); n; n--) {
		scanf("%d", &t);
		if (x > t) // if value is less than target
			printf("%d ", t);
	}
	return 0;
}