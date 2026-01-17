#include <stdio.h>

typedef long long ll;

ll get_gcd(ll a, ll b) {
	while (b > 0) {
		ll temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int main() {
	ll a, b;
	scanf("%lld %lld", &a, &b);
	ll gcd = get_gcd(a, b);
	ll lcm = (a / gcd) * b;
	printf("%lld", lcm);
	return 0;
}