#include <stdio.h>
#define ARRAY_SIZE 1000000

typedef struct Array {
	int pos;
	int index;
	int result;
} AR;

AR arr[ARRAY_SIZE];
int n;
int tempCount;

int indexOrder(AR* a, AR* b) {
	return a->index - b->index;
}

int posOrder(AR* a, AR* b) {
	return a->pos - b->pos;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		arr[i].index = i + 1;
		scanf("%d", &arr[i].pos);
	}
	qsort(arr, n, sizeof(AR), posOrder);
	arr[0].result = 0;
	for (int i = 1; i < n; i++) {
		tempCount += (arr[i - 1].pos != arr[i].pos);
		arr[i].result = tempCount;
	}
	qsort(arr, n, sizeof(AR), indexOrder);
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i].result);
	return 0;
}