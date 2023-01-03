#include <stdio.h>

#define bool char
const bool true = 1;
const bool false = 0;

#define MAX_IDX 1001
int n = 0, k, x, y, w;
int cost[MAX_IDX], dp[MAX_IDX], deg[MAX_IDX];
int queue[MAX_IDX], front, rear;
bool matrix[MAX_IDX + 1][MAX_IDX + 1];
bool visit[MAX_IDX + 1];

#define max(a, b) (((a) > (b)) ? (a) : (b))

void init() {
	for (int i = 0; i <= n; ++i) {
		dp[i] = -1;
		deg[i] = 0;
		visit[i] = false;
		for (int j = 0; j <= n; ++j) {
			matrix[i][j] = false;
		}
	}
	front = rear = 0;
	return;
}

void read_input() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", cost + i + 1);
	}
	int a, b;
	for (int i = 0; i < k; ++i) {
		scanf("%d %d", &a, &b);
		matrix[a][b] = true;
		++deg[b];
	}
	scanf("%d", &w);
	return;
}

int solve() {
	for (int i = 1; i <= n; ++i) {
		if (deg[i] == 0) {
			queue[rear++] = i;
			visit[i] = true;
			dp[i] = 0;
		}
	}

	while (front < rear) {
		int a = queue[front++];
		if (a == w) {
			break;
		}

		for (int i = 1; i <= n; ++i) {
			if (!visit[i] && matrix[a][i]) {
				dp[i] = max(dp[i], dp[a] + cost[a]);
				if (--deg[i] == 0) {
					queue[rear++] = i;
					visit[i] = true;
				}
			}
		}
	}
	return dp[w] + cost[w];
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		init();
		read_input();
		printf("%d\n", solve());
	}
	return 0;
}