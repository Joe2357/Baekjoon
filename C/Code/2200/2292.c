#include <stdio.h>

typedef long long ll;

int main() {
	ll n;
	scanf("%lld", &n);

	ll temp = 2, i = 0;
	while (n >= temp + 6 * i) {
		temp = temp + 6 * i++;
	}
	printf("%lld", i + 1);
	return 0;
}