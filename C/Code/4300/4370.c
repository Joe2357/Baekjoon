#include <stdbool.h>
#include <stdio.h>

typedef long long ll;

int main() {
	ll n;
	while (scanf("%lld", &n) != EOF) {
		ll p = 1LL;

		while (true) {
			p *= 9LL;
			if (p >= n) {
				printf("Baekjoon wins.\n");
				break;
			}
			p *= 2LL;
			if (p >= n) {
				printf("Donghyuk wins.\n");
				break;
			}
		}
	}
	return 0;
}