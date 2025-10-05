#include <stdio.h>

typedef long long ll;

#define MAX_IDX (int)(1e6)

int room[MAX_IDX];
int n;
int b, c;

int ceil(int x, int y) {
	int ret = x / y;
	if (x % y > 0) {
		ret += 1;
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", room + i);
	}
	scanf("%d %d", &b, &c);

	ll ret = 0LL;
	for (int i = 0; i < n; ++i) {
		room[i] -= b;
		if (room[i] <= 0) {
			ret += 1LL;
		} else {
			ret += (1LL + ceil(room[i], c));
		}
	}
	printf("%lld", ret);
	return 0;
}