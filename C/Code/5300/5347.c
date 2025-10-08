#include <stdio.h>

typedef long long ll;

ll gcd(ll a, ll b) {
	while (b > 0) {
		ll temp = a;
		a = b;
		b = temp % b;
	}
	return a;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		ll a, b;
		scanf("%lld %lld", &a, &b);
		printf("%lld\n", a * b / gcd(a, b));
	}
	return 0;
}