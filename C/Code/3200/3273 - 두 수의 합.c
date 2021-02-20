#include <stdio.h>

#define M_I (int)1e5

int cmp(int* a, int* b) {
	return *a - *b;
}

int main() {
	int n;
	scanf("%d", &n);
	int arr[M_I];

	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
	}
	int target;
	scanf("%d", &target);
	qsort(arr, n, sizeof(int), cmp);

	int left = 0, right = n - 1;
	int result = 0;

	while (left < right) {
		int sum = arr[left] + arr[right];
		result += (sum == target);
		right -= (sum >= target), left += (sum <= target);
	}

	printf("%d", result);
	return 0;
}