#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef long long ll;

int main() {
	ll n;
	scanf("%lld", &n);

	ll ret;
	if (n == 4LL || n == 7LL) {
		ret = -1LL;
	} else {
		ret = n / 5LL;
		switch (n % 5LL) {
			case 0LL: { // n = (5 x q)
				break;
			}
			case 1LL: { // n = (5 x q) + 1 -> (5 x (q - 1)) + 6
				ret += 1LL;
				break;
			}
			case 2LL: { // n = (5 x q) + 2 -> (5 x (q - 2)) + 12
				ret += 2LL;
				break;
			}
			case 3LL: { // n = (5 x q) + 3
				ret += 1LL;
				break;
			}
			case 4LL: { // n = (5 x q) + 4 -> (5 x (q - 1)) + 9
				ret += 2LL;
				break;
			}
		}
	}

	printf("%lld", ret);
	return 0;
}