#include <stdio.h>

#define MAX_IDX 200
#define MAX_COLOR (20 + 1)
const int INF = 987654321;

int n, k;
int arr[MAX_IDX];
int dp[MAX_IDX][MAX_IDX][MAX_COLOR];

#define min(a, b) (((a) > (b)) ? (b) : (a))

void init() {
	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < n; ++b) {
			for (int c = 1; c <= k; ++c) {
				dp[a][b][c] = INF;
			}
		}
	}

	return;
}

int solve(int s, int e, int c) {
	if (dp[s][e][c] < INF) {
		return dp[s][e][c];
	} else if (s == e) {
		return dp[s][e][c] = ((arr[s] == c) ? 0 : 1);
	} else {
		int ret = INF;
		for (int i = s; i < e; ++i) {
			int temp = ((arr[s] == c) ? 0 : 1) + ((arr[i + 1] == c) ? 0 : 1);
			ret = min(ret, solve(s, i, arr[s]) + solve(i + 1, e, arr[i + 1]) + temp);
		}
		return dp[s][e][c] = ret;
	}
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
	}

	init();

	int ret = INF;
	for (int i = 1; i <= k; ++i) {
		ret = min(ret, solve(0, n - 1, i));
	}

	printf("%d", ret);
	return 0;
}