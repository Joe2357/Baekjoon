#include <stdio.h>
#define min(a, b) (a > b) ? b : a

long long r2, r5;

void getValue(long long a, int mode) {
	for (long long i = 5; i <= a; i *= 5)
		r5 += a / i * mode;
	for (long long i = 2; i <= a; i *= 2)
		r2 += a / i * mode;
	return;
}

int main() {
	long long n, m;
	scanf("%lld %lld", &n, &m);
	getValue(n, 1);
	getValue(m, -1);
	getValue(n - m, -1);
	printf("%lld", min(r2, r5));
	return 0;
}