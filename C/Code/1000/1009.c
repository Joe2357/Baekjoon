#include <stdio.h>

const int MAX_COMPUTER = 10;

int power_modular(int a, int b) {
	int ret = 1;
	a %= MAX_COMPUTER;

	while (b > 0) {
		if (b % 2 == 1) {
			ret = (ret * a) % MAX_COMPUTER;
		}
		a = (a * a) % MAX_COMPUTER;
		b /= 2;
	}
	return ret;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b;
		scanf("%d %d", &a, &b);
		int result = power_modular(a, b);

		if (result == 0) { // 0번 컴퓨터는 10번 컴퓨터로 변경
			result = MAX_COMPUTER;
		}
		printf("%d\n", result);
	}
	return 0;
}