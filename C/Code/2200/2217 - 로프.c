#include <stdio.h>
#define max(a, b) (a > b) ? a : b

int cmp(int* a, int* b) {
	return *a - *b;
}

int main(n) {
	scanf("%d", &n);
	int arr[100000];
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	qsort(arr, n, sizeof(int), cmp);				// sort ascending
	long result = 0, count = n;
	for (int i = 0; i < n; i++)						// weight = smallest ope * remain number of lope
		result = max(result, arr[i] * (n - i));
	printf("%ld", result);
	return 0;
}