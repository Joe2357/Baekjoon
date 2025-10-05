#include <stdio.h>

const int ONE_STEP = 9;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int yonsei = 0, korea = 0;

		for (int i = 0; i < ONE_STEP; ++i) {
			int y, k;
			scanf("%d %d", &y, &k);
			yonsei += y, korea += k;
		}
		if (yonsei > korea) {
			printf("Yonsei\n");
		} else if (yonsei == korea) {
			printf("Draw\n");
		} else {
			printf("Korea\n");
		}
	}
	return 0;
}