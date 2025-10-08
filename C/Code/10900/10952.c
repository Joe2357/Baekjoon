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
		} else {
			printf("%d\n", a + b);
		}
	}
	return 0;
}