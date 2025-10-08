#include <stdio.h>

int cmp(int* a, int* b) // 정수의 범위이므로 -20억과 20억의 값 비교는 overflow!
{
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
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	qsort(arr, n, sizeof(int), cmp);
	for (scanf("%d", &t); t; t--) {
		int target, result = 0,
					start = 0, end = n, mid;
		scanf("%d", &target);
		while (start <= end) {
			mid = (start + end) / 2;
			if (target == arr[mid]) {
				result = 1;
				break;
			} else if (mid == start || mid == end)
				break;
			else if (target < arr[mid])
				end = mid;
			else
				start = mid;
		}
		printf("%d\n", result);
	}
	return 0;
}