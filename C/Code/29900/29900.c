#include <stdio.h>
#include <stdlib.h>

#define MAX_IDX 1000

int coin[MAX_IDX];
int n;

int asc(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &coin[i]);
	}
	qsort(coin, n, sizeof(int), asc);

	int ret = 0;
	for (int i = 0; i < n; ++i) {
		if (coin[i] > ret + 1) {
			break;
		}
		ret += coin[i];
	}

	printf("%d", ret + 1);
	return 0;
}