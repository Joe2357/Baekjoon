#include <stdio.h>

#define INF (int)1e9
#define MAX_IDX 30
#define MAX_PROB (1 << 15)

#define FRONT 0
#define BACK 1

int arr[2][MAX_PROB];
int len[2];
int package[MAX_IDX];
int n, c;
long long result;

int asc(int* a, int* b) {
	return *a > *b;
}

int upper_bound(int key) {
	int start = 0;
	int end = len[1];
	int mid;

	while (end > start) {
		mid = (end + start) >> 1;

		if (arr[1][mid] <= key) {
			start = mid + 1;
		}
		else {
			end = mid;
		}
	}

	return end + 1;
}

void knapsack(int cur, int end, int cap, int mode) {
	if (cur == end) {
		arr[mode][len[mode]++] = cap;
		return;
	}

	if (cap + package[cur] <= c) {
		knapsack(cur + 1, end, cap + package[cur], mode);
	}
	knapsack(cur + 1, end, cap, mode);

	return;
}

int main() {
	scanf("%d %d", &n, &c);
	for (int i = 0; i < n; ++i) {
		scanf("%d", package + i);
	}

	knapsack(0, n >> 1, 0, FRONT);
	knapsack(n >> 1, n, 0, BACK);

	qsort(arr[1], len[1], sizeof(int), asc);

	for (int i = 0; i < len[0]; ++i) {
		result += (upper_bound(c - arr[0][i]) - 1);
	}

	printf("%lld", result);
}