#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 10
const int NONE = -1;
const int WALL = 'x';

int dp[MAX_IDX + 1][1 << MAX_IDX];
char grid[MAX_IDX][MAX_IDX + 1];

int n, m;

#define max(a, b) (((a) > (b)) ? (a) : (b))

void init() {
	for (int i = 0; i < MAX_IDX; ++i) {
		for (int j = 0; j < (1 << MAX_IDX); ++j) {
			dp[i][j] = NONE;
		}
	}
	return;
}

bool isValid(int line, int pos, int prev) {
	bool retval = true;

	for (int i = 0; i < m; ++i) {
		if ((pos & (1 << i)) == 0) {
			continue;
		} else {
			// broken position check
			retval &= (grid[line][i] != WALL);

			// other person check
			if (i > 0) {
				retval &= ((prev & (1 << (i - 1))) == 0); // (-1, -1)
			}
			if (i < (m - 1)) {
				retval &= ((prev & (1 << (i + 1))) == 0); // (-1, 1)
			}
			if (i > 0) {
				retval &= ((pos & (1 << (i - 1))) == 0); // (0, -1)
			}
			if (i < (m - 1)) {
				retval &= ((pos & (1 << (i + 1))) == 0); // (0, 1)
			}
		}
	}

	return retval;
}

int cnt(int x) {
	int ret = 0;

	for (int i = 0; i < m; ++i) {
		if ((x & (1 << i)) > 0) {
			++ret;
		}
	}

	return ret;
}

int solve(int x, int y) {
	if (x == n) {
		return 0;
	} else if (dp[x][y] != NONE) {
		return dp[x][y];
	}

	// printf("a : %d %d\n", x, y);

	int ret = 0;
	for (int i = 0; i < (1 << m); ++i) {
		if (isValid(x, i, y) == true) {
			// printf("isValid(%d, %d, %d) : true\n", x, i, y);
			ret = max(ret, cnt(i) + solve(x + 1, i));
		}
	}

	// printf("solve %d %d : %d\n", x, y, ret);
	return dp[x][y] = ret;
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		init();
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i) {
			scanf("%s", grid[i]);
		}

		printf("%d\n", solve(0, 0));
	}
	return 0;
}