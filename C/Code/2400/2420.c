#include <stdio.h>

typedef long long ll;

#define abs(x) ((x) < 0 ? -(x) : (x))

int main() {
	ll a, b;
	scanf("%lld %lld", &a, &b);
	printf("%lld", abs(a - b));
	return 0;
}