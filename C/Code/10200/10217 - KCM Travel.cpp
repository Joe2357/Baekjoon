#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
#define MAX_INDEX 100
#define MAX_MONEY 10000

using namespace std;
class Node {
public:
	int pos, money, dist;
	Node(int a, int b, int c) {
		pos = a, money = b, dist = c;
	}
};

vector<vector<Node>> matrix;
int dp[MAX_INDEX + 1][MAX_MONEY + 1];

int dijkstra(int n, int m) {
	// init
	queue<Node> q;
	q.push(Node(1, 0, 0));
	fill(&dp[1][0], &dp[n][m + 1], INF);
	dp[1][0] = 0;

	// start dijkstra
	while (!q.empty()) {
		Node node = q.front();
		q.pop();

		if (node.dist <= dp[node.pos][node.money]) {
			for (Node a : matrix[node.pos]) {
				a.money += node.money, a.dist += node.dist;

				// check available
				if (a.money <= m && a.dist < dp[a.pos][a.money]) { // why don't change all values from a.money to m?
					dp[a.pos][a.money] = a.dist;
					q.push(a);
				}
			}
		}
	}

	// get result
	int retval = INF;
	for (int i = 0; i <= m; i++)
		retval = min(retval, dp[n][i]);

	// no way to get there
	return retval;
}

int main() {
	// i/o init
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	// loop testcase
	int n, m, t;
	for (cin >> t; t; t--) {
		// init
		int k;
		cin >> n >> m >> k;

		// ticket init
		matrix = vector<vector<Node>>(n + 1);
		for (; k; k--) {
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			matrix[a].push_back(Node(b, c, d));
		}

		// start algorithm
		int retval = dijkstra(n, m);

		// print result
		(retval == INF) ? cout << "Poor KCM" : cout << retval;
		cout << "\n";
	}

	return 0;
}