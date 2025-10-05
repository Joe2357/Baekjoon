#include <stdio.h>

int T(int n) {
	return (n * (n + 1)) / 2;
}
int W(int n) {
	int ret = 0;
	for (int k = 1; k <= n; ++k) {
		ret += (k * T(k + 1));
	}
	return ret;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", W(n));
	}
	return 0;
}