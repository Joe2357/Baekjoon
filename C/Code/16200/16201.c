#include <stdio.h>

typedef long long ll;
typedef struct Node {
	ll x, y;
} ND;

const ll MOD = (ll)(1e9 + 7);
ll r, c;

#define MAX_IDX 1000
ND arr[MAX_IDX + 1];
int k;

ll tile = 0, method = 1;

int cmp(ND* a, ND* b) {
	if (a->x == b->x) {
		return a->y > b->y;
	} else {
		return a->x > b->x;
	}
}

ll power(ll a, ll b) {
	if (b == 0) {
		return 1;
	} else if (b == 1) {
		return a % MOD;
	} else {
		ll x = power((a * a) % MOD, b / 2);
		if (b % 2 == 1) {
			x = (x * a) % MOD;
		}
		return x % MOD;
	}
}

void addLineResult(ll x) {
	tile += (x * (c / 2));
	if (c % 2 == 1) {
		method *= power((c + 1) / 2, x);
		method %= MOD;
	}
	return;
}
void addPartResult(ll x) {
	if (x > 1) {
		tile += (x / 2);
		if (x % 2 == 1) {
			method *= ((x + 1) / 2);
			method %= MOD;
		}
	}
	return;
}

int main() {
	scanf("%lld %lld %d", &r, &c, &k);
	for (int i = 0; i < k; ++i) {
		ll a, b;
		scanf("%lld %lld", &a, &b);
		arr[i] = (ND){a, b};
	}
	arr[k] = (ND){r + 1, 0};

	if (k == 0) {
		addLineResult(r);
	} else {
		qsort(arr, k + 1, sizeof(ND), cmp);
		ND pre = (ND){1, 0};

		for (int i = 0; i < k + 1; ++i) {
			ND cur = arr[i];
			if (cur.x > pre.x && pre.y > 0) {
				addPartResult(c - pre.y);
				pre = (ND){pre.x + 1, 0};
			}

			if (cur.x > pre.x) {
				addLineResult(cur.x - pre.x);
				pre = (ND){cur.x, 0};
			}

			if (cur.y > pre.y) {
				addPartResult(cur.y - pre.y - 1);
			}
			pre = cur;
		}
	}

	printf("%lld %lld", tile, method % MOD);
	return 0;
}