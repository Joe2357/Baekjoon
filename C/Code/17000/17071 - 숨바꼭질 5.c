#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct QueueNode {
	int x;
	int cnt;
} QN;

#define INF 987654321
#define MAX_IDX (500000 + 1)

int n, k;
int target[2][MAX_IDX];
int dp[2][MAX_IDX];

QN q[MAX_IDX * 6 + 1];
int f, r;

int result = INF;

#define min(a, b) (((a) > (b)) ? (b) : (a))

void init() {
	for (int i = 0; i < MAX_IDX; ++i) {
		for (int j = 0; j < 2; ++j) {
			dp[j][i] = INF;
			target[j][i] = INF;
		}
	}
	return;
}

bool canBeReach(int a, int b) {
	return ((target[a][b] < INF) && (target[a][b] >= dp[a][b]) &&
			((target[a][b] - dp[a][b]) % 2 == 0));
}

int main() {
	init();
	scanf("%d %d", &n, &k);

	int temp = k;
	for (int i = 0; temp + i < MAX_IDX; ++i) {
		target[i % 2][temp = (temp + i)] = i;
	}

	q[r++] = (QN){n, 0};
	while (f < r) {
		QN node = q[f++];

		if (dp[node.cnt % 2][node.x] < INF) {
			continue;
		}
		dp[node.cnt % 2][node.x] = node.cnt;

		int x = node.x, cnt = node.cnt;
		if (canBeReach(cnt % 2, x) == true) {
			result = min(result, target[cnt % 2][x]);
			continue;
		}

		if (x > 1) {
			q[r++] = (QN){x - 1, cnt + 1};
		}
		if (x < MAX_IDX - 1) {
			q[r++] = (QN){x + 1, cnt + 1};
		}
		if (x * 2 < MAX_IDX) {
			q[r++] = (QN){x * 2, cnt + 1};
		}
	}

	printf("%d", ((result == INF) ? -1 : result));
	return 0;
}