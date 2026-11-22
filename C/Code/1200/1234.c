#include <stdio.h>

typedef long long ll;

#define MAX_LEVEL 10
#define MAX_DECORATIONS 100
const int RED = 0, GREEN = 1, BLUE = 2;
const ll NONE = -1LL;

ll dp[MAX_LEVEL + 1][MAX_DECORATIONS + 1][MAX_DECORATIONS + 1][MAX_DECORATIONS + 1];
int n;
int r, g, b;

void init() {
	for (int i = 0; i <= MAX_LEVEL; ++i) {
		for (int j = 0; j <= MAX_DECORATIONS; ++j) {
			for (int k = 0; k <= MAX_DECORATIONS; ++k) {
				for (int l = 0; l <= MAX_DECORATIONS; ++l) {
					dp[i][j][k][l] = NONE;
				}
			}
		}
	}
	return;
}

ll getCombination(int n, int k) {
	if (k > n) {
		return 0;
	} else if (k == 0 || k == n) {
		return 1;
	} else if (k == 1 || k == n - 1) {
		return n;
	}

	ll res = 1LL;
	for (int i = 0; i < k; ++i) {
		res = res * (n - i) / (i + 1);
	}
	return res;
}

ll solve(int cur_level, int red, int green, int blue) {
	if (cur_level == n) {
		return 1;
	} else if (dp[cur_level][red][green][blue] != NONE) {
		return dp[cur_level][red][green][blue];
	}

	ll ways = 0LL;
	int next = cur_level + 1;

	// one color
	if (next % 1 == 0) {
		if (red >= next) {
			ways += solve(next, red - next, green, blue);
		}
		if (green >= next) {
			ways += solve(next, red, green - next, blue);
		}
		if (blue >= next) {
			ways += solve(next, red, green, blue - next);
		}
	}

	// two colors
	if (next % 2 == 0) {
		int half = next / 2;
		if (red >= half && green >= half) {
			ways += (getCombination(next, half) * solve(next, red - half, green - half, blue));
		}
		if (red >= half && blue >= half) {
			ways += (getCombination(next, half) * solve(next, red - half, green, blue - half));
		}
		if (green >= half && blue >= half) {
			ways += (getCombination(next, half) * solve(next, red, green - half, blue - half));
		}
	}

	// three colors
	if (next % 3 == 0) {
		int third = next / 3;
		if (red >= third && green >= third && blue >= third) {
			ways += (getCombination(next, third) * getCombination(next - third, third) * solve(next, red - third, green - third, blue - third));
		}
	}

	dp[cur_level][red][green][blue] = ways;
	return ways;
}

int main() {
	init();
	scanf("%d %d %d %d", &n, &r, &g, &b);
	printf("%lld", solve(0, r, g, b));
	return 0;
}