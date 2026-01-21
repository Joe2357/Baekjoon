#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef long long ll;

#define MAX_IDX (int)(1e6)
#define DIGIT 10

ll ans[MAX_IDX + 1];
int ans_len = 0;

bool isDigitAllDifferent(ll x) {
	bool digit_used[DIGIT + 1] = {false};
	while (x > 0LL) {
		int d = x % DIGIT;
		if (digit_used[d] == true) {
			return false;
		}
		digit_used[d] = true;
		x /= DIGIT;
	}
	return true;
}

void init() {
	for (ll cur = 1LL; ans_len < MAX_IDX; cur += 1LL) {
		if (isDigitAllDifferent(cur) == true) {
			ans[++ans_len] = cur;
		}
	}
	return;
}

int main() {
	init();
	while (true) {
		int n;
		scanf("%d", &n);

		if (n == 0) {
			break;
		} else {
			printf("%lld\n", ans[n]);
		}
	}
	return 0;
}