#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct HeapNode {
	int value;
	int index;
	HeapNode(int a, int b) : value(a), index(b) {

	}
} HN;

struct cmp {
	bool operator()(HN a, HN b) {
		return a.value > b.value;
	}
};

int main() {
	// i/o init
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	// init
	int n, k;
	cin >> n >> k;

	// min heap
	priority_queue<HN, vector<HN>, cmp> heap;

	// loop number
	for (int i = 0; i < n; i++) {
		// push to heap
		int temp;
		cin >> temp;
		heap.push({ temp, i + 1 });

		// check the smallest value is valid
		HN node = heap.top();
		while (node.index <= i - k + 1) {
			heap.pop();
			node = heap.top();
		}

		// print result
		cout << node.value << " ";
	}

	return 0;
}