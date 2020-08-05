#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2147483648

using namespace std;

typedef struct Matrix {
	int n, m;
	long long cost;
} MT;

int main() {
	// i/o init
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	// init
	int n;
	cin >> n;
	vector<vector<MT>> dp(n + 1, vector<MT>(n + 1, { 0, 0, INF }));

	// input & dp
	for (int i = 1; i <= n; i++) {
		// input
		cin >> dp[i][i].n >> dp[i][i].m;
		dp[i][i].cost = 0;

		// dp
		for (int j = i - 1; j > 0; j--) {
			dp[j][i] = { dp[j][j].n, dp[i][i].m, INF };
			for (int k = i - 1; k >= j; k--)
				dp[j][i].cost = min(dp[j][i].cost, dp[j][k].cost + dp[k + 1][i].cost + dp[j][k].n * dp[k + 1][i].n * dp[k + 1][i].m);
		}
	}

	// print result
	cout << dp[1][n].cost;

	return 0;
}