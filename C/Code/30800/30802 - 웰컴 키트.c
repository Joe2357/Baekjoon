#include <stdio.h>

int main() {
	int n;
	int shirts[10];
	int t, p;

	scanf("%d", &n);
	for (int i = 0; i < 6; ++i) {
		scanf("%d", shirts + i);
	}
	scanf("%d %d", &t, &p);

	int ret = 0;
	for (int i = 0; i < 6; ++i) {
		ret += (shirts[i] / t);
		if (shirts[i] % t > 0) {
			++ret;
		}
	}
	printf("%d\n%d %d", ret, n / p, n % p);

	return 0;
}