#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> matrix;
int n;

void dfs(int idx) {

	for (int i = 0; i < n; i++) { // check all vertaxs
		if (matrix[idx][i] > 0) { // if there is an edge

			// remove one edge
			matrix[idx][i]--, matrix[i][idx]--;
			dfs(i);
		}
	}

	// if no edges left
	cout << idx + 1 << " ";
	return;
}

int main() {
	// i/o init
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	// init
	cin >> n;
	vector<int> line(n, 0);
	matrix = vector<vector<int>>(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
			line[i] += matrix[i][j];
		}

	// find start position
	// check whether there is odd-edge vertax
	for (int i = 0; i < n; i++)
		if (line[i] % 2 != 0) {
			cout << -1;
			return 0;
		}

	// start from 1 using dfs
	dfs(0);

	return 0;
}