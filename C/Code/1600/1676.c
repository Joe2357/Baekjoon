#include <stdio.h>

const int FACTOR = 5;

int main() {
	int n;
	scanf("%d", &n);

	int ret = 0;
	while (n--) {
		for (int temp = n + 1; temp > 0 && temp % FACTOR == 0; temp /= FACTOR) {
			ret += 1;
		}
	}
	printf("%d", ret);
	return 0;
}