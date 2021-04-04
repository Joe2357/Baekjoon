#include <stdio.h>

typedef struct Node {
	int left;
	int right;
} ND;

#define MAX_LEN (int)1e5

int n;
int inord[MAX_LEN];
int postord[MAX_LEN];
ND tree[MAX_LEN + 1];
int root;

int makeTree(int is, int ie, int ps, int pe) {
	//printf("a : %d %d %d %d\n", is, ie, ps, pe);
	if (is == ie || ps == pe) {
		return 0;
	}
	else if (ps + 1 >= pe) {
		return postord[ps];
	}
	else {
		int r = postord[pe - 1];
		int ts = is;
		for (; inord[ts] != r; ++ts);
		tree[r] = (ND) { makeTree(is, ts, ps, ps + (ts - is)), makeTree(ts + 1, ie, ps + (ts - is), pe - 1) };
		//printf("tree[%d] = %d %d\n", r, tree[r].left, tree[r].right);
		return r;
	}
}

void preorder(int x) {
	if (x != 0) {
		printf("%d ", x);
		preorder(tree[x].left);
		preorder(tree[x].right);
	}
	return;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", inord + i);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", postord + i);
	}

	root = makeTree(0, n, 0, n);

	preorder(root);
	return 0;
}