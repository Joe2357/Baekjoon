#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int dest;
	struct Node* next;
} ND;
typedef char boolean;
#define True 1
#define False 0

#define MAX_IDX 10000
#define ROOT 1

ND* path[MAX_IDX + 1];
int n;
int weight[MAX_IDX + 1];
int res, result[MAX_IDX], len;
int dp[MAX_IDX + 1][2];

#define max(a, b) (((a) > (b)) ? (a) : (b))

int cmp(int* a, int* b) {
	return *a > *b;
}

ND* insertNewNode(int s, int x) {
	ND* newNode = (ND*)malloc(sizeof(ND));
	newNode->dest = x;
	newNode->next = path[s];
	path[s] = newNode;
	return;
}

void makeDP(int node, int parent) {
	dp[node][True] = weight[node], dp[node][False] = 0;
	int t1 = 0, t2 = 0;

	ND* cur = path[node];
	while (cur) {
		if (cur->dest != parent) {
			makeDP(cur->dest, node);
		}
		cur = cur->next;
	}

	cur = path[node];
	while (cur) {
		if (cur->dest != parent) {
			t1 += dp[cur->dest][False];
			t2 += max(dp[cur->dest][True], dp[cur->dest][False]);
		}
		cur = cur->next;
	}
	dp[node][True] += t1, dp[node][False] += t2;
	return;
}

void trace(int node, int parent, boolean mode) {
	ND* cur = path[node];
	if (mode) {
		result[len++] = node;
		int i = 0, v = 0;
		while (cur) {
			if (cur->dest != parent) {
				trace(cur->dest, node, False);
			}
			cur = cur->next;
		}
		return;
	}
	else {
		while (cur) {
			if (cur->dest != parent) {
				trace(cur->dest, node, dp[cur->dest][True] > dp[cur->dest][False]);
			}
			cur = cur->next;
		}
		return;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", weight + i);
	}

	for (int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		insertNewNode(a, b), insertNewNode(b, a);
	}

	makeDP(ROOT, 0);

	printf("%d\n", max(dp[ROOT][False], dp[ROOT][True]));

	trace(ROOT, 0, dp[ROOT][True] > dp[ROOT][False]);
	qsort(result, len, sizeof(int), cmp);

	for (int i = 0; i < len; ++i) {
		printf("%d ", result[i]);
	}
	return 0;
}