#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1975308642 // 987654321 * 2

using namespace std;
struct heapNode {
	int index, distance, previous;
	heapNode(int idx, int dis, int pre) : index(idx), distance(dis), previous(pre) {}
};
struct cmp {
	bool operator()(heapNode a, heapNode b) {
		return a.distance > b.distance;
	}
};

int main() {
	// i/o init
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// testcase init
	int T;
	cin >> T;
	for (; T; T--) {
		// init
		int n, m, t, s, g, h;
		cin >> n >> m >> t;
		cin >> s >> g >> h;

		// make matrix
		vector<vector<int>> edge(n + 1, vector<int>(n + 1, INF));
		for (; m; m--) { // edge init
			int a, b, d;
			cin >> a >> b >> d;
			edge[a][b] = 2 * d, edge[b][a] = 2 * d;
		}
		edge[g][h]--, edge[h][g]--; // target line weight -> odd number

		// target init
		vector<int> target;
		for (; t; t--) {
			int x;
			cin >> x;
			target.push_back(x);
		}
		sort(target.begin(), target.end());

		// Dijkstra init
		vector<int> arrival(n + 1, INF);
		arrival[s] = 0; // start position
		priority_queue<heapNode, vector<heapNode>, cmp> pq;
		for (int i = 1; i <= n; i++)
			// min heap init
			pq.push(heapNode(i, arrival[i], 0));

		// start algorithm
		while (!pq.empty()) {
			heapNode use = pq.top();
			pq.pop();
			if (arrival[use.index] < use.distance)
				continue;
			for (int i = 1; i <= n; i++) { // check near vertax
				if (edge[use.index][i] != INF) { // if has edge
					if (arrival[i] > arrival[use.index] + edge[use.index][i]) {
						// if has shorter way
						arrival[i] = arrival[use.index] + edge[use.index][i];
						pq.push(heapNode(i, arrival[i], use.index));
					}
				}
			}
		}

		// print result
		for (int a : target)
			if (arrival[a] % 2 == 1)
				// if passed target line
				cout << a << " ";
		cout << "\n";
	}
	return 0;
}