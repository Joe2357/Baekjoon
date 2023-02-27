#include <stdio.h>

typedef struct Result {
	int sum;
	int x, y;
} RT;

#define MAX_IDX (int)1e5
int arr[MAX_IDX];
int n;

int cmp(int* a, int* b) {
	return *a > *b;
}

#define abs(x) (((x) < 0) ? (-(x)) : (x))

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
	}
	qsort(arr, n, sizeof(int), cmp);

#define INF (int)(2e9 + 1)
	RT ret = (RT){INF, 0, 0};

	int left = 0, right = n - 1;
	while (ret.sum > 0 && left < right) {
		int sum = arr[left] + arr[right];
		if (abs(sum) < ret.sum) {
			ret = (RT){abs(sum), arr[left], arr[right]};
		}
		if (sum < 0) {
			++left;
		}
		if (sum > 0) {
			--right;
		}
	}

	printf("%d %d", ret.x, ret.y);
	return 0;
}