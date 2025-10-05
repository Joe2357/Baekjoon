#include <stdio.h>

#define MAX_IDX 5

int array[MAX_IDX];

int asc(int* a, int* b) {
	return *a > *b;
}

int main() {
	int average_of_array = 0;
	for (int i = 0; i < MAX_IDX; i++) {
		scanf("%d", array + i);
		average_of_array += array[i];
	}

	qsort(array, MAX_IDX, sizeof(int), asc); // 정렬

	printf("%d\n%d", average_of_array / MAX_IDX, array[MAX_IDX / 2]);
	return 0;
}