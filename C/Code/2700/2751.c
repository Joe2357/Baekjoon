#include <stdio.h>
#include <stdlib.h>

#define MAX_IDX (int)(1e6)

int arr[MAX_IDX], n;

int asc(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	qsort(arr, n, sizeof(int), asc);
	for (int i = 0; i < n; ++i) {
		printf("%d\n", arr[i]);
	}
	return 0;
}