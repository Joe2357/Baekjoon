#include <stdio.h>

#define MAX_IDX (10000 + 1)

int ans[MAX_IDX][4];

void init() {
	ans[1][1] = 1;
	ans[2][2] = 1;
	ans[3][3] = 1;

	/* only 1 */
	for (int i = 2; i < MAX_IDX; ++i) {
		ans[i][1] = ans[i - 1][1];
	}

	/* max value = 2 */
	for (int i = 3; i < MAX_IDX; ++i) {
		ans[i][2] = ans[i - 2][1] + ans[i - 2][2]; // 1+1 or 2
	}

	/* max value = 3 */
	for (int i = 4; i < MAX_IDX; ++i) {
		ans[i][3] = ans[i - 3][1] + ans[i - 3][2] + ans[i - 3][3]; // 1+1+1 or 1+2 or 3
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
		printf("%d\n", ans[n][1] + ans[n][2] + ans[n][3]);
	}
	return 0;
}