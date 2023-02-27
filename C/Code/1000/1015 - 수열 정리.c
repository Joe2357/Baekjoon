#include <stdio.h>

typedef struct Array {
	int index, value, result;
} AR;

int cmp_value(AR *a, AR *b) {
	return a->value - b->value;
}
int cmp_index(AR *a, AR *b) {
	return a->index - b->index;
}

int main(n) {
	AR arr[50];	 // B array
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {	 // input
		scanf("%d", &arr[i].value);	 // value
		arr[i].index = i;			 // index
	}
	qsort(arr, n, sizeof(AR), cmp_value);  // value ascending sort
	for (int i = 0; i < n; i++)			   // A[i] setting
		arr[i].result = i;
	qsort(arr, n, sizeof(AR), cmp_index);  // input order ascending sort
	for (int i = 0; i < n; i++)			   // print result
		printf("%d ", arr[i].result);
	return 0;
}