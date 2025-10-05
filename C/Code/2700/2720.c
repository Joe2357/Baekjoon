#include <stdio.h>

const int value[4] = {25, 10, 5, 1};

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int money;
		scanf("%d", &money);
		for (int i = 0; i < 4; i++) {
			printf("%d ", money / value[i]);
			money %= value[i];
		}
		printf("\n");
	}
	return 0;
}