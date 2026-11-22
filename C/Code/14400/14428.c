#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_IDX (int)(1e5)
const int INF = (int)(1e9 + 1);

typedef struct SegmentTreeNode {
	int idx;
	int v;
} Node;

int arr[MAX_IDX];
int n, m;

Node segtree[MAX_IDX * 4];

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) > (b)) ? (b) : (a))

Node make_segmentTree(int node, int left, int right) {
	if (left == right) {
		return segtree[node] = (Node){left, arr[left]};
	} else {
		int mid = (left + right) / 2;
		Node leftNode = make_segmentTree(node * 2, left, mid);
		Node rightNode = make_segmentTree(node * 2 + 1, mid + 1, right);

		if (leftNode.v > rightNode.v) {
			return segtree[node] = rightNode;
		} else {
			return segtree[node] = leftNode;
		}
	}
}

Node update(int node, int left, int right, int idx, int v) {
	if (idx < left || idx > right) { // 현재 노드에 해당 없음
		return segtree[node];
	} else if (left == right) { // 리프노드에 도착
		return segtree[node] = (Node){idx, v};
	}

	// 하위 노드 탐색
	int mid = (left + right) / 2;
	Node leftNode = update(node * 2, left, mid, idx, v);
	Node rightNode = update(node * 2 + 1, mid + 1, right, idx, v);

	if (leftNode.v > rightNode.v) {
		return segtree[node] = rightNode;
	} else {
		return segtree[node] = leftNode;
	}
}

Node query(int node, int left, int right, int ql, int qr) {
	if (ql > right || qr < left) { // 없는 노드. 답이 될 수 없는 값으로 반환
		return (Node){-1, INF};
	} else if (ql <= left && right <= qr) { // 범위에 모두 포함되므로, 모든 노드 반환
		return segtree[node];
	} else { // 어느 정도 걸친 경우이므로, 해당되는 노드만 반환하도록 조정
		int mid = (left + right) / 2;
		Node leftNode = query(node * 2, left, mid, ql, qr);
		Node rightNode = query(node * 2 + 1, mid + 1, right, ql, qr);

		if (leftNode.v > rightNode.v) {
			return rightNode;
		} else {
			return leftNode;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
	}
	make_segmentTree(1, 0, n - 1);

	scanf("%d", &m);
	while (m--) {
		int op, a, b;
		scanf("%d %d %d", &op, &a, &b);
		switch (op) {
			case 1: {
				arr[a - 1] = b;
				update(1, 0, n - 1, a - 1, b);
				break;
			}
			case 2: {
				printf("%d\n", query(1, 0, n - 1, a - 1, b - 1).idx + 1);
				break;
			}
		}
	}
	return 0;
}