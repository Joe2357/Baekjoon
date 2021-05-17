#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int dest;
	struct Node *next;
} Node;

#define MAX_IDX (int)1e5

Node *matrix[MAX_IDX + 1];
int dp[MAX_IDX + 1];
int n, start, q;

Node *createNewNode(int x) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->dest = x;
	newNode->next = NULL;
	return newNode;
}

void insertNewNode(int s, int x) {
	Node *newNode = createNewNode(x);
	newNode->next = matrix[s];
	matrix[s] = newNode;
	return;
}

int makeTree(int s, int p) {
	dp[s] = 1;
	Node *cur = matrix[s];

	while (cur) {
		if (cur->dest != p) {
			dp[s] += makeTree(cur->dest, s);
		}
		cur = cur->next;
	}
	return dp[s];
}

int main() {
	scanf("%d %d %d", &n, &start, &q);
	for (int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		insertNewNode(a, b), insertNewNode(b, a);
	}

	dp[start] = makeTree(start, -1);

	while (q--) {
		int a;
		scanf("%d", &a);
		printf("%d\n", dp[a]);
	}

	return 0;
}