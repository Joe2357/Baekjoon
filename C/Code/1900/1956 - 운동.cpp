#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

int main()
{
	// i/o init
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	// init
	int n, k;
	cin >> n >> k;

	// matrix init
	vector<vector<int>> matrix(n + 1, vector<int>(n + 1, INF));

	// edge init
	for (; k; k--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		matrix[a][b] = c;
	}

	// floyd algorithm
	for (int a = 1; a <= n; a++)
		for (int b = 1; b <= n; b++)
			for (int c = 1; c <= n; c++)
				matrix[b][c] = min(matrix[b][c], matrix[b][a] + matrix[a][c]);

	// get result
	int retval = INF;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			retval = min(retval, matrix[i][j] + matrix[j][i]);

	// print result
	retval = (retval == INF) ? -1 : retval;
	cout << retval;

	return 0;
}