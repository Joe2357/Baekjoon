#include <stdio.h>

const int DIGIT = 10;

int sum_of_decomposition(int x) {
	int ret = x;
	while (x > 0) {
		ret += (x % DIGIT);
		x /= DIGIT;
	}
	return ret;
}

int main() {
	int n;
	scanf("%d", &n);

	int result = 0;
	for (int i = 0; i < n; i++) { // 생성자는 항상 n보다 작다.
		int cur = sum_of_decomposition(i);

		if (cur == n) {
			result = i;
			break;
		}
	}

	printf("%d", result);
	return 0;
}