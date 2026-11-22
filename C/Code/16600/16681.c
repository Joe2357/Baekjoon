#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct Edge {
	int a, b;
	ll n;
} ED;
typedef struct Node {
	int des;
	ll dist;
	struct Node* next;
} ND;
typedef struct HeapNode {
	int idx;
	ll dist;
} HN;

#define MAX_VER 100000
const ll INF = 987654321987654321;

int height[MAX_VER + 1];
ND* grid[MAX_VER + 1];
int n, m, d, e;

ll home[MAX_VER + 1];
ll school[MAX_VER + 1];

HN heap[MAX_VER * 2 + 10];
int top;

void insertNewNode(ED edge) {
	ND* newNode = (ND*)malloc(sizeof(ND));
	newNode->des = edge.b, newNode->dist = edge.n;

	newNode->next = grid[edge.a];
	grid[edge.a] = newNode;
	return;
}

void read_input() {
	scanf("%d %d %d %d", &n, &m, &d, &e);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &height[i]);
	}
	for (int i = 0; i < m; ++i) {
		int t1, t2;
		ll t3;
		scanf("%d %d %lld", &t1, &t2, &t3);
		insertNewNode((ED){t1, t2, t3});
		insertNewNode((ED){t2, t1, t3});
	}
	return;
}

void init() {
	for (int i = 1; i <= n; ++i) {
		home[i] = INF;
		school[i] = INF;
	}
	home[1] = 0;
	school[n] = 0;
	return;
}

void pushHeap(HN node) {
	heap[++top] = node;

	int temp = top;
	while (temp > 1) {
		if (node.dist >= heap[temp >> 1].dist) {
			break;
		}

		heap[temp] = heap[temp >> 1];
		heap[temp >> 1] = node;
		temp >>= 1;
	}
	return;
}
bool isHeapEmpty() {
	return (top == 0);
}
HN popHeap() {
	HN ret = heap[1];
	heap[1] = heap[top--];

	int i = 1, tp = 2;
	while (tp < top) {
		tp += (heap[tp].dist > heap[tp + 1].dist);
		if (heap[i].dist <= heap[tp].dist) {
			break;
		}

		HN a = heap[tp];
		heap[tp] = heap[i], heap[i] = a;

		i = tp, tp *= 2;
	}
	if (tp == top && heap[i].dist > heap[tp].dist) {
		HN a = heap[tp];
		heap[tp] = heap[i], heap[i] = a;
	}

	return ret;
}

void dijkstra(ll* arr, int s) {
	for (int i = 1; i <= n; ++i) {
		pushHeap((HN){i, arr[i]});
	}

	while (isHeapEmpty() == false) {
		HN cur = popHeap();
		if (cur.dist <= arr[cur.idx]) {
			for (ND* curNode = grid[cur.idx]; curNode != NULL; curNode = curNode->next) {
				if (height[curNode->des] > height[cur.idx]) {
					if (arr[curNode->des] > cur.dist + curNode->dist) {
						arr[curNode->des] = cur.dist + curNode->dist;
						pushHeap((HN){curNode->des, arr[curNode->des]});
					}
				}
			}
		}
	}
	return;
}

#define max(a, b) (((a) > (b)) ? (a) : (b))

void solve() {
	init();
	dijkstra(home, 1);
	dijkstra(school, n);

	ll ret = -INF;
	bool isAnswerExists = false;
	for (int i = 2; i < n; ++i) {
		if (home[i] != INF && school[i] != INF) {
			isAnswerExists = true;
			ret = max(ret, ((height[i] * e) - (home[i] + school[i]) * d));
		}
	}

	// print_result()
	if (isAnswerExists == false) {
		printf("Impossible");
	} else {
		printf("%lld", ret);
	}
	return;
}

int main() {
	read_input();
	solve();
	return 0;
}