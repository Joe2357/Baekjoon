#include <stdio.h>

typedef long long ll;

#define MAX_IDX 200
const ll INF = (ll)(1e18);

int n, m;
ll arr[MAX_IDX + 1][MAX_IDX + 1];
ll sum_arr[MAX_IDX + 1][MAX_IDX + 1];

void read_input() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%lld", &arr[i][j]);
			sum_arr[i][j] = sum_arr[i - 1][j] + sum_arr[i][j - 1] - sum_arr[i - 1][j - 1] + arr[i][j];
		}
	}
	return;
}

#define max(a, b) (((a) > (b)) ? (a) : (b))

int main() {
	read_input();

	ll ans = -INF;
	for (int a = 0; a <= n; ++a) {
		for (int b = 0; b <= m; ++b) {
			for (int x = 0; x < a; ++x) {
				for (int y = 0; y < b; ++y) {
					ll current = sum_arr[a][b] - sum_arr[x][b] - sum_arr[a][y] + sum_arr[x][y];
					ans = max(ans, current);
				}
			}
		}
	}
	printf("%lld", ans);
	return 0;
}