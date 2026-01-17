#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		int ret = 0;
		for (int x = 1; x <= a; ++x) {
			for (int y = 1; y <= b; ++y) {
				for (int z = 1; z <= c; ++z) {
					ret += (x % y == y % z && y % z == z % x);
				}
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}