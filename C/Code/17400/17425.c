#include <stdio.h>

typedef long long ll;

#define MAX_IDX (int)(1e6 + 1)

ll g[MAX_IDX];

void init() {
	for (int i = 1; i < MAX_IDX; ++i) {
		for (int j = i; j < MAX_IDX; j += i) {
			g[j] += i;
		}
		g[i] += g[i - 1];
	}
	return;
}

int main() {
	init();

	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", g[n]);
	}
	return 0;
}