#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedListNode {
	int idx;
	struct LinkedListNode* next;
} LN;
typedef struct QueueNode {
	int idx;
	int elapsed_time;
} QN;

#define MAX_IDX 10000

LN* grid[MAX_IDX + 1];
int cost[MAX_IDX + 1];
int deg[MAX_IDX + 1];
int dp[MAX_IDX + 1];
int n;

#define max(a, b) (((a) > (b)) ? (a) : (b))

void insertNode(int idx, int prev) {
	LN* newNode = (LN*)malloc(sizeof(LN));
	newNode->idx = idx;
	newNode->next = grid[prev], grid[prev] = newNode;
	return;
}

void read_input() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &cost[i], &deg[i]);
		for (int j = 0; j < deg[i]; ++j) {
			int x;
			scanf("%d", &x);
			insertNode(i, x);
		}
	}
	return;
}

int solve() {
	QN q[MAX_IDX + 1];
	int front = 0, rear = 0;

	for (int i = 1; i <= n; ++i) {
		if (deg[i] == 0) {
			q[rear++] = (QN){i, 0};
		}
	}

	int ret = 0;
	while (front < rear) {
		QN node = q[front++];
		int complete_time = dp[node.idx] + cost[node.idx];
		ret = max(ret, complete_time);

		for (LN* cur = grid[node.idx]; cur != NULL; cur = cur->next) {
			dp[cur->idx] = max(dp[cur->idx], complete_time);
			if (--deg[cur->idx] == 0) {
				q[rear++] = (QN){cur->idx, dp[cur->idx]};
			}
		}
	}

	return ret;
}

int main() {
	read_input();
	printf("%d", solve());
	return 0;
}