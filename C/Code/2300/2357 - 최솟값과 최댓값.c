#include <stdio.h>

#define MAX_IDX (int)1e5
#define ROOT 1
#define INF (int)2e9

typedef struct Node {
	int minV, maxV;
} ND;

int arr[MAX_IDX];
ND tree[MAX_IDX * 4];
int n, m;

#define min(a, b) (((a) > (b)) ? (b) : (a))
#define max(a, b) (((a) > (b)) ? (a) : (b))
void makeTree(int node, int left, int right) {
	if (left == right) {
		tree[node] = (ND) { arr[left], arr[left] };
	}
	else {
		int mid = (left + right) >> 1;
		int l = node << 1, r = l + 1;
		makeTree(l, left, mid);
		makeTree(r, mid + 1, right);

		tree[node] = (ND) {
			min(tree[l].minV, tree[r].minV),
				max(tree[l].maxV, tree[r].maxV)
		};
	}
	return;
}

ND check(int node, int nl, int nr, int left, int right) {
	if (left > nr || right < nl) {
		return (ND) { INF, -INF };
	}
	else if (left <= nl && nr <= right) {
		return tree[node];
	}
	else {
		int mid = (nl + nr) >> 1;
		int l = node << 1, r = l + 1;

		ND leftNode = check(l, nl, mid, left, right),
			rightNode = check(r, mid + 1, nr, left, right);
		return (ND) {
			min(leftNode.minV, rightNode.minV),
				max(leftNode.maxV, rightNode.maxV)
		};
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
	}

	makeTree(ROOT, 0, n - 1);

	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		ND c = check(ROOT, 0, n - 1, a - 1, b - 1);
		printf("%d %d\n", c.minV, c.maxV);
	}

	return 0;
}