#include <stdio.h>

#define MAX_IDX 100

int arr[MAX_IDX][MAX_IDX];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				int a;
				scanf("%d", &a);
				arr[j][k] += a;
			}
		}
	}

	for (int j = 0; j < n; j++) {
		for (int k = 0; k < m; k++) {
			printf("%d ", arr[j][k]);
		}
		printf("\n");
	}
	return 0;
}