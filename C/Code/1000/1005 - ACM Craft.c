#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX (1000 + 1)

bool matrix[MAX_IDX][MAX_IDX];	// x -> y
int n, k, w;
int cost[MAX_IDX];	// cost per building
int dp[MAX_IDX];	// total cost before build target building
int deg[MAX_IDX];
int queue[MAX_IDX], front, rear;
bool visit[MAX_IDX];

#define max(a, b) (((a) > (b)) ? (a) : (b))

void reset() {
	front = rear = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			matrix[i][j] = false;
		}
	}
	for (int i = 1; i <= n; ++i) {
		deg[i] = 0;
		dp[i] = 0;
		visit[i] = false;
	}
	return;
}

void read_input() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", cost + i);
	}
	for (int i = 0; i < k; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		matrix[x][y] = true;
		++deg[y];
	}
	scanf("%d", &w);
	return;
}

// topology sort initialize
void init() {
	for (int i = 1; i <= n; ++i) {
		if (deg[i] == 0) {
			visit[i] = true;
			queue[rear++] = i;
		}
	}
	return;
}

int solve() {
	while (front < rear) {
		int x = queue[front++];
		// exit point
		if (x == w) {
			return dp[x] + cost[x];
		}

		// using topology sort
		for (int i = 1; i <= n; ++i) {
			if (matrix[x][i] == true) {
				dp[i] = max(dp[i], dp[x] + cost[x]);

				if (--deg[i] == 0 && visit[i] == false) {
					visit[i] = true;
					queue[rear++] = i;
				}
			}
		}
	}
	return 0;
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		reset();
		read_input();
		init();
		printf("%d\n", solve());
	}

	return 0;
}