#include <stdio.h>

typedef struct Node {
	int left;
	int right;
} ND;

#define MAX_LEN (int)1e4
#define MAX_VAL (int)1e6

int arr[MAX_LEN];
int n;
int root;
ND tree[MAX_VAL + 1];

int makeTree(int s, int e) {
	if (s == e) {
		return 0;
	}
	else if (s + 1 == e) {
		return arr[s];
	}
	else {
		int r = arr[s];
		int t;
		for (t = s + 1; t < e; ++t) {
			if (arr[t] > r)
				break;
		}

		tree[r] = (ND) { makeTree(s + 1, t), makeTree(t, e) };
		return r;
	}
}

void postorder(int x) {
	if (x != 0) {
		postorder(tree[x].left);
		postorder(tree[x].right);
		printf("%d\n", x);
	}
	return;
}

int main() {
	n = 0;
	int temp;
	while (~scanf("%d", &temp)) {
		arr[n++] = temp;
	}

	root = makeTree(0, n);
	postorder(root);
	return 0;
}