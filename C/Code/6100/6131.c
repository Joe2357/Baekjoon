#include <stdio.h>

#define MAX_IDX 500

int main() {
	int n;
	scanf("%d", &n);
	int ret = 0;

	for (int a = 1; a <= MAX_IDX; ++a) {
		for (int b = 1; b < a; ++b) {
			ret += (a * a == b * b + n);
		}
	}

	printf("%d", ret);
	return 0;
}