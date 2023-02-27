#include <stdio.h>

#define MAX_IDX 50
int arr_a[MAX_IDX];
int arr_b[MAX_IDX];

int cmp(int* a, int* b) {
	return *a > *b;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", arr_a + i);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", arr_b + i);
	}

	qsort(arr_a, n, sizeof(int), cmp);
	qsort(arr_b, n, sizeof(int), cmp);

	int s = 0;
	for (int i = 0; i < n; ++i) {
		s += (arr_a[i] * arr_b[n - i - 1]);
	}
	printf("%d", s);
	return 0;
}