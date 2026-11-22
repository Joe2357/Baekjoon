#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int l, r;
		scanf("%d %d", &l, &r);

		if (r >= 4) {
			printf("%d\n", r);
		} else {
			int target = 0, cur = 1;
			for (int i = 0; i < 4; ++i) {
				if (l <= i && i <= r) {
					target *= 10;
					target += cur;
				}
				cur *= 2;
			}

			int ans = 0;
			while (target % 2 == 0) {
				target /= 2;
				ans += 1;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}