#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int x;
	struct Node* next;
} ND;

#define MAX_IDX (int)(1e5 + 1)
#define NONE 0

ND* tree[MAX_IDX];
int dp[MAX_IDX];
int n, root, q;

ND* createNewNode(int x) {
	ND* newNode = (ND*)malloc(sizeof(ND));
	newNode->x = x;
	newNode->next = NULL;
	return newNode;
}

void makePath(int a, int b) {
	ND* newNode = createNewNode(b);
	newNode->next = tree[a];
	tree[a] = newNode;
	return;
}

int getDP(int x, int parent) {
	ND* cur = tree[x];
	if (cur == NULL) {
		return (dp[x] = 1);
	}

	int retval = 1;
	while (cur != NULL) {
		if (cur->x != parent) {
			retval += getDP(cur->x, x);
		}
		cur = cur->next;
	}
	return dp[x] = retval;
}

int main() {
	scanf("%d %d %d", &n, &root, &q);
	for (int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		makePath(a, b);
		makePath(b, a);
	}

	getDP(root, NONE);

	for (int i = 0; i < q; ++i) {
		int a;
		scanf("%d", &a);
		printf("%d\n", dp[a]);
	}
	return 0;
}