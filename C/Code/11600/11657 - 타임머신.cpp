#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

typedef struct Edge {
	int start, end;
	int weight;
} ED;

vector<ED> line;
vector<long long> ret;
int n, m;
bool isChanged = true;

bool Bellman_Ford() {
	bool changed = false;
	for (ED l : line) { // loop all edges
		if (ret[l.start] != INF)
			// if start was defined
			if (ret[l.end] > ret[l.start] + l.weight) { // if shorter way exists
				ret[l.end] = ret[l.start] + l.weight;
				changed = true;
			};
	}
	return changed;
}

int main() {
	// i/o init
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	// init
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		line.push_back({ a, b, c });
	}
	// start pos
	ret = vector<long long>(n + 1, INF);
	ret[1] = 0;

	// loop algorithm at most n times
	for (int i = 0; i < n && isChanged; i++)
		isChanged = Bellman_Ford();

	// print result
	if (isChanged)
		cout << -1;
	else
		for (int i = 2; i <= n; i++) {
			(ret[i] == INF) ? cout << -1 : cout << ret[i];
			cout << "\n";
		}

	return 0;
}