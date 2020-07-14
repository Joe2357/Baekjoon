#include <stdio.h>

int cmp(int *a, int *b) {
	return *b - *a;
}

int main(t) {
	for (scanf("%d", &t); t; t--) {
		int arr[10];
		for (int i = 0; i < 10; i++)
			scanf("%d", arr + i);
		qsort(arr, 10, sizeof(int), cmp);       // descending sort
		printf("%d\n", arr[2]);                 // third biggest value
	}
	return 0;
}