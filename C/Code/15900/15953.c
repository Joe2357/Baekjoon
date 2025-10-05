#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b;
		scanf("%d %d", &a, &b);
		int prize = 0;

		if (a > 0) {
			if (a <= 1) {
				prize += 5000000;
			} else if (a <= 1 + 2) {
				prize += 3000000;
			} else if (a <= 1 + 2 + 3) {
				prize += 2000000;
			} else if (a <= 1 + 2 + 3 + 4) {
				prize += 500000;
			} else if (a <= 1 + 2 + 3 + 4 + 5) {
				prize += 300000;
			} else if (a <= 1 + 2 + 3 + 4 + 5 + 6) {
				prize += 100000;
			}
		}
		if (b > 0) {
			if (b <= 1) {
				prize += 5120000;
			} else if (b <= 1 + 2) {
				prize += 2560000;
			} else if (b <= 1 + 2 + 4) {
				prize += 1280000;
			} else if (b <= 1 + 2 + 4 + 8) {
				prize += 640000;
			} else if (b <= 1 + 2 + 4 + 8 + 16) {
				prize += 320000;
			}
		}

		printf("%d\n", prize);
	}
	return 0;
}