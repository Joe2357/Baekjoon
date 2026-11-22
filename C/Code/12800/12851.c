#include <stdio.h>

typedef struct Node {
	int c;
	int p;
	int m;
} ND;
typedef struct Visited {
	int m;
	int c;
} VT;

#define M (int)(2e5 + 1)

VT dp[M + 10];
ND q[M * 10];
int n, k;
const int MI = M * 10;
const int START = M + 4;
int front = 0, rear = 1;

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < M + 10; ++i) {
		dp[i] = (VT){M + 10, 0};
	}
	dp[START] = (VT){-1, 1};

	q[0] = (ND){n, START, 0};
	while (front != rear) {
		ND a = q[front++];
		front %= MI;
		if (a.c < 0 || a.c > M) {
			continue;
		}
		int temp = dp[a.c].m;

		if (a.m <= temp) {
			dp[a.c].m = a.m;
			dp[a.c].c += dp[a.p].c;

			if (a.m < temp) {
				q[rear++] = (ND){a.c - 1, a.c, a.m + 1}, rear %= MI;
				q[rear++] = (ND){a.c + 1, a.c, a.m + 1}, rear %= MI;
				q[rear++] = (ND){a.c << 1, a.c, a.m + 1}, rear %= MI;
			}
		}
	}

	printf("%d\n%d", dp[k].m, dp[k].c);
	return 0;
}