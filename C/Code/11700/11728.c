#include <stdio.h>

#define MAX_IDX (int)(1e6)

int A[MAX_IDX], n;
int B[MAX_IDX], m;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &B[i]);
	}

	int i, j;
	for (i = 0, j = 0; i < n && j < m;) {
		if (A[i] < B[j]) {
			printf("%d ", A[i++]);
		} else {
			printf("%d ", B[j++]);
		}
	}
	for (; i < n; ++i) {
		printf("%d ", A[i]);
	}
	for (; j < m; ++j) {
		printf("%d ", B[j]);
	}
	return 0;
}