#include <stdio.h>

const int MAX_DICE = 6;

#define max(a, b) (((a) > (b)) ? (a) : (b))

int main() {
	int ret = 0;

	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		// case 1 : 모두 같은 수
		if (a == b && b == c) {
			ret = max(ret, 10000 + 1000 * a);
		} else {
			if (a == b) {
				ret = max(ret, 1000 + 100 * a);
			} else if (b == c) {
				ret = max(ret, 1000 + 100 * b);
			} else if (c == a) {
				ret = max(ret, 1000 + 100 * c);
			} else {
				ret = max(ret, 100 * max(max(a, b), c));
			}
		}
	}
	printf("%d", ret);
	return 0;
}