#include <stdbool.h>
#include <stdio.h>

#define MAX_IDX 16
const int INF = 987654321;

int grid[MAX_IDX][MAX_IDX];
int n;
int need_to_on;

int dp[1 << MAX_IDX];
int init_mask;
int active_cnt;

#define min(a, b) (((a) > (b)) ? (b) : (a))

void read_input() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &grid[i][j]);
		}
	}

	for (int i = 0; i < (1 << MAX_IDX); ++i) {
		dp[i] = INF;
	}

	char str[MAX_IDX + 1];
	scanf("%s", str);
	for (int i = 0; i < n; ++i) {
		if (str[i] == 'Y') {
			init_mask |= (1 << i);
			active_cnt += 1;
		}
	}
	dp[init_mask] = 0; // 시작지점

	scanf("%d", &need_to_on);
	return;
}

int solve() {
	// dp 배열 채우기
	for (int mask = 0; mask < (1 << n); ++mask) {
		if (dp[mask] == INF) {
			continue;
		}

		for (int i = 0; i < n; ++i) {
			if ((mask & (1 << i)) > 0) { // i번 발전소가 켜져있는 경우 진행 가능
				for (int j = 0; j < n; ++j) {
					if ((mask & (1 << j)) == 0) { // j번 발전소는 꺼져있을 경우, 켜는 연산을 할 수 있다
						int next_mask = (mask | (1 << j));
						dp[next_mask] = min(dp[next_mask], dp[mask] + grid[i][j]);
					}
				}
			}
		}
	}

	// 정답 도출하기
	int ret = INF;
	for (int mask = 0; mask < (1 << n); ++mask) {
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			cnt += ((mask & (1 << i)) > 0);
		}
		if (cnt >= need_to_on) {
			ret = min(ret, dp[mask]);
		}
	}
	return (ret == INF ? -1 : ret);
}

int main() {
	read_input();
	if (active_cnt >= need_to_on) {
		printf("0");
		return 0;
	}

	printf("%d", solve());
	return 0;
}