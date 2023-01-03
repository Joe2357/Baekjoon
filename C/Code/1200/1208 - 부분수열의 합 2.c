#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;
typedef long long ll;

#define MAX_IDX 40
int arr[MAX_IDX];
bool ch[MAX_IDX + 1];
int n;
int target;

#define MAX_VAL 2000000
ll dp[2][MAX_VAL * 2 + 1];

void makeSubResult(int x, int s, int e, int mode) {
	if (x == e) {
		int temp = 0;
		for (int i = s; i < e; ++i) {
			if (ch[i]) {
				temp += arr[i];
			}
		}
		// printf("%d : %d\n", mode, temp);
		++dp[mode][temp + MAX_VAL];
		return;
	}

	ch[x] = true;
	makeSubResult(x + 1, s, e, mode);
	ch[x] = false;
	makeSubResult(x + 1, s, e, mode);
	return;
}

int main() {
	scanf("%d %d", &n, &target);
	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
	}

	makeSubResult(0, 0, n >> 1, 0);
	makeSubResult(n >> 1, n >> 1, n, 1);

    --dp[0][MAX_VAL], --dp[1][MAX_VAL];
    ll retval = dp[0][target + MAX_VAL] + dp[1][target + MAX_VAL];
	for (int i = 0; i < MAX_VAL * 2 + 1; ++i) {
		int t = 2 * MAX_VAL + target - i;
		if (t >= 0 && t < MAX_VAL * 2 + 1) {
			retval += (dp[0][i] * dp[1][t]);
		}
	}

	printf("%lld", retval);
	return 0;
}