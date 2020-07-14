#include <stdio.h>

int compare(int *a, int *b) {
	return *a - *b;
}

int main(n) {
	int arr[1000000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	qsort(arr, n, sizeof(int), compare);    // quick sort
	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);
	return 0;
}