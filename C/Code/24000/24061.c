#include <stdio.h>

#define MAX_IDX (int)(5e5)

int arr[MAX_IDX + 1], temp[MAX_IDX + 1];
int n, k;

void read_input() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &arr[i]);
	}
	return;
}

void merge_array(int p, int q, int r) {
	int i = p, j = q + 1, t = 1;
	while (i <= q && j <= r) {
		if (arr[i] <= arr[j]) {
			temp[t++] = arr[i++];
		} else {
			temp[t++] = arr[j++];
		}
	}

	while (i <= q) {
		temp[t++] = arr[i++];
	}
	while (j <= r) {
		temp[t++] = arr[j++];
	}

	i = p, t = 1;
	while (i <= r) {
		arr[i++] = temp[t++];
		if (--k == 0) {
			for (int x = 1; x <= n; ++x) {
				printf("%d ", arr[x]);
			}
			break;
		}
	}
	return;
}

void merge_sort(int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(p, q);
		merge_sort(q + 1, r);
		merge_array(p, q, r);
	}
	return;
}

int main() {
	read_input();
	merge_sort(1, n);

	if (k > 0) {
		printf("-1");
	}
	return 0;
}