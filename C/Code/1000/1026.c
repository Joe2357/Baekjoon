#include <stdio.h>
#include <stdlib.h>

#define MAX_IDX 50

int A[MAX_IDX];
int B[MAX_IDX];
int n;

int asc(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}
int desc(const void* a, const void* b) {
	return (*(int*)b - *(int*)a);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &B[i]);
	}
	qsort(A, n, sizeof(int), asc);
	qsort(B, n, sizeof(int), desc);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += A[i] * B[i];
	}
	printf("%d\n", sum);
	return 0;
}