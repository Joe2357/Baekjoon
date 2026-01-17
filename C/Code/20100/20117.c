#include <stdio.h>
#include <stdlib.h>

#define MAX_IDX (int)(1e5)

int quality[MAX_IDX];
int n;

int asc(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &quality[i]);
	}
	qsort(quality, n, sizeof(int), asc);

	int ret = -1 * ((n % 2 == 1) * quality[n / 2]);
	for (int i = 0; i < n; i += 1, n -= 1) {
		ret += (quality[n - 1] * 2);
	}
	printf("%d", ret);
	return 0;
}