#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;
typedef long long ll;

#define MAX_SIZE 50
const int MOD = (int)(1e9 + 7);

int orig[MAX_SIZE][MAX_SIZE];
int ret[MAX_SIZE][MAX_SIZE];
int n, m, d;

void read_input() {
	scanf("%d %d", &n, &m);
	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		orig[a - 1][b - 1] = orig[b - 1][a - 1] = 1;
	}
	scanf("%d", &d);
	return;
}

void multiply(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE]) {
	ll temp[MAX_SIZE][MAX_SIZE] = {0};

	for (int i = 0; i < MAX_SIZE; ++i) {
		for (int k = 0; k < MAX_SIZE; ++k) {
			for (int j = 0; j < MAX_SIZE; ++j) {
				temp[i][j] = (temp[i][j] + (ll)A[i][k] * B[k][j]) % MOD;
			}
		}
	}

	for (int i = 0; i < MAX_SIZE; ++i) {
		for (int j = 0; j < MAX_SIZE; ++j) {
			A[i][j] = (int)temp[i][j];
		}
	}
	return;
}

void power_matrix(int x) {
	// 단위행렬로 초기화
	for (int i = 0; i < MAX_SIZE; ++i) {
		for (int j = 0; j < MAX_SIZE; ++j) {
			ret[i][j] = ((i == j) ? 1 : 0);
		}
	}

	// orig를 base에 복사하여 원본 보존
	int base[MAX_SIZE][MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; ++i) {
		for (int j = 0; j < MAX_SIZE; ++j) {
			base[i][j] = orig[i][j];
		}
	}

	// 분할정복을 이용한 거듭제곱
	while (x > 0) {
		if (x % 2 == 1) {
			multiply(ret, base);
		}
		multiply(base, base);
		x /= 2;
	}
	return;
}

int main() {
	read_input();
	// init();
	power_matrix(d);
	printf("%d", ret[0][0]);
	return 0;
}