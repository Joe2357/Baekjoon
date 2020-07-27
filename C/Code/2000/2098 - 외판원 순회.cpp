#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
#define START 0

using namespace std;

int n, complete;
vector<vector<int>> matrix;
vector<vector<int>> dp;

int TSP(int pos, int visited) {
	// search complete
	if (visited == complete)
		if (matrix[pos][START] == 0)
			// no way
			return INF;
		else // has way
			return matrix[pos][START];

	// not complete
	if (dp[pos][visited] > 0)
		// already memorized
		return dp[pos][visited];

	// loop dp
	int temp = INF;
	for (int i = 1; i < n; i++)
		// loop all city except start ( 0 )
		if ((visited & (1 << i)) == 0)
			// not visited yet
			if (matrix[pos][i] != 0)
				// has a path to go
				temp = min(temp, TSP(i, (visited | (1 << i))) + matrix[pos][i]);

	// save to dp array
	dp[pos][visited] = temp;
	return temp;
}

int main() {
	// i/o init
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	// init
	cin >> n;
	complete = (1 << n) - 1;

	// matrix init
	matrix = vector<vector<int>>(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> matrix[i][j];

	// dp init
	dp = vector<vector<int>>(n, vector<int>(1 << n, 0));

	// print result
	cout << TSP(START, 1);
	return 0;
}