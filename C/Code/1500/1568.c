#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	int day = 0;
	for (int k = 1; n > 0; ++k) {
		if (n >= k) {
			n -= k;
			day += 1;
		} else {
			k = 0;
		}
	}

	printf("%d", day);
	return 0;
}