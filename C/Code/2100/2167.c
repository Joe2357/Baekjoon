#include <stdio.h>

typedef long long ll;

#define MAX_IDX 300

int arr[MAX_IDX + 1][MAX_IDX + 1];
ll cumulative_sum[MAX_IDX + 1][MAX_IDX + 1];
int n, m, k;

void read_input() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &arr[i][j]);
		}
	}
	return;
}

void init() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cumulative_sum[i][j] = cumulative_sum[i - 1][j];
			cumulative_sum[i][j] += cumulative_sum[i][j - 1];
			cumulative_sum[i][j] -= cumulative_sum[i - 1][j - 1];
			cumulative_sum[i][j] += arr[i][j];
		}
	}
	return;
}

void query() {
	int i, j, x, y;
	scanf("%d %d %d %d", &i, &j, &x, &y);

	ll ret = 0LL;
	ret += cumulative_sum[x][y];
	ret -= cumulative_sum[i - 1][y];
	ret -= cumulative_sum[x][j - 1];
	ret += cumulative_sum[i - 1][j - 1];
	printf("%lld\n", ret);

	return;
}

int main() {
	read_input();
	init();

	scanf("%d", &k);
	while (k--) {
		query();
	}
	return 0;
}