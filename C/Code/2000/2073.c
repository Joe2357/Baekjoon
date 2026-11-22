#include <stdio.h>

typedef struct Pipe {
	int l, c;
} PIPE;

#define MAX_IDX 100000
#define MAX_PIPE 350
const int INF = (1 << 30);
const int NONE = 0;

PIPE pipe[MAX_PIPE];
int dp[MAX_IDX + 1];
int d, p;
int result;

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) > (b)) ? (b) : (a))

void solve() {
	dp[NONE] = INF;
	for (int i = 0; i < p; ++i) {
		for (int j = MAX_IDX; j >= pipe[i].l; --j) {
			if (dp[j - pipe[i].l] != NONE) {
				dp[j] = max(dp[j], min(dp[j - pipe[i].l], pipe[i].c));
			}
		}
	}
	return;
}

int main() {
	scanf("%d %d", &d, &p);
	for (int i = 0; i < p; ++i) {
		int l, c;
		scanf("%d %d", &l, &c);
		pipe[i] = (PIPE){l, c};
	}
	solve();
	printf("%d", dp[d]);
	return 0;
}