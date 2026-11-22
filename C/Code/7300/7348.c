#include <stdio.h>

#define MAX_IDX 200

int used[MAX_IDX + 1];

#define max(a, b) (((a) > (b)) ? (a) : (b))

void init() {
	for (int i = 0; i <= MAX_IDX; ++i) {
		used[i] = 0;
	}
	return;
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		init();
		int n;
		scanf("%d", &n);
		int ret = 0;

		for (int i = 0; i < n; ++i) {
			int s, t;
			scanf("%d %d", &s, &t);
			if (s > t) {
				int temp = t;
				t = s, s = temp;
			}

			for (int i = (s + 1) / 2; i <= (t + 1) / 2; ++i) {
				used[i] += 1;
				ret = max(ret, used[i]);
			}
		}

		printf("%d\n", ret * 10);
	}
	return 0;
}
