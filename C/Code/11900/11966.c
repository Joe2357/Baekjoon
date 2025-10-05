#include <stdio.h>

const int MAX_EXP = 30;

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i <= MAX_EXP; ++i) {
		if (n == (1 << i)) {
			printf("1");
			return 0;
		}
	}
	printf("0");
	return 0;
}