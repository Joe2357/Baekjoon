#include <stdio.h>

const int MAX_ROUND = 5;

int main() {
	int sum = 0;
	for (int i = 0; i < MAX_ROUND; ++i) {
		int x;
		scanf("%d", &x);
		sum += x;
	}
	printf("%d", sum);
	return 0;
}