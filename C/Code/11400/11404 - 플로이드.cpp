#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
#define MAX_COST 100001

using namespace std;

int n;
vector<vector<int>> matrix;

int main() {
	// i/o init
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	// init
	int m;
	cin >> n >> m;
	matrix = vector<vector<int>>(n + 1, vector<int>(n + 1, INF));
	// edge init
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		matrix[a][b] = min(matrix[a][b], c);
	}
	for (int i = 1; i <= n; i++)
		matrix[i][i] = 0;

	// floyd algorithm
	for (int a = 1; a <= n; a++)
		for (int b = 1; b <= n; b++)
			for (int c = 1; c <= n; c++)
				matrix[b][c] = min(matrix[b][c], matrix[b][a] + matrix[a][c]);

	// print result
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			(matrix[i][j] == INF) ? cout << 0 : cout << matrix[i][j];
			cout << " ";
		}
		cout << "\n";
	}

	return 0;
}