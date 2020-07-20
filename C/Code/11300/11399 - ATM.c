#include <stdio.h>
#include <stdlib.h>

int cmp(int *a, int *b) {
	return *a - *b;
}

int main() {
	// init
	int arr[1001] = { 0 }, n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);

	// Shortest Job First Algorithm
	qsort(arr, n, sizeof(arr[0]), cmp);
	int result = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			result += arr[j];

	// print result
	printf("%d", result);
	return 0;
}