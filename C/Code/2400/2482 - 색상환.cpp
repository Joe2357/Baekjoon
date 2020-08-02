#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000003

using namespace std;
vector<vector<int>> dp;

int dc(int color, int used) {

	// exception
	if (dp[color][used] != -1)
		return dp[color][used];
	else if (color / used < 2)
		return 0;

	// dp line
	dp[color][used] = (dc(color - 2, used - 1) + dc(color - 1, used)) % MOD;

	return dp[color][used];
}

int main() {
	// i/o init
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	// init
	int n, k;
	cin >> n >> k;
	dp = vector<vector<int>>(n + 1, vector<int>(k + 1, -1));

	// exception
	if (n / k < 2) {
		cout << 0;
		return 0;
	}

	// dp init
	for (int i = 0; i <= k; i++)
		dp[0][i] = 0;
	for (int i = 0; i <= n; i++)
		dp[i][0] = 1;
	dp[1][1] = 1;
	for (int i = 1; i <= k; i++)
		dp[i * 2][i] = 2;

	// print result
	cout << dc(n, k);

	return 0;
}