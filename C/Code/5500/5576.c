#include <stdio.h>
#include <stdlib.h>

#define MAX_IDX 10
int arr[MAX_IDX];

int desc(const void* a, const void* b) {
	if (*(int*)a > *(int*)b) {
		return -1;
	} else if (*(int*)a < *(int*)b) {
		return 1;
	} else {
		return 0;
	}
}

int sum_best_3_score() {
	for (int i = 0; i < MAX_IDX; ++i) {
		scanf("%d", arr + i);
	}
	qsort(arr, MAX_IDX, sizeof(int), desc);
	return arr[0] + arr[1] + arr[2];
}

int main() {
	int w = sum_best_3_score();
	int k = sum_best_3_score();
	printf("%d %d", w, k);
	return 0;
}