#include <stdio.h>

int main(t, n, r, a) {
	for (scanf("%d", &t); t; t--) {
		r = 0;
		for (scanf("%d", &n); n; n--) {
			scanf("%d", &a);
			r += a;
		}
		printf("%d\n", r);
	}
	return 0;
}