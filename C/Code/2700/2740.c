#include <stdio.h>

#define MAX_IDX 100

int A[MAX_IDX][MAX_IDX];
int B[MAX_IDX][MAX_IDX];
int C[MAX_IDX][MAX_IDX];
int n, m, k;

void read_input() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &A[i][j]);
		}
	}
	scanf("%d %d", &m, &k);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < k; ++j) {
			scanf("%d", &B[i][j]);
		}
	}
	return;
}

void matrix_multiply() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			C[i][j] = 0;
			for (int x = 0; x < m; ++x) {
				C[i][j] += A[i][x] * B[x][j];
			}
		}
	}
	return;
}

void print_matrix() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}
	return;
}

int main() {
	read_input();
	matrix_multiply();
	print_matrix();
	return 0;
}