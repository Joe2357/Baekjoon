#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_IDX 1000

int n;
int cards[MAX_IDX + 1];
int dp[MAX_IDX + 1][MAX_IDX + 1]; // dp[l][r] := [l, r] 까지의 카드 덱에서 근우가 얻을 수 있는 점수의 최댓값

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int solve(int left, int right, bool turn) {
	if (left == right) {
		if (turn == true) {
			return cards[left];
		} else {
			return 0;
		}
	}

	if (dp[left][right] != -1) {
		return dp[left][right];
	}

	int result;
	if (turn == true) {
		// 근우 차례: 왼쪽 또는 오른쪽 카드를 더하고 다음 턴(명우)으로 넘김
		int pick_left = cards[left] + solve(left + 1, right, false);
		int pick_right = cards[right] + solve(left, right - 1, false);
		result = max(pick_left, pick_right);
	} else {
		// 명우 차례: 명우는 근우가 가져갈 점수를 최소화함
		// 명우가 가져가므로 근우의 점수는 추가되지 않음
		int opp_pick_left = solve(left + 1, right, true);
		int opp_pick_right = solve(left, right - 1, true);
		result = min(opp_pick_left, opp_pick_right);
	}

	return dp[left][right] = result;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &cards[i]);
		}
		memset(dp, -1, sizeof(dp));

		printf("%d\n", solve(0, n - 1, true));
	}

	return 0;
}