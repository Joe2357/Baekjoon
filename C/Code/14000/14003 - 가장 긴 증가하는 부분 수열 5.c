#include <stdio.h>

#define MAX_LEN (int)1e6

int arr[2][MAX_LEN];
int lis[MAX_LEN];
int n, len;
int last;

int lower_bound(int x) {
	int start = 0, end = len;
	int mid;

	while (end > start) {
		mid = (start + end) >> 1;

		if (lis[mid] < x) {
			start = mid + 1;
		}
		else {
			end = mid;
		}
	}

	return end;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[0][i]);
	}

	lis[0] = arr[0][0];
	arr[1][0] = ++len;

	for (int i = 1; i < n; ++i) {
		if (arr[0][i] > lis[len - 1]) {
			lis[len++] = arr[0][i];
			arr[1][i] = len;
			last = i;
		}
		else {
			int x = lower_bound(arr[0][i]);
			lis[x] = arr[0][i];
			arr[1][i] = x + 1;
		}
	}

	printf("%d\n", arr[1][last]);
	for (int i = last, j = len; j > 0; --i) {
		if (arr[1][i] == j) {
			lis[--j] = arr[0][i];
		}
	}
	for (int i = 0; i < len; ++i) {
		printf("%d ", lis[i]);
	}

	return 0;
}