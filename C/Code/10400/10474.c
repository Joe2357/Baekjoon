#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

int main() {
	while (true) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a == 0 && b == 0) {
			break;
		}
		printf("%d %d / %d\n", a / b, a % b, b);
	}
	return 0;
}