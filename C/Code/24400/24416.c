#include <stdio.h>

#define MAX_IDX 40

int ans[2][MAX_IDX + 1];

void init() {
	ans[0][1] = ans[0][2] = 1;
	for (int i = 3; i <= MAX_IDX; ++i) {
		ans[0][i] = ans[0][i - 2] + ans[0][i - 1];
	}

	ans[1][1] = ans[1][2] = 1;
	for (int i = 3; i <= MAX_IDX; ++i) {
		ans[1][i] = i - 2;
	}
	return;
}

int main() {
	init();

	int n;
	scanf("%d", &n);
	printf("%d %d", ans[0][n], ans[1][n]);
	return 0;
}