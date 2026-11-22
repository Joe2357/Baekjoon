#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;
typedef long long ll;

#define MAX_SIZE 8
const int MOD = (int)(1e9 + 7);

int orig[MAX_SIZE][MAX_SIZE];
int ret[MAX_SIZE][MAX_SIZE];

void init() {
	orig[0][1] = orig[0][2] = 1;
	orig[1][0] = orig[1][2] = orig[1][3] = 1;
	orig[2][0] = orig[2][1] = orig[2][3] = orig[2][4] = 1;
	orig[3][1] = orig[3][2] = orig[3][4] = orig[3][5] = 1;
	orig[4][2] = orig[4][3] = orig[4][5] = orig[4][6] = 1;
	orig[5][3] = orig[5][4] = orig[5][7] = 1;
	orig[6][4] = orig[6][7] = 1;
	orig[7][5] = orig[7][6] = 1;
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
	init();
	int d;
	scanf("%d", &d);
	power_matrix(d);
	printf("%d", ret[0][0]);
	return 0;
}