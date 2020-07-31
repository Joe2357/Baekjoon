#include <stdio.h>
#define PRI 1234567891

int main(n) {
	// init
	scanf("%d", &n);
	long long result = 0, r = 1;
	char str[51];
	scanf("%s", str);

	// hashing function ( ASCII )
	for (int i = 0; i < n; i++, r *= 31, r %= PRI)
		result += (str[i] - 'a' + 1) * r, result %= PRI;

	// print result
	printf("%lld", result);
	return 0;
}