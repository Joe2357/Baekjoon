#include <stdio.h>
#define abs(x) ((x) < 0 ? (-(x)) : (x))

#define M_I (int)1e5
#define INF (int)(1e9 + 1)

int arr[M_I];
int n;
int result[2] = { INF,INF };

int cmp(int* a, int *b) {
	return *a - *b;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
	}
	qsort(arr, n, sizeof(int), cmp);

	int left = 0, right = n - 1;
	while (left < right) {
		int sum = arr[left] + arr[right];
		if (abs(sum) < abs(result[0] + result[1])) {
			result[0] = arr[left], result[1] = arr[right];
		}

		if (sum == 0)
			break;
		else {
			left += (sum <= 0),
				right -= (sum >= 0);
		}
	}

	printf("%d %d", result[0], result[1]);
	return 0;
}