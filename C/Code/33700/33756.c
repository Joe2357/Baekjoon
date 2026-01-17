#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef long long ll;

const ll DIGIT = 10LL;
const ll LUCKY_NUMBER = 8LL;

bool solve(ll x) {
	if (x % LUCKY_NUMBER != 0LL) {
		return false;
	} else {
		x /= LUCKY_NUMBER;

		// 각 자릿수는 오름차순이어야하며, 0 또는 9가 포함되어 있으면 안 된다.
		ll prev_digit = DIGIT;
		while (x > 0LL) {
			ll digit = x % DIGIT;
			if (digit == 9LL || prev_digit < digit) {
				return false;
			}
			prev_digit = digit;
			x /= DIGIT;
		}
		return true;
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		ll x;
		scanf("%lld", &x);
		printf("%s\n", solve(x) == true ? "Yes" : "No");
	}
	return 0;
}