#include <stdio.h>

typedef long long ll;

#define MAX_IDX (int)(1e6)
int arr[MAX_IDX];
int m;

int phi(int x) {
	int retval = 1;
	for (int i = 2; i * i <= x; ++i) {
		int k = 0;
		int p = 1;
		while (x % i == 0) {
			++k, p *= i;
			x /= i;
		}

		if (k > 0) {
			p /= i;
			retval *= (p * (i - 1));
		}
	}

	if (x > 1) {
		retval *= (x - 1);
	}
	return retval;
}
int gcd(int a, int b) {
	int temp = 0;
	while (b != 0) {
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}
int inverse(int a, int m) {
	int m0 = m;
	int y = 0;
	int x = 1;

	if (m == 1) {
		return 0;
	}
	while (a > 1) {
		int q = a / m;
		int t = m;

		m = a % m;
		a = t;
		t = y;

		y = x - q * y;
		x = t;
	}

	if (x < 0) {
		x = x + m0;
	}

	return x;
}
int chineseRemainder(int mod, int pe, ll r) { return ((mod / pe) * (inverse(mod / pe, pe) * r)); }
ll powWithModulo(ll x, int y, int mod) {
	ll ret = 0;
	if (y == 0) {
		return 1;
	} else if (y == 1) {
		ret = x;
	} else {
		ll xx = powWithModulo(x, y / 2, mod);
		if (y % 2 == 0) {
			ret = xx * xx;
		} else {
			ret = (xx * xx % mod) * x;
		}
	}
	return ret % mod;
}

#define INF 20
int powUntilMax(int x, int y) {
	ll ret = 0;
	if (y == 0) {
		return 1;
	} else if (y == 1) {
		ret = x;
	} else {
		int xx = powUntilMax(x, y / 2);
		if (xx >= INF) {
			return INF;
		}
		if (y % 2 == 0) {
			ret = xx * xx;
		} else {
			ret = (xx * xx) * x;
		}
	}
	return ret;
}
int getPower(int s, int e, int cur) {
	if (s == e) {
		return 0;
	} else if (s + 1 == e) {
		return powUntilMax(arr[s], cur);
	}
	if (cur >= INF) {
		return INF;
	} else if (arr[s] >= INF) {
		return INF;
	} else if (arr[e - 1] >= INF) {
		return INF;
	}

	return getPower(s, e - 1, powUntilMax(arr[e - 1], cur));
}

ll solve(int s, int e, int mod) {
	if (mod == 1) {
		return 0;
	} else if (s + 1 == e) {
		return arr[s] % mod;
	}

	if (gcd(arr[s], mod) == 1) {
		return powWithModulo((ll)arr[s], solve(s + 1, e, phi(mod)), mod);
	}

	// ai and mod is not coprime
	// loop for mod's prime set -> chinese remainder theorem
	int subMod = mod;
	ll ret = 0;

	for (int i = 2; i * i <= subMod; ++i) {
		int cnt = 0;
		int pe = 1;
		while (subMod % i == 0) {
			++cnt, pe *= i;
			subMod /= i;
		}

		if (cnt > 0) {
			if (gcd(arr[s], i) == 1) {
				ret += chineseRemainder(mod, pe, powWithModulo((ll)arr[s], solve(s + 1, e, phi(pe)), pe));
			} else {
				int powerValue = getPower(s + 1, e, 1);
				if (powerValue < cnt) {
					ret += chineseRemainder(mod, pe, powWithModulo((ll)arr[s], powerValue, pe));
				}
			}
		}
	}

	if (subMod > 1) {
		int cnt = 1, pe = subMod;
		if (gcd(arr[s], subMod) == 1) {
			ret += chineseRemainder(mod, pe, powWithModulo((ll)arr[s], solve(s + 1, e, phi(pe)), pe));
		}
	}

	return ret % mod;
}

int main() {
	int t;
	scanf("%d %d", &t, &m);

	while (t--) {
		int n;
		scanf("%d", &n);
		int firstOneAppear = n;
		for (int i = 0; i < n; ++i) {
			scanf("%d", arr + i);
			if (arr[i] == 1 && firstOneAppear == n) {
				firstOneAppear = i + 1;
			}
		}

		printf("%lld\n", solve(0, firstOneAppear, m));
	}
	return 0;
}