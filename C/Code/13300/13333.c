#include <stdio.h>
#include <stdlib.h>

#define MAX_IDX 1000
#define MAX_SITE 10000

int site[MAX_IDX];
int n;

int desc(const void* a, const void* b) {
	return (*(int*)b - *(int*)a);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &site[i]);
	}
	qsort(site, n, sizeof(int), desc);

	int ret = 0;
	for (int k = 0; k < MAX_SITE; ++k) {
		if (site[k - 1] >= k && site[k] <= k) {
			ret = k;
			break;
		}
	}
	printf("%d", ret);
	return 0;
}