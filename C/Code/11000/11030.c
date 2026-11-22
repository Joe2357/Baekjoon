#include <stdio.h>

typedef long long ll;

#define MAX_IDX (int)(20000 + 3)
ll arr[MAX_IDX];

ll phi(ll x) {
	ll retval = 1;
	for (ll i = 2; i * i <= x; ++i) {
		ll k = 0;
		ll p = 1;
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
ll gcd(ll a, ll b) {
	ll temp = 0;
	while (b != 0) {
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}
ll inverse(ll a, ll m) {
	ll m0 = m;
	ll y = 0;
	ll x = 1;

	if (m == 1) {
		return 0;
	}
	while (a > 1) {
		ll q = a / m;
		ll t = m;

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
ll chineseRemainder(ll mod, ll pe, ll r) { return ((mod / pe) * (inverse(mod / pe, pe) * r)); }
ll powWithModulo(ll x, ll y, ll mod) {
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

#define INF 31
ll powUntilMax(ll x, ll y) {
	ll ret = 0;
	if (y == 0) {
		return 1;
	} else if (y == 1) {
		ret = x;
	} else {
		ll xx = powUntilMax(x, y / 2);
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
ll getPower(ll s, ll e, ll cur) {
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

ll solve(ll s, ll e, ll mod) {
	if (mod == 1) {
		return 0;
	} else if (arr[s] == 1) {
		return 1;
	} else if (s + 1 == e) {
		return arr[s] % mod;
	}

	if (gcd(arr[s], mod) == 1) {
		return powWithModulo(arr[s], solve(s + 1, e, phi(mod)), mod);
	}

	// ai and mod is not coprime
	// loop for mod's prime set -> chinese remainder theorem
	ll subMod = mod;
	ll ret = 0;

	for (ll i = 2; i * i <= subMod; ++i) {
		ll cnt = 0;
		ll pe = 1;
		while (subMod % i == 0) {
			++cnt, pe *= i;
			subMod /= i;
		}

		if (cnt > 0) {
			if (gcd(arr[s], i) == 1) {
				ret += chineseRemainder(mod, pe, powWithModulo(arr[s], solve(s + 1, e, phi(pe)), pe));
			} else {
				ll powerValue = getPower(s + 1, e, 1);
				if (powerValue < cnt) {
					ret += chineseRemainder(mod, pe, powWithModulo(arr[s], powerValue, pe));
				}
			}
		}
	}

	if (subMod > 1) {
		ll cnt = 1, pe = subMod;
		if (gcd(arr[s], subMod) == 1) {
			ret += chineseRemainder(mod, pe, powWithModulo(arr[s], solve(s + 1, e, phi(pe)), pe));
		}
	}

	return ret % mod;
}

ll main() {
	ll a, b;
	scanf("%lld %lld", &a, &b);
	for (int i = 0; i < b; ++i) {
		arr[i] = a;
	}

#define STD (ll)(1e8)
	ll ans = solve(0, b, STD);
	// printf("ans : %lld\n", ans);

	if (a == 1) {
		printf("%lld", ans);
	} else if (a == 2) {
		if (b > 4) {
			printf("%08lld", ans);
		} else {
			printf("%lld", ans);
		}
	} else if (b == 1) {
		printf("%lld", ans);
	} else if (b == 2) {
		if (a < 9) {
			printf("%lld", ans);
		} else {
			printf("%08lld", ans);
		}
	} else {
		printf("%08lld", ans);
	}
	return 0;
}