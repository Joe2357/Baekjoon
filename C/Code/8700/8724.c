#include <stdio.h>

const int PIN = 1;
const int EMPTY = 0;

#define max(a, b) (((a) > (b)) ? (a) : (b))

int main() {
	int n;
	scanf("%d", &n);

	int ret = 0, cur = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);

		switch (x) {
			case 0: {
				ret = max(ret, cur);
				cur = 0;
				break;
			}
			case 1: {
				cur += 1;
			}
		}
	}
	ret = max(ret, cur);
	printf("%d", ret);
	return 0;
}