#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

int main() {
	while (true) {
		int n;
		scanf("%d", &n);
		if (n == 0) {
			break;
		} else {
			printf("%d\n", n * (n + 1) / 2);
		}
	}
	return 0;
}