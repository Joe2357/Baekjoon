#include <stdio.h>
#include <stdlib.h>

#define MAX_IDX (int)(5e6)

int arr[MAX_IDX];

int asc(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
	}
	qsort(arr, n, sizeof(int), asc);
	printf("%d", arr[k - 1]);
	return 0;
}