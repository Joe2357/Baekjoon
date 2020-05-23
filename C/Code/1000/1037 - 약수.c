#include <stdio.h>

int compare(const void*, const void*);			// quicksort compare function

int main(n) {
	scanf("%d", &n);
	int arr[50];
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	qsort(arr, n, sizeof(int), compare);		// quicksort
	long long result = arr[0] * arr[n - 1];		// smallest * biggest = target
	printf("%lld", result);
	return 0;
}

int compare(const void* a, const void* b) {		// compare function
	return *(int*)a - *(int*)b;					// a > b ? + : -
}