#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef long long ll;

#define MAX_IDX (1 << 10)
const ll DIGIT = 10LL;
const ll NONE = -1LL;

int n;
ll queue[MAX_IDX];
int front, rear;

ll solve() {
	if (n == 0) {
		return 0;
	} else if (n < DIGIT) {
		return n;
	} else if (n >= MAX_IDX) {
		return NONE;
	}

	ll queue[MAX_IDX];
	for (ll i = 0; i < DIGIT; ++i) {
		queue[rear++] = i;
	}

	while (front < rear) {
		ll curr = queue[front++];
		for (ll digit = 0LL; digit < curr % DIGIT; ++digit) {
			ll next = curr * DIGIT + digit;
			if (rear == n) {
				return next;
			} else {
				queue[rear++] = next;
			}
		}
	}
	return NONE;
}

int main() {
	scanf("%d", &n);
	printf("%lld", solve());
	return 0;
}