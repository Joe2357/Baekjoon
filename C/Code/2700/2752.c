#include <stdio.h>
#include <stdlib.h>

#define MAX_IDX 3

int arr[MAX_IDX];

int asc(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int main() {
	for (int i = 0; i < MAX_IDX; ++i) {
		scanf("%d", &arr[i]);
	}
	qsort(arr, MAX_IDX, sizeof(int), asc);
	for (int i = 0; i < MAX_IDX; ++i) {
		printf("%d ", arr[i]);
	}
	return 0;
}