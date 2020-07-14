#include <stdio.h>
#define MAX 500000

int cmp(int *a, int *b) {
	return *a - *b;
}

int main(n, t) {
	// input
	int arr[MAX];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);

	// ascending order sort
	qsort(arr, n, sizeof(int), cmp);

	// output
	for (scanf("%d", &t); t; t--) {
		int target,
			start = 0, end = n, mid,
			result[3] = { 0 };
		scanf("%d", &target);
		while (start < end) // lower bound
		{
			mid = (start + end) / 2;
			if (arr[mid] >= target)
				end = mid;
			else
				start = mid + 1;
		}
		result[0] = end + 1,
			start = 0, end = n;
		while (start < end) // upper bound
		{
			mid = (start + end) / 2;
			if (arr[mid] > target)
				end = mid;
			else
				start = mid + 1;
		}
		result[1] = end + 1;
		result[2] = (result[1] >= result[0]) ? result[1] - result[0] : 0;
		printf("%d ", result[2]);
	}
	return 0;
}