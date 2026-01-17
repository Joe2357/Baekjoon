#include <stdio.h>

#define MAX_IDX 300

int arr[MAX_IDX];
int n, m;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}

	for (scanf("%d", &m); m--;) {
		int left, right;
		scanf("%d %d", &left, &right);

		int cur = left;
		for (int i = 0; i < n; ++i) {
			printf("%d ", (arr[i] >= left && arr[i] <= right) ? cur++ : arr[i]);
		}
		printf("\n");
	}
	return 0;
}