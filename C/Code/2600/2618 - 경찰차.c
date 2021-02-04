#include <stdio.h>
#define abs(x) (((x) < 0) ? -(x) : (x))
#define min(a, b) (((a) > (b)) ? (b) : (a))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define MAX_INDEX 1000

typedef struct Position {
	int x, y;
} PO;

typedef struct Node {
	int value;
	int a, b;
} ND;

int Manhattan(PO p1, PO p2) {
	return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

ND dp[MAX_INDEX + 1][MAX_INDEX + 1];
PO Case[MAX_INDEX + 1];
int n, t;

void init(int x) {
	for (int i = 0; i <= x; ++i)
		for (int j = 0; j <= x; ++j)
			dp[i][j].value = -1;
	return;
}

PO returnCase(int x, int mode) {
	if (x == 0) {
		if (mode == 0) {
			return (PO) { 1, 1 };
		}
		else {
			return (PO) { n, n };
		}
	}
	else return Case[x];
}

int solve(int a, int b) {
	if (a == t || b == t) {
		return 0;
	}
	else if (dp[a][b].value != -1) {
		return dp[a][b].value;
	}

	int next = max(a, b) + 1;

	int v1 = solve(next, b) + Manhattan(returnCase(a, 0), Case[next]);
	int v2 = solve(a, next) + Manhattan(returnCase(b, 1), Case[next]);

	if (v1 <= v2) {
		dp[a][b] = (ND) { v1, next, b };
	}
	else {
		dp[a][b] = (ND) { v2, a, next };
	}

	return dp[a][b].value;
}

int main() {
	scanf("%d %d", &n, &t);
	init(t);

	int a, b;
	for (int i = 1; i <= t; ++i) {
		scanf("%d %d", &a, &b);
		Case[i] = (PO) { a, b };
	}

	printf("%d\n", solve(0, 0));
	a = 0, b = 0;
	for (int i = 0; i < t; ++i) {
		int x = a, y = b;
		a = dp[x][y].a, b = dp[x][y].b;
		printf("%d\n", (b > a) + 1);
	}

	return 0;
}