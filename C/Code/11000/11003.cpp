#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
	int value;
	int index;

	Node(int x, int y) : value(x), index(y) {};
};

struct cmp {
	bool operator()(Node& a, Node& b) {
		return a.value > b.value;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, l;
	cin >> n >> l;

	priority_queue<Node, vector<Node>, cmp> pq;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		pq.push(Node(a, i));

		while (pq.top().index < i - l + 1) {
			pq.pop();
		}
		cout << pq.top().value << " ";
	}

	return 0;
}