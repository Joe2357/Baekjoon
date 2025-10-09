#include <stdio.h>

int get_bottle_count(int x) {
	int count = 0;
	while (x > 0) {
		count += (x & 1);
		x /= 2;
	}
	return count;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	int ret = 0;
	for (int i = 1; get_bottle_count(n) > k; i *= 2) {
		if ((n & i) > 0) {
			n += i;
			ret += i;
		}
	}
	printf("%d", ret);
	return 0;
}