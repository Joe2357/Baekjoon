#include <stdio.h>

#define MAX_IDX (int)(1e6)
const int NONE = -1;

int a[MAX_IDX + 1], b[MAX_IDX + 1];
int n;

void read_input() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &b[i]);
	}
	return;
}

int solve() {
	int ret = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (a[i] != b[i]) {
			ret += 1;
			a[i + 1] ^= (a[i] ^ b[i]);
		}
	}

	return ((a[n - 1] != b[n - 1]) ? NONE : ret);
}

int main() {
	read_input();
	printf("%d", solve());
	return 0;
}