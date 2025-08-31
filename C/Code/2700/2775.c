#include <stdio.h>

#define MAX_IDX 15

int person[MAX_IDX][MAX_IDX];

void init() {
	// 0층 i호에는 i명이 산다
	for (int i = 1; i < MAX_IDX; ++i) {
		person[0][i] = i;
	}

	// a층 b호는 (a-1)층 1호부터 b호까지의 사람 수의 합과 같다
	// 다르게 쓰면, p(a, b) = p(a, b-1) + p(a-1, b)
	for (int i = 1; i < MAX_IDX; ++i) {
		for (int j = 1; j < MAX_IDX; ++j) {
			person[i][j] = person[i - 1][j] + person[i][j - 1];
		}
	}

	return;
}

int main() {
	init();

	int t;
	scanf("%d", &t);

	while (t--) {
		int k, n;
		scanf("%d %d", &k, &n);

		printf("%d\n", person[k][n]);
	}
	return 0;
}