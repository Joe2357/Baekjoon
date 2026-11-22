#include <stdbool.h>
#include <stdio.h>

#define MAX_IDX 10000
const int NONE = -1;

typedef struct Node {
	int l, r;
	int lv, idx;
} Node;

Node tree[MAX_IDX + 1];
int root;
int n;
int max_level = NONE;

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) > (b)) ? (b) : (a))

void read_input() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int a, l, r;
		scanf("%d %d %d", &a, &l, &r);
		tree[a].l = l, tree[a].r = r;
	}
	return;
}

void find_root() {
	// root를 찾기
	bool hasParent[MAX_IDX + 1] = {false};
	for (int i = 1; i <= n; ++i) {
		hasParent[max(tree[i].l, 0)] = true, hasParent[max(tree[i].r, 0)] = true;
	}
	for (int i = 1; i <= n; ++i) {
		if (hasParent[i] == false) {
			root = i;
			break;
		}
	}
	return;
}

void update_level() {
	// 각 노드의 level 지정 (root = 1)
	int q[MAX_IDX];
	tree[root].lv = 1;
	q[0] = root;

	for (int front = 0, rear = 1; front < rear; ++front) {
		int tmp = q[front];
		max_level = max(max_level, tree[tmp].lv);

		if (tree[tmp].l != NONE) {
			tree[tree[tmp].l].lv = tree[tmp].lv + 1;
			q[rear++] = tree[tmp].l;
		}
		if (tree[tmp].r != NONE) {
			tree[tree[tmp].r].lv = tree[tmp].lv + 1;
			q[rear++] = tree[tmp].r;
		}
	}
	return;
}

void dfs(int cur, int* i) {
	if (tree[cur].l != NONE) {
		dfs(tree[cur].l, i);
	}
	tree[cur].idx = (*i)++;
	if (tree[cur].r != NONE) {
		dfs(tree[cur].r, i);
	}

	return;
}

void inorder_traversal() {
	// 트리를 중위순회하며 그 위치에 idx 부여
	int current_idx = 1;
	dfs(root, &current_idx);
	return;
}

void solve() {
	// 각 level의 왼쪽 끝과 오른쪽 끝을 탐색
	int leftmost[MAX_IDX + 1], rightmost[MAX_IDX + 1];
	for (int i = 1; i <= max_level; ++i) {
		leftmost[i] = MAX_IDX + 1;
		rightmost[i] = NONE;
	}

	for (int i = 1; i <= n; ++i) {
		leftmost[tree[i].lv] = min(leftmost[tree[i].lv], tree[i].idx);
		rightmost[tree[i].lv] = max(rightmost[tree[i].lv], tree[i].idx);
	}

	int ans = 1, len = 1; // root의 lv은 1, 그 때의 거리는 1
	for (int i = 2; i <= max_level; ++i) {
		if (rightmost[i] - leftmost[i] + 1 > len) {
			ans = i, len = rightmost[i] - leftmost[i] + 1;
		}
	}
	printf("%d %d", ans, len);
	return;
}

int main() {
	read_input();
	find_root();
	update_level();
	inorder_traversal();
	solve();
	return 0;
}