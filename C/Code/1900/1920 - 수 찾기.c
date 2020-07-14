#include <stdio.h>

int cmp(int *a, int *b) {   // quick sort compare function
	// -0.2 billion - 0.2 billion = (int)overflow!
	if (*a > *b)
		return 1;
	else if (*a < *b)
		return -1;
	else
		return 0;
}

int main(n, t) {
	int arr[100000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)					// input
		scanf("%d", arr + i);
	qsort(arr, n, sizeof(int), cmp);			// sorting ascending
	for (scanf("%d", &t); t; t--)				// in Test Case:
	{
		int target, result = 0,
			start = 0, end = n, mid;
		scanf("%d", &target);					// get target number
		while (start <= end) {
			mid = (start + end) / 2;			// get middle point
			if (target == arr[mid])				// if target number
			{
				result = 1;						// value found
				break;
			}
			else if (mid == start || mid == end) // no more value we can search
				break;
			else if (target < arr[mid])			// on left side
				end = mid;
			else								// on right side
				start = mid;
		}
		printf("%d\n", result);
	}
	return 0;
}