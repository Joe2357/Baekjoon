#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1000000000

using namespace std;

typedef struct Vertax {
	int index;
	long long dist;
	int previous;
} VT;

struct cmp {
	bool operator()(VT a, VT b) {
		return a.dist > b.dist;
	}
};

vector<vector<long long>> matrix;
int n, e;

vector<long long> dijkstra(int start) {
	vector<long long> dist = vector<long long>(n + 1, INF);
	dist[start] = 0;
	priority_queue<VT, vector<VT>, cmp> pq;
	for (int i = 1; i <= n; i++)
		pq.push({ i, dist[i], 0 });

	// start
	while (!pq.empty()) {
		// pop a node
		VT temp = pq.top();
		pq.pop();

		if (temp.dist > dist[temp.index])
			continue;

		for (int i = 1; i <= n; i++) {
			if (dist[i] > dist[temp.index] + matrix[temp.index][i]) {
				dist[i] = dist[temp.index] + matrix[temp.index][i];
				pq.push({ i, dist[i], temp.index });
			}
		}
	}

	return dist;
}

int main() {
	// i/o init
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	// init
	cin >> n >> e;
	matrix = vector<vector<long long>>(n + 1, vector<long long>(n + 1, INF));
	for (int i = 1; i <= n; i++)
		matrix[i][i] = 0;
	for (; e; e--) {
		int a, b;
		long long c;
		cin >> a >> b >> c;
		matrix[a][b] = c, matrix[b][a] = c;
	}

	int v1, v2;
	cin >> v1 >> v2;

	// dijkstra from start
	vector<long long> dist_start = dijkstra(1);

	// dijkstra from v1
	vector<long long> dist_v1 = dijkstra(v1);

	// dijkstra from end
	vector<long long> dist_end = dijkstra(n);

	// calc result
	long long retval_1 = dist_start[v1] + dist_v1[v2] + dist_end[v2];
	long long retval_2 = dist_start[v2] + dist_v1[v2] + dist_end[v1];
	if (retval_1 >= INF && retval_2 >= INF)
		cout << -1;
	else
		cout << min(retval_1, retval_2);
	return 0;
}