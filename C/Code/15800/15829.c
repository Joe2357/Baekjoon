#include <stdio.h>

typedef long long ll;

const ll M = 1234567891LL;
const ll r = 31LL;
#define MAX_LEN 50

char str[MAX_LEN + 1];
int n;

int main() {
	scanf("%d", &n);
	scanf("%s", str);

	ll result = 0LL, ri = 1LL;
	for (int i = 0; i < n; i += 1, ri *= r, ri %= M) {
		result += (str[i] - 'a' + 1) * ri;
		result %= M;
	}

	printf("%lld", result);
	return 0;
}