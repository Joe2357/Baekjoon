#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX (int)(1e6)
const int INF = 987654321;
const int UNDEFINED = 0;
const int LOSE = 1;
const int WIN = 2;
const int NONE = -1;

int dp[MAX_IDX + 1];
int n;

#define min(a, b) ((a) < (b) ? (a) : (b))

void init() {
	for (int i = 0; i < 10; ++i) {
		dp[i] = LOSE;
	}
	return;
}

int solve(int x) {
	bool canWin = false;

	int ret = INF;

	for (int i = 10; i <= x; i *= 10) {
		for (int temp = x; temp > 0; temp /= 10) {
			int new_x = x - (temp % i);

			if (new_x > 0 && new_x < x) {
				if (dp[new_x] == LOSE) {
					canWin = true;
					ret = min(ret, (temp % i));
				}
			}
		}
	}

	if (canWin == true) {
		dp[x] = WIN;
	} else {
		dp[x] = LOSE;
		ret = NONE;
	}
	return ret;
}

int main() {
	init();
	scanf("%d", &n);
	for (int i = 10; i < n; ++i) {
		int temp = solve(i);
	}
	printf("%d", solve(n));
	return 0;
}